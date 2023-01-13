
#include <stdio.h>
#include <stdlib.h>

#define LONG 3 //define el espacio prederteminado de la pila

//estructura de datos sobre la fecha y que va anidada a la estructura principal
struct Fecha{
	int dia,mes,anio;
	
};
//estrcutura de datos principal de la pila
struct persona {
	int cedula; 
	char nombre[50]; 
	char apellido[50]; 
	char sexo[1]; 
	struct Fecha fecha_nacimiento; 
	long long int telefono; 
};

int final= -1;
struct persona  pila[LONG];

/*prototipo de funciones */
int crearpilar();//funcion que se encarga de crear una pila a base de su espacio prederteminado (LONG)
void apilar();//funcion que se encarga de agregar un elemnto a la pila
void desapilar();//funcion que se encarga de eliminar un elemento de la pila
void mostrarPILA();//funcion que se encarga de mostrar los elementos de la pila
void menuMAIN(); //funcion que se encarga de mostrar un menu principal

/*Funcion inicial*/
int main (void){


menuMAIN();

    return 0;

}
/*inicio de la funcion encargada del menu principal*/
void menuMAIN(){
	int opcion;
	do{
	printf("\t\tMENU\n\t[1] CREAR LA PILA\n\t[2] APILAR\n\t[3] DESAPILAR\n\t[4] MOSTRAR LO QUE TIENE LA PILA\n\t[5] SALIR\n\t->");
    scanf("%d",&opcion);
	fflush(stdin);
	system("cls");
	switch(opcion){
		
		case 1:{
			crearpilar();
			break;
		}
		
		case 2:{
		apilar();
			break;
		}
		case 3:{
			desapilar();
			
			break;
		}
		case 4:{
			mostrarPILA();
			break;
			
	}
	case 5:{
		exit(-1);

		break;
	}
	default:{
		puts("Opcion incorrecta");		
		system("pause");
		system("cls");
		break;
	}
}} while (opcion);
} //Se termina la funcion del menu inicial

/*inicio de la funcion que agrega un nuevo elemento a la pila*/
void apilar(){
	
	char opc;
	
	if (final<=LONG){
		do{
			final++;
			printf("\tINSERTE LA INFORMACION DE LA PERSONA\nNombre:");
			gets(pila[final].nombre);
			printf("\nApellido:");
			gets(pila[final].apellido);
			printf("\nCedula:");
			scanf("%d", &pila[final].cedula);
			printf("\nFecha de nacimiento\nDia:");
			scanf("%d",&pila[final].fecha_nacimiento.dia);
			printf("\nMes:");
			scanf("%d",&pila[final].fecha_nacimiento.mes);
			printf("\nAnio:");
			scanf("%d",&pila[final].fecha_nacimiento.anio);
			printf("\nNumero telefonico:");
			scanf("%lld", &pila[final].telefono);
			printf("\n\t\t GENERO \n Masculino [M] \t Femenino [F]  \t Otro. [X]\n->");
			fflush(stdin);
			gets(pila[final].sexo);
			printf("\n");
			puts("Desea agregar otro elemento? [Y] [N]");
			scanf("%c",&opc);
			if (final == LONG){
				puts("\tPILA LLENA!");
				
				break;
				
			} else{
			
			}
		} while(opc == 'Y' || opc == 'y');
	}
		system("pause");
				system("cls");
}

/*inicio de la funcion que crea la pila a base de 20 espacios libre*/
int crearpilar(){
	
int i;//variable de inicio e incremento del bucle for
char opcion;

if ( final <LONG){

    puts("\t\t LA PILA SE PUEDE LLENAR\n\t--------------------------------------------");
    for (i=0; i<LONG && final<LONG; i++ ){
		printf("\tINSERTE LA INFORMACION DE LA PERSONA\nNombre:");
		gets(pila[i].nombre);
		printf("\nApellido:");
		gets(pila[i].apellido);
		printf("\nCedula:");
		scanf("%d", &pila[i].cedula);
		printf("\nFecha de nacimiento\nDia:");
		scanf("%d",&pila[i].fecha_nacimiento.dia);
		printf("\nMes:");
		scanf("%d",&pila[i].fecha_nacimiento.mes);
		printf("\nAnio:");
		scanf("%d",&pila[i].fecha_nacimiento.anio);
		printf("\nNumero telefonico:");
		scanf("%lld", &pila[i].telefono);
		printf("\n\t\t GENERO \n Masculino [M] \t Femenino [F]  \t Otro. [X]\n->");
		fflush(stdin);
		gets(pila[i].sexo);
		printf("\n");

 		final++;
 
 puts("Desea limitar la pila?  [Y] [N]");
 scanf("%c",&opcion);
 
      if (opcion == 'Y' || opcion == 'y'){
      	break;
	  } else 
	  continue;
        }
} else{
	
printf("\t      ERROR!\n\tLa pila esta vacia\n\tPor favor llenela\n");	
    return -1;
    
}
puts("la pila se ha llenado con excito!");
 	system("pause");
	system("cls");
}//Fin de la funcion para crear la pila

/*inicio de la funcion que elimina un elemento de la pila*/
void desapilar(){ 
	
	if(final>=0){
		final--;
		puts("se ha eliminado un elemento de la pila");
		printf ("el usuario eliminado fue  %s\n", pila[final+1].nombre);
		
	} else {
printf("\t      ERROR!\n\tLa pila esta vacia\n\tPor favor llenela\n");	
	}
	system("pause");
	system("cls");
}//fin de la funcion que elimina un elemento de la pila

/*inicio de la funcion que muestra lo que tiene la pila*/
void mostrarPILA(){
	
	int i; //variable de inicio e incremento del bucle for
	
	if (final ==-1){
printf("\t      ERROR!\n\tLa pila esta vacia\n\tPor favor llenela\n");	
			system("pause");
				system("cls");
	} else {
		
		for (i=0; i<final+1; i++){
			printf("\t\t LUGAR DE LA PILA %d\n",i+1);
			printf("Nombre: %s %s\n",pila[i].nombre,pila[i].apellido);
			printf("Genero: %s\n",pila[i].sexo);
			printf("Fecha de nacimiento: %d/%d/%d\n",pila[i].fecha_nacimiento.dia,pila[i].fecha_nacimiento.mes,pila[i].fecha_nacimiento.anio);
			printf("Cedula: %d\n",pila[i].cedula);
			printf("Numero telefonico: %lld\n",pila[i].telefono);
		}
		system("pause");
				system("cls");
	}
		
}//fin de la funcion que muestra los elementos de la pila
