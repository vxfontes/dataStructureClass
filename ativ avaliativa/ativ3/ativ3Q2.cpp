// 2. Faça um programa em C++ para ler uma sequência de caracteres 
// (vetor de char) e enfileirá-los. Em seguida, desenfileire todos os 
// caracteres e empilhe-os em uma pilha P seguindo as orientações: a) 
// Converta as letras para minúsculas antes de empilhá-las; b) Qualquer 
// outro caractere, empilhe sem alteração. Ao final, desempilhe tudo, 
// exibindo o resultado na saída padrão

#include <iostream>
#include <string>
using namespace std;

#define MAX 100

void enfileirar(string fila[], int &finalFila, string valor);
int desenfileirar(string fila[], int &inicioFila, int finalFila, string &valor);
void empilhar(string pilha[], int &topo, char valor);
void empilharProcessamento(string pilha[], int &topo, string texto);
int desempilhar(string pilha[], int &topo, string &valor);

int main(void) {

    // Declarando uma fila
    string fila[MAX], pilha[MAX], caracteres;
    int inicioFila = 0, topo = -1, finalFila = -1;
    int i, valor, numero;
    string value;

    cout << "Digite uma sequencia de caracteres: ";
    getline(cin, caracteres);

    enfileirar(fila, finalFila, caracteres);
    while(desenfileirar(fila, inicioFila, finalFila, caracteres) == 0) {
        empilharProcessamento(pilha, topo, caracteres); // movido para dentro do while
        cout << "desenfileirando: " << caracteres << endl;
        caracteres = ""; // resetar a variável caracteres a cada iteração
    }

    do {
        valor = desempilhar(pilha, topo, value);
        if (valor == 0) cout << value;
    } while (valor == 0);

    return 0;
}



void enfileirar(string fila[], int &finalFila, string valor) {
    for (int i = 0; i < valor.length(); i++) {
        if(finalFila < MAX - 1) { 
            finalFila++;  
            fila[finalFila] = valor[i];
        } else {
            cout << "A lista esta cheia" << endl;
        }
    }
}

int desenfileirar(string fila[], int &inicioFila, int finalFila, string &valor) {
    if(inicioFila <= finalFila) {
        valor = fila[inicioFila];
        inicioFila++;
        return 0;
    }
    return 1;
}

void empilhar(string pilha[], int &topo, char valor) {
    if (topo<MAX-1) {
        topo = topo + 1;
        pilha[topo] = valor;
    }
}

int desempilhar(string pilha[], int &topo, string &valor) {
    if (topo<0) {
        return 1;
    }
    valor = pilha[topo];
    topo = topo - 1;
    return 0;
}

void empilharProcessamento(string pilha[], int &topo, string texto) {
    for (int i = 0; i < texto.length(); i++) {
        if (texto[i] >= 'A' && texto[i] <= 'Z') {
            texto[i] = texto[i] + 32;
        }

        char getValue = texto[i];

        empilhar(pilha, topo, getValue);
    }
}