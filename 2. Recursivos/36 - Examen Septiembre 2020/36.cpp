// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>

using namespace std;

bool esInteresante(int num, int sumaDer, int sumaIz)
{
    if (num == 0) return true;
    else if (num / )
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    int num;

    // Leer los datos de la entrada
    cin >> num;
    // Resolver problema
    bool sol = esInteresante(num);
    // Escribir solución
    if (sol)
        cout << "SI" << endl;
    else
        cout << "NO" << endl;
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
