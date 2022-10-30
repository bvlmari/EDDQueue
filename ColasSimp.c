#include <stdio.h>

#define SIZE 100

void agregar();
void eliminar();
void imprimir();

int arr[SIZE];
int final = -1;
int frente = -1;

main(){
    int op, wh=1;
    while(wh==1){
        printf("\nMenu\n1 Agregar a cola\n2 Remover de cola\n3 Mostrar cola\n4 salir\nElige una opcion --> ");
        scanf("%d",&op);
    
        switch(op){
            case 1:
                agregar();
                break;
            case 2:
                eliminar();
                break;
            case 3: 
                imprimir();
                break;
            case 4:
                wh=0;
                printf("Saliendo");
                break;
            default:
                printf("Opcion incorrecta");
        }

    }
}

void agregar(){
    int in;
    
    if (final == SIZE - 1)
        printf("Sobreflujo");
    else{
        if(frente == - 1)

        frente = 0;
        printf("\nIngrese el elemento a ingresar a la cola -->");
        scanf("%d", &in);
        final = final + 1;
        arr[final] = in;
    }
}

void eliminar(){
    if(frente == - 1 || frente > final)
        printf("Esta vacio");
    else{
        printf("\nElemento eliminado de la cola --> %d\n", arr[frente]);
        frente = frente + 1;
    }
}

void imprimir(){
    if(frente == -1)
        printf("Cola vacia \n");
    else{
        printf("Cola Actual: \n");
        for (int i = frente; i<= final; i++)
            printf("\n%d", arr[i]);
        printf("\n");
    }
}