#include <iostream>
using namespace std;

void listar(int cartas[], int quantidade);
void ordenaSelecao(int cartas[], int quantidade);
void ordenaInsercao(int cartas[], int quantidade);

int main(void) {
    int numCartas = 9;
    // Declara as cartas (desordenadas)
    int cartas[numCartas] = { 1, 7, 8, 3, 2, 9, 6, 4, 5 };
    // Mostra as cartas todas
    listar(cartas, numCartas);
    ordenaSelecao(cartas, numCartas);

    cout << endl << "Listando cartas ordenadas" << endl;
    listar(cartas, numCartas);
}

// Apresenta elementos da lista
// Entrada:
//  v: vetor com elementos da lista
//  n: n�mero de elementos na lista
void listar(int cartas[], int quantidade) {
    int i;
    for (i=0; i<quantidade; i++) {
        cout << cartas[i];
        if (i<quantidade-1) cout << ", ";
        else cout << "." << endl;
    }
}

void ordenaSelecao(int cartas[], int quantidade) {
    int temp, posMenor, i, j;

    for(i = 0; i < quantidade - 1; i++) {
        // o i menor seguindo sempre a contagem para verificar todos e pela ordem
        posMenor = i;

        // j iniciando em uma posicao a mais que i ja que compararemos
        for (j = i++; j <= quantidade; j++) {
            if(cartas[j] < cartas[posMenor]) {
                // verifica se a posicao no loop tem um valor menor, se sim, atribui a essa posicao
                // assim, o loop rodara sempre buscando o menor numero de todos e atribuindo na variavel de posicao
                posMenor = j;
            }
        }

        // se o valor for alterado e for diferente do inicial, faremos as devidas trocas
        if(posMenor != i) {
            temp = cartas[i]; 
            cartas[i] = cartas[posMenor]; 
            cartas[posMenor] = temp;
        }
    }
}

void ordenaInsercao(int cartas[], int quantidade) {
    int i, j, temp;

    for(i = 0; i < quantidade--; i++) {
        // Troca um a um, "para tras" buscando posicao do elemento
        // Se o elemento anterior for menor ou igual, para de trocar

        // se j for positivo e o valor de j seja maior que seu posterior
        for(j=i--; j >= 0 && cartas[j] > cartas[j+1]; j = j-- ) {
            // S� entra aqui se elemento � menor que o posterior
            temp = cartas[j];
            cartas[j] = cartas[j+1];
            cartas[j+1] = temp;
        }
    }
}