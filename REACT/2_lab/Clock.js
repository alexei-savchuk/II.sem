
import React, { Component } from "react";

class Clock extends Component {
  constructor(props) {
    super(props);
    this.state = {
      time: new Date(),
      format: props.format || 24,
      timezone: props.timezone || Intl.DateTimeFormat().resolvedOptions().timeZone,
    };
  }

  componentDidMount() {
    this.intervalID = setInterval(() => this.tick(), 1000);
  }

  componentWillUnmount() {
    clearInterval(this.intervalID);
  }

  tick() {
    this.setState({ time: new Date() });
  }

  handleFormatChange = (event) => {
    this.setState({ format: parseInt(event.target.value, 10) });
  };

  handleTimezoneChange = (event) => {
    this.setState({ timezone: event.target.value });
  };

  render() {
    const { time, format, timezone } = this.state;
    const options = {
      timeZone: timezone,
      hour12: format === 12,
      hour: format === 12 ? "numeric" : "2-digit",
      minute: "2-digit",
      second: "2-digit",
    };
    const formattedTime = time.toLocaleTimeString(undefined, options);

    return (
      <div>
        <h1>{formattedTime}</h1>
        <label>
          Format:
          </label>
          <select value={format} onChange={this.handleFormatChange}>
            <option value={12}>12 hours</option>
            <option value={24}>24 hours</option>
          </select>
        
        <label>
          Timezone:
          <select value={timezone} onChange={this.handleTimezoneChange}>
            <option value={Intl.DateTimeFormat().resolvedOptions().timeZone}>
              Local time ({Intl.DateTimeFormat().resolvedOptions().timeZone})
            </option>
            <option value="America/New_York">New York</option>
            <option value="Europe/London">London</option>
            <option value="Asia/Tokyo">Tokyo</option>
            <option value="Australia/Sydney">Sydney</option>
            <option value="Pacific/Honolulu">Honolulu</option>
          </select>
        </label>
      </div>
    );
  }
}

export default Clock;
