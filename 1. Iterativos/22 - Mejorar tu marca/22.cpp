// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

using pii = pair<int, int>;

// función que resuelve el problema
pii resolver(vector<int> const &v)
{
    int longMax = 0, ult = 0, longAct = 0, maxMarca = v[0];
    pii sol;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] <= maxMarca)
        {
            longAct++;
            if (longAct >= longMax)
            {
                ult = i;
                longMax = longAct;
            }
        }
        else
        {
            longAct = 0;
            maxMarca = v[i];
        }
    }
    sol.first = longMax;
    sol.second = ult - longMax + 1;
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    int n;

    // Leer los datos de la entrada
    cin >> n;
    if (n == 0)
        return false;

    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    // Resolver
    pii sol = resolver(v);

    // Escribir sol
    cout << sol.first << ' ' << sol.second << endl;

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
