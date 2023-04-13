#include <iostream>
using namespace std;

void merge(int arr[], int inicio, int meio, int final) {
    int i, j, k;
    int tamEsquerda = meio - inicio + 1;
    int tamDireita = final - meio;

    int left[tamEsquerda], right[tamDireita];

    for (i = 0; i < tamEsquerda; i++)
        left[i] = arr[inicio + i];
    for (j = 0; j < tamDireita; j++)
        right[j] = arr[meio + 1 + j];

    i = 0;
    j = 0;
    k = inicio;

    // juncao das ordenações
    while (i < tamEsquerda && j < tamDireita) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < tamEsquerda) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < tamDireita) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int inicio, int final) {
    if (inicio < final) {
        int meio = inicio + (final - inicio) / 2; // dividindo no meio

        // divisao ate que o vetor tenha apenas uma posição
        mergeSort(arr, inicio, meio); // pegando a parte da esqueda
        mergeSort(arr, meio + 1, final); // pegando a parte da direita

        merge(arr, inicio, meio, final);
    }
}

int main() {
    int arr_size = 6;
    int arr[arr_size] = { 12, 11, 13, 5, 6, 7 };

    cout << "Array original: ";
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, 0, arr_size - 1);

    cout << "Array ordenado: ";
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
