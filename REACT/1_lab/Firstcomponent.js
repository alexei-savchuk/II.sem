import React from 'react'

export default function Firstcomponent() {
    
    let Stocks = [{
        stock_name: "EFX",
        company_name: "Equifax Inc",
        price: 163.55,
        currency: "USD",
        change: "+9.03"
    }, {
        stock_name: "IRM",
        company_name: "Iron Mountain Inc",
        price: 33.21,
        currency: "USD",
        change: "+1.42"
    }, {
        stock_name: "NTAP",
        company_name: "NetApp Inc",
        price: 54.81,
        currency: "USD",
        change: "-6.01"
    }, {
        stock_name: "CTL",
        company_name: "Centurylink Inc",
        price: 13.79,
        currency: "USD",
        change: "-1.37"
    }];
    
    function bob() {
       document.querySelector('.tablet').innerHTML=`<table class="company"></table>`
        let row = document.createElement('tr')
        row.className = 'roow';
        row.innerHTML = `<td>Название</td><td>Компания</td><td>Цена</td><td>Валюта</td><td>Изменение</td>`
        document.querySelector('.company').appendChild(row)
        
    for(let i=0; i<Stocks.length; i++){
       
        let row = document.createElement('tr')
        row.innerHTML=`
        <td>${Stocks[i].stock_name}</td>
        <td>${Stocks[i].company_name}</td>
        <td>${Stocks[i].price}</td>
        <td>${Stocks[i].currency}</td>
        ${change(Stocks[i])}
        `
        document.querySelector('.company').appendChild(row)
        
    }
    
    }

    function change(stock){
            if(parseInt(stock.change) > 0) {
                return(`<td class = "green">${stock.change}</td>`)}
            if (parseInt(stock.change) < 0) {
                return(`<td class = "red">${stock.change}</td>`)}
    }


 let hello = new Date()
  return (
    <div>
      <h1>First task</h1>
      <p>{hello.getDate()}.{hello.getMonth() + 1}.{hello.getFullYear()}</p>
      <h1>Second task</h1>
      <button onClick={bob}>table</button>
      <div class="tablet"></div>
    </div>
  )
  }






















































  