// 1. Faça um programa em C++ para ler um número inteiro maior que zero, 
// converter este número de decimal para binário, usando pilha e apresentar 
// na tela, o resultado da conversão. DICA: Veja as aulas!

// conversao de binario com pilha

#include <iostream>
using namespace std;

#define MAX 50

void empilhar(int pilha[], int &topo, int valor);
int desempilhar(int pilha[], int &topo, int &valor);

int main(void) {
    int pilha[MAX];
    int topo = -1, dado, vazia, resto, divisao;

    cout << "Digite um numero inteiro: ";
    cin >> dado;

    do {
        divisao = dado / 2;
        resto = dado % 2;
        empilhar(pilha, topo, resto);
        dado = divisao;
    } while (dado > 0);

    do {
        vazia = desempilhar(pilha, topo, dado);
        if (vazia == 0) cout << dado;
    } while (vazia == 0);

    cout << "b" << endl;
}


void empilhar(int pilha[], int &topo, int valor) {
    if (topo<MAX-1) {
        topo = topo + 1;
        pilha[topo] = valor;
    }
}

int desempilhar(int pilha[], int &topo, int &valor) {
    if (topo<0) {
        return 1;
    }
    valor = pilha[topo];
    topo = topo - 1;
    return 0;
}

