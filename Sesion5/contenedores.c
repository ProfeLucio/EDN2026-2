#include <stdio.h>
#include <malloc.h>

typedef struct contenedor
{
    float tara;
    float carga; 
    float masa;
    struct contenedor *sig;
} contenedor;

contenedor *cab, *aux;

void insertar_contenedor();
void mostrar_manifiesto();
void verificar_alertas_peso();
void eliminar_contenedor();
void alerta(contenedor *aux2);
void main(){
    int opcion;
    do {        
        printf("Gestion de Contenedores\n1. Insertar\n2. Mostrar Manifiesto\n3. Alertas\n4. Eliminar\n5. Salir\n\nDigite su opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1: insertar_contenedor(); break;
        case 2: mostrar_manifiesto(); break;
        case 3: verificar_alertas_peso(); break;
        case 4: eliminar_contenedor(); break;
        
        default:
            break;
        }
    } while(opcion!=5);
}

void insertar_contenedor(){
    contenedor *nuevo = (contenedor*) malloc(sizeof(contenedor));
    printf("Digite la tara del nuevo contenedor (Toneladas): ");
    scanf("%f", &nuevo->tara);
    printf("Digite el peso de la carga (Toneladas): ");
    scanf("%f", &nuevo->carga);
    nuevo->masa = nuevo->tara + nuevo->carga;
    alerta(nuevo);
    nuevo->sig = NULL; 

    if(cab==NULL){
        cab = nuevo;        
    } else {
        aux = cab; 
        while (aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo;        
    }
};
void mostrar_manifiesto(){
    aux = cab;
    int contador = 1;
    while (aux != NULL){
        printf("Contenedor #%d - ", contador);
        printf("Tara (Toneladas): %.2f ", aux->tara);
        printf("Carga (Toneladas): %.2f ", aux->carga);
        printf("Masa (Toneladas): %.2f\n", aux->masa);
        aux = aux->sig;
        contador= contador+1;
    }
};
void alerta(contenedor *aux2){
     if(aux2->masa>32)
        printf("ADVERTENCIA! El contenedor supera el límite de Masa Bruta, su masa es %.2f\n", aux2->masa);

}
void verificar_alertas_peso(){
    aux = cab;
    int contador = 1;
    while (aux != NULL){
        if(aux->masa>32)
            printf("ADVERTENCIA! El contenedor %d supera el límite de Masa Bruta, su masa es %.2f", contador, aux->masa);
        aux = aux->sig;
        contador= contador+1;
    }    
};
void eliminar_contenedor(){};