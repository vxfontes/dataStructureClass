// Inserir: sempre no fim da lista (topo da pilha) 
// Remover: sempre do fim da lista (topo da pilha) 

#include <iostream>
using namespace std;

#define MAX 50

void empilhar(int pilha[], int &topo, int valor);
int desempilhar(int pilha[], int &topo, int &valor);

int main(void) {
    // Declara a pilha
    int pilha[MAX];
    int topo = -1, i;

    // Vari�vel para armazenar dado digitado
    int dado;
    // Vari�vel que indica se acabaram valores da pilha
    int vazia;

    // L� valores e os empilha, se forem >= 0
    do {
        cout << "Digite um numero inteiro: ";
        cin >> dado;
        if (dado >=0) empilhar(pilha, topo, dado);
    } while(dado >= 0);

    do {
        vazia = desempilhar(pilha, topo, dado);
        if (vazia == 0) cout << dado << endl;
    } while (vazia == 0);

}

void empilhar(int pilha[], int &topo, int valor) {
    if(topo < MAX-1) {
        topo++;
        pilha[topo] = valor;
    } else {
        cout << "Pilha cheia, digite -1 para encerrar" << endl;
    }
}

int desempilhar(int pilha[], int &topo, int &valor) {
    // Se a pilha est� vazia... retorna 1
    if (topo<0) {
        cout << "Fim da pilha" << endl;
        return 1;
    } 
    
    valor = pilha[topo];
    topo = topo - 1;
    return 0;
}