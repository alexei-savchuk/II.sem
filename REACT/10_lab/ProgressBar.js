import React from 'react';

const ProgressBar = ({ percentage }) => {
  const getColor = (percent) => {
     if (percent <= 25) return 'grey';
     if (percent <= 50) return 'red';
     if (percent <= 99) return 'yellow';
     if (percent === 100) return 'green';
  };

  const getProgressStyle = (percent) => ({
    width: `100%`,
    backgroundColor: getColor(percent),
  });

  return (
    <div className="progress-bar-container">
      <div className="progress-bar" style={getProgressStyle(percentage)}>
       
      </div>
    </div>
  );
};

export default ProgressBar;
