/* Tecnica de programacion II / SECCION 02
	Alumnos: Puerta Andrew 30857308
					 Balan Yorman  31782211
*/
#include <stdio.h>
#include <stdlib.h>

#define LONG 20 // define el espacio prederteminado de la pila

// estructura de datos sobre la fecha y que va anidada a la estructura principal
struct Fecha
{
	int dia, mes, anio;
};

// estrcutura de datos principal de la pila
struct persona
{
	int cedula;
	char nombre[50];
	char apellido[50];
	char sexo[1];
	struct Fecha fecha_nacimiento;
	long long int telefono;
};

int final = 0;
struct persona pila[LONG];

/* prototipo de funciones */
void apilar();					 // funcion que se encarga de agregar un elemnto a la pila
void desapilar();				 // funcion que se encarga de eliminar un elemento de la pila
void mostrarPILA();			 // funcion que se encarga de mostrar los elementos de la pila
void menuMAIN();				 // funcion que se encarga de mostrar un menu principal
void vaciarPILA();			 // Funcion que se encarga de vaciar la pila por completo
void longitud_de_pila(); // Muestra la cantidad de elementos que tiene la pila
void pila_vacia();
void pila_llena();

/*Funcion inicial*/
int main(void)
{

	menuMAIN();

	return 0;
}

/*
***************************************************************************
*                               menuMain                                  *
***************************************************************************
* Esta funcion se encarga de mostrar el menu principal, donde da a elegir *
* 6 acciones, crear pila, apilar, desapilar, mostrar contenido de la pila *
* ,vaciar por completo la pila y salir del programa.                      *
***************************************************************************
*/

/* Muestra el menu principal */
void menuMAIN()
{
	int opcion;
	do
	{
		puts("\t\t\t\tMENU");
		puts("\t\t\t[1] APILAR");
		puts("\t\t\t[2] DESAPILAR");
		puts("\t\t\t[3] MOSTRAR LO QUE TIENE LA PILA");
		puts("\t\t\t[4] VACIAR PILA POR COMPLETO");
		puts("\t\t\t[5] LONGITUD DE PILA");
		puts("\t\t\t[6] VERIFICAR SI ESTA VACIA");
		puts("\t\t\t[7] VERIFICAR SI ESTA LLENA");
		puts("\t\t\t[8] Salir");
		printf("\t\t\t->");

		scanf("%d", &opcion);
		fflush(stdin);
		system("cls");

		if (opcion == 1)
		{
			apilar();
		}
		else if (opcion == 2)
		{
			desapilar();
		}
		else if (opcion == 3)
		{
			mostrarPILA();
		}
		else if (opcion == 4)
		{
			vaciarPILA();
		}
		else if (opcion == 5)
		{
			longitud_de_pila();
		}
		else if (opcion == 6)
		{
			pila_vacia();
		}
		else if (opcion == 7)
		{
			pila_llena();
		}
		else if (opcion == 8)
		{
			exit(-1);
		}
		else
		{
			puts("OPCION INCORRECTA!");
			system("pause");
			system("cls");
		}
	} while (opcion);
} // Se termina la funcion del menu inicial

/*
***************************************************************************
*                          longitud_de_pila                               *
***************************************************************************
* Muestra la cantidad de elementos que contiene la pila                   *
***************************************************************************
*/
void longitud_de_pila()
{
	system("cls");
	printf("Hay %d elementos en la pila\n", final);
	puts("Presiona cualquier tecla para continuar...");
	getchar();
}

/*
***************************************************************************
*                                pila_vacia                               *
***************************************************************************
* Avisa en pantalla si la pila esta vacia o no                            *
***************************************************************************
*/
void pila_vacia()
{
	if (final == 0)
	{
		system("cls");
		puts("La pila esta vacia");
		puts("Presiona cualquier tecla para continuar...");
		getchar();
	}
	else
	{
		system("cls");
		puts("La pila no esta vacia");
		puts("Presiona cualquier tecla para continuar...");
		getchar();
	}
}

/*
***************************************************************************
*                                pila_llena                               *
***************************************************************************
* Avisa en pantalla si la pila esta llena o no                            *
***************************************************************************
*/
void pila_llena()
{
	if (final == LONG)
	{
		system("cls");
		puts("La pila esta llena");
		puts("Presiona cualquier tecla para continuar...");
		getchar();
	}
	else
	{
		system("cls");
		puts("La pila no esta llena");
		puts("Presiona cualquier tecla para continuar...");
		getchar();
	}
}

/*
***************************************************************************
*                               apilar                                    *
***************************************************************************
* Esta funcion se encarga de agregar un elemento nuevo a la pila uno por  *
* uno, tambien pregunta si el usuario quiere seguir agregando y cuando la *
* pila llegue a su cantidad maxima se mostrara un mensaje como aviso.     *
***************************************************************************
*/

