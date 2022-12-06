// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

pair<int, bool> esCaucasico(vector<int> const &v, int ini, int fin)
{
    if (ini + 1 == fin)
    {
        if (v[ini] % 2 == 0)
            return {1, true};
        else
            return {0, true};
    }
    else
    {
        int mitad = (ini + fin) / 2;

        pair<int, bool> iz = esCaucasico(v, ini, mitad);
        pair<int, bool> der = esCaucasico(v, mitad, fin);

        if (abs(iz.first - der.first) <= 2 && iz.second && der.second)
            return {iz.first + der.first, iz.second && der.second};
        else
            return {iz.first + der.first, false};
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
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

    // Resolver problema
    pair<int, bool> sol = esCaucasico(v, 0, v.size());

    // Escribir sol
    (sol.second) ? cout << "SI" << endl : cout << "NO" << endl;

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
