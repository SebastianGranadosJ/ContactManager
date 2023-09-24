// Online C++ compiler to run C++ program online
#include <iostream>
#include <fstream>
using namespace std;
int main() {
	int n,max;
	ofstream escribir;
	ifstream leer;
	leer.open("archivo.txt", ios::app);
	leer>>n;
	leer.close();
	max = n + 3;
	escribir.open("archivo.txt",ios::app );
	escribir<<endl;
	for( n ; n<= max;n++ ){
		escribir<<"escritura numero: "<<n<<endl;
	}
	escribir<<max;
	escribir.close();
}
