// 1. Faça um programa em C++ para apresentar um menu várias vezes, 
// com as seguintes opções: 
//     1- Enfileirar um número inteiro positivo.  
//     2- Desenfileirar tudo e imprimir apenas os valores que são múltiplos de 2.  
//     3- Terminar o programa. Implemente, adequadamente, cada opção 
//     fornecida. 

#include <iostream>
using namespace std;

#define MAX 10

// funcoes
void menuExibir ();
void enfileirar(int fila[], int &finalFila, int valor);
void escolherOpcao(int valor, int &numero, int fila[], int &inicioFila, int &finalFila);
int desenfileirar(int fila[], int &inicioFila, int finalFila, int &num, int &valor)
void enfileirandoNumero(int &numero, int fila[], int &finalFila, int &nValue);
void desenfileirando(int fila[], int &inicioFila, int &finalFila);

int main(void) {

    // Declarando uma fila
    int fila[MAX];
    int inicioFila = 0, finalFila = -1, nFila = 0;
    int i, valor, numero;

    do {
        menuExibir();

        cout << "Digite uma opcao: ";
        cin >> valor;

        escolherOpcao(valor, numero, fila, inicioFila, finalFila, nFila);
    } while( valor != 0);
}

void menuExibir() {
    cout << endl << "Bem vindo ao menu" << endl;
    cout << "1 - enfileirar um numero inteiro positivo" << endl;
    cout << "2 - desenfileirar e imprimir o dobro" << endl;
    cout << "3 - desenfileirar tudo exibindo valores sem alteracoes" << endl;
    cout << "0 - terminar programa" << endl << endl;
}

void escolherOpcao(int valor, int &numero, int fila[], int &inicioFila, int &finalFila, int &nValue) {
    switch(valor) {
        case 0: 
            cout <<endl << "Programa encerrado, obrigado por utilizar" << endl;
            break;
        case 1: 
            enfileirandoNumero(numero, fila, finalFila, nValue);
            break;
        // case 2: 
        //     desenfileirando(fila, inicioFila, finalFila);
        //     break;
        // case 3: 
        //     desenfileirando(fila, inicioFila, finalFila);
        //     break;
        default: 
            cout << endl << "Tente novamente" << endl;
    }
}

void enfileirar(int fila[], int &finalFila, int &nValue, int valor) {
    if(nValue != MAX) { 
        finalFila++;
        if (finalFila >= MAX) finalFila = finalFila - MAX;
        fila[finalFila] = valor;
        nValue++;
    } else {
        cout << "A lista esta cheia" << endl;
    }
}

int desenfileirar(int fila[], int &inicioFila, int finalFila, int &num, int &valor) {
    if(num != 0) {
        valor = fila[inicioFila];
        inicioFila++;
        if(inicioFila >= MAX) inicioFila - inicioFila - MAX;
        num--;

        return 0;
    }
    return 1;
}

void enfileirandoNumero(int &numero, int fila[], int &finalFila, int &nValue) {
    cout <<endl << "Digite um numero para ter seu valor enfileirado: ";
    cin >> numero;

    int digit;
    while (numero != 0) {
        digit = numero % 10; 
        numero /= 10;       
        cout << digit << endl;
        enfileirar(fila, finalFila, nValue, digit);  // enfileirando
    }

    cout <<endl << "Numero enfileirado!" << endl << endl;
}

void desenfileirando(int fila[], int &inicioFila, int &finalFila) {
    int finalFF = finalFila+2, i, getValue;

    for(i = 0; i < finalFF; i++) {
        if(desenfileirar(fila, inicioFila, finalFila, getValue) == 0) {
            if(getValue % 2 == 0)
                cout << "Numero par que foi enfileirado: " << getValue << endl;
        }
    }
}