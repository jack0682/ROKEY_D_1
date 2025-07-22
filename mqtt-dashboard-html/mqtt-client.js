const brokerUrl = 'wss://p021f2cb.ala.asia-southeast1.emqxsl.com:8084/mqtt';
const options = {
  username: 'Rokey',
  password: '1234567',
  clientId: 'mqtt-html-client-' + Math.floor(Math.random() * 1000),
  reconnectPeriod: 1000,
  clean: true,
};

const client = mqtt.connect(brokerUrl, options);
const topic = 'tb4';
const topicsListEl = document.getElementById('topics-list');
const topicDataMap = {}; // topic -> HTML element map

const expectedTopics = [
  "/robot1/battery_state",
  "/robot1/ip",
  "/robot1/cmd_vel",
  "/robot1/dock_status",
  "/robot1/waypoints",
  "/robot1/imu",
  "/robot1/goal_pose",
];

client.on('connect', () => {
  console.log('✅ Connected to MQTT Broker');
  client.subscribe(topic, (err) => {
    if (!err) {
      console.log(`📡 Subscribed to topic: ${topic}`);
    }
  });
});

// 메시지 수신 핸들러
client.on('message', (topic, message) => {
  try {
    const payload = JSON.parse(message.toString());
    const rosTopic = payload.topic;
    const data = payload.data;

    // 토픽이 예상 목록에 있는 경우만 표시
    if (!expectedTopics.includes(rosTopic)) return;

    // UI 요소가 없다면 생성
    if (!topicDataMap[rosTopic]) {
      const container = document.createElement('div');
      container.className = 'topic-entry';

      const title = document.createElement('h3');
      title.textContent = `📍 ${rosTopic}`;
      container.appendChild(title);

      const content = document.createElement('pre');
      content.className = 'topic-content';
      container.appendChild(content);

      topicsListEl.appendChild(container);
      topicDataMap[rosTopic] = content;
    }

    // 데이터 업데이트
    topicDataMap[rosTopic].innerText = JSON.stringify(data, null, 2);
  } catch (err) {
    console.error('❌ Error parsing message:', err);
  }
});
