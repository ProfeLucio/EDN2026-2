#include <stdio.h>
#include <malloc.h>

typedef struct nodo { 
    int dato; 
    struct nodo *sig; 
} nodo; 
nodo *cab, *aux = NULL;

void registrarNodo(){
    if(cab==NULL){
        cab = (nodo*) malloc(sizeof(nodo));    
        cab->dato = 10;   
        cab->sig = NULL; 
        printf("Cabeza registrada\n %d", cab->dato);
    } else {
        aux = cab; 
        while (aux->sig != NULL){
            aux = aux->sig;
        }
        nodo *nuevo = (nodo*) malloc(sizeof(nodo));
        nuevo->dato = aux->dato+10;
        aux->sig = nuevo;
        nuevo->sig = NULL; 
        printf("Nodo registrado\n");
    }
}
void mostrarNodo(){
    aux = cab;
    while (aux != NULL){
        printf("Nodo : %d\n", aux->dato);
        aux = aux->sig;
    }
}
void liberarMemoria(){    
    while (cab != NULL){
        aux = cab->sig;
        free(cab);
        cab = aux;
    }
}
void main(){
    
   int opcion;
   do{
     printf("1. Insertar\n2. Mostrar\n3. Salir\n Elige la opción: ");
     scanf("%d", &opcion);
     switch (opcion)
     {
        case 1: 
            for(int i=0; i<900; i++)
                registrarNodo(); 
        break;
        case 2: mostrarNodo(); break;
     }
   } while(opcion!=3);
   liberarMemoria();

}