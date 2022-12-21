// NOMBRE Y APELLIDOS 
// 

// Comentario general sobre la solucion,
// explicando como se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


//Implementa la funcion recursiva

//Analisis justificado del coste de esta funcion recursiva 


bool resolver(vector<int> const& v)
//Esta funcion determina si v es extraño
{
	//Invoca aqui a tu funcion recursiva
}


void resuelveCaso() {
	int n = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
			cin >> v[i];
	if (resolver(v))
		cout << "SI\n";
	else
		cout << "NO\n";
}

int main() {
	// Para la entrada por fichero
#ifndef DOMJUDGE
	ifstream in("sample2.in");
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

