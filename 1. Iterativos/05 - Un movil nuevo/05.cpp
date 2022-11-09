// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// O(n), recorremos los vectores una vez
vector<int> resolver(vector<int> const &v, vector<int> const &u)
{
    int i = 0, j = 0;
    vector<int> sol;

    while (i < v.size() && j < u.size())
    {
        if (v[i] < u[j])
            sol.push_back(v[i++]);
        else if (u[j] < v[i])
            sol.push_back(u[j++]);
        else
        {
            sol.push_back(v[i]);
            i++;
            j++;
        }
    }

    while (i < v.size())
        sol.push_back(v[i++]);
    while (j < u.size())
        sol.push_back(u[j++]);

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    int n1, n2;
    vector<int> sol;

    // Leer los datos de la entrada
    cin >> n1 >> n2;

    vector<int> v1(n1);
    for (int &i : v1)
        cin >> i;

    vector<int> v2(n2);
    for (int &i : v2)
        cin >> i;

    // Resolver problema
    sol = resolver(v1, v2);

    // Escribir solución
    for (auto n : sol)
        cout << n << " ";

    cout << endl;
}

int main()
{
    // Ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casos.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

        // Para dejar todo como estaba al principio
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
