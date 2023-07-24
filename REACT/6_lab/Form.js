import {useState} from "react";

export function Form({notes, setNotes}) {

    const [title, setTitle] = useState('')
    const [text, setText] = useState('')

    const addButtonHandler = (e) => { //вызывается при нажатии кнопки «Добавить примечание». Он создает новый объект заметки с текущей датой, заголовком и текстом и добавляет его в массив заметок с помощью функции setNotes.
        setNotes([...notes, {
            noteTitle: title,
            noteDesc: text
        }])
    }

    const deleteAllButtonHandler = (e) => { //вызывается при нажатии кнопки «Удалить все». Он удаляет все заметки, которые имеют то же значение даты, что и текущая дата.
        setNotes();
    }
    return (
      <form className="myNoteForm">
            <div className="date">{date.toLocaleDateString()}</div>
            <input className="myInput" type="text" placeholder="title"
                   value={title} onChange={(event => setTitle(event.target.value))}
            />
            <textarea className="myInput myTextarea"
                       value={text} onChange={(event => setText(event.target.value))}
                      placeholder="description"
            />
            <div className="buttons">
                <input type="button" className="button" onClick={addButtonHandler} value="Add Note"/>
                <input type="button" className="button" onClick={deleteAllButtonHandler} value="Delete all"/>
                <input type="button" className="button" onClick={deleteFirstNoteButtonHandler} value="Delete first"/>
                <input type="button"  className="button" onClick={deleteLastNoteButtonHandler} value="Delete last   "/>
            </div>
        </form>
    );
}