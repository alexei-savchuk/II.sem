import React, { useState } from 'react';
import SignUpEmailInput from './SignUpEmailInput';
import SignUpPasswordInput from './SignUpPasswordInput';
import PhoneInput from './PhoneInput';
import ProgressBar from './ProgressBar';

const SignUpForm = () => {
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');
  const [confirmPassword, setConfirmPassword] = useState('');
  const [firstName, setFirstName] = useState('');
  const [lastName, setLastName] = useState('');
  const [patronymic, setPatronymic] = useState('');
  const [gender, setGender] = useState('');
  const [birthDay, setBirthDay] = useState('');
  const [birthMonth, setBirthMonth] = useState('');
  const [birthYear, setBirthYear] = useState('');
  const [passwordStrength, setPasswordStrength] = useState(0);
  const [passwordMatch, setPasswordMatch] = useState(true);

  const handleSubmit = (event) => {
    event.preventDefault();

  };

  const handlePasswordChange = (event) => {
    setPassword(event.target.value);
    setPasswordStrength(getPasswordStrength(event.target.value));
    setPasswordMatch(event.target.value === confirmPassword);
  };

  const handleConfirmPasswordChange = (event) => {
    setConfirmPassword(event.target.value);
    setPasswordMatch(event.target.value === password);
  };

  const getPasswordStrength = (password) => {
    let strength = 0;
    const length = password.length;
    const hasNumber = /\d/.test(password);
    const hasUpper = /[A-Z]/.test(password);
    const hasLower = /[a-z]/.test(password);
    const hasSpecial = /[\W_]/.test(password);
    if (length >= 8) strength += 0.25;
    if (hasNumber) strength += 0.25;
    if (hasUpper) strength += 0.25;
    if (hasLower) strength += 0.25;
    if (hasSpecial) strength += 0.25;
    return strength;
  };

  const isFormValid = () => {
    return (
      email !== '' &&
      password !== '' &&
      confirmPassword !== '' &&
      firstName !== '' &&
      lastName !== '' &&
      patronymic !== '' &&
      gender !== '' &&
      birthDay !== '' &&
      birthMonth !== '' &&
      birthYear !== '' &&
      SignUpEmailInput.isValidEmail(email)
    );
  };

  return (
    <form onSubmit={handleSubmit}>
      <div>
        <SignUpEmailInput value={email} onChange={setEmail} />
      </div>
      <div>
        <SignUpPasswordInput
          password={password}
          onPasswordChange={handlePasswordChange}
          confirmPassword={confirmPassword}
          onConfirmPasswordChange={handleConfirmPasswordChange}
          passwordMatch={passwordMatch}
        />
        <ProgressBar percentage={passwordStrength * 80} class="progress" />
      </div>
      <div>
          <input
          placeholder='First Name:'
          type="text"
          id="firstName"
          value={firstName}
          onChange={(event) => setFirstName(event.target.value)}
        />
      </div>
      <div>
<input
placeholder='Last Name:'
type="text"
id="lastName"
value={lastName}
onChange={(event) => setLastName(event.target.value)}
/>
</div>
<div>
<input
placeholder='Patronymic:'
type="text"
id="patronymic"
value={patronymic}
onChange={(event) => setPatronymic(event.target.value)}
/>
</div>
<div>
<label htmlFor="gender">Gender:</label>
<div>
<label htmlFor="male">
<input
type="radio"
id="male"
name="gender"
value="male"
checked={gender === 'male'}
onChange={(event) => setGender(event.target.value)}
/>
Male
</label>
<label htmlFor="female">
<input
type="radio"
id="female"
name="gender"
value="female"
checked={gender === 'female'}
onChange={(event) => setGender(event.target.value)}
/>
Female
</label>
<label htmlFor="other">
<input
type="radio"
id="other"
name="gender"
value="other"
checked={gender === 'other'}
onChange={(event) => setGender(event.target.value)}
/>
Other
</label>
</div>
</div>
<div>
<label htmlFor="birthDate">Date of Birth:</label>
<div>
<select
id="birthDay"
value={birthDay}
onChange={(event) => setBirthDay(event.target.value)}
>
<option value="">-- Day --</option>
{[...Array(31).keys()].map((day) => (
<option key={day + 1} value={day + 1}>
{day + 1}
</option>
))}
</select>
<select
id="birthMonth"
value={birthMonth}
onChange={(event) => setBirthMonth(event.target.value)}
>
<option value="">-- Month --</option>
{[...Array(12).keys()].map((month) => (
<option key={month + 1} value={month + 1}>
{month + 1}
</option>
))}
</select>
<select
id="birthYear"
value={birthYear}
onChange={(event) => setBirthYear(event.target.value)}
>
<option value="">-- Year --</option>
{[...Array(100).keys()].map((year) => (
<option key={year + 1920} value={year + 1920}>
{year + 1920}
</option>
))}
</select>
</div>
</div>
<PhoneInput/>
<button type="submit" disabled={!isFormValid()}>
Submit
</button>
</form>
);
};

export default SignUpForm;
