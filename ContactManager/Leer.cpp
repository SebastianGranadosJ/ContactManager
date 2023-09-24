// Online C++ compiler to run C++ program online
#include <iostream>
#include <fstream>
using namespace std;


int main() {
	
	//Eliminar y renombrar un archivo
	//rename//
	/** if (rename("archivo.txt", "epico.txt") == 0){
		cout<<"Renombrado con exito"; //retorna 0  al hacer la funcion
	}
	else{
		cout<<"no se pudo xd";
	}
	**/
	//remove
	if(remove("epico.txt")==0){
		cout<<"Exitosamente eliminado";
	}
	else{
		cout<<"No se pudo eliminar";
	}
	
	
	return 0;

}
