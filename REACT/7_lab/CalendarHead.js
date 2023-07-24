import React from "react";

function CalendarHead({ selectedDate, prevMonth, nextMonth }) {
  const monthNames = [
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December",
  ];

  return (
    <div className="calendar-head">
      <button onClick={prevMonth}>{"<"}</button>
      <b className="thead">
        {monthNames[selectedDate.getMonth()]} {selectedDate.getFullYear()}
      </b>
      <button onClick={nextMonth}>{">"}</button>
    </div>
  );
}

export default CalendarHead;