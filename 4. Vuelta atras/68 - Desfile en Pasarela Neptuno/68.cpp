// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void asignarCombinaciones(vector<vector<int>> trajes, vector<vector<int>> zapatos, int n, int k)
{

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    int n; // Número de modelos, trajes y zapatos

    // Leer los datos de la entrada
    cin >> n;

    vector<vector<int>> trajes(n, vector<int>(n));
    vector<vector<int>> zapatos(n, vector<int>(n));

    for (vector<int> &i : trajes)
        for (int &j : i)
            cin >> j;

    for (vector<int> &i : zapatos)
        for (int &j : i)
            cin >> j;
    
    // Resolver problema
    

    // Escribir solución
}

int main()
{
    // Ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casos.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

        // Para dejar todo como estaba al principio
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
