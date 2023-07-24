import React, { useState } from "react";
import CalendarHead from "./CalendarHead";
import CalendarBody from "./CalendarBody";
import Notes from "./Notes";
import "./calend.css";

function Scheduler() {
  const [selectedDate, setSelectedDate] = useState(new Date());
  const [showNotes, setShowNotes] = useState(false);
  const [notes, setNotes] = useState([]);

  const nextMonth = () => {
    setSelectedDate((prevDate) => new Date(prevDate.getFullYear(), prevDate.getMonth() + 1, 1));
  };

  const prevMonth = () => {
    setSelectedDate((prevDate) => new Date(prevDate.getFullYear(), prevDate.getMonth() - 1, 1));
  };

  const handleCellClick = (date) => {
    const selectedNote = notes.find((note) => note.date === date.toDateString());
    setShowNotes(!showNotes);
    if (selectedNote) {
      setNotes(
        notes.map((note) =>
          note.date === date.toDateString() ? { ...note, selected: true } : { ...note, selected: false }
        )
      );
    } else {
      setNotes([...notes, { date: date.toDateString(), selected: true }]);
    }
  };

  const handleAddNote = (newNote) => {
    setNotes([...notes, newNote]);
  };

  const handleUpdateNote = (updatedNote) => {
    setNotes(
      notes.map((note) => (note.date === updatedNote.date ? { ...note, ...updatedNote } : note))
    );
  };

  const handleDeleteNote = (date) => {
    setNotes(notes.filter((note) => note.date !== date));
  };

  const handleDeleteAllNotes = () => {
    setNotes([]);
  };

  return (
    <div className="scheduler">
      <div className="calendar">
        <CalendarHead selectedDate={selectedDate} prevMonth={prevMonth} nextMonth={nextMonth} />
        <CalendarBody selectedDate={selectedDate} handleCellClick={handleCellClick} notes={notes} />
      </div>
      {showNotes && (
        <Notes
          selectedDate={selectedDate}
          handleAddNote={handleAddNote}
          handleUpdateNote={handleUpdateNote}
          handleDeleteNote={handleDeleteNote}
          handleDeleteAllNotes={handleDeleteAllNotes}
          notes={notes}
        />
      )}
    </div>
  );
}

export default Scheduler;
