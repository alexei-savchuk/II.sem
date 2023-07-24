import React, { useState } from "react";
import CalendarHead from "./CalendarHead";
import CalendarBody from "./CalendarBody";
import Notes from "./Notes";
import "./calend.css";

function Scheduler() {
  const [selectedDate, setSelectedDate] = useState(new Date());
  const [showNotes, setShowNotes] = useState(false);

  const nextMonth = () => {
    setSelectedDate((prevDate) => new Date(prevDate.getFullYear(), prevDate.getMonth() + 1, 1));
  };

  const prevMonth = () => {
    setSelectedDate((prevDate) => new Date(prevDate.getFullYear(), prevDate.getMonth() - 1, 1));
  };

  const handleCellClick = () => {
    setShowNotes(!showNotes);
  };

  return (
    <div className="scheduler">
      <div className="calendar">
        <CalendarHead selectedDate={selectedDate} prevMonth={prevMonth} nextMonth={nextMonth} />
        <CalendarBody selectedDate={selectedDate} handleCellClick={handleCellClick} />
      </div>
      {showNotes && <Notes />}
    </div>
  );
}

export default Scheduler;
