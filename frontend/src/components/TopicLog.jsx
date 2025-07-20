import React from 'react';

const TopicLog = ({ messages }) => {
  return (
    <div className="log-box">
      <h2 style={{ fontWeight: 'bold', marginBottom: '0.5rem' }}>📝 수신 로그</h2>
      <div style={{ maxHeight: '260px', overflowY: 'auto' }}>
        {messages.length === 0 && <p style={{ color: '#9ca3af' }}>수신된 메시지가 없습니다.</p>}
        {messages.map((msg, idx) => (
          <div key={idx} style={{ marginBottom: '0.25rem' }}>
            <span style={{ fontWeight: 'bold', color: '#1e3a8a' }}>{msg.time}</span>{" "}
            <span style={{ fontWeight: 'bold', color: '#2563eb' }}>{msg.topic}</span>:
            <span style={{ marginLeft: '0.5rem' }}>{msg.payload}</span>
          </div>
        ))}
      </div>
    </div>
  );
};

export default TopicLog;
