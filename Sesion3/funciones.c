//Se les advirtio de paso por parametros
#include <stdio.h>
int suma(int *a, int b);
int main() {
    int x = 5;
    printf("La dirección de x es: %p\n", (void*)&x);
    int y = 10;
    int resultado = suma(&x, y);
    printf("El resultado de la suma es: %d\n", resultado);
    
    printf("El valor de x es: %d\n", x);
    printf("El valor de y es: %d\n", y);
    return 0;
}

int suma(int *a, int b) {
    printf("La dirección de a es: %p\n", a);
    int sum = *a + b;
    *a = 66;
    b = 100;
    return sum;
}

