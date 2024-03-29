#include <iostream>
#include<conio.h>
#include<stdio.h>
#include <stdlib.h>

using namespace std;
//crear una estructura
struct nodo{
       int numero;       
       struct nodo *punteroSiguiente;
};
// crear un tipo de datos
typedef struct nodo *Tlista;

//Insertar un elemento en la posicion inicial
void insertarInicio(Tlista &lista, int valor){
    Tlista primerNodo;
    primerNodo = new(struct nodo);
    primerNodo->numero = valor;
    primerNodo->punteroSiguiente = lista;
    lista  = primerNodo;
}

void mostrarNumerosDeLista(Tlista lista){
	int indice = 0;
    while(lista != NULL)
     {
          cout <<' '<< indice+1 <<") " << lista->numero << endl;
          lista = lista->punteroSiguiente;
          indice++;
     }
}
/*
void mostrarElementos(Tlista *lista){
	Tlista *actual = new Tlista;
	actual = lista;

 	while(actual !=NULL){
 		cout<<actual->numero;
 		actual = actual->punteroSiguiente;
 }
}



}
*/
void mostrarOpcionesDelMenu(){
    cout<<"\n\t\tLISTA ENLAZADA SIMPLE\n\n";
    cout<<" 1. INSERTAR AL INICIO               "<<endl;
    cout<<" 2. Mostrar Lista 					"<<endl;				
    cout<<" 8. SALIR                            "<<endl;
    cout<<"\n INGRESE OPCION: ";
}

int obtenerOpcionDelMenuIngresadaPorUsuario(){
	int opcion;
	cout<<"INGRESE LA OPCION "<<endl;
	cin>>opcion;
	return opcion;
}
int obtenerNumeroIngresadoPorElUsuario()
{
	int numero;
	cout<<" numero a insertar "<<endl;
	cin>>numero;
	
	return numero;
}


/*                        Funcion Principal
---------------------------------------------------------------------*/
int main()
{
    Tlista lista = NULL;
    int opcionMenu, numero,  pos;   

    system("color 0b");
    do
    {
        mostrarOpcionesDelMenu();
        opcionMenu=obtenerOpcionDelMenuIngresadaPorUsuario();

        switch(opcionMenu)
        {
            case 1:
                 numero=obtenerNumeroIngresadoPorElUsuario();
                 insertarInicio(lista, numero);
            case 2: mostrarNumerosDeLista(lista);
			break;
        }

        cout<<endl<<endl;
        system("pause");  system("cls");

    }while(opcionMenu!=8);


   system("pause");
   return 0;
}
