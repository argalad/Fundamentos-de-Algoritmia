// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

using tMatriz = vector<vector<int>>;

int sumaDeValores(vector<int> const &v, tMatriz matriz, int s, int i, int suma)
{
    if (s == 0) return 1;
    else if (v.size() == 0) return 0;
    else if (i == 0 && s > 0) return s == suma;
    else
    {
        if (suma > s) return 0;
        else 
        {
            
        }
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
    for(int &i : v) cin >> i;

    tMatriz matriz(n + 1, vector<int>(s + 1, - 1));

    // Resolver problema y escribir sol
    cout << sumaDeValores(v) << endl;

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
