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
int desenfileirar(int fila[], int &inicioFila, int finalFila, int &valor);
void enfileirandoNumero(int &numero, int fila[], int &finalFila);
void desenfileirando(int fila[], int &inicioFila, int &finalFila);

int main(void) {

    // Declarando uma fila
    int fila[MAX];
    int inicioFila = 0;
    int finalFila = -1;

    int i, valor, numero;

    do {
        menuExibir();

        cout << "Digite uma opcao: ";
        cin >> valor;

        escolherOpcao(valor, numero, fila, inicioFila, finalFila);
    } while( valor != 0);
}

void menuExibir() {
    cout << endl << "Bem vindo ao menu" << endl;
    cout << "1 - enfileirar um numero inteiro positivo" << endl;
    cout << "2 - desenfileirar e exibir numeros pares" << endl;
    cout << "0 - terminar programa" << endl << endl;
}

void escolherOpcao(int valor, int &numero, int fila[], int &inicioFila, int &finalFila) {
    switch(valor) {
        case 0: 
            cout <<endl << "Programa encerrado, obrigado por utilizar" << endl;
            break;
        case 1: 
            enfileirandoNumero(numero, fila, finalFila);
            break;
        case 2: 
            desenfileirando(fila, inicioFila, finalFila);
            break;
        default: 
        cout << endl << "Tente novamente" << endl;
    }
}

void enfileirar(int fila[], int &finalFila, int valor) {
    if(finalFila < MAX - 1) { // verificando se a fila esta cheia
        // a posicao que vamos inserir sera a final
        finalFila++;  // como começa do -1, ja iniciaremos incrementando
        fila[finalFila] = valor;
    } else {
        cout << "A lista esta cheia" << endl;
    }
}

int desenfileirar(int fila[], int &inicioFila, int finalFila, int &valor) {
    if(inicioFila <= finalFila) {
        valor = fila[inicioFila];
        inicioFila++;
        return 0;
    }
    return 1;
}

void enfileirandoNumero(int &numero, int fila[], int &finalFila) {
    cout <<endl << "Digite um numero para ter seu valor enfileirado: ";
    cin >> numero;

    int digit;
    while (numero != 0) {
        digit = numero % 10;   // obter o último dígito
        numero /= 10;          // remover o último dígito
        enfileirar(fila, finalFila, digit);  // enfileirando
    }

    cout <<endl << "Numero enfileirado!" << endl << endl;
}

//     2- Desenfileirar tudo e imprimir apenas os valores que são múltiplos de 2.  
void desenfileirando(int fila[], int &inicioFila, int &finalFila) {
    int finalFF = finalFila+2, i, getValue;

    for(i = 0; i < finalFF; i++) {
        if(desenfileirar(fila, inicioFila, finalFila, getValue) == 0) {
            if(getValue % 2 == 0)
                cout << "Numero par que foi enfileirado: " << getValue << endl;
        }
    }
}