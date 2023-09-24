#include <iostream>
#include <fstream>
using namespace std;
void pasar_mayusculas(char cadena[]);
int main(){
	char cadena[256];
	ifstream leer;
	ofstream escribir;
	escribir.open("archivo2.txt");
	leer.open("archivo.txt");
	while (!leer.eof()){
		leer.getline(cadena, 256);
		pasar_mayusculas(cadena);
		escribir<<cadena<<endl;
	}
	escribir.close();
	leer.close();
	
	return 0;
}
void pasar_mayusculas(char cadena[]){
	int i = 0;
	while(cadena[i]){
		cadena[i] = toupper(cadena[i]);
		i++;
	}
}
