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
void empilhar(string pilha[], int &topo, string valor);
void empilharProcessamento(string pilha[], int &topo, string texto);
int desempilhar(string pilha[], int &topo, string &valor);

int main(void) {

    // Declarando uma fila
    string fila[MAX], pilha[MAX];
    int inicioFila = 0, topo = -1;
    int finalFila = -1;
    string caracteres;

    int i, valor, numero;

    cout << "Digite uma sequencia de caracteres: ";
    getline(cin, caracteres);

    enfileirar(fila, finalFila, caracteres);
    empilharProcessamento(fila, inicioFila, finalFila, caracteres);

    return 0;
}


void enfileirar(string fila[], int &finalFila, string valor) {
    if(finalFila < MAX - 1) { // verificando se a fila esta cheia
        // a posicao que vamos inserir sera a final
        finalFila++;  // como começa do -1, ja iniciaremos incrementando
        fila[finalFila] = valor;
        cout << valor;
    } else {
        cout << "A lista esta cheia" << endl;
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

void empilhar(string pilha[], int &topo, string valor) {
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
    }
}