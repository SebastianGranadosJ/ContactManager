// Online C++ compiler to run C++ program online
#include <iostream>
#include <fstream>
using namespace std;

struct persona{
	char nombre[8];
	int edad;
	
};
int main() {
	//Un archivo binario guarda las cosas tal cual se guardarian
	// en la memoria
	persona p = {"Tormen", 14};
	persona p2 = {"Catatre", 63};
	ofstream salida;
	salida.open("data.bin", ios::binary); // .bin  de que es binario
	                         //abrirlo en modo binario
	                         
	/**
	EL PROCESO DE ESCRITURA ES 
	   DESDE MEMORIA -----> AL ARCHIVO
	     (Es byte por byte)
	     1. desde que punto de la memoria pasara info
	     2. Cuantos bytes voy a pasar.
	     
	
	**/
	//con sizeof() puedo saber el tamaño el bytes
	
	cout<<sizeof(persona)<<endl;
	//escribir en binario 1. un puntero de tipo char que guarde el byte de unucuio
	// 2do. parametro cuantos bytes.
	salida.write((char*)&p, sizeof(persona));
	salida.write((char*)&p2, sizeof(persona));
	 // con el primer parametro convierto la direccion de memoria de persona, que tipo persoan a tipo char que es como me lo pide el formato
	// con el segundo pongo el tampo en bites de persona
	
	salida.close();
}
