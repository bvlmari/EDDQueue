#include <stdio.h>
#include <stdlib.h>

struct colas
{
	int num;                    // cada nodo Lista contiene un num entero
	struct colas *ptrSiguiente; // apuntador al siguiente nodo
  int orden[50];    
  int cont;                // contador de ordenes
  int tipo;           // tipo de orden (mesa o domicilio)
};

// sestructura auto referenciada
typedef struct colas Cola; 
typedef Cola *ptrCola;	

// prototipos
void inicializar(ptrCola *ptrS, int valor, int tipo);
void agregar(ptrCola *ptrS, int valor, int tipo);
void borrar(ptrCola *sPtr);
int estaVacia(ptrCola ptrS);
void imprimirCola(ptrCola ptrActual);
void instrucciones(void);
int obtenerEntero(char mensaje[]);
void top(ptrCola cola);
int size(ptrCola cola);
void agregarPlatillos(ptrCola ptrActual);
void imprimirPlatillos(ptrCola ptrActual);
void insertarCentro(ptrCola *ptrS, int valor, int tipo);

char platillos[][20] = {"", "Enchiladas", "Tacos", "Quesadillas", "Burritos", "Chilaquiles","Coca Cola", "Sprite", "Fanta", "Agua", "Jugo"};
int main()
{
	ptrCola cola = NULL; // inicialmente no existen nodos
	int opc, com = 1;

	// ciclo while para que el usuario no elija 3
	do
	{
		instrucciones();
		opc = obtenerEntero("Ingrese su opcion");
		switch (opc)
    {
    case 1:
      if(cola == NULL){
        inicializar(&cola, com, obtenerEntero("Ingrese tipo de orden (1 = mesa, 2 = domicilio)"));
      }else{
        agregar(&cola, com, obtenerEntero("Ingrese tipo de orden (1 = mesa, 2 = domicilio)"));
      }
      imprimirCola(cola);
      com++;
      break;
    case 2:
			if(!estaVacia(cola)){
				borrar(&cola);
				imprimirCola(cola);
			}else{
				printf("La comandera esta vacia");
			}
      break;
    case 3:
      imprimirCola(cola);
      break;
    case 4:
      printf("Saliendo...");
      break;
    default:
      printf("Opcion no valida");
      break;
    }
		 // fin del switch
		printf("\n\n");
	}while (opc != 4);

	printf("Termino el programa.");
	return 0;
}

void instrucciones(void)
{
	printf("\n1. Agregra Comanda\n2. Comanda Preparada\n3. Imprimir Comanda\n4. Salir");
}

