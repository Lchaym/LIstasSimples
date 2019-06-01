//insertar elementos en la lista y mostrarlos de forma ordenada.
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *punteroSiguiente;
	
};
//prototipos de funciones
void insertarLista(Nodo *&, int);
void mostrarElementos(Nodo *);
void menu();
void buscarEnLista(Nodo*,int);
void eliminarNodo(Nodo *&, int);
void BuscarYModificar(Nodo *, int);
//funicon principal
Nodo *lista=NULL;

int main(){
	
	menu();
	
	getch();
	return 0;
}

void menu(){
	int opcion;
	int dato;
	do{
		cout<<"\t.:MENU:,\n";
		cout<<"1. Insertar elementos a la lsita"<<endl;
		cout<<"2. Mostrar elementos de la lista"<<endl;
		cout<<"3. Buscar un elemento en la lista"<<endl;
		cout<<"4. Eliminar elemnto de la lista"<<endl;
		cout<<"5. Buscar y modificar"<<endl;
		cout<<"6. Salir"<<endl;
		cout<<"Opcion"<<endl;
		cin>>opcion;
		
		switch (opcion){
			case 1: cout<<"\nDigite un numero: ";
					cin>>dato;
					insertarLista(lista,dato);
					cout<<"\n";
					system("pause");
					break;
			case 2: mostrarElementos(lista);
					cout<<"\n";	
					system("pause");
					break;
			case 3: cout<<"Digite un numero: ";
					cin>>dato;
					buscarEnLista(lista, dato);
					cout<<"\n";
					system("pause");
					break;
			case 4: cout<<"\nDigite el elemetno que desea eliminar: ";
					cin>>dato;
					eliminarNodo(lista,dato);
					cout<<"\n";
					system("pause");
					break;
			case 5: cout<<"\nDigite el numero a modificar: ";
					cin>>dato;
					BuscarYModificar(lista, dato);
					cout<<"\n";
					system("pause");
					break;
		}
		system("cls");
	}while(opcion!=6);
}

void insertarLista(Nodo *&lista, int n){ //dos parametos, lista y tipo entero
	Nodo *nuevo_nodo = new Nodo();//crear un nuevo nodo y servar memoria
	nuevo_nodo->dato =n;//asignar al campo dato del nuevo nodo
	
	Nodo *aux1= lista; //crear nodos auxiliares
	Nodo *aux2;
	
	while ((aux1!= NULL) && (aux1->dato<n)){// dos condiciones siempre y cuando
		aux2= aux1;
		aux1 = aux1->punteroSiguiente;
	}
	if(lista == aux1){
		lista = nuevo_nodo;
	}
	else{
		aux2->punteroSiguiente=nuevo_nodo;
	}
	nuevo_nodo->punteroSiguiente = aux1;
	
	
	cout<<"el elemento insertado a la lista correctamente";
}

void mostrarElementos(Nodo *lista){
	int indice=0;
	Nodo *actual = new Nodo;
	actual = lista;

 	while(actual !=NULL){
 		cout<<' '<<indice+1<<" ) "<<actual->dato<<endl; //aca se van imprimiendo los datos a mostrar
 		actual = actual->punteroSiguiente;
 		indice++;
 }
}

void buscarEnLista(Nodo *lista, int n){
	bool band = false;
	
	Nodo *actual = new Nodo();
	actual = lista;
	
	while((actual !=NULL)&&(actual->dato <=n)){
		if(actual->dato==n){
			band = true;
		}
		actual = actual->punteroSiguiente;
	}
	if(band==true){
		cout<<"El elemeneto "<<n<<"Si a sido encontrado"<<endl;
	}
	else{
		cout<<"El elemento "<<n<<"No a sido encontrado"<<endl;
	}
}

void eliminarNodo(Nodo *&lista, int n){
	if( lista != NULL){//preguntar si la lista no esta vacia
		Nodo *aux_borrar;
		Nodo *anterior = NULL;

		aux_borrar = lista;
		//recorrer la lista
		while((aux_borrar != NULL) && (aux_borrar->dato !=n)){
				anterior = aux_borrar;
				aux_borrar = aux_borrar->punteroSiguiente;
		}
		// El elemento no ha sido encontrado
		if(aux_borrar == NULL){
			cout<<"El elemento no existe";
		}
		//El primer elemento es el que vamos a eliminar
		else if(anterior ==NULL){
			lista = lista->punteroSiguiente;
			delete aux_borrar;
			cout<<"El elemento "<<n<<" a sido eliminado ";
		}
		// El elemento esta en la lista pero, no es el primer nodo
		else{
			anterior->punteroSiguiente = aux_borrar->punteroSiguiente;
			delete aux_borrar;
			cout<<"El elemento "<<n<<" a sido eliminado";
		}
	}
}

void BuscarYModificar(Nodo *lista, int buscar){
    bool encontrado = false;

        while ((lista != NULL ) && ( encontrado != true)){
            if(lista->dato == buscar){
                cout<<"Ingrese dato a modificar"<<endl;
                cin>>lista->dato;
                encontrado = true;
            }
            lista = lista->punteroSiguiente;
        }
        if(!encontrado){
            cout<<"Dato  no encontrado"<<endl;
        }else{
            cout<<"Dato Modificado"<<endl;
        }
}

