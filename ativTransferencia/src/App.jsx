import React from "react";
import { Fila } from "./components/fila";
import { Pilha } from "./components/pilha";

const App = () => {
    return (
        <>
            <Estruturas />
            <Pilha />
            <Fila />
        </>
    );
}

export default App;

function Estruturas() {
    return (
        <div style={{
            minHeight: '100vh',
            display: 'flex',
            alignItems: 'center',
            justifyContent: 'center',
            textAlign: 'center'
        }}>
            <span style={{
                fontSize: '50px',
                background: '#ffffff8f',
                color: '#1d2b3a',
                padding: 20,
                paddingLeft: 60,
                letterSpacing: 10,
                textTransform: 'uppercase',
                fontWeight: 'bolder '
            }}>Métodos de estruturas de dados</span>
        </div>
    )
}