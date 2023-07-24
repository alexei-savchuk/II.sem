import React, { useState } from 'react';
import './Note.css';

function Notes() {
  const [title, setTitle] = useState('');
  const [date, setDate] = useState('');
  const [text, setText] = useState('');
  const [notes, setNotes] = useState([]);

  const handleTitleChange = (event) => {
    setTitle(event.target.value);
  };

  const handleDateChange = (event) => {
    setDate(event.target.value);
  };

  const handleTextChange = (event) => {
    setText(event.target.value);
  };

  const handleAddNote = (event) => {
    event.preventDefault();
    const newNote = { title, date, text };
    setNotes([...notes, newNote]);
    setTitle('');
    setDate('');
    setText('');
  };

  const handleRemoveFirstNote = () => {
    setNotes(notes.slice(1));
  };

  const handleRemoveLastNote = () => {
    setNotes(notes.slice(0, -1));
  };

  const handleRemoveNote = (index) => {
    const newNotes = notes.filter((note, noteIndex) => noteIndex !== index);
    setNotes(newNotes);
  };

  return (
    <div className="notes-container">
      <form className="form-container" onSubmit={handleAddNote}>
        <label>
          Заголовок заметки:
          <input type="text" value={title} onChange={handleTitleChange} />
        </label>
        <label>
          Дата заметки:
          <input type="date" value={date} onChange={handleDateChange} />
        </label>
        <label>
          Текст заметки:
          <textarea value={text} onChange={handleTextChange} />
        </label>
        <button type="submit">Добавить заметку</button>
      </form>
      <hr />
      <h2>Заметки:</h2>
      {notes.map((note, index) => (
        <div className="note-wrapper" key={index}>
          <h3>{note.title}</h3>
          <p>{note.date}</p>
          <p>{note.text}</p>
          <button onClick={() => handleRemoveNote(index)}>Удалить заметку</button>
        </div>
      ))}
      {notes.length > 2 && (
        <div>
          <div className="button-wrapper">
            <button onClick={handleRemoveFirstNote}>Удалить первую заметку</button>
            <button onClick={handleRemoveLastNote}>Удалить последнюю заметку</button>
          </div>
        </div>
      )}
    </div>
  );
}

export default Notes;