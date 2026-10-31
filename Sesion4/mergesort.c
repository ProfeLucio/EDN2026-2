// Función para fusionar dos mitades ordenadas del 
#include <stdio.h>

int mostrar(int arr[]){
    int n = 10;
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Función recursiva de Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;        
        mergeSort(arr, left, mid);        
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
        mostrar(arr);
    }
}

int main() {
    int data[] = {6, 2, 4, 1, 5, 8, 12, 3, 9, 7};
    int n = sizeof(data) / sizeof(data[0]);
    mergeSort(data, 0, n - 1);
    // Imprimir arreglo ordenado
    for (int i = 0; i < n; i++) {
    printf("%d ", data[i]);
    }
    return 0;
}