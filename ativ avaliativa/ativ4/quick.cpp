#include <iostream>
using namespace std;

void trocando(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int dividindo(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            trocando(arr[i], arr[j]);
        } 
    }
    trocando(arr[i+1], arr[high]);                         
    return i + 1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int trocandoPivot = dividindo(arr, low, high);
        quicksort(arr, low, trocandoPivot - 1);
        quicksort(arr, trocandoPivot + 1, high);
    }
}

int main() {
    int n = 9;
    int arr[n] = {9, 5, 8, 1, 7, 2, 6, 3, 4};
    
    cout << "Array before sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    quicksort(arr, 0, n - 1);
    
    cout << "\nArray after sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
