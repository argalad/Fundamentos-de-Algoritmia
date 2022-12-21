// NOMBRE Y APELLIDOS 
// 

// Comentario general sobre la solucion,
// explicando como se resuelve el problema


#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//ESPECIFICA la funcion que resuelve el problema
//Precondicion: 

int resolver(vector<int> const& v, int k) {
	int r;
	//Aqui tu codigo
    //...
	//Funcion de cota 
	//Invariante
	return r;
	}
	
//Postcondicion:
	

//Analisis justificado del coste: 


// Esta funcion resuelve un caso de prueba
void resuelveCaso() {
	int numElems = 0;
	int tope;
	cin >> numElems >> tope ;
	vector<int> v(numElems);
	for (int& i : v) cin >> i;
	int sol = resolver(v, tope);
	cout << sol << "\n";
}

int main() {
	// Para la entrada por fichero
#ifndef DOMJUDGE
	ifstream in("sample1.in");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

#ifndef DOMJUDGE 
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
