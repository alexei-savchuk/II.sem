import React from 'react';

const SignUpPasswordInput = ({ password, onPasswordChange, confirmPassword, onConfirmPasswordChange, passwordMatch }) => {
  return (
    <div>
      
      <input placeholder='Password:' type="password" id="password" value={password} onChange={onPasswordChange} />
      <br />
      <input placeholder='Confirm Password:' type="password" id="confirmPassword" value={confirmPassword} onChange={onConfirmPasswordChange} />
      {passwordMatch ? null : <div>Passwords do not match</div>}
    </div>
  );
};

export default SignUpPasswordInput;
