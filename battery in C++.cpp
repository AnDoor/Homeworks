//programa que ordena, agrega y elimina pilas
/* ANDREW PUERTA
   C.I: 30.857.308
   SECCION 02 / TEC.Programacion II*/
   
/* Se pide realizar un programa que cree una pila de productos comestibles (frutas)
   el programa debe crear una pila, agregar productos, eliminar la pila y mostrar 
   los productos de la pila*/
   
#include <iostream> 
#include <conio.h>

#define TAM_PILA 50 //longitud de la pila
#define TAM_PRO 3 //longitud de los productos

using namespace std;

/* estructura de datos de los productos */

struct producto {
int codigo;
char descripcion[41];
float precio;};
	
struct producto frutas[TAM_PRO];

/* estructura de datos de la pila*/
struct PILA {
	int fin;
    int elementos[TAM_PILA];
 
};

struct PILA pila;

/* Funcion que genera un menu de inicio*/
void MENU();

/* funcion que inicia la pila */
void INICIO(){
	pila.fin=-1;
	for (int i=0; i<TAM_PILA;i++){
		pila.elementos[i]=0;
		
	}
}

/* funcion para saber si la pila esta vacia o no*/

bool vacio(){

return pila.fin == -1;
}

/* funcion para saber si la pila se encuentra llena o no*/
bool PilaLLENA(){
	return pila.fin== TAM_PILA-1;
	
}
/* Funcion que ayuda a agregar los productos a la pila para que se llene*/
void llenarPILA(struct producto n){


if (PilaLLENA()){
	cout<<"La pila esta llena"<<endl;
	
}	else {
	pila.fin++;
	pila.elementos[pila.fin] =n.codigo;
	
			pila.elementos[pila.fin] =n.precio;
	for (int i=0; i<3;i++){
		cout<<"\tProducto "<<i<<endl;
		cout<<"CODIGO"<<endl;
		cin>>frutas[i].codigo;
			cout<<"Descripcion"<<endl;
				cin>>frutas[i].descripcion;
				cout<<"Precio"<<endl;
				cin>>frutas[i].precio;
	}
}
}
/* funcion que ayuda a eliminar productos de la pila*/
int eliminar(){
	if (vacio()){
		cout<<"Pila vacia"<<endl;
		
	}else {
		int tmp = pila.elementos[pila.fin];
		pila.elementos[pila.fin] =0;
		pila.fin--;
	}
}
/* funcion que muestra en pantalla los productos ingresados*/
void imprimir(){
	if(vacio()){
		cout<<"Pila vacia"<<endl;
	}else{
	
	for (int i=0; i<=TAM_PRO; i++){
		
		cout<<"Pila ["<<i<<"] "<<endl;
		cout<<"CODIGO: "<<frutas[i].codigo<<endl;
			cout<<"DESCRIPCION: "<<frutas[i].descripcion<<endl;
				cout<<"PRECIO: $"<<frutas[i].precio<<endl;
	}
}
}
int main (void){

textcolor(YELLOW);
	MENU();
	
	
	return 0;
}

void MENU(){
		char opcion;
		do{
		cout<<"\t\t  MENU\n\t------------------------"<<endl;
	cout<<"\t1. llenar pila\n";
	cout<<"\t2. Eliminar todos los elementos de la pila\n";
	cout<<"\t3. Mostrar un elemento de la pila\n";
	cout<<"\t4. salir\n";
	cout<<"\t-> ";
	opcion =getch();
	
	switch(opcion){
		
		case '1':{
			clrscr();
			INICIO();
				llenarPILA(*frutas);
	
			cout<<"La pila se lleno con excito\n";
			break;
		}
		case '2':{
				clrscr();
			eliminar();
			
			break;
			
			
		}
		case '3':{
			clrscr();
			
				imprimir();
				
				break;
			}
			case '4':{
					clrscr();
				exit(0);
				
				break;
			}
	}
	} while (opcion == '1' || opcion =='2' || opcion =='3' || opcion=='4');
}
