// 3. Uma palavra é um palíndromo se a sequência de letras que a forma é a 
// mesma, quer seja lida da esquerda para a direita ou da direita para a 
// esquerda (exemplo: raiar, ovo, ana, mussum). Escreva um programa em 
// C++ que reconheça se uma dada palavra é um palíndromo. DICA: conte o 
// número de letras da palavra... insira a primeira metade na pilha e 
// compare com a segunda metade! 

#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 100;

void empilhar(char pilha[], int &topo, char valor);
int desempilhar(char pilha[], int &topo, char &valor);
void returnMessage(bool palindromo);


int main() {
    char palavra[MAX];
    int topo = -1;
    bool palindromo = true;
    
    cout << "Digite uma palavra: ";
    cin >> palavra;
    
    int tamanho = strlen(palavra);
    
    for (int i = 0; i < tamanho/2; i++) {
        empilhar(palavra, topo, palavra[i]);
    }
    
    // se o tamanho da palavra for par, o resto será zero
    int inicio = (tamanho%2 == 0) ? tamanho/2 : (tamanho/2)+1;
    
    for (int i = inicio; i < tamanho; i++) {
        char letra;

        // seguindo o last in first out, conseguimos comparar de tras pra frente as duas metades da palavra
        if (desempilhar(palavra, topo, letra) != 0 || letra != palavra[i]) {
            palindromo = false;
            break;
        }
    }

    returnMessage(palindromo);
    
    return 0;
}

void returnMessage(bool palindromo) {
    if (palindromo) {
        cout << "A palavra eh um palindromo" << endl;
    } else {
        cout << "A palavra nao eh um palindromo" << endl;
    }
}

void empilhar(char pilha[], int &topo, char valor) {
    if (topo < MAX-1) {
        topo = topo + 1;
        pilha[topo] = valor;
    }
}

int desempilhar(char pilha[], int &topo, char &valor) {
    if (topo < 0) {
        return 1;
    }
    valor = pilha[topo];
    topo = topo - 1;
    return 0;
}