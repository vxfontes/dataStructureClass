#include <iostream>
using namespace std;

void listar(float v[], int n);
void inserirOrdenado(float lista[], int &quantidade, int max, float valor);
int buscaBinaria(float lista[], int quantidade, float valor);
void buscar(float lista[], int quantidade, float valor);
void bubbleSort(float lista[], int quantidade);

int main(void) {
    int numMax = 50, quantidade = 0, value;
    float lista[numMax];

    cout << "Criando a lista ordenada";

    do {
        cout << "Digite valor ou 0 para finalizar: ";
        cin >> value;
        if (value != 0) inserirOrdenado(lista, quantidade, numMax, value);
    } while(value != 0);

    listar(lista, quantidade);

    cout << "O valor que deseja procurar: ";
    cin >> value;

    buscar(lista, quantidade, value);
}

void listar(float v[], int quantidade) {
    int i;
    for (i = 0; i < quantidade; i++) cout << v[i] << " ";
}

void inserirOrdenado(float lista[], int &quantidade, int max, float valor) {
    int i, j;

    if (max == quantidade) {
        cout << "A lista está cheia" << endl;
        return;
    } 
    
    for (i = 0; i < quantidade && lista[i] < valor; i++); // quando algum numero da lista for igual ao valor de insercao, o loop para e o indice sera definido
    
    // deslocando os valores à direita para abrir espaço para o novo valor
    // começa de tras pra frente, iniciando na ultima posicao
    for (j = quantidade; j > i; j--) {
        lista[j] = lista[j - 1];
    }

    // valor no local correto
    lista[i] = valor;
    quantidade++;
}

int buscaBinaria(float lista[], int quantidade, float valor) {
    int inicio = 0, end = quantidade - 1, meio;
    
    while(inicio <= end) {
        meio = (inicio + end)/2;

        if(lista[meio] = valor) return meio;
        if(lista[meio] < valor) inicio = meio + 1;
        if(lista[meio] > valor) inicio = meio - 1;
    }

    return -1;
}

void buscar(float lista[], int quantidade, float valor) {
    int indice = buscaBinaria(lista, quantidade, valor);

    cout << endl;

    if(indice == -1) {
        cout << "Valor nao encontrado na lista" << endl;
    } else {
        cout << "O valor esta na posicao: " << indice << endl;
    }
}

void bubbleSort(float lista[], int quantidade) {
    bool trocouOLugar;
    int var, i;

    do {
        trocouOLugar = false;

        for(i = 0; i < quantidade < i++) {
            
        }
    } while (trocouOLugar);
}