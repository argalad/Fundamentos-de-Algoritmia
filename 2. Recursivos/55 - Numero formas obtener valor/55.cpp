// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

using tMatriz = vector<vector<int>>;

int sumaDeValores(vector<int> const &v, tMatriz matriz, int s, int i, int suma)
{
    if (s == 0)
        return 1;
    else if (v.size() == 0 || suma > s)
        return 0;
    else if (i == 0 && s > 0)
        return s == suma;
    else
    {
        int iz = 0, der = 0;
        if (v[i - 1] + suma == s)
            iz = 1;
        else if (v[i - 1] + suma <= s)
        {
            if (matriz[i - 1][v[i - 1] + suma] == -1)
            {
                matriz[i - 1][v[i - 1] + suma] = sumaDeValores(v, matriz, s, i - 1, v[i - 1] + suma);
                iz = matriz[i - 1][v[i - 1] + suma];
            }
        }

        if (suma == s)
            der = 1;
        else
        {
            if (matriz[i - 1][suma] == -1)
            {
                matriz[i - 1][suma] = sumaDeValores(v, matriz, s, i - 1, suma);
                der = matriz[i - 1][suma];
            }
        }
        return matriz[i][suma] = iz + der;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    int n, s;

    // Leer los datos de la entrada
    cin >> n >> s;
    if (!cin) // Fin de la entrada
        return false;

    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    tMatriz matriz(n + 1, vector<int>(s + 1, -1));

    // Resolver problema y escribir sol
    cout << sumaDeValores(v, matriz, s, n, 0) << endl;

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
