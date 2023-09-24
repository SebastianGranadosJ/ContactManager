#include <iostream>
#include <fstream>
using namespace std;

int main(){
	/// VERIFICAR EL ESTAOD DEL ARCHIVO Y ESTADO DEL FLUJO
	//Estado de flujo es ver que las operaciones hechas desdes
	//el programa al archivo esten siendo de manera efectiva
	
	// bad() -> si es verdadera hubo error y no se pudo hacer todo bien
	//sucede cuando no tenemos permiso para entrar en el archivo o no hay espacio en el disco
	//cuando no existe el archivo
	
	//fail() -> verdadero cuando algo malo sucede pero es un error menor
	// leer un enetero pero solo hay un caracter, no evita al comunicacion, la operacionno fue exitosa
	
	// eof()-> cuando llegemos al final del archivo es verdadera
	
	//good() -> la comunicacion esta en buen estado
	
	ifstream entrada;
	entrada.open("data.txt");
	if(entrada.good()){
		cout<<"Todo piola";
	}
	else{
		cout<<"error xd";
	}
	return 0;	
}
