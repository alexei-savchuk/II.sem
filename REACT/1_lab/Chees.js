import React from 'react'

export default function Chess() {

    function letters() {
        return(
            <tr>
                <td className="space"></td>
                <td className="letter">a</td>
                <td className="letter">b</td>
                <td className="letter">c</td>
                <td className="letter">d</td>
                <td className="letter">e</td>
                <td className="letter">f</td>
                <td className="letter">g</td>
                <td className="letter">h</td>
            </tr>
        )
      
      }
      
      const ChessBoard = () =>{
        const dosk = [];
        for (let i = 8; i > 0; i--) {
            dosk.push(
                <tr> 
                    <td className='number'>{i}</td>
                    <td className={i % 2? 'Odd' : 'Even'}/>
                    <td className={i % 2? 'Even' : 'Odd'}/>
                    <td className={i % 2? 'Odd' : 'Even'}/>
                    <td className={i % 2? 'Even' : 'Odd'}/>
                    <td className={i % 2? 'Odd' : 'Even'}/>
                    <td className={i % 2? 'Even' : 'Odd'}/>
                    <td className={i % 2? 'Odd' : 'Even'}/>
                    <td className={i % 2? 'Even' : 'Odd'}/>
                    <td className='number'>{i}</td>
                </tr>
            );
        }
        return dosk;
      }
      



    return (
        <div>
          <h1>Third task</h1>
          <table class="chess">
                {letters()}
                {ChessBoard()}
                {letters()}
          </table>
        </div>
      )
}
