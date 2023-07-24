import React, { useState } from "react";

const PhoneInput = () => {
  const [phoneNumber, setPhoneNumber] = useState("");
  const [countryCode, setCountryCode] = useState("");
  const [operatorCode, setOperatorCode] = useState("");

  const handleCountryCodeChange = (event) => {
    setCountryCode(event.target.value);
    setPhoneNumber(`+${event.target.value}`);
  };

  const handleOperatorCodeChange = (event) => {
    setOperatorCode(event.target.value);
    setPhoneNumber(`+${countryCode}${event.target.value}`);
  };

  const handlePhoneNumberChange = (event) => {
    let value = event.target.value;
    switch (countryCode) {
      case "375":
        value = value.replace(/\D/g, "").slice(0, 12); 
        value = value.replace(/(\d{3})(\d{2})(\d{3})(\d{2})(\d{2})/, "+$1 ($2) $3-$4-$5");
        break;
      case "7":
        value = value.replace(/\D/g, "").slice(0, 11); 
        value = value.replace(/(\d{1})(\d{3})(\d{3})(\d{2})(\d{2})/, "+$1 ($2) $3-$4-$5");
        break;
      case "380":
        value = value.replace(/\D/g, "").slice(0, 12); 
        value = value.replace(/(\d{3})(\d{2})(\d{3})(\d{2})(\d{2})/, "+$1 ($2) $3-$4-$5");
        break;
      case "48":
        value = value.replace(/\D/g, "").slice(0, 11); 
        value = value.replace(/(\d{2})(\d{3})(\d{3})(\d{3})/, "+$1-$2-$3-$4");
        break;
      case "370":
        value = value.replace(/\D/g, "").slice(0, 12); 
        value = value.replace(/(\d{3})(\d{2})(\d{3})(\d{2})(\d{2})/, "+$1 ($2) $3-$4-$5");
        break;
      case "371":
        value = value.replace(/\D/g, "").slice(0, 11);
        value = value.replace(/(\d{3})(\d{4})(\d{4})/, "+$1 $2-$3");
        break;
      default:
        break;
    }
    setPhoneNumber(value);
  };
  

  const getPlaceholder = () => {
    switch (countryCode) {
      case "375":
        return "+375 (XX) XXX-XX-XX";
      case "7":
        return "+7 (XXX) XXX-XX-XX";
      case "380":
        return "+380 (XX) XXX-XX-XX";
      case "48":
        return "+48 XXX-XXX-XXX";
      case "370":
        return "+370 (XX) XXX-XX-XX";
      case "371":
        return "+371 XXXX-XXXX";
      default:
        return "";
    }
  };

  return (
    <div>
      <label>
        <select class="selectt" value={countryCode} onChange={handleCountryCodeChange}>
          <option value="">Select country</option>
          <option value="375">Belarus (+375)</option>
          <option value="7">Russia (+7)</option>
          <option value="380">Ukraine (+380)</option>
          <option value="48">Poland (+48)</option>
          <option value="370">Lithuania (+370)</option>
          <option value="371">Latvia (+371)</option>
        </select>
      </label>
      <p>
      {countryCode && (
        <label>
          <select  class="selectt" value={operatorCode} onChange={handleOperatorCodeChange}>
            <option value="">Select operator</option>
            {countryCode === "375" && (
              <>
                <option value="(33)">MTC (33)</option>
                <option value="(29)">Velcom (29)</option>
                <option value="(25)">Life (25)</option>
              </>
            )}
            {countryCode === "7" && (
              <>
                <option value="(900)">Beeline (900)</option>
                <option value="(901)">MTS (901)</option>
                <option value="(902)">MegaFon (902)</option>
              </>
            )}
            {countryCode === "380" && (
              <>
                <option value="(50)">MTS (50)</option>
                <option value="(63)">Life (63)</option>
                <option value="(67)">Kyivstar (67)</option>
              </>
            )}
            {countryCode === "48" && (
              <>
                <option>Orange</option>
                <option>Play</option>
                <option>Plus</option>
                <option>T-mobile</option>
              </>
          )}
        {countryCode === "370" && (
              <>
                <option value="(20)">Telia</option>
                <option value="(25)">Bite</option>
                <option value="(21)">Tele2</option> 
              </>
          )}
        {countryCode === "371" && (
              <>
                <option>LMT</option>
                <option>Bite</option>
                <option>Tele2</option>
              </>
          )}
      </select>
    </label>
  )}
  </p>
  <label>
    <input
      type="tel"
      value={phoneNumber}
      onChange={handlePhoneNumberChange}
      placeholder='Phone Number:'
    />
  </label>
</div>
);
};

export default PhoneInput;