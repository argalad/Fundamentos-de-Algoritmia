//NOMBRE Y APELLIDOS

// Comentario general sobre la solucion,
// explicando como se resuelve el problema

// Definicion del espacio de soluciones y del arbol de exploracion


#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct tDatos { // Datos de entrada
	int numPlazas, numCom;
	vector<vector<float>> distancias; 
	vector<vector<bool>> allegados; 
	
	// constructor
	tDatos(int pl, int com) : numPlazas(pl), numCom(com),
			distancias(pl, vector<float>(pl)), allegados(com, vector<bool>(com)){
	};
};

const float seguridad = 2; //distancia de seguridad

// IMPLEMENTACION DEL ALGORITMO DE VUELTA ATRAS
// Explicaciones detalladas sobre la implementacion 
// Indicacion de los marcadores utilizados

// PODAS DE OPTIMALIDAD



void resuelveCaso()
{
	// LECTURA DE LOS DATOS DE ENTRADA 
	int numPlazas, numCom;
	cin >> numPlazas >> numCom;
	tDatos d(numPlazas, numCom);
	for (int i = 0; i < numPlazas; ++i) {
		for (int j = 0; j < numPlazas; j++){
		cin >> d.distancias[i][j]; 
		}
	}

	int aux;
	for (int i = 0; i < numCom; ++i) {
		for (int j = 0; j < numCom; j++){
			cin >> aux;
			d.allegados[i][j] = aux == 1;
		}
	}


	//CALCULO Y ESCRITURA DEL RESULTADO

	// Inicializa para hacer la llamada

	int mejorParejas; 
	bool exito;
	//...

	// Llama aqui a tu funcion
	
	if (exito)
	{
		cout << "PAREJAS " << mejorParejas << "\n";
	}
	else
	{
		cout << "CANCELA\n";
	}
}


int main() {
	// Para la entrada por fichero
#ifndef DOMJUDGE
	ifstream in("sample3.in");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso();

#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}