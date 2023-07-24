import styles from './MyComponent.module.css';
import React, { useState } from "react";
import "react-datepicker/dist/react-datepicker.css";
import DatePicker from "react-datepicker";
import AdditionalInfo from "./StudentInfoHandler";

function StudentInfo() {
    const renderYearOptions = () => {
        const currentYear = new Date().getFullYear();
        const years = [];
        for (let i = currentYear; i >= currentYear - 10; i--) {
            years.push(i);
        }
        return years.map((year) => (
            <option key={year} value={year}>
                {year}
            </option>  // добовление выподающего списка с годами 2023 - 10
        ));
    };

    const [birthdate, setBirthdate] = useState(null);

    const isFormValid = () => {
        return (
            formData.name &&
            formData.email &&
            birthdate &&
            formData.year &&
            formData.faculty &&
            formData.gruppa &&
            formData.specialnost
        );
    };

    const [formData, setFormData] = useState({
        name: "",
        email: "",
        message: "",
        birthdate: "",
        faculty: "",
        gruppa: "",
        specialnost: ""
    });

    const handleChange = (event) => {
        const { name, value } = event.target;
        setFormData({ ...formData, [name]: value });
    };

    const handleSubmit = (event) => {
        event.preventDefault();
        // Отображение данных студента на странице
        setFormData({
            ...formData,
            submitted: true, // добавляем флаг, что данные были отправлены
            birthdate: birthdate // добавляем дату рождения в объект formData
        });
        setBirthdate(null);
    };

    const handleReset = () => {
        setFormData({
            name: "",
            email: "",
            message: "",
            birthdate: "",
            faculty: "",
            gruppa: "",
            specialnost: "",
            phone: "",
            submitted: false // reset the submitted flag
        });
        setBirthdate(null);
    };

    return (
        <div className={styles['my-component']}>
          {formData.submitted ? (
            <div className={styles['my-component-qwerty']}>
              <table>
                <tr>
                  <td>ФИО:</td>
                  <td>{formData.name}</td>
                </tr>
                <tr>
                  <td>Дата рождения:</td>
                  <td>{formData.birthdate.toLocaleDateString()}</td>
                </tr>
                <tr>
                  <td>Дата поступления:</td>
                  <td>{formData.year}</td>
                </tr>
                <tr>
                  <td>Факультет:</td>
                  <td>{formData.faculty}</td>
                </tr>
                <tr>
                  <td>Группа:</td>
                  <td>{formData.gruppa}</td>
                </tr>
                <tr>
                  <td>Специальность:</td>
                  <td>{formData.specialnost}</td>
                </tr>
                <tr>
                  <td>Email:</td>
                  <td>{formData.email}</td>
                </tr>
                <tr>
                  <td>Номер телефона:</td>
                  <td>{formData.phone}</td>
                </tr>
                <AdditionalInfo formData={formData} />
              </table>
              <button className={styles['my-component-reset-button']} onClick={handleReset}>Reset</button>
            </div>
          ) : (
            <form onSubmit={handleSubmit} className={styles['my-component-form']}>
              <label className={styles['my-component-label']}>
                ФИО:
                <input
                  type='text'
                  name='name'
                  value={formData.name}
                  onChange={handleChange}
                  className={styles['my-component-input']}
                />
              </label>
              <label className={styles['my-component-label']}>
                Дата рождения:
                <DatePicker
                  selected={birthdate}
                  onChange={(date) => setBirthdate(date)}
                  dateFormat='dd/MM/yyyy'
                  showYearDropdown
                  scrollableYearDropdown
                  yearDropdownItemNumber={100}
                  className={styles['my-component-input']}
                />
              </label>
              <label className={styles['my-component-label']}>
                Дата поступления:
                <select
                  name='year'
                  value={formData.year}
                  onChange={handleChange}
                  className={styles['my-component-input']}
                >
                  {renderYearOptions()}
                </select>
              </label>
              <label className={styles['my-component-label']}>
                Факультет:
                <input
                  type='text'
                  name='faculty'
                  value={formData.faculty}
                  onChange={handleChange}
                  className={styles['my-component-input']}
                />
              </label>
                    <label className={styles['my-component-label']}>
                        Группа:
                        <input
                            type="text"
                            name="gruppa"
                            value={formData.gruppa}
                            onChange={handleChange}
                            className={styles['my-component-input']}
                        />
                    </label>
                    <label className={styles['my-component-label']}>
                        Специальность:
                        <input
                            type="text"
                            name="specialnost"
                            value={formData.specialnost}
                            onChange={handleChange}
                            className={styles['my-component-input']}
                        />
                    </label>
                    <label className={styles['my-component-label']}>
                        Email:
                        <input
                            type="email"
                            name="email"
                            value={formData.email}
                            onChange={handleChange}
                            className={styles['my-component-input']}
                        />
                    </label>
                    <label className={styles['my-component-label']}>
                        Номер телефона:
                        <input
                            type="tel"
                            name="phone"
                            value={formData.phone}
                            onChange={handleChange}
                            className={styles['my-component-input']}
                        />
                    </label>
                    <input  type="submit" value="Submit" disabled={!isFormValid()} className={styles['my-component-label']} />
                </form>
            )}
        </div>
    );
}
export default StudentInfo;
