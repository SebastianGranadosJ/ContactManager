// Online C++ compiler to run C++ program online
#include <iostream>
#include <fstream>
using namespace std;
int main() {
	//Leer multiples lineas
	ifstream entrada;
	entrada.open("archivo.txt");
	char linea[90];
	entrada.getline(linea,80);
	cout<<linea<<endl;
	entrada.close();
}
