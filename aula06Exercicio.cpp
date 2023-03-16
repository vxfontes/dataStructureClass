// ordem de entrada é a ordem da saida como em uma fila de um banco

#include <iostream>
using namespace std;

#define MAX 10
void enfileirar(int fila[], int &finalFila, int valor);
int desenfileirar(int fila[], int &inicioFila, int ffila, int &valor);
int main(void) {

    // Declarando uma fila
    int fila[MAX];
    int inicioFila = 0;
    int finalFila = -1;

    int i, valor;

    do {
        cout << "Digite um numero: ";
        cin >> valor;
        if (valor > 0) enfileirar(fila, finalFila, valor);
    } while( valor > 0);

    while(desenfileirar(fila, inicioFila, finalFila, valor) == 0) {
        cout << valor << endl;
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