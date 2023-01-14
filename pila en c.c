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

int final = -1;
struct persona pila[LONG];

/*prototipo de funciones */
int crearpilar();		// funcion que se encarga de crear una pila a base de su espacio prederteminado (LONG)
void apilar();			// funcion que se encarga de agregar un elemnto a la pila
void desapilar();		// funcion que se encarga de eliminar un elemento de la pila
void mostrarPILA(); // funcion que se encarga de mostrar los elementos de la pila
void menuMAIN();		// funcion que se encarga de mostrar un menu principal

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
* 5 acciones, crear pila, apilar, desapilar, mostrar contenido de la pila *
* y salir del programa                                                    *
***************************************************************************
*/

/* Muestra el menu principal */
void menuMAIN()
{
	int opcion;
	do
	{
		puts("\t\t\t\tMENU");
		puts("\t\t\t[1] CREAR LA PILA");
		puts("\t\t\t[2] APILAR");
		puts("\t\t\t[3] DESAPILAR");
		puts("\t\t\t[4] MOSTRAR LO QUE TIENE LA PILA");
		puts("\t\t\t[5] SALIR");
		printf("\t\t\t->");

		scanf("%d", &opcion);
		fflush(stdin);
		system("cls");

		if (opcion == 1)
		{
			crearpilar();
		}
		else if (opcion == 2)
		{
			apilar();
		}
		else if (opcion == 3)
		{
			desapilar();
		}
		else if (opcion == 4)
		{
			mostrarPILA();
		}
		else if (opcion == 5)
		{
			exit(-1);
		}
		else
		{
			puts("Opcion incorrecta");
			system("pause");
			system("cls");
		}
	} while (opcion);
} // Se termina la funcion del menu inicial

/*inicio de la funcion que agrega un nuevo elemento a la pila*/
void apilar()
{

	char opc;
	if (final == LONG)
	{
		puts("PILA LLENA!");
		system("pause");
		system("cls");
	}
	else
	{

		if (final <= LONG)
		{
			do
			{
				final++;

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
				printf("\nFecha de nacimiento");

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
				puts("->");

				fflush(stdin);
				gets(pila[final].sexo);

				printf("\n");
				puts("Desea agregar otro elemento? [Y] [N]");
				fflush(stdin);

				opc = getchar();

				fflush(stdin);
				if (final == LONG)
				{
					puts("\tPILA LLENA!");

					break;
				}
			} while (opc == 'Y' || opc == 'y');
		}
		system("pause");
		system("cls");
	}
}

/*inicio de la funcion que crea la pila a base de 20 espacios libre*/
int crearpilar()
{

	int i; // variable de inicio e incremento del bucle for
	char opcion;

	if (final < LONG)
	{
		puts("\t\tLA PILA SE PUEDE LLENAR");
		puts("\t-------------------------------------------");
		for (i = 0; i < LONG && final < LONG; i++)
		{
			printf("\tINSERTE LA INFORMACION DE LA PERSONA");
			
			/* Nombre */
			puts("Nombre: ");
			gets(pila[i].nombre);

			/* Apellido */
			puts("Apellido: ");
			gets(pila[i].apellido);

			/* Cedula */
			puts("Cedula: ");
			scanf("%d", &pila[i].cedula);

			/* Fecha de Nacimiento */
			puts("Fecha de nacimiento");
			
			/* Dia */
			puts("Dia: ");
			scanf("%d", &pila[i].fecha_nacimiento.dia);

			/* Mes */
			puts("Mes: ");
			scanf("%d", &pila[i].fecha_nacimiento.mes);

			/* Año */
			puts("Anio: ");
			scanf("%d", &pila[i].fecha_nacimiento.anio);

			/* Numero Telefonico */
			puts("Numero telefonico: ");
			scanf("%lld", &pila[i].telefono);

			/* Genero */
			puts("\t\tGENERO");
			puts("Masculino [M]\tFemenino [F]\tOtro [X]");
			puts("->");

			fflush(stdin);
			gets(pila[i].sexo);
			fflush(stdin);
			printf("\n");

			final++;

			puts("Desea limitar la pila?  [Y] [N]");
			fflush(stdin);
			opcion = getchar();
			fflush(stdin);
			if (opcion == 'Y' || opcion == 'y')
			{
				break;
			}
		}
	}
	else
	{

		printf("\t\tERROR!");
		puts("\tLa pila esta vacia");
		puts("\tPor favor llenela");
		return -1;
	}
	puts("la pila se ha llenado con excito!");
	system("pause");
	system("cls");
} // Fin de la funcion para crear la pila

/*inicio de la funcion que elimina un elemento de la pila*/
void desapilar()
{

	if (final >= 0)
	{
		final--;
		puts("se ha eliminado un elemento de la pila");
		printf("el usuario eliminado fue %s\n", pila[final + 1].nombre);
	}
	else
	{
		printf("\t\tERROR!");
		puts("\tLa pila esta vacia");
		puts("\tPor favor llenela");
	}
	system("pause");
	system("cls");
} // fin de la funcion que elimina un elemento de la pila

/*inicio de la funcion que muestra lo que tiene la pila*/
void mostrarPILA()
{

	int j; // variable de inicio e incremento del bucle for

	if (final == -1)
	{
		printf("\t\tERROR!");
		puts("\tLa pila esta vacia");
		puts("\tPor favor llenela");
		system("pause");
	}
	else
	{

		for (j = 0; j < final + 1; j++)
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
