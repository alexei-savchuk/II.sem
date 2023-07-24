import React from "react";
import { Component } from "react";

export class Comments extends Component {
  constructor(props) {
    super(props);
    this.state = {
      img: "",
      comments: [
        {
          name: "Nikita",
          avatar: "/avatars/avatar2.jpg",
          email: "alxei.savchuk.l@mail.ru",
          message: "кто если не вы",
          secretWord: "chaika",
          date: new Date(),
        },
      ],
      delete: null,
      edit: null,
      info: null,
    };
  }
  avatars = [
    {
      img: "/avatars/avatar.jpg",
      name: "выберите аватар",
    },
    {
      img: "/avatars/avatar1.jpg",
      name: "first",
    },
    {
      img: "/avatars/avatar2.jpg",
      name: "second",
    },
    {
      img: "/avatars/avatar3.jpg",
      name: "third",
    },
  ];
  onSubmit = (e) => {
    e.preventDefault();
    let comment = {
      name: this.name.value,
      avatar: this.state.img,
      email: this.email.value,
      message: this.message.value,
      secretWord: this.secretWord.value,
      date: new Date(),
    };
    this.setState({
      comments: [...this.state.comments, comment],
    });
    this.name.value = null;
    this.email.value = null;
    this.message.value = null;
    this.secretWord.value = null;
    
  };
  comments() {
    return this.state.comments.map((comment) => {
      return (
        <div className="comment" key={comment.message}>
          <button class="av" onClick={() => this.setState({ edit: comment, delete: null, info: null })}>Редактирование</button>
          {comment === this.state.edit ? 
          <CommentsEdit 
            comment={this.state.edit}
            editComment={this.editComment}
          />
           : null}
          <button class="av" onClick={() => this.setState({ delete: comment, edit: null, info: null })}>
            Удалить
          </button>
          {comment === this.state.delete ? (
            <CommentsDel
              deleteComment={this.deleteComment}
              comment={this.state.delete}
            />
          ) : null}
          <button class="av" onClick={() => this.setState({ info: comment, edit: null, delete: null })}>Инфоформация</button>
          {comment === this.state.info ? (
            <CommentsInfo comment={this.state.info} />
          ) : null}
          <div className="name">Пользователь:{comment.name}</div>
          <div className="message">Комментарий:{comment.message}</div>
          <img
            style={{ height: "70px", width: "70px" }}
            src={comment.avatar}
            alt=""
          />
        </div>
      );
    });
  }
  deleteComment = (comment) => {
    for (let i = 0; i < this.state.comments.length; i++) {
      if (this.state.comments[i] === comment) {
        return this.setState(({ comments }) => ({
          comments: [...comments.slice(0, i), ...comments.slice(i + 1)],
          delete: null
        }));
      }
    }
  };
  editComment = (comment, text) => {
    for (let i = 0; i < this.state.comments.length; i++) {
      if (this.state.comments[i] === comment) {
        comment.message = text;
        comment.date = new Date();
        return this.setState(({ comments }) => ({
          comments: [...comments.slice(0, i), comment, ...comments.slice(i + 1)],//
          edit: null
        }));
      }
    }
  }
  render() {
    return (
      <>
        <form className="form-container" onSubmit={this.onSubmit}>
          <div className="form-inputs">
            <div className="input-field">
              <label className="label">Имя пользователя:</label>
              <input
                ref={(e) => (this.name = e)}
                type="text"
                placeholder="Имя пользователя"
                name=""
              />
            </div>
            <div className="input-field">
              <label className="label">Email:</label>
              <input
                ref={(e) => (this.email = e)}
                type="email"
                placeholder="Email"
              />
            </div>
            <div className="input-field">
              <label className="label">Комментарий:</label>
              <textarea
                placeholder="Комментарий"
                ref={(e) => (this.message = e)}
              />
            </div>
            <div className="input-field">
              <label className="label">Секретное слово:</label>
              <input
                ref={(e) => (this.secretWord = e)}
                type="text"
                placeholder="Секретное слово"
              />
            </div>
          </div>
          <div className="avatar-selection">
            <select onChange={(e) => this.setState({ img: e.target.value })}>
              {this.avatars.map((avatar) => {
                return (
                  <option key={avatar.img} value={avatar.img}>
                    {avatar.name}
                  </option>
                );
              })}
            </select>
            <img
              className="avatar-preview"
              src={this.state.img}
              alt=""
            />
          </div>
          <div className="submit-button">
            <button type="submit" class='but'>Отправить</button>
          </div>
        </form>
        {this.comments()}
      </>
    );
  }
}

class CommentsDel extends Component {
  onSubmit = (e) => {
    e.preventDefault()//предотвращает отправку данных формы и перезагрузку страницы
    if (this.yourWord.value === this.props.comment.secretWord) {
      return this.props.deleteComment(this.props.comment);
    }
    alert("Неправильное секретное слово!")
  }
  render() {
    return (
      <form onSubmit={this.onSubmit}>
        <input
          type="text"
          ref={(e) => (this.yourWord = e)}
          placeholder="Секретное слово"
        />
        <input type="submit" value="Подтвердить" />
      </form>
    );
  }
}
class CommentsEdit extends Component {
  onSubmit = e => {
    e.preventDefault()
    this.props.editComment(this.props.comment, this.yourComment.value)
  }
  render() {
    return (
      <form onSubmit={this.onSubmit}>
        <div className="name">Пользователь:{this.props.comment.name}</div>
        <div className="message">Email:{this.props.comment.email}</div>
        <textarea ref={(e) => (this.yourComment = e)} defaultValue={this.props.comment.message} />
        <input type="submit" value="Подтвердить" />
      </form>
    )
  }
}
class CommentsInfo extends Component {
  render() {
    let comment = this.props.comment;
    return (
      <>
        <div className="name">Пользователь:{comment.name}</div>
        <div className="date">Дата изменения:{comment.date.toLocaleString()}</div>
        <div className="message">Email:{comment.email}</div>
      </>
    );
  }
}
