#include <stdio.h>

int x = 10;
int y = 20;
int vector[5] = {1, 2, 3, 4, 5};

int *p;

int main() {
   
    printf("El valor de x es: %d\n", x);
    printf("La direccion de x es: %p\n", p);
    printf("El valor de y es: %d\n", y); 
    p = &vector[2];
    int z = vector[2];//3
    //Cambiar valor de vector[3] a 10
    *p = 22;
    for (int i = 0; i < 5; i++) {
        printf("El valor del vector[%d] es: %d\n", i, vector[i]);        
    }
    printf("El valor de p que apunta a vector[2] es: %p\n", p);
    printf("El valor de z es: %d\n", z);
    p = &z;
    printf("El valor de p que apunta a Z es: %p\n", p);
    return 0;
}
