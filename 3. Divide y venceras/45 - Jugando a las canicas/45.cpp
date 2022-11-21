// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/*
Recurrencia

T(n) = c1              si n == 2
T(n) = 2T(n/2) + c2    si n >= 4

Coste
    O(n)
*/

struct jugador
{
    string nombre;
    int canicas;
};

jugador torneoCanicas(vector<jugador> const &v, int ini, int fin)
{
    if (ini + 2 == fin)
    {
        if (v[ini].canicas >= v[ini + 1].canicas)
            return {v[ini].nombre, v[ini].canicas + v[ini + 1].canicas / 2};
        else
            return {v[ini + 1].nombre, v[ini + 1].canicas + v[ini].canicas / 2};
    }

    int mitad = (ini + fin) / 2;
    jugador ganadorIz = torneoCanicas(v, ini, mitad);
    jugador ganadorDer = torneoCanicas(v, mitad, fin);
    if (ganadorIz.canicas >= ganadorDer.canicas)
        return {ganadorIz.nombre, ganadorIz.canicas + ganadorDer.canicas / 2};
    else
        return {ganadorDer.nombre, ganadorDer.canicas + ganadorIz.canicas / 2};
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    int n, canicas;
    string nombre;

    // Leer los datos de la entrada
    cin >> n;
    if (!cin) // Fin de la entrada
        return false;
    vector<jugador> v;
    for (int i = 0; i < n; i++)
    {
        cin >> nombre >> canicas;
        v.push_back({nombre, canicas});
    }

    // Resolver problema
    auto sol = torneoCanicas(v, 0, v.size());
    // Escribir sol
    cout << sol.nombre << " " << sol.canicas << endl;

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
