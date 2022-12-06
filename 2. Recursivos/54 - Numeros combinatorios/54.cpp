// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

using tMatriz = vector<vector<int>>;

int numerosCombinatorios(int n, int m, tMatriz &matriz)
{
    if (m == 0 || m == n)
        return matriz[n][m] = 1;
    else if (m == 1 || m == n - 1)
        return matriz[n][m] = n;
    else
    {
        if (matriz[n - 1][m - 1] == -1)
            matriz[n - 1][m - 1] = numerosCombinatorios(n - 1, m - 1, matriz);
        if (matriz[n - 1][m] == -1) 
            matriz[n- 1][m] = numerosCombinatorios(n -1, m, matriz);

        return matriz[n][m] = matriz[n - 1][m - 1] + matriz[n - 1][m];
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    int n, m;

    // Leer los datos de la entrada
    cin >> n >> m;

    if (!cin) // Fin de la entrada
        return false;

    tMatriz matriz(n + 1, vector<int>(m + 1, -1));

    // Resolver problema y escribir sol
    cout << numerosCombinatorios(n, m, matriz) << endl;

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
