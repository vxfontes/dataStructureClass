#include <iostream>
using namespace std;

struct No {
    int valor;
    No* prox;
};

struct Fila {
    No* ini;
    No* fim;
};

void inicializar(Fila& f);
No* insereFrente(No* fila, int valor);
void imprimirLista(const Fila& f);
void substituir(No* inicio, int no, int novoValor);
No* removerInicio(No* inicio);
No* busca(No* inicio, int valor);
int contaNos(No* inicio);
No* insereFim(No* inicio, int valor);
No* removeFim(No* inicio);
No* concatena(No* inicio1, No* inicio2);


// main 

int main() {
    Fila fila;
    Fila filaOriginal;
    inicializar(fila);
    inicializar(filaOriginal);

    int n;
    cout << "Digite o número de nós a serem inseridos: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int valor;
        cout << "Digite o valor a ser inserido no início da lista: ";
        cin >> valor;

        fila.ini = insereFrente(fila.ini, valor);
        filaOriginal.ini = insereFrente(filaOriginal.ini, valor);
    }

    imprimirLista(fila);

    int no, novoValor;
    cout << "Digite o numero do no a ser substituido: ";
    cin >> no;
    cout << "Digite o novo valor: ";
    cin >> novoValor;

    substituir(fila.ini, no, novoValor);

    imprimirLista(fila);

    cout << "Removendo inicio" << endl;

    fila.ini = removerInicio(fila.ini);

    imprimirLista(fila);

    int valor;
    cout << "Digite o valor a ser buscado: ";
    cin >> valor;

    No* resultado = busca(fila.ini, valor);

    if (resultado != NULL) {
        cout << "Valor encontrado!" << endl;
    } else {
        cout << "Valor não encontrado!" << endl;
    }

    int quantidade = contaNos(fila.ini);
    cout << "Quantidade de nós: " << quantidade << endl;

    for (int i = 0; i < n; i++) {
        int valor;
        cout << "Digite o valor a ser inserido no fim da lista: ";
        cin >> valor;

        fila.ini = insereFim(fila.ini, valor);
    }

    imprimirLista(fila);

    cout << "Removendo o último nó" << endl;
    fila.ini = removeFim(fila.ini);

    imprimirLista(fila);

    cout << "Lista resultante da concatenação: ";
    
    No* listaConcatenada = concatena(filaOriginal.ini, fila.ini);
    imprimirLista(listaConcatenada);


    No* posicao = fila.ini;
    while (posicao != NULL) {
        No* proximo = posicao->prox;
        delete posicao;
        posicao = proximo;
    }

    return 0;
}

/**
 * inicializa a fila
 * 
 * @param f recebe o ponteiro da fila que usaremos
*/
void inicializar(Fila& f) {
    f.ini = NULL;
    f.fim = NULL;
}


/**
 * insere um novo nó no início da lista
 *
 * @param fila O ponteiro para o nó inicial da lista
 * @param valor O valor a ser inserido no novo nó
 * @return O ponteiro para o novo início da lista
 */
No* insereFrente(No* fila, int valor) {
    No* novoNo = new No;  // Cria um novo nó
    novoNo->valor = valor;
    novoNo->prox = fila;  // O próximo nó é o antigo início da lista
    return novoNo;  // Retorna o ponteiro para o novo início da lista
}


/**
 * imprime os valores armazenados na lista
 *
 * @param f A fila contendo o ponteiro para o início da lista
 */
void imprimirLista(const Fila& f) {
    No* posicao = f.ini;
    cout << "Lista: ";
    while (posicao != NULL) {
        cout << posicao->valor << " ";
        posicao = posicao->prox;
    }
    cout << endl;
}


/**
 * substitui o valor de um nó específico na lista
 *
 * @param inicio O ponteiro para o início da lista
 * @param no O número do nó a ser substituído
 * @param novoValor O novo valor a ser atribuído ao nó
 */
void substituir(No* inicio, int no, int novoValor) {
    No* posicao = inicio;
    int contador = 1;

    while (posicao != NULL && contador < no) {
        posicao = posicao->prox;
        contador++;
    }

    if (posicao != NULL && contador == no) { // posicao encontrada
        posicao->valor = novoValor;
    }
}


