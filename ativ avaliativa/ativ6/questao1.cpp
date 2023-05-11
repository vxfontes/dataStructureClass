#include <iostream>
using namespace std;

struct No {
    int valor;
    No *prox;
};

struct Fila {
    No *ini, *fim;
};

void inicializar(Fila &f) {
    f.ini = NULL;
    f.fim = NULL;
}

int inserir(Fila &f, int valor) {
    No *tmp;
    tmp = new No;
    tmp->valor = valor; 
    tmp->prox = NULL; 
    if (f.ini == NULL) {
        f.ini = f.fim = tmp;
    }
    else {
        f.fim->prox = tmp;
        f.fim = tmp;
    }
    return 0;
}

int remover(Fila &f, int &valor) {
    No *tmp;
    if (f.ini == NULL) return 1;
    valor = f.ini->valor;
    tmp = f.ini;
    f.ini = f.ini->prox;
    delete tmp;
    if (f.ini == NULL) f.fim = NULL;
    return 0;
}

int contar(Fila &f) {
    int cont = 0;
    No *aux;
    aux = f.ini;
    while (aux != NULL) {
        cont++;
        aux = aux->prox;
    }
    return cont;
}

void imprimir(Fila &f) {
    No *aux;
    aux = f.ini;
    while (aux != NULL) {
        cout << aux->valor << " ";
        aux = aux->prox;
    }
    cout << endl;
}

int main() {
    Fila fila;
    int valor;

    inicializar(fila);

    cout << "Digite um valor inteiro positivo para inserir na fila: ";
    cin >> valor;

    while (valor > 0) {
        inserir(fila, valor);
        cout << "Digite outro valor inteiro positivo para inserir na fila: ";
        cin >> valor;
    }

    cout << "Fila criada: ";
    if (fila.ini == NULL) {
        cout << "fila vazia" << endl;
    }
    else {
        imprimir(fila);
    }

    if (remover(fila, valor) == 0) {
        cout << "Elemento desenfileirado: " << valor << endl;
    }
    else {
        cout << "Fila vazia, nao foi possivel remover nenhum elemento" << endl;
    }

    cout << "Numero de elementos na fila: " << contar(fila) << endl;

    cout << "Elementos pares desenfileirados: ";
    while (fila.ini != NULL) {
        remover(fila, valor);
        if (valor % 2 == 0) {
            cout << valor << " ";
        }
    }
    cout << endl;

    return 0;
}

