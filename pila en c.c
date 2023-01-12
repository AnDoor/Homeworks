#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define LONG 3
struct Fecha{
	int dia,mes,anio;
	
};
struct persona {
 int cedula; 
 char nombre[50]; 
 char apellido[50]; 
 char sexo[1]; 
 struct Fecha fecha_nacimiento; 
 long int telefono; 
};

int final= -1;
struct persona  pila[LONG];

/*prototipo de funciones */
int crearpilar();
void apilar();
void desapilar();
void mostrarPILA();
void menuMAIN();

/*Funcion inicial*/
int main (void){

textcolor (LIGHTGREEN);
menuMAIN();

    return 0;

}
/*Funcion encargada del menu principal*/
void menuMAIN(){
	char opcion;
	do{
	
	puts("\t\tMENU");
	puts("\t[1] CREAR LA PILA\n");
	puts("\t[2] APILAR\n");
	puts("\t[3] DESAPILAR\n");
	puts("\t[4] MOSTRAR LO QUE TIENE LA PILA\n");
	puts("\t[5] SALIR\n");
	printf("\t->");
 opcion = getch();
	
	switch(opcion){
		
		case '1':{
			clrscr();
			crearpilar();
			break;
		}
		
		case '2':{
		clrscr();
		apilar();
			break;
		}
		case '3':{
			clrscr();
			desapilar();
			
			break;
		}
		case '4':{
			clrscr();
			mostrarPILA();
			break;
			
	}
	case '5':{
		exit(-1);
		break;
	}
	default:{
		puts("Opcion incorrecta");
		
		break;
	}
}} while (opcion == '1' || opcion == '2' || opcion == '3' || opcion == '4');
}

/*Funcion que agrega un nuevo elemento a la pila*/
void apilar(){
	
	char opc;
	
	if (final<=LONG){
		do{
			final++;
			
puts("\tINSERTE LA INFORMACION DE LAS PERSONAS");
printf("Nombre:");
gets(pila[final].nombre);
printf("\n");
printf("Apellido:");
gets(pila[final].apellido);
printf("\n");
printf("Cedula:");
scanf("%d", &pila[final].cedula);
printf("Fecha de nacimiento\n");
printf("Dia:");
scanf("%d",&pila[final].fecha_nacimiento.dia);
printf("\nMes:");
scanf("%d",&pila[final].fecha_nacimiento.mes);
printf("\nAño:");
scanf("%d",&pila[final].fecha_nacimiento.anio);
printf("\n Numero telefonico:");
scanf("%ld", &pila[final].telefono);
printf("\n\t\t GENERO \n Masculino [M] \t Femenino [F]  \t Otro. [X]\n->");
fflush(stdin);
gets(pila[final].sexo);
printf("\n");
			puts("Desea agregar otro elemento? [Y] [N]");
			opc =getch();
			
		} while(opc == 'Y' || opc == 'y');
	}
}
/*Funcion que crea la pila a base de 20 espacion*/
int crearpilar(){
	
int i;
char opcion;

if ( final <LONG){

    puts("\t\t LA PILA SE PUEDE LLENAR\n\t--------------------------------------------");
        for (i=0; i<LONG && final<LONG; i++ ){

puts("\tINSERTE LA INFORMACION DE LAS PERSONAS");
printf("Nombre:");
gets(pila[i].nombre);
printf("\n");
printf("Apellido:");
gets(pila[i].apellido);
printf("\n");
printf("Cedula:");
scanf("%d", &pila[i].cedula);
printf("Fecha de nacimiento\n");
printf("Dia:");
scanf("%d",&pila[i].fecha_nacimiento.dia);
printf("\nMes:");
scanf("%d",&pila[i].fecha_nacimiento.mes);
printf("\nAño:");
scanf("%d",&pila[i].fecha_nacimiento.anio);
printf("\n Numero telefonico:");
scanf("%ld", &pila[i].telefono);
printf("\n\t\t GENERO \n Masculino [M] \t Femenino [F]  \t Otro. [X]\n->");
fflush(stdin);
gets(pila[i].sexo);
printf("\n");

 final++;
 
 puts("Desea limitar la pila?  [Y] [N]");
 opcion=getch();
 
      if (opcion == 'Y' || opcion == 'y'){
      	break;
	  } else 
	  continue;
        }
} else{
	textcolor(RED);
printf("\t      ERROR!\n\tLa pila esta vacia\n\tPor favor llenela\n");	
    return -1;
    
}
puts("la pila se ha llenado con excito!");
system("pause");
clrscr();
}

void desapilar(){ 
	
	if(final>=0){
		final--;
		puts("se ha eliminado un elemento de la pila");
		printf ("el usuario eliminado fue  %s\n", pila[final+1].nombre);
		
	} else {
printf("\t      ERROR!\n\tLa pila esta vacia\n\tPor favor llenela\n");	
	}
	system("pause");
clrscr();
}

void mostrarPILA(){
	
	int i;
	
	if (final ==-1){
printf("\t      ERROR!\n\tLa pila esta vacia\n\tPor favor llenela\n");	
			system("pause");
			clrscr();
	} else {
		
		for (i=0; i<final+1; i++){
			printf("\t\t LUGAR DE LA PILA %d\n",i+1);
			printf("Nombre: %s %s\n",pila[i].nombre,pila[i].apellido);
			printf("Genero: %s\n",pila[i].sexo);
			printf("Fecha de nacimiento: %d/%d/%d\n",pila[i].fecha_nacimiento.dia,pila[i].fecha_nacimiento.mes,pila[i].fecha_nacimiento.anio);
			printf("Cedula: %d\n",pila[i].cedula);
			printf("Numero telefonico: %ld\n",pila[i].telefono);
		}
		
	}
		
}