/*inicio de la funcion que agrega un nuevo elemento a la pila*/
void apilar()
{

	char opc;
	do
	{
		if (final >= LONG)
		{
			puts("PILA LLENA!");
			system("pause");
			system("cls");
			return;
		}

		puts("\tINSERTE LA INFORMACION DE LA PERSONA");

		/* Nombre de la persona */
		puts("Nombre:");
		gets(pila[final].nombre);

		/* Apellido de la persona */
		puts("Apellido:");
		gets(pila[final].apellido);

		/* Cedula de la persona */
		puts("Cedula:");
		scanf("%d", &pila[final].cedula);

		/* Fecha de nacimiento */
		printf("\nFecha de nacimiento\n");

		/* Dia */
		puts("Dia: ");
		scanf("%d", &pila[final].fecha_nacimiento.dia);

		/* Mes */
		puts("Mes: ");
		scanf("%d", &pila[final].fecha_nacimiento.mes);

		/* Año */
		puts("Anio: ");
		scanf("%d", &pila[final].fecha_nacimiento.anio);

		/* Numero telefonico */
		puts("Numero telefonico: ");
		scanf("%lld", &pila[final].telefono);

		/* Genero */
		puts("\t\tGENERO");
		puts("Masculino [M]\tFemenino [F]\tOtro [X]");
		printf("->");

		fflush(stdin);
		gets(pila[final].sexo);

		printf("\n");
		puts("Desea agregar otro elemento? [Y] [N]");
		fflush(stdin);

		opc = getchar();

		fflush(stdin);

		final++;
	} while (opc == 'Y' || opc == 'y');
	system("pause");
	system("cls");
}

/*
***************************************************************************
*                               desapilar                                 *
***************************************************************************
* Esta funcion se encarga de eliminar el ultimo elemento agregado a la    *
* pila,tambien nos muestra un mensaje cuando la pila se encuentra vacia   *
* y la queramos desapilar.                                                *
***************************************************************************
*/

/*inicio de la funcion que elimina un elemento de la pila*/
void desapilar()
{

	if (final > 0)
	{
		puts("se ha eliminado un elemento de la pila");
		printf("el usuario eliminado fue %s\n", pila[final].nombre);
		final--;
	}
	else
	{
		puts("\t\tERROR!");
		puts("\t  La pila esta vacia");
		puts("\t  Por favor llenela");
	}
	system("pause");
	system("cls");
} // fin de la funcion que elimina un elemento de la pila

/*
***************************************************************************
*                               mostrarPILA                               *
***************************************************************************
* Esta funcion se encarga de mostrar en patalla todos los elementos       *
* que hemos introducido a la pila. Si la pila se encuentra vacia y quere- *
* mos mostrar los elementos, nos saldra un mensaje de error avizandonos   *
* que la pila se encuntra vacia y debemos llenarla para que esta funcion  *
* se puede ejecutar ocn excito.                                           *
***************************************************************************
*/

/*inicio de la funcion que muestra lo que tiene la pila*/
void mostrarPILA()
{

	int j; // variable de inicio e incremento del bucle for

	if (final == 0)
	{
		puts("\t\tERROR!");
		puts("\t  La pila esta vacia");
		puts("\t  Por favor llenela");
		system("pause");
	}
	else
	{

		for (j = 0; j < final; j++)
		{
			printf("\t\t [LUGAR DE LA PILA %d]\n", j + 1);
			printf("Nombre: %s %s\n", pila[j].nombre, pila[j].apellido);
			printf("Genero: %s\n", pila[j].sexo);
			printf("Fecha de nacimiento: %d/%d/%d\n", pila[j].fecha_nacimiento.dia, pila[j].fecha_nacimiento.mes, pila[j].fecha_nacimiento.anio);
			printf("Cedula: %d\n", pila[j].cedula);
			printf("Numero telefonico: %lld\n", pila[j].telefono);
		}
		system("pause");
	}
	system("cls");
} // fin de la funcion que muestra los elementos de la pila

/*
***************************************************************************
*                              vaciarPILA                                 *
***************************************************************************
* Esta funcion se encarga de eliminar todos los elementos que contiene    *
* actualmente la pila, si la pila ya estaba vacia y le damos a este opcion*
* entonces nos saldra una advertencia de que la pila ya esta vacia.       *
***************************************************************************
*/

// Inicio de la funcion vaciarPILA
void vaciarPILA()
{

	int k; // variable de inicializacion e incrementacion del bucle

	if (final == 0)
	{
		puts("\t    ADVERTENCIA!");
		puts("\tNo se puede vaciar\n\t  Llene la pila!");
		system("pause");
		system("cls");
	}
	else
	{
		final = 0;
		puts("la pila ya se ha vaciado con excito!");
		system("pause");
		system("cls");
	}

} // fin de la funcion vaciarPILA
