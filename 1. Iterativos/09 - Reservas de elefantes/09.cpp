// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

using lli = long long int;

void resolver(vector<int> const &nacimientos, vector<lli> &sol)
{
    sol[0] = 0;
    for (int i = 0; i < sol.size(); i++)
        sol[i] = sol[i - 1] + nacimientos[i - 1];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    int p, u, n, m, num;

    // Leer los datos de la entrada
    cin >> p >> u;
    if (p == 0 && u == 0)
        return false;
    n = u - p + 1;

    vector<lli> sol(n + 1);
    vector<int> nacimientos(n);
    for (int &i : nacimientos)
        cin >> i;

    cin >> m;

    // Resolver problema
    resolver(nacimientos, sol);

    // Escribir sol
    for (int i = 0; i < m; i++)
    {
        int f1, f2;
        cin >> f1 >> f2;
        cout << sol[f2 - p + 1] - sol[f1 - p] << endl;
    }
    
    cout << "---" << endl;

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
