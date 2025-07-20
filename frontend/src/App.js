import React, { useEffect, useState } from 'react';
import client from './mqttClient';

import TopicLog from './components/TopicLog';
import RealtimeChart from './components/RealtimeChart';
import TopicSelector from './components/TopicSelector';
import StatusBar from './components/StatusBar';

const predefinedTopics = [
  "/robot1/odom",
  "/robot1/battery_state",
  "/robot1/amcl_pose",
  "/robot3/odom",
  "/robot3/scan"
];

function App() {
  const [connected, setConnected] = useState(false);
  const [selectedTopic, setSelectedTopic] = useState(predefinedTopics[0]);
  const [messages, setMessages] = useState([]);
  const [chartData, setChartData] = useState([]);

  useEffect(() => {
    client.on('connect', () => {
      console.log('✅ MQTT Connected');
      setConnected(true);
      predefinedTopics.forEach(topic => client.subscribe(topic));
    });

    client.on('disconnect', () => {
      console.log('❌ MQTT Disconnected');
      setConnected(false);
    });

    client.on('message', (topic, payload) => {
      const msg = {
        topic,
        payload: payload.toString(),
        time: new Date().toLocaleTimeString()
      };

      // 로그 업데이트 (최대 100개)
      setMessages(prev => [msg, ...prev.slice(0, 99)]);

      // 차트용 데이터 업데이트
      if (topic === selectedTopic) {
        const numeric = parseFloat(msg.payload);
        if (!isNaN(numeric)) {
          setChartData(prev => [...prev.slice(-19), { time: msg.time, value: numeric }]);
        }
      }
    });

    return () => client.end(); // 컴포넌트 언마운트 시 연결 종료
  }, [selectedTopic]);

  return (
    <div className="min-h-screen bg-gray-50 text-gray-800 p-4">
      <h1 className="text-2xl font-bold mb-4">🤖 MQTT 대시보드 (robot1 / robot3)</h1>

      <StatusBar connected={connected} messageCount={messages.length} />

      <TopicSelector topics={predefinedTopics} onSelect={setSelectedTopic} />

      <RealtimeChart data={chartData} topic={selectedTopic} />

      <TopicLog messages={messages} />
    </div>
  );
}

export default App;