/**
 * remove o nó inicial da lista
 *
 * @param inicio o ponteiro para o início da lista
 * @return o ponteiro para o novo início da lista após a remoção
 *         retorna NULL se a lista estiver vazia
 */
No* removerInicio(No* inicio) {
    if (inicio == NULL) {
        cout << "Lista vazia! Não é possível remover." << endl;
        return NULL;
    }

    No* novoInicio = inicio->prox;
    delete inicio;
    return novoInicio;
}


/**
 * realiza uma busca sequencial na lista pelo valor especificado
 *
 * @param inicio O ponteiro para o início da lista
 * @param valor O valor a ser procurado na lista
 * @return O ponteiro para o nó com o valor encontrado
 *         Retorna NULL se o valor não for encontrado na lista
 */
No* busca(No* inicio, int valor) {
    No* posicao = inicio;

    while (posicao != NULL) { // procurando valor
        if (posicao->valor == valor) {
            return posicao;
        }
        posicao = posicao->prox;
    }

    return NULL;  
}


/**
 * conta o número de nós em uma lista
 *
 * @param inicio O ponteiro para o início da lista
 * @return A quantidade de nós presentes na lista
 */
int contaNos(No* inicio) {
    int contador = 0;
    No* posicao = inicio;

    // Percorre a lista contando os nós
    while (posicao != NULL) {
        contador++;
        posicao = posicao->prox;
    }

    return contador;
}


/**
 * Insere um novo nó no final de uma lista
 *
 * @param inicio O ponteiro para o início da lista
 * @param valor O valor a ser inserido no novo nó
 * @return O ponteiro para a lista atualizada após a inserção do novo nó
 */
No* insereFim(No* inicio, int valor) {
    No* novoNo = new No;
    novoNo->valor = valor;
    novoNo->prox = NULL;

    if (inicio == NULL) {
        // Se a lista estiver vazia, o novo nó será o primeiro nó da lista
        return novoNo;
    } else {
        // Percorre a lista até encontrar o último nó
        No* posicao = inicio;
        while (posicao->prox != NULL) {
            posicao = posicao->prox;
        }

        // O último nó apontará para o novo nó
        posicao->prox = novoNo;
        return inicio;
    }
}

/**
 * Remove o último nó de uma lista
 *
 * @param inicio O ponteiro para o início da lista
 * @return O ponteiro para a lista atualizada após a remoção do último nó
 *         Retorna NULL se a lista estiver vazia após a remoção
 */
No* removeFim(No* inicio) {
    if (inicio == NULL) {
        cout << "Lista vazia! Não é possível remover." << endl;
        return NULL;
    } 
    // Verifica se há apenas um nó na lista
    else if (inicio->prox == NULL) {
        delete inicio;
        return NULL;
    } else {
        // Encontra o penúltimo nó
        No* posicao = inicio;
        while (posicao->prox->prox != NULL) {
            posicao = posicao->prox;
        }

        // Deleta o último nó e atualiza o ponteiro próximo do penúltimo nó
        delete posicao->prox;
        posicao->prox = NULL;
        return inicio;
    }
}


/**
 * Concatena duas listas encadeadas, colocando a lista com m nós no final da lista com n nós.
 *
 * @param inicio1 O ponteiro para o início da primeira lista
 * @param inicio2 O ponteiro para o início da segunda lista
 * @return O ponteiro para o início da lista resultante da concatenação
 */
No* concatena(No* inicio1, No* inicio2) {
    if (inicio1 == NULL) {
        return inicio2;
    }

    if (inicio2 == NULL) {
        return inicio1;
    }

    // Percorre a primeira lista até encontrar o último nó
    No* posicao = inicio1;
    while (posicao->prox != NULL) {
        posicao = posicao->prox;
    }

    // O último nó da primeira lista aponta para o início da segunda lista
    posicao->prox = inicio2;

    // Retorna o ponteiro para o início da lista resultante
    return inicio1;
}
