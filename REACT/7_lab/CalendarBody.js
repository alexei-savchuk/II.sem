import React from "react";

function CalendarBody({ selectedDate, handleCellClick, notes }) {
  const isCurrentMonth = (date) => {
    return date.getMonth() === selectedDate.getMonth() && date.getFullYear() === selectedDate.getFullYear();
  };

  const isSelectedDay = (date) => {
    return notes.some((note) => note.date === date.toDateString() && note.selected);
  };

  const formatDate = (date) => {
    const today = new Date();
    const isToday = date.toDateString() === today.toDateString();
    const hasNote = notes.some((note) => note.date === date.toDateString());
    const className = isSelectedDay(date) ? "selected" : isCurrentMonth(date) ? "" : "not-current";
    return (
      <td className={`${className}${hasNote ? " has-note" : ""}${isToday ? " today" : ""}`} onDoubleClick={() => handleCellClick(date)}>
        {date.getDate()}
      </td>
    );
  };
  const dayNames = ["Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"];

  const days = [];
  const firstDay = new Date(selectedDate.getFullYear(), selectedDate.getMonth(), 1).getDay();
  const lastDay = new Date(selectedDate.getFullYear(), selectedDate.getMonth() + 1, 0).getDate();

  const prevMonthLastDay = new Date(selectedDate.getFullYear(), selectedDate.getMonth(), 0).getDate();
  for (let i = firstDay - 1; i >= 0; i--) {
    days.push(new Date(selectedDate.getFullYear(), selectedDate.getMonth() - 1, prevMonthLastDay - i));
  }

  for (let i = 1; i <= lastDay; i++) {
    days.push(new Date(selectedDate.getFullYear(), selectedDate.getMonth(), i));
  }

  const nextMonthDaysCount = 7 - new Date(selectedDate.getFullYear(), selectedDate.getMonth(), lastDay).getDay() - 1;
  for (let i = 1; i <= nextMonthDaysCount; i++) {
    days.push(new Date(selectedDate.getFullYear(), selectedDate.getMonth() + 1, i));
  }

  const rows = [];
  let cells = [];

  days.forEach((date, index) => {
    cells.push(formatDate(date));
    if (index + 1 === days.length || (index + 1) % 7 === 0) {
      rows.push(<tr key={index}>{cells}</tr>);
      cells = [];
    }
  });

  return (
    <table>
      <thead>
        <tr>
          {dayNames.map((day) => (
            <th key={day}>{day}</th>
          ))}
        </tr>
      </thead>
      <tbody>{rows}</tbody>
    </table>
  );
}

export default CalendarBody;