// insertar un valor nuevo al inicio de la lista
void inicializar(ptrCola *ptrS, int valor, int tipo)
{
	ptrCola ptrNuevo;
	ptrNuevo = malloc(sizeof(Cola)); // crear nodo

	if (ptrNuevo != NULL)
	{													// hay espacio disponible?
		ptrNuevo->num = valor; // coloca el valor en el nodo
		// inserta un nuevo nodo al principio de la lista
		ptrNuevo->ptrSiguiente = *ptrS;
    ptrNuevo->cont = 0; // inicializa el contador de orden en 0
    ptrNuevo->tipo = tipo; // inicializa el tipo de orden
     // inicializa el tipo de orden en mesa o domicilio
    agregarPlatillos(ptrNuevo); // agregar platillo al orden
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

void agregar(ptrCola *ptrS, int valor, int tipo) // Inserta un valor al final de la lista
{
	ptrCola ptrNuevo;
	ptrCola ptrActual;
	ptrNuevo = malloc(sizeof(Cola)); // crear nodo

	if (ptrNuevo != NULL)
	{													// hay espacio disponible?
		ptrNuevo->num = valor; // coloca el valor en el nodo
    ptrNuevo->cont = 0; // inicializa el contador de orden en 0
    ptrNuevo->tipo = tipo; // inicializa el tipo de orden en mesa o domicilio
    agregarPlatillos(ptrNuevo); // agregar platillo al orden
		ptrActual = *ptrS;
		while (ptrActual->ptrSiguiente != NULL ) // Recorre la lista hasta encontrar el ultimo valor
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
	if (estaVacia(ptrActual))
	{
		printf("La comandera esta vacia.\n");
	}
	else
	{
		// mientras no sea el final de la lista
		int tam = size(ptrActual);
    char *tipo; // variable para guardar el tipo de orden
    
		for (int i = 0; i < tam; i++)
		{
      if(ptrActual->tipo == 1){
        tipo = "Mesa";
      }else{
        tipo = "Domicilio";
      } // inicializa el tipo de orden en mesa o domicilio
      printf("+--------------------+\n");
      printf("|%s%*d|\n", "Orden: ", -13, ptrActual->num); // Imprime el numero de orden
      printf("|%s%*s|\n", "Tipo: ", -14, tipo); // Imprime el tipo de orden
      printf("+--------------------+"); 
      imprimirPlatillos(ptrActual);
      printf("\n+--------------------+\n\n");
			ptrActual = ptrActual->ptrSiguiente;
		}
	}
  
}

void agregarPlatillos(ptrCola ptrActual){
  int opcion;
  do{
    printf("Que platillo desea agregar?");
    printf("\n1. Enchiladas\n 2. Tacos\n 3. Quesadillas\n 4. Burritos\n 5. Chilaquiles\n 6. Coca Cola\n 7. Sprite\n 8. Fanta\n 9. Agua\n 10. Jugo\n 11. Salir");
    opcion = obtenerEntero("Opcion: ");
    ptrActual->orden[ptrActual->cont] = opcion; // Agrega el platillo al orden
    ptrActual->cont++; // Aumenta el contador de platillos
  }while(opcion != 11); // Sale cuando el usuario elige la opcion 6
}

void imprimirPlatillos(ptrCola ptrActual){
  for (int i = 0; i < ptrActual->cont; i++)
  {
    printf("\n|%*s|",-20,platillos[ptrActual->orden[i]]); // Imprime el platillo
  }
  
}



void insertarCentro(ptrCola *ptrS, int valor, int tipo)
{
	ptrCola ptrNuevo;
	ptrCola ptrActual;
	ptrCola ptrAnterior;
	ptrNuevo = malloc(sizeof(Cola)); // crear nodo
	int i = 2;
	if (ptrNuevo != NULL) // Revisa si hay espacio en memoria
	{ 
		ptrNuevo->num = valor; // coloca el valor en el nodo
    ptrNuevo->cont = 0; // inicializa el contador de orden en 0
    ptrNuevo->tipo = tipo; // inicializa el tipo de orden en mesa o domicilio
    agregarPlatillos(ptrNuevo); // agregar platillo al orden
		ptrActual = *ptrS;
    if (size(ptrActual) == 1 && ptrActual->tipo <= tipo) // Si solo hay un elemento en la lista
    {
      ptrNuevo->ptrSiguiente = ptrActual->ptrSiguiente; // inserta el nuevo nodo al final
      ptrActual->ptrSiguiente = ptrNuevo;
    }else if(size(ptrActual) == 1 && ptrActual->tipo > tipo){ // Si solo hay un elemento en la lista
      ptrNuevo->ptrSiguiente = ptrActual; 
      *ptrS = ptrNuevo;
    }else{
      while (i < tipo && ptrActual != NULL) // Iteramos el nodo hasta que se encuentra la tipo pedida o llega al final de la lista
      {     
      	ptrAnterior = ptrActual;						 // entra al...
      	ptrActual = ptrActual->ptrSiguiente; // ... siguiente nodo
      	i++;
      }
      if (ptrActual != NULL) // valida el rango, si posicion es menor dos esta debajo y si ptrActual es nulo esta sobrepasado
      {
      	// inserta un nuevo nodo al principio de la lista
      	ptrAnterior->ptrSiguiente = ptrNuevo;
      	ptrNuevo->ptrSiguiente = ptrActual;
      }
    }
	}
	else
	{
		printf("Memoria no disponible.\n");
	}
}