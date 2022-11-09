// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Coste lineal, recorremos cada vector una vez
void resolver(vector<int> const &v, vector<int> const &u, vector<int> &sol)
{
    int i = 0, j = 0;

    while (i < v.size() && j < u.size())
    {
        if (v[i] < u[j])
            sol.push_back(v[i++]);
        else if (u[j] < v[i])
            sol.push_back(u[j++]);
        else
        {
            i++;
            j++;
        }
    }

    while (i < v.size())
        sol.push_back(v[i++]);
    while (j < u.size())
        sol.push_back(u[j++]);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    int num;
    vector<int> v, u, sol;

    // Leer los datos de la entrada
    cin >> num;
    while (num != 0)
    {
        v.push_back(num);
        cin >> num;
    }

    cin >> num;
    while (num != 0)
    {
        u.push_back(num);
        cin >> num;
    }
    // Resolver problema
    resolver(v, u, sol);
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
