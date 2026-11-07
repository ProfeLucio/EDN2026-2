#include <stdio.h>
#include <malloc.h>

typedef struct puntoControl
{ 
    int id; //Identificador
    float peso; //Kilogramos
    int semana;//1 - 2 - 3 - 4 - 5
    int mes;//1. Enero, 2. Febrero. 
    int year;// YYYY
    struct puntoControl *sig; 
} puntoControl;

puntoControl *cab = NULL, *aux, *antes;


int ingresarPeso();
int recorrerRegistros();
int actualizarRegistro();
int eliminarRegistro();
int main(){
    int opcion;

    do{
        printf("Control Peso\n1. Registrar\n2. Mostrar\n3. Actualizar\n4. Eliminar\n5. Salir\nDigite su opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
            case 1: ingresarPeso();break;
            case 2: recorrerRegistros(); break;        
            case 3: actualizarRegistro(); break;        
            case 4: eliminarRegistro(); break;  
        }
    }while(opcion!=5);
}

int ingresarPeso(){
    puntoControl *nuevo = (puntoControl*) malloc(sizeof(puntoControl));
    printf("Digite la semana: ");
    scanf("%d", &nuevo->semana);
    printf("Digite el mes: ");
    scanf("%d", &nuevo->mes);
    printf("Digite el año: ");
    scanf("%d", &nuevo->year);
    printf("Digite el peso: ");
    scanf("%f", &nuevo->peso);
    nuevo->sig = NULL; 
     if(cab==NULL){
        cab = nuevo;  
        cab->id = 1;      
    } else {
        nuevo->sig = cab;
        nuevo->id = cab->id + 1;
        cab = nuevo;
    }
}

int recorrerRegistros(){
    aux = cab;
    while (aux != NULL){
        printf("%d : ", aux->id);
        printf("Peso : %.2f - ", aux->peso);
        printf("Semana : %d - ", aux->semana);
        printf("Mes : %d - ", aux->mes);
        printf("Anio : %d\n", aux->year);
        aux = aux->sig;
    }
}

int actualizarRegistro(){
    int buscar;
    printf("Id del registro a actualizar: ");
    scanf("%d", &buscar);
    aux = cab;
    while(aux!=NULL&&aux->id!=buscar){
        aux = aux->sig;
    }
    if(aux==NULL){
        printf("Id no existe.\n");
    } else {
        printf("Digite la semana: ");
        scanf("%d", &aux->semana);
        printf("Digite el mes: ");
        scanf("%d", &aux->mes);
        printf("Digite el año: ");
        scanf("%d", &aux->year);
        printf("Digite el peso: ");
        scanf("%f", &aux->peso);
    }

}

int eliminarRegistro(){
    int buscar;
    printf("Id del registro a actualizar: ");
    scanf("%d", &buscar);
    aux = cab;
    while(aux!=NULL&&aux->id!=buscar){
        aux = aux->sig;
    }
    if(aux==NULL){
        printf("Id no existe.\n");
    } else {
        if(aux==cab){
            cab = cab->sig;            
        } else {
            antes = cab;
            while(antes->sig!=aux){
                antes = antes->sig;
            }
            antes->sig = aux->sig;
            antes = NULL;
        }
        free(aux);
        aux = NULL;
        printf("Registro eliminado.\n");        
    }
}