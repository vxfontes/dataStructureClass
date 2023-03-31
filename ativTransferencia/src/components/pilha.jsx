import React, { useState } from 'react';
import { useAutoAnimate } from '@formkit/auto-animate/react';
import { button, container, containerGeral, divInput, inputPrincipal, styleItem, title } from '../styles';
import { Item } from './components';


export function Pilha() {
    const [pilha, setPilha] = useState([]);
    const [value, setValue] = useState();
    const [animationParent] = useAutoAnimate('bouncy');

    function empilhar(valor) {
        setPilha([...pilha, valor]);
    }

    function desempilhar() {
        if (pilha.length > 0) {
            setPilha(pilha.slice(0, -1));
        }
    }

    return (
        <div style={containerGeral}>
            <span style={title}>Pilha</span>

            <br />
            <br />
            <br />

            <div style={divInput}>
                <div style={{ width: '25%', marginLeft: -20 }}>
                    <label style={{
                        color: '#e0ccfcb7',
                        marginLeft: -100
                    }}>Insira elemento a ser enfileirado</label>
                    <input type="text" onChange={(e) => setValue(e.target.value)} style={inputPrincipal} />
                </div>
            </div>

            <br />

            <button onClick={() => empilhar(value)} style={button}
                onMouseEnter={(e) => e.target.style.backgroundColor = '#f7f7f725'}
                onMouseLeave={(e) => e.target.style.backgroundColor = '#0000007c'}>Empilhar</button>
                
            <button onClick={() => desempilhar(value)} style={button}
                onMouseEnter={(e) => e.target.style.backgroundColor = '#f7f7f725'}
                onMouseLeave={(e) => e.target.style.backgroundColor = '#0000007c'}>Desempilhar</button>

            <br />
            <br />

            <div ref={animationParent} style={container}>
                {pilha.map((item, index) => (
                    <Item key={index} item={item} style={styleItem} />
                ))}
            </div>
        </div>
    );
}


