import React, { useState } from "react";
import "./Note.css";

function Notes({ selectedDate, handleAddNote, handleUpdateNote, handleDeleteNote, handleDeleteAllNotes, notes }) {
  const [title, setTitle] = useState("");
  const [date, setDate] = useState("");
  const [text, setText] = useState("");

  const handleTitleChange = (event) => {
    setTitle(event.target.value);
  };

  const handleDateChange = (event) => {
    setDate(event.target.value);
  };

  const handleTextChange = (event) => {
    setText(event.target.value);
  };

  const handleAddClick = (event) => {
    event.preventDefault();
    if (title && date && text) {
      handleAddNote({
        title,
        date,
        text,
      });
      setTitle("");
      setDate("");
      setText("");
    }
  };

  const handleUpdateClick = (event) => {
    event.preventDefault();
    if (title && date && text) {
      handleUpdateNote({
        title,
        date,
        text,
      });
      setTitle("");
      setDate("");
      setText("");
    }
  };

  const handleNoteClick = (note) => {
    setTitle(note.title);
    setDate(note.date);
    setText(note.text);
  };

  const handleRemoveNote = (date) => {
    handleDeleteNote(date);
    setTitle("");
    setDate("");
    setText("");
  };

  return (
    <div className="notes-container">
      <form className="form-container">
<label>
Заголовок заметки:
<input type="text" value={title} onChange={handleTitleChange} />
</label>
<label>
Текст заметки:
<textarea value={text} onChange={handleTextChange} />
</label>
{!title && !date && !text && (
<button onClick={handleAddClick} type="submit">Добавить заметку</button>
)}
{title || date || text ? (
<div>
<button onClick={handleUpdateClick} type="submit">
Обновить заметку
</button>
<button onClick={() => {
setTitle("");
setDate("");
setText("");
}}
>
Отменить
</button>
</div>
) : null}
</form>
<hr />
<h2>Заметки:</h2>
{notes.length > 0 ? (
<div>
{notes.map((note, index) => (
<div className={`note-wrapper ${selectedDate === note.date ? "selected-note" : ""}`} key={index}>
<h3>{note.title}</h3>
<p>{note.date}</p>
<p>{note.text}</p>
<button onClick={() => handleNoteClick(note)}>Редактировать</button>
<button onClick={() => handleRemoveNote(note.date)}>Удалить заметку</button>
</div>
))}
<div className="button-wrapper">
<button onClick={handleDeleteAllNotes}>Удалить все заметки</button>
</div>
</div>
) : (
<p>Нет заметок</p>
)}
</div>
);
}

export default Notes;
