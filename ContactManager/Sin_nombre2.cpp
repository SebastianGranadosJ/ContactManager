// Online C++ compiler to run C++ program online
#include <iostream>
#include <fstream>
using namespace std;

struct persona{
	char nombre[8];
	int edad;
	
};
int main() {
	persona p, p1;
	ifstream lectura;
	                         
	/**
	EL PROCESO DE LECTURA BINARIO ES 
	   DESDE el archivo -----> a la memoria
	     (Es byte por byte)
	     1. A que punto de la memoria voy a pasar los bytes, siempre lee desde el inicio
	     2. Cuantos bytes voy a pasar.
	     
	
	**/
	lectura.open("data.bin", ios::binary);

	while(lectura.read((char*)&p, sizeof(persona))){ //estoy diciendo, mientras pueda leer
		cout<<p.nombre<<endl;
		cout<<p.edad<<endl;
	}
	
	lectura.close();
	return 0;	

}
