#include <stdio.h>
#include <stdlib.h>
 
struct cola
{
    int *elementos;     
    int tammax;    
    int frente;      
    int final;      
    int tam;     
};
 
// Funcion para inicializar una cola
struct cola* nuevaCola(int size)
{
    struct cola *pt = NULL;
    pt = (struct cola*)malloc(sizeof(struct cola));
 
    pt->elementos = (int*)malloc(size * sizeof(int));
    pt->tammax = size;
    pt->frente = 0;
    pt->final = -1;
    pt->tam = 0;
 
    return pt;
}

void agregar(struct cola *pt, int x);
void eliminar(struct cola *pt);
int tamaño(struct cola *pt);
int vacia(struct cola *pt);
int tope(struct cola *pt);
 
int main()
{
    int optam, op, x, wh=1;

    printf("\nBienvenido\nIngrese el tamaño deseado de la cola\n--> ");
    scanf("%d", &optam);
    struct cola *pt = nuevaCola(optam);

    while(wh==1){
        printf("\nMenu\n1 Agregar a cola\n2 Remover de cola\n3 Tamaño de la cola\n4 Tope de la cola\n5 salir\nElige una opcion --> ");
        scanf("%d",&op);
        switch(op){
            case 1:
                printf("\nIngrese el elemento a ingresar a la cola --> ");
                scanf("%d", &x);
                agregar(pt, x);
                break;
            case 2:
                if (vacia(pt)) {
                    printf("\nLa cola esta vacia");
                }
                else {
                    eliminar(pt);
                }
                break;
            case 3: 
                printf("\nTamaño de la cola: %d\n", tamaño(pt));
                break;
            case 4:
                printf("\nTope de la cola: %d\n", tope(pt));
                break;
            case 5:
                wh=0;
                printf("\nSaliendo");
                break;
            default:
                printf("\nOpcion incorrecta");
        }
    }
    
    return 0;
}

//Funcion para agregar un elemento a la cola
void agregar(struct cola *pt, int x)
{
    if (tamaño(pt) == pt->tammax)
    {
        printf("\nDesbordamiento\n");
    }
 
    printf("\n%d Insertado\n", x);
 
    pt->final = (pt->final + 1) % pt->tammax;   //Cola circular
    pt->elementos[pt->final] = x;
    pt->tam++;
 
}
 
//Funcion para eliminar un elemento de la cola
void eliminar(struct cola *pt)
{
    if (vacia(pt))    
    {
        printf("\nSubdesbordamiento\n");
        exit(EXIT_FAILURE);
    }
 
    printf("\n%d Eliminado\t", tope(pt));
 
    pt->frente = (pt->frente + 1) % pt->tammax;  //Cola Circular
    pt->tam--;
}

// Funcion para retornar el tamaño de la cola
int tamaño(struct cola *pt) {
    return pt->tam;
}
 
// Funcion para verificar si la cola esta vacia
int vacia(struct cola *pt) {
    return !tamaño(pt);
}

// Funcion para retornar el elemento que esta al tope de la cola
int tope(struct cola *pt)
{
    if (vacia(pt))
    {
        printf("\nSubdesbordamiento\n");
    }
 
    return pt->elementos[pt->frente];
}
