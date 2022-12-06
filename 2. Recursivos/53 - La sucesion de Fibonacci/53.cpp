// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>

using namespace std;
using lli = long long int;

lli sucesionFibonacci(int n, int x, lli n1, lli n2)
{
    if (n == x)
        return n2;
    else
        return sucesionFibonacci(n, x + 1, n1 + n2, n1);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    int num;

    // Leer los datos de la entrada
    cin >> num;
    if (!cin) // Fin de la entrada
        return false;

    // Resolver problema y escribir sol
    cout << sucesionFibonacci(num, 0, 1, 0) << endl;

    return true;
}

int main()
{
    // Ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casos.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

        // Para dejar todo como estaba al principio
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
