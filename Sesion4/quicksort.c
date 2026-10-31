#include <stdio.h>
// Función para intercambiar dos elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // elegimos el último elemento como pivote
    int i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);// 
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}
int mostrar(int arr[]){
    int n = 10;
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// Función recursiva de Quicksort
void quickSort(int arr[], int low, int high) {
 if (low < high) {
    int p = partition(arr, low, high);
    mostrar(arr);
    quickSort(arr, low, p - 1);
    mostrar(arr);
    quickSort(arr, p + 1, high);
 }
}

int main() {
    int data[] = {6, 2, 4, 1, 5, 8, 12, 3, 9, 7};
    int n = sizeof(data) / sizeof(data[0]);
    quickSort(data, 0, n - 1);
    // Imprimir arreglo ordenado
    mostrar(data);
    return 0;
}