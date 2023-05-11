#include <iostream>
using namespace std;

struct Aluno {
    int matricula;
    float media;
    Aluno *prox;
};

struct Fila {
    Aluno *ini, *fim;
};

void inicializar(Fila &f);
int inserir(Fila &f, int matricula, float media);
int remover(Fila &f, int &matricula, float &media);
void imprimir(Fila &f);
void desenfileirar(Fila &f);

int main() {
    Fila f;
    inicializar(f);
    int n, matricula;
    float media;
    cout << "Digite a quantidade de alunos: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Digite a matricula do aluno " << i+1 << ": ";
        cin >> matricula;
        cout << "Digite a media do aluno " << i+1 << ": ";
        cin >> media;
        inserir(f, matricula, media);
    }
    cout << "Dados de todos os alunos: " << endl;
    imprimir(f);
    cout << "Alunos com media >= 5: " << endl;
    desenfileirar(f);
    return 0;
}


void inicializar(Fila &f) {
    f.ini = NULL;
    f.fim = NULL;
}

int inserir(Fila &f, int matricula, float media) {
    Aluno *tmp;
    tmp = new Aluno;
    tmp->matricula = matricula;
    tmp->media = media;
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

int remover(Fila &f, int &matricula, float &media) {
    Aluno *tmp;
    if (f.ini == NULL) return 1;
    matricula = f.ini->matricula;
    media = f.ini->media;
    tmp = f.ini;
    f.ini = f.ini->prox;
    delete tmp;
    if (f.ini == NULL) f.fim = NULL;
    return 0;
}

void imprimir(Fila &f) {
    Aluno *aux;
    aux = f.ini;
    while (aux != NULL) {
        cout << aux->matricula << " " << aux->media << endl;
        aux = aux->prox;
    }
}

void desenfileirar(Fila &f) {
    int matricula;
    float media;
    while (f.ini != NULL) {
        remover(f, matricula, media);
        if (media >= 5.0) {
            cout << "Matricula: " << matricula << endl;
        }
    }
}
