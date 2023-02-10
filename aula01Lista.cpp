#include <iostream>
using namespace std;

// Protótipos
void inserir (float v[], float n, int &pos, int max);
void imprimir (float vet[], int quant);
int buscar (float vet[], int quant, int value);
void remover(float vet[], int &quant, int value);
void adicionarSemRepetir(float vet[], int quant, int value, int num);

// Programa Principal
int main(void) {
    // Declaração da lista de notas
    int numNotas = 4;
    float notas[numNotas];
    int quantidade, valor, returned = 0;
    // Valor a ser lido
    float n;

    // Inicializa a Lista: contém, inicialmente, zero elementos
    quantidade = 0;

    // Leitura de N dado
    do {
        cout << "Digite valor ou 0 para finalizar: ";
        cin >> n;
        if (n != 0) inserir (notas, n, quantidade, numNotas);
    } while(n != 0);
    
    cout << "Lista completa \n";
    
    imprimir(notas, quantidade);
    
    // cout << "\n\nInforme o valor que deseja buscar: ";
    // cin >> valor;
    
    // returned = buscar (notas, quantidade, valor);
    
    // if (returned == -1) cout << "\nNao existe nenhum valor que seja igual a esse";
    // else cout << "A posicao do valor pesquisado eh: " << returned++;
    
    // cout << "\n\nInforme o valor que deseja remover: ";
    // cin >> valor;
    
    // remover(notas, quantidade, valor);
    // cout << "\nImprimindo: ";
    // imprimir(notas, quantidade);
    
    cout << "Informe o valor que deseja inserir na lista:";
    cin >> n;
    
    inserir (notas, n, quantidade, numNotas);
    
    imprimir(notas, quantidade);
}


// Função que Insere N na posição POS da lista V
void inserir (float v[], float n, int &pos, int max) {
    if (pos >= max) cout << "ERRO: Lista cheia!" << endl;
    else {
        v[pos] = n;
        pos++;
    }
}

void imprimir (float vet[], int quant) {
	int i;
	for(i = 0; i<quant; i++) {
    	cout << vet[i] << endl;
	}
}

int buscar (float vet[], int quant, int value) {
	int i;
	for(i = 0; i<quant; i++) {
	    if(value == vet[i]) return i;
	}
	return -1;
}

void remover(float vet[], int &quant, int value) {
    int i, existe;
    existe = buscar(vet, quant, value);
    cout << existe;
    
    if (existe != -1) {
        vet[i] = vet[quant--];
        quant--;
    } else {
        cout << "O Valor nao existe ou o array esta vazio";
    }
}

void adicionarSemRepetir(float vet[], int quant, int value, int num) {
    int existe = buscar(vet, quant, value);
    
    if(existe != -1) {
        inserir(vet, value, quant, num);
    } else {
        cout << "Numero ja existe";
    }
}


