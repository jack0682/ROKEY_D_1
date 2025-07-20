import React from 'react';

const TopicSelector = ({ topics, onSelect }) => {
  return (
    <div style={{ marginBottom: '1rem' }}>
      <label htmlFor="topic-select" style={{ fontWeight: 'bold', display: 'block', marginBottom: '0.5rem' }}>
        🧭 구독할 토픽 선택
      </label>
      <select
        id="topic-select"
        onChange={(e) => onSelect(e.target.value)}
        style={{
          padding: '0.5rem',
          fontSize: '1rem',
          borderRadius: '6px',
          border: '1px solid #d1d5db',
          width: '100%'
        }}
      >
        {topics.map((topic, idx) => (
          <option key={idx} value={topic}>
            {topic}
          </option>
        ))}
      </select>
    </div>
  );
};

export default TopicSelector;
