import "react-datepicker/dist/react-datepicker.css";

const calculateAge = (birthdate) => {
    const today = new Date();
    const birthDate = new Date(birthdate);
    let age = today.getFullYear() - birthDate.getFullYear();
    const monthDiff = today.getMonth() - birthDate.getMonth();
  
    if (monthDiff < 0 || (monthDiff === 0 && today.getDate() < birthDate.getDate())) {
      age--;
    }
  
    return age;
  };
  
  const calculateCourse = (year) => {
    const currentYear = new Date().getFullYear();
    const course = currentYear - year;
    return course > 4 ? "Окончил университет" : course;
  };

  const getEmailProvider = (email) => {
    return email.split('@')[1];
  };

  const getMobileProvider = (phoneNumber) => {
    // Удаление символа '+' из начала номера, если он есть
    const formattedNumber = phoneNumber.startsWith('+') ? phoneNumber.slice(1) : phoneNumber;
  
    // Извлечение кода оператора из номера телефона (три цифры после кода страны)
    const operatorCode = formattedNumber.slice(3, 5);
  
    // Словарь с кодами операторов и их названиями
    const operators = {
      '33': 'МТС',
      '29': 'МТС',
      '44': 'Билайн',
      '25': 'Velcome',
    };
  
    // Возвращение названия оператора или "Неизвестный оператор", если код не найден
    return operators[operatorCode] || 'Неизвестный оператор';
  };

const AdditionalInfo = ({ formData }) => {
  const age = calculateAge(formData.birthdate);
  const course = calculateCourse(formData.year);
  const emailProvider = getEmailProvider(formData.email);
  const mobileProvider = getMobileProvider(formData.phone);

  return (
    <div>
      <tr>Возраст: {age}</tr>
      <tr>Курс: {course}</tr>
      <tr>Оператор электронной почты: {emailProvider}</tr>
      <tr>Оператор мобильной связи: {mobileProvider}</tr>
    </div>
  );
};

export default AdditionalInfo;