// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int resolver(vector<int> const &v, int ini, int fin)
{
    if (ini == fin)
        return v[ini];
    else
    {
        int mitad = (ini + fin) / 2;
        
        if (v[mitad] < v[mitad + 1])
        {
            if (mitad == 0 || v[mitad - 1] > v[mitad])
                return v[mitad];
            else
                return resolver(v, ini, mitad - 1);
        }
        else
            return resolver(v, mitad + 1, fin);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    int n;
    // Leer los datos de la entrada
    cin >> n;

    if (!cin) // Fin de la entrada
        return false;

    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    // Resolver problema
    int sol = resolver(v, 0, v.size() - 1);

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
