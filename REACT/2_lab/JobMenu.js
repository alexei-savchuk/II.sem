import React, { useState } from 'react';

const professions = [
  { id: 1, name: 'Программист', links: [
    { id: 1, title: 'Stack Overflow', url: 'https://stackoverflow.com/' },
    { id: 2, title: 'GitHub', url: 'https://github.com/' },
    { id: 3, title: 'Habr', url: 'https://habr.com/ru/' },
    { id: 4, title: 'Medium', url: 'https://medium.com/' },
    { id: 5, title: 'Codepen', url: 'https://codepen.io/' },
    { id: 6, title: 'Dev.to', url: 'https://dev.to/' },
    { id: 7, title: 'W3Schools', url: 'https://www.w3schools.com/' }
  ]},
  { id: 2, name: 'Дизайнер', links: [
    { id: 1, title: 'Behance', url: 'https://www.behance.net/' },
    { id: 2, title: 'Dribbble', url: 'https://dribbble.com/' },
    { id: 3, title: 'Canva', url: 'https://www.canva.com/' },
    { id: 4, title: 'Pinterest', url: 'https://www.pinterest.com/' },
    { id: 5, title: 'Adobe Creative Cloud', url: 'https://www.adobe.com/creativecloud.html' },
    { id: 6, title: 'Figma', url: 'https://www.figma.com/' },
    { id: 7, title: 'Sketch', url: 'https://www.sketch.com/' }
  ]},
  { id: 3, name: 'Маркетолог', links: [
    { id: 1, title: 'Google Ads', url: 'https://ads.google.com/' },
    { id: 2, title: 'Facebook Ads', url: 'https://www.facebook.com/business/help/103521543020943' },
    { id: 3, title: 'Yandex.Direct', url: 'https://direct.yandex.ru/' },
    { id: 4, title: 'LinkedIn Ads', url: 'https://www.linkedin.com/ad/start/' },
    { id: 5, title: 'Google Analytics', url: 'https://analytics.google.com/' },
    { id: 6, title: 'HubSpot', url: 'https://www.hubspot.com/' },
    { id: 7, title: 'Mailchimp', url: 'https://mailchimp.com/' }
  ]},
  { id: 4, name: 'Юрист', links: [
    { id: 1, title: 'КонсультантПлюс', url: 'https://www.consultant.ru/' },
    { id: 2, title: 'Гарант', url: 'https://www.garant.ru/' },
    { id: 3, titel: 'Конституция', url:'https://www.garant.ru/'},
    { id: 4, title: 'Лента.бай', url: 'https://lenta.ru/' },
    { id: 5, title: 'Ведомости', url: 'https://www.vedomosti.ru/' },
    { id: 6, title: 'The Belarus Times', url: 'https://www.themoscowtimes.com/' },
    { id: 7, title: 'РБК', url: 'https://www.rbc.ru/' }
    ]}
  ];
  
  const JobMenu = () => {
    const [selectedProfession, setSelectedProfession] = useState(2);
  
    const handleProfessionChange = (event) => {
      setSelectedProfession(Number(event.target.value));
    }
  
    const selectedProfessionLinks = professions.find((profession) => profession.id === selectedProfession).links;
  
    return (
      <div>
        <h1>SECOND TASK</h1>
        <div>
          {professions.map((profession) => (
            <div key={profession.id}>
              <input type="radio" id={profession.name} name="profession" value={profession.id} checked={selectedProfession === profession.id} onChange={handleProfessionChange} />
              <label htmlFor={profession.name}>{profession.name}</label>
            </div>
          ))}
        </div>
        <div>
          {selectedProfessionLinks.map((link) => (
            <p>
            <a key={link.id} href={link.url}>{link.title}</a>
  
            </p>
          ))}
        </div>
      </div>);
  };
  
export default JobMenu;