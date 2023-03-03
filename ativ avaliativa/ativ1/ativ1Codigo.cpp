#include <iostream>

using namespace std;

//prototipos
int buscar(float vet[], int quant, int some);
void inserirSemRepetir(float data[], float some, int &quant, int max);
void visualizar(float data[], int quant);
void intercalar(int quantidade1, int quantidade2, float data1[], float data2[], float dataResultante[]);
void interseccao(int quantidade1, int quantidade2, float data1[], float data2[], float dataResultante[], int &quantidadeResultado);
void uniao(int quantidade1, int quantidade2, float data1[], float data2[], float dataResultante[]);
void removerPeloIndex(float data[], int &quant, int indice);

int main() {
    int numMax = 7, quantidade1, quantidade2, value, quantidadeResultado;
    float dados1[numMax], dados2[numMax], dadosResultante[numMax*2], dadosResultanteIntersecao[numMax*2], dadosResultanteUniao[numMax*2];

    cout << "Iniciando processamento da lista 1" << endl;
    
    do {
        cout << "Digite valor ou 0 para finalizar: ";
        cin >> value;
        if (value != 0) inserirSemRepetir(dados1, value, quantidade1, numMax);
    } while(value != 0);

    visualizar(dados1, quantidade1);

    cout << "\nIniciando processamento da lista 2" << endl;

    do {
        cout << "Digite valor ou 0 para finalizar: ";
        cin >> value;
        if (value != 0) inserirSemRepetir(dados2, value, quantidade2, numMax);
    } while(value != 0);

    visualizar(dados2, quantidade2);
    
    cout << endl << "Agora iremos intercalar as informacoes" << endl;
    intercalar(quantidade1, quantidade2, dados1, dados2, dadosResultante);
    
    visualizar(dadosResultante, quantidade1+quantidade2);

    cout << endl << "Agora iremos interseptar as informacoes" << endl;
    interseccao(quantidade1, quantidade2, dados1, dados2, dadosResultanteIntersecao, quantidadeResultado);
    
    visualizar(dadosResultanteIntersecao, quantidadeResultado);

    cout << endl << "Agora iremos unir as informacoes" << endl;
    uniao(quantidade1, quantidade2, dados1, dados2, dadosResultanteUniao);

    visualizar(dadosResultanteUniao, quantidade1+quantidade2);

    cout << endl << "Agora iremos remover as informacoes da lista 1" << endl;

    cout << "Informe o indice do valor que deseja remover, se nao deseja remover, informe um valor negativo" << endl;
    cin >> value;

    if(value < 0) {
        removerPeloIndex(dados1, quantidade1, value);
        cout << "Removido com sucesso" << endl;
    } else {
        cout << "Indice negativo identificado!" << endl;
    }

    cout << endl << "Agora iremos remover as informacoes da lista 2" << endl;

    cout << "Informe o indice do valor que deseja remover, se nao deseja remover, informe um valor negativo" << endl;
    cin >> value;

    if(value < 0) {
        removerPeloIndex(dados2, quantidade2, value);
        cout << "Removido com sucesso" << endl;
    } else {
        cout << "Indice negativo identificado!" << endl;
    }

    return 0;
}

void inserirSemRepetir(float data[], float some, int &quant, int max) {
    int existe = buscar(data, quant, some);
    
    if(existe == -1) {
        if(quant == max) cout << "A lista ja esta cheia" << endl;
        else {
            data[quant] = some;
            quant++;
        }
    } else {
        cout << "Numero ja existe" << endl;
    }
}

void visualizar(float data[], int quant) {
    int i;
    cout << "Segue a lista: " << endl;
    
    for(i = 0; i < quant; i++) {
        cout << data[i] << "  ";
    }
}

int buscar(float vet[], int quant, int some) {
	int i;
	for(i = 0; i<quant; i++) {
        if(some == vet[i]) return i;
	}
	return -1;
}

void intercalar(int quantidade1, int quantidade2, float data1[], float data2[], float dataResultante[]) {
    int i;
    int quantidade = quantidade1 + quantidade2, posicao1 = 0, posicao2 = 0;
    
    cout << "\nGerando lista resultante" << endl;
    for(i = 0; i < quantidade; i++) {
        if(i % 2 == 0) {
            if(posicao1 < quantidade1) {
                dataResultante[i] = data1[posicao1];
                posicao1++;
            }
        } else {
            if(posicao2 < quantidade2) {
                dataResultante[i] = data2[posicao2];
                posicao2++;
            }
        }
    }
}

void interseccao(int quantidade1, int quantidade2, float data1[], float data2[], float dataResultante[], int &quantidadeResultado) {
    quantidadeResultado = 0;
    for(int i = 0; i < quantidade1; i++) {
        for(int j = 0; j < quantidade2; j++) {
            if(data1[i] == data2[j]) {
                dataResultante[quantidadeResultado] = data1[i];
                quantidadeResultado++;
                break;
            }
        }
    }
}

void uniao(int quantidade1, int quantidade2, float data1[], float data2[], float dataResultante[]) {
    int i, j, k;
    int quantidade = quantidade1 + quantidade2;
    bool repetido;
    
    for(i = 0; i < quantidade1; i++) {
        dataResultante[i] = data1[i];
    }
    
    for(j = 0; j < quantidade2; j++) {
        dataResultante[i] = data2[j];
        i++;
    }
}

void removerPeloIndex(float data[], int &quant, int indice) {
    int i;

    for(i = indice; i < quant, i++) {
        data[i] = data[i++];
    }

    quant--;
}