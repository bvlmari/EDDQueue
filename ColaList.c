// Inserting and deleting nodes in a list
#include <stdio.h>
#include <stdlib.h>

struct colas
{
	int num;												// cada nodo Lista contiene un num entero
	struct colas *ptrSiguiente; // apuntador al siguiente nodo
};

// sestructura auto referenciada
typedef struct colas Cola; // sinonimo para struct Cola
typedef Cola *ptrCola;		// synonym for ListNode*

// prototypes
void inicializar(ptrCola *ptrS, int valor);
void agregar(ptrCola *ptrS, int valor);
void borrar(ptrCola *sPtr);
int estaVacia(ptrCola ptrS);
void imprimirCola(ptrCola ptrActual);
void instrucciones(void);
int obtenerEntero(char mensaje[]);
void top(ptrCola cola);
int size(ptrCola cola);

int main()
{
	ptrCola cola = NULL; // inicialmente no existen nodos
	int opc;

	// ciclo while para que el usuario no elija 3
	do
	{
		instrucciones();
		opc = obtenerEntero("Ingrese su opcion");
		switch (opc)
    {
    case 1:
      if(cola == NULL){
        inicializar(&cola, obtenerEntero("Ingrese numero"));
      }else{
        agregar(&cola, obtenerEntero("Ingrese numero"));
      }
      imprimirCola(cola);
      break;
    case 2:
			if(!estaVacia(cola)){
				borrar(&cola);
				imprimirCola(cola);
			}else{
				printf("La lista esta vacia");
			}
      break;
    case 3:
			if(!estaVacia(cola)){
				top(cola);
			}else{
				printf("La lista esta vacia");
			}
      break;
    case 4:
      printf("El tamaño es: %d\n", size(cola));
      break;
    case 5:
      imprimirCola(cola);
      break;
    case 6:
      printf("Saliendo...");
      break;
    default:
      printf("Opcion no valida");
      break;
    }
		 // fin del switch
		printf("\n\n");
	}while (opc != 6);

	printf("Termino el programa.");
	return 0;
}

// display program instructions to user
void instrucciones(void)
{
	printf("\n1. Push\n2. Pop\n3. Top\n4. Size \n5. Imprimir Lista \n6. Salir");
}

// insertar un valor nuevo al inicio de la lista
void inicializar(ptrCola *ptrS, int valor)
{
	ptrCola ptrNuevo;
	ptrNuevo = malloc(sizeof(Cola)); // crear nodo

	if (ptrNuevo != NULL)
	{													// hay espacio disponible?
		ptrNuevo->num = valor; // coloca el valor en el nodo
		// inserta un nuevo nodo al principio de la lista
		ptrNuevo->ptrSiguiente = *ptrS;
		*ptrS = ptrNuevo;
	}
	else
	{
		printf("%d no se inserto. Memoria no disponible.\n", valor);
	}
}

int obtenerEntero(char mensaje[]) // Elimina la redundacia al obtener los int
{
	int var;
	printf("\n%s: ", mensaje);
	scanf("%d", &var);
	return var;
}

void agregar(ptrCola *ptrS, int valor) // Inserta un valor al final de la lista
{
	ptrCola ptrNuevo;
	ptrCola ptrActual;
	ptrNuevo = malloc(sizeof(Cola)); // crear nodo

	if (ptrNuevo != NULL)
	{													// hay espacio disponible?
		ptrNuevo->num = valor; // coloca el valor en el nodo
		ptrActual = *ptrS;
		while (ptrActual->ptrSiguiente != NULL) // Recorre la lista hasta encontrar el ultimo valor
		{
			ptrActual = ptrActual->ptrSiguiente; // ... siguiente nodo
		}
		ptrActual->ptrSiguiente = ptrNuevo; // inserta el nuevo nodo al final
		ptrNuevo->ptrSiguiente = NULL;
	}
	else
	{
		printf("%d no se inserto. Memoria no disponible.\n", valor);
	}
}

// Borra el primer elemento de la lista
void borrar(ptrCola *ptrS)
{
	ptrCola ptrTemporal;

	// borrar el primero nodos
	ptrTemporal = *ptrS;					 // almacena el nodo a eliminar
	*ptrS = (*ptrS)->ptrSiguiente; // desata el nodo
	free(ptrTemporal);						 // libera el nodo
}

void top(ptrCola Cola){
	ptrCola ptrActual;
	ptrActual = Cola;
	while (ptrActual->ptrSiguiente != NULL) // itera la lista hasta llegar al ulimo nodo
	{
		ptrActual = ptrActual->ptrSiguiente; // ... siguiente nodo
	}
	printf("El elemento top es: %d\n", ptrActual->num);
}

int size(ptrCola Cola)
{
	ptrCola ptrActual;
	ptrActual = Cola;
	int cont = 0;
	while (ptrActual != NULL) // itera la lista hasta llegar al ulimo nodo
	{
		ptrActual = ptrActual->ptrSiguiente; // ... siguiente nodo
		cont++;
	}
	return(cont);
}

int estaVacia(ptrCola ptrS)
{
	return ptrS == NULL;
}

// imprime la lista
void imprimirCola(ptrCola ptrActual)
{
	// Si la lista esta vacia
	
	if (estaVacia(ptrActual))
	{
		printf("La lista esta vacia.\n");
	}
	else
	{
		printf("La lista es:");
		// mientras no sea el final de la lista
		int tam = size(ptrActual);
		int arreglo[tam];
		for (int i = 0; i < tam; i++)
		{
			arreglo[i] = ptrActual->num;
			ptrActual = ptrActual->ptrSiguiente;
		}
		for (int i = tam-1; i >= 0; i--)
		{
			printf("\n%d", arreglo[i]);
		}
	}
}