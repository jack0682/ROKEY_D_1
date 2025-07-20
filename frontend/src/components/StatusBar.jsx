import React from 'react';

const StatusBar = ({ connected, messageCount }) => {
  return (
    <div className="status-bar">
      <div>
        🔌 연결 상태:{" "}
        <strong style={{ color: connected ? 'green' : 'red' }}>
          {connected ? "연결됨" : "해제됨"}
        </strong>
      </div>
      <div>
        📥 수신된 메시지: <strong>{messageCount}</strong> 개
      </div>
    </div>
  );
};

export default StatusBar;
