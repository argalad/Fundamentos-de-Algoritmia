// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

bool suficientementeDisperso(vector<int> const &v, int k, int ini, int fin)
{
    if (ini + 1 == fin)
        return true;
    else
    {
        int mitad = (ini + fin) / 2;
        bool iz = suficientementeDisperso(v, k, ini, mitad);
        bool der = suficientementeDisperso(v, k, mitad, fin);
        return der && iz && k <= abs(v[ini] - v[fin - 1]);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    int n, k;

    // Leer los datos de la entrada
    cin >> n;
    if (!cin) // Fin de la entrada
        return false;
    cin >> k;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    // Resolver problema
    bool sol = suficientementeDisperso(v, k, 0, v.size());
    // Escribir sol
    if (sol)
        cout << "SI" << endl;
    else
        cout << "NO" << endl;

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
