// 2. Construa um programa em C++, que use a estrutura pilha e verifique se 
// o número de abre parênteses é igual ao número de fecha parênteses. 
// DICA: Coloque os “abre parênteses” na pilha e remova cada um deles 
// quando cada “fecha parênteses” for encontrado.

#include <iostream>
using namespace std;

#define MAX 100

void empilhar(int pilha[], int &topo, int valor);
int desempilhar(int pilha[], int &topo, int &valor);

int main() {
    int pilha[MAX];
    int topo = -1;
    string expressao;
    bool balanceada = true;

    cout << "Digite uma expressao matematica: ";
    getline(cin, expressao);

    for (int i = 0; i < expressao.length(); i++) {
        if (expressao[i] == '(') {
            empilhar(pilha, topo, 1);
        } else if (expressao[i] == ')') {
            int valor; // descobrindo qual valor esta no topo da pilha
            int getValue = desempilhar(pilha, topo, valor); // descartando valor da pilha (fechando parenteses)
            if (getValue == 10) {
                balanceada = false;
                break;
            }
        }
    }

    if (balanceada && topo == -1) {
        cout << "A expressao esta balanceada." << endl;
    } else {
        cout << "A expressao nao esta balanceada." << endl;
    }

    return 0;
}

void empilhar(int pilha[], int &topo, int valor) {
    if (topo < MAX-1) {
        topo = topo + 1;
        pilha[topo] = valor;
    }
}

int desempilhar(int pilha[], int &topo, int &valor) {
    if (topo < 0) {
        return 1;
    }
    valor = pilha[topo];
    topo = topo - 1;
    return 0;
}