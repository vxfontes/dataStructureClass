import React, { useState } from 'react';
import { useAutoAnimate } from '@formkit/auto-animate/react';
import { buttonFila, container, containerGeralFila, divInput, inputPrincipal, inputPrincipalFila, styleItemFila, titleFila } from '../styles';
import { Item } from './components';

export function Fila() {
    const [value, setValue] = useState();
    const [animationParent] = useAutoAnimate();
    const [fila, setFila] = useState([]);

    function enfileirar(valor) {
        setFila([...fila, valor]);
    }

    function desenfileirar() {
        if (fila.length > 0) {
            setFila(fila.slice(1, fila.length));
        }

        console.log(fila);
    }

    return (
        <div style={containerGeralFila}>
            <span style={titleFila}>fila</span>

            <br />
            <br />
            <br />

            <div style={divInput}>
                <div style={{ width: '25%', marginLeft: -20 }}>
                    <label style={{
                        color: '#979797ae',
                        marginLeft: -100
                    }}>Insira elemento a ser empilhado</label>
                    <input type="text" onChange={(e) => setValue(e.target.value)} style={inputPrincipalFila} />
                </div>
            </div>

            <br />

            <button onClick={() => enfileirar(value)} style={buttonFila}
                onMouseEnter={(e) => e.target.style.backgroundColor = '#979797ae'}
                onMouseLeave={(e) => e.target.style.backgroundColor = '#0000007c'}>Enfileirar</button>

            <button onClick={() => desenfileirar()} style={buttonFila}
                onMouseEnter={(e) => e.target.style.backgroundColor = '#979797ae'}
                onMouseLeave={(e) => e.target.style.backgroundColor = '#0000007c'}>Desenfileirar</button>

            <br />
            <br />

            <div ref={animationParent} style={container}>
                {fila.map((item, index) => (
                    <Item key={index} item={item} style={styleItemFila} />
                ))}
            </div>
        </div>
    );
}


