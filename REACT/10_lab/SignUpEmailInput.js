import React from 'react';

const SignUpEmailInput = ({ value, onChange }) => {
  const isValidEmail = (email) => {
    // email validation logic here
    return true; // replace with actual validation logic
  };

  const handleEmailChange = (event) => {
    const email = event.target.value;
    if (isValidEmail(email)) {
      onChange(email);
    }
  };

  return (
    <div>
      <input
      placeholder='Email:'
        type="email"
        id="email"
        value={value}
        onChange={handleEmailChange}
      />
    </div>
  );
};

SignUpEmailInput.isValidEmail = (email) => {
  // email validation logic here
  return true; // replace with actual validation logic
};

export default SignUpEmailInput;
