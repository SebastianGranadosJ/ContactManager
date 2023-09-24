#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <conio.h>
using namespace std;
const char dir_archivo[] = "contactos.dat";
/**
Agenda
- ingresar contactos
- Buscar contactos
- Ver listado de contactos
- Eliminar un contacto
- Actualizar un contacto
**/
struct contacto{
	char nombre[50];
	char apellido[50];
	int edad;
	char correo[60];
};
///////////            FUNCIONES DEL PROGRAMA                                      //////////
void almacenar_contacto(contacto ); //Mete el contacto en la memeoria
contacto ingresar_contacto(); // pide los datos al usuario del contacto;
void mostrar_contacto(contacto); //Muestra un contacto ingresado
contacto buscar_contacto(char[], char[]); // busca un contacto
void mostrar_listado();
void eliminar_contacto(char[], char[]);
void actualizar_contacto(char[], char[]);

///////// FUNCIONES DEL MENU ///////
void menu_ingresar();
void menu_buscar();
void menu_listado();
void menu_eliminar();
void menu_actualizar();


//////////               MENU                     /////////////////////////////
int main(){
	int opccion;
	
	do{
		system("cls");
		cout<<"\t\t\tAGENDA"<<endl;
		cout<<"\t\t\tIngresar contacto.............[1]"<<endl;
		cout<<"\t\t\tBuscar contacto...............[2]"<<endl;
		cout<<"\t\t\tVer lista de contactos........[3]"<<endl;
		cout<<"\t\t\tEliminar contacto.............[4]"<<endl;	
		cout<<"\t\t\tActualizar contacto...........[5]"<<endl;
		cout<<"\t\t\tCerrar Agenda.................[6]"<<endl;
		cout<<"\t\t\tIngrese un numero segun que accion quiere ejecutar: ";
		cin>>opccion;
		switch(opccion){
			case 1:
				system("cls");
				cin.ignore();
				menu_ingresar();
				break;
			case 2:
				system("cls");
				cin.ignore();
				menu_buscar();
				break;
			case 3:
				system("cls");
				menu_listado();
				break;
			case 4:
				system("cls");
				cin.ignore();
				menu_eliminar();
				break;
			case 5:
				system("cls");
				cin.ignore();
				menu_actualizar();
				break;
			case 6:
				system("cls");
				cout<<"\t\t\tAgenda cerrada"<<endl;
				break;
			default:
				cout<<"\t\t\tIngrese un numero valido"<<endl;
		}
		getch();
	}while(opccion != 6);
	return 0;
}

