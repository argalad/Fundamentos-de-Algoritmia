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
void variaciones(int m, int n, int k, vector<bool> &marcas, vector<char> &sol)
{
    for (char i = 'a'; i < 'a' + m; ++i)
    {
        sol[k] = i;
        if (!marcas[i - 'a']) // Si la letra no se ha utilizado
        {
            marcas[i - 'a'] = true;
            if (k == n - 1) // Es solución
                escribirSol(sol);
            else // Genera el resto de la solución
                variaciones(m, n, k + 1, marcas, sol);
            marcas[i - 'a'] = false;
        }
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
    vector<bool> marcas(m, false);

    // Resolver problema
    variaciones(m, n, 0, marcas, sol);
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
