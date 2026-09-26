#include <stdio.h>

int i;
int main() {
    //while - do while - for
    for (i = 5; i >= 0; i=i-1) {
        /*if (i % 2 == 0) {
            printf("%d es par\n", i);
        } else {
            printf("%d es impar\n", i);
        }*/
        (i % 2 == 0) ? printf("%d es par\n", i) : printf("%d es impar\n", i);
       
    }
    return 0;
}