////////////////////////////////////////
void almacenar_contacto(contacto c){
	ofstream escribir;
	escribir.open(dir_archivo, ios::binary | ios::app);
	escribir.write((char*)&c, sizeof(contacto));
	escribir.close();
}
contacto ingresar_contacto(){
	contacto c;

	cout<<"\t\t\tNombre: ";
	cin.getline(c.nombre, 50);
	cout<<"\t\t\tApeliido: ";
	cin.getline(c.apellido, 50);
	cout<<"\t\t\tEdad: ";
	cin>>c.edad;
	cout<<"\t\t\tCorreo: ";
	cin.ignore();
	cin.getline(c.correo, 60);
	return c;
	
}
void mostrar_contacto(contacto c){
	if(strcmp(c.nombre, "0xf16") == 0){
		cout<<"contacto no encontrado";
	}
	else{
		cout<<"\t\t\tNombre: "<< c.nombre<<endl;
		cout<<"\t\t\tApeliido: "<< c.apellido<<endl;
		cout<<"\t\t\tEdad: "<<c.edad<<endl;
		cout<<"\t\t\tCorreo: "<<c.correo<<endl;
	}
	
}
contacto buscar_contacto(char nombre[], char apellido[]){
	contacto no_encontrado = {"0xf16","0", 0, "0"};
	contacto c;
	ifstream leer;
	leer.open(dir_archivo, ios::binary );
	while(leer.read((char*)&c, sizeof(contacto))){
		if (strcmp(c.nombre, nombre) == 0 && strcmp(c.apellido, apellido) == 0){
			leer.close();
			return c;
		}
	}
	leer.close();
	return no_encontrado;
	
	
}
void mostrar_listado(){
	contacto c;
	ifstream leer;
	leer.open(dir_archivo, ios::binary );
	while(leer.read((char*)&c, sizeof(contacto))){
		cout<<"\t\t\tNombre: "<< c.nombre<<endl;
		cout<<"\t\t\tApeliido: "<< c.apellido<<endl;
		cout<<"\t\t\tEdad: "<<c.edad<<endl;
		cout<<"\t\t\tCorreo: "<<c.correo<<endl;
		cout<<"\t\t\t--------------------------------------"<<endl;
	}
	leer.close();
}
void actualizar_contacto(char nombre[] , char apellido[]){
	contacto c;
	ifstream leer;
	ofstream escribir;
	escribir.open("temp.dat");
	leer.open(dir_archivo, ios::binary);
	int existe = 0;
	while(leer.read((char*)&c, sizeof(contacto))){
		if (strcmp(c.nombre, nombre) == 0 && strcmp(c.apellido, apellido) == 0){
			contacto temp;
			cout<<"\t\t\tUsted desea actualizar el siguiente contato: "<<endl;
			mostrar_contacto(c);
			cout<<"\t\t\tIngrese los nuevos datos del contacto"<<endl;
			temp = ingresar_contacto();
			existe = 1;
			escribir.write((char*)&temp, sizeof(contacto));
		}
		else{
			escribir.write((char*)&c, sizeof(contacto));
		}
	}
	leer.close();
	escribir.close();
	if (existe == 0){
		remove("temp.dat");
		cout<<"\t\t\tEl contacto no existe"<<endl;
	}
	else{
		remove(dir_archivo);
		rename("temp.dat", dir_archivo);
	}
}
void eliminar_contacto(char nombre[] , char apellido[]){
	contacto c;
	ifstream leer;
	ofstream escribir;
	escribir.open("temp.dat");
	leer.open(dir_archivo, ios::binary);
	int existe = 0;
	while(leer.read((char*)&c, sizeof(contacto))){
		if (strcmp(c.nombre, nombre) == 0 && strcmp(c.apellido, apellido) == 0){
			existe = 1;
		}
		else{
			escribir.write((char*)&c, sizeof(contacto));
		}
	}
	leer.close();
	escribir.close();
	if (existe == 0){
		remove("temp.dat");
		cout<<"El contacto no existe"<<endl;
	}
	else{
		remove(dir_archivo);
		rename("temp.dat", dir_archivo);
		cout<<"El contacto ha sido eliminado con exito"<<endl;
	}
}

///////////////////////////////////////

void menu_ingresar(){
	cout<<"\t\t\tINGRESAR CONTACTO NUEVO"<<endl;
	almacenar_contacto(ingresar_contacto());
	cout<<"\t\t\tContacto ingresado con exito"<<endl;
}
void menu_buscar(){
	char nombre[50], apellido[50];
	cout<<"\t\t\tBUSCAR CONTACTO"<<endl;
	cout<<"\t\t\tIngrese el nombre del contacto que desea buscar: ";
	cin.getline(nombre, 50);
	cout<<"\t\t\tIngrese el apellido del contacto que desea buscar: ";
	cin.getline(apellido, 50);
	mostrar_contacto(buscar_contacto(nombre, apellido));
}
void menu_listado(){
	cout<<"\t\t\tLista de contactos: "<<endl;
	cout<<endl;
	mostrar_listado();
}
void menu_eliminar(){
	char nombre[50], apellido[50];
	cout<<"\t\t\tBUSCAR CONTACTO"<<endl;
	cout<<"\t\t\tIngrese el nombre del contacto que desea eliminar: ";
	cin.getline(nombre, 50);
	cout<<"\t\t\tIngrese el apellido del contacto que desea eliminar: ";
	cin.getline(apellido, 50);
	eliminar_contacto(nombre, apellido);
}
void menu_actualizar(){
	char nombre[50], apellido[50];
	cout<<"\t\t\tBUSCAR CONTACTO"<<endl;
	cout<<"\t\t\tIngrese el nombre del contacto que desea actualizar: ";
	cin.getline(nombre, 50);
	cout<<"\t\t\tIngrese el apellido del contacto que desea actualizar: ";
	cin.getline(apellido, 50);
	actualizar_contacto(nombre, apellido);
	
}
