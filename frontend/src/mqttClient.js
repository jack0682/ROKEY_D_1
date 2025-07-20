import mqtt from 'mqtt';

// EMQX WebSocket over TLS 브로커 주소
const brokerUrl = 'wss://p021f2cb.ala.asia-southeast1.emqxsl.com:8084/mqtt';

const options = {
  username: 'Rokey',
  password: '1234567',
  connectTimeout: 4000,
  reconnectPeriod: 2000,
  clean: true
};

// MQTT.js 클라이언트 생성
const client = mqtt.connect(brokerUrl, options);

// 디버깅용 로그 (선택)
client.on('error', (err) => {
  console.error('MQTT 연결 오류:', err);
});

export default client;
