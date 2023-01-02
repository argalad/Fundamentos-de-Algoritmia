// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int resolver(vector<int> const &puntuaciones, int l)
{
    int p = 0, u = 1;
    int suma = puntuaciones[0];
    int maxSuma, sol = 0;

    while (u < p + l)
        suma += puntuaciones[u++];

    maxSuma = suma;

    while (u < puntuaciones.size())
    {
        suma -= puntuaciones[p++];
        suma += puntuaciones[u++];
        if (suma >= maxSuma)
        {
            maxSuma = suma;
            sol = p;
        }
    }
    return p;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    int n, l;

    // Leer los datos de la entrada
    cin >> n >> l;
    if (n == 0 && l == 0)
        return false;

    vector<int> puntuaciones(n);
    for (int &i : puntuaciones)
        cin >> i;

    // Resolver problema
    int sol = resolver(puntuaciones, l);

    // Escribir sol
    cout << sol << endl;

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
