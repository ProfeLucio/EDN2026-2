#include <stdio.h>
#include <stdint.h> // Libreria para tipos de datos enteros con tamaño fijo

int edad = -2147483648; // 4Bytes - 1024 - Y2K
float estatura = 1.75; 
char letra = 'J';
//uint8_t numero = 255;
int main(){
    printf("Edad: %d\n", edad);
    printf("Estatura: %f\n", estatura);
    printf("Letra: %c\n", letra);
    

    return 0;
}