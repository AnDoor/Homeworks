/* Tecnica de programacion II / SECCION 02
	Alumnos: Puerta Andrew 30957308
         	 Balan Yorman  31782211
*/
#include <stdio.h>
#include <stdlib.h>

#define LONG 1 // define el espacio prederteminado de la pila

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
int crearpilar();// funcion que se encarga de crear una pila a base de su espacio prederteminado (LONG)
void apilar();// funcion que se encarga de agregar un elemnto a la pila
void desapilar();// funcion que se encarga de eliminar un elemento de la pila
void mostrarPILA(); // funcion que se encarga de mostrar los elementos de la pila
void menuMAIN();// funcion que se encarga de mostrar un menu principal
void vaciarPILA(); //Funcion que se encarga de vaciar la pila por completo

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
		puts("\t\t\t[1] CREAR LA PILA");
		puts("\t\t\t[2] APILAR");
		puts("\t\t\t[3] DESAPILAR");
		puts("\t\t\t[4] MOSTRAR LO QUE TIENE LA PILA");
		puts("\t\t\t[5] VACIAR PILA POR COMPLETO");
		puts("\t\t\t[6] Salir");
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
			vaciarPILA();
		}
		else if(opcion == 6) {
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

/*
***************************************************************************
*                               crearpilar                                *
***************************************************************************
* Esta funcion se encarga de crear una nueva pila con un almacenamiento   *
* prederteminado con un espacio de 20 espacios en la pila.Tambien pregunta*
* si queremos limitar la cantidad de la pila o no y muestra un mensaje    *
* cuando la pila se haya llenado.                                         *
***************************************************************************
*/
int crearpilar()
{

	int i; // variable de inicio e incremento del bucle for
	char opcion;

if (final >= 0){
	puts("\t\t LA PILA ESTA LLENA\n\t NO SE PUEDE CREAR UNA NUEVA PILA");
	puts("\t\t DEBE VACIARLA!");
	system("pause");
	system("cls");
	return -1;
}
	if (final < LONG)
	{
		puts("\t\tLA PILA SE PUEDE LLENAR");
		puts("\t-------------------------------------------");
		for (i = 0; i < LONG && final < LONG; i++)
		{
			printf("\tINSERTE LA INFORMACION DE LA PERSONA");
			
			/* Nombre */
			puts("\nNombre: ");
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

		puts("\t\tERROR!");
		puts("\t  La pila esta vacia");
		puts("\t  Por favor llenela");
		return -1;
	}
	puts("la pila se ha llenado con excito!");
	system("pause");
	system("cls");
} // Fin de la funcion para crear la pila

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

	if (final >= 0)
	{
		final--;
		puts("se ha eliminado un elemento de la pila");
		printf("el usuario eliminado fue %s\n", pila[final + 1].nombre);
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

	if (final == -1)
	{
		puts("\t\tERROR!");
		puts("\t  La pila esta vacia");
		puts("\t  Por favor llenela");
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

/*
***************************************************************************
*                              vaciarPILA                                 *
***************************************************************************
* Esta funcion se encarga de eliminar todos los elementos que contiene    *
* actualmente la pila, si la pila ya estaba vacia y le damos a este opcion*
* entonces nos saldra una advertencia de que la pila ya esta vacia.       *
***************************************************************************
*/

//Inicio de la funcion vaciarPILA
void vaciarPILA(){
	
	int k;//variable de inicializacion e incrementacion del bucle
	
	if (final == -1){
		puts("\t    ADVERTENCIA!");
		puts("\tNo se puede vaciar\n\t  Llene la pila!");
		system("pause");
		system("cls");
	} else {
		do{
				for (k =0; k<=final;k++){
			
			final--;
			pila[final-1];
			if (final ==-1){
				puts("la pila ya se ha vaciado con excito!");
				system("pause");
				system("cls");
				
			}
		} 
	
		}while(final!=-1);
	}
	
}//fin de la funcion vaciarPILA
