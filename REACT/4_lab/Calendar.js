import React, { useState } from "react";
import CalendarHead from "./CalendarHead";
import CalendarBody from "./CalendarBody";

function Calendar() {
  // Состояние для хранения выбранной даты
  const [selectedDate, setSelectedDate] = useState(new Date());

  // Функция для перехода к следующему месяцу
  const nextMonth = () => {
    setSelectedDate(prevDate => new Date(prevDate.getFullYear(), prevDate.getMonth() + 1, 1));
  };

  // Функция для перехода к предыдущему месяцу
  const prevMonth = () => {
    setSelectedDate(prevDate => new Date(prevDate.getFullYear(), prevDate.getMonth() - 1, 1));
  };

  return (
    <div className="calendar">
      <CalendarHead selectedDate={selectedDate} prevMonth={prevMonth} nextMonth={nextMonth} />
      <CalendarBody selectedDate={selectedDate} />
    </div>
  );
}

export default Calendar;
