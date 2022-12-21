// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void escribirSol(vector<char> const &v)
{
    for (char c : v)
        cout << c;
    cout << endl;
}

// Calcula de forma recursiva las variaciones de los elementos
void variaciones(int m, int n, int k, vector<char> &sol)
{
    for (char i = 'a'; i < 'a' + m; ++i)
    {
        sol[k] = i;
        if (k == n - 1) // Si es solución, la escribimos
            escribirSol(sol);
        else // Si no, seguimos completando la solución
            variaciones(m, n, k + 1, sol);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    int m, n;

    // Leer los datos de la entrada
    cin >> m >> n;

    if (!cin) // Fin de la entrada
        return false;

    vector<char> sol(n);

    // Resolver problema
    variaciones(m, n, 0, sol);
    cout << endl;

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
