// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void particion(vector<int> &v, int a, int b, int pivote, int &p, int &q)
{
    int k;
    p = a;
    k = a;
    q = b - 1;
    while (k <= q)
    {
        if (v[k] == pivote)
            ++k;
        else if (v[k] < pivote)
            swap(v[p++], v[k++]);
        else
            swap(v[q--], v[k]);
    }
}

void quickSort(vector<int> &v, int ini, int fin)
{
    int p, q;
    if (ini + 1 < fin)
    {
        particion(v, ini, fin, v[ini], p, q);
        quickSort(v, ini, p);
        quickSort(v, q+1, fin);
    }
}

int ordenarNaves(vector<int> &naves, int ini, int fin)
{
    if (ini == fin || ini + 1 == fin) // Caso base
        return 0;
    else
    {
        int mitad = (ini + fin - 1) / 2;
        int iz = ordenarNaves(naves, ini, mitad + 1);
        int der = ordenarNaves(naves, mitad + 1, fin);
        int c = 0, i = ini, j = mitad + 1;

        while (i < mitad && j < fin)
        {
            if (naves[i] > naves[j])
            {
                c += (mitad - i + 1);
                j++;
            }
            else
                i++;
        }

        quickSort(naves, ini, fin);
        return c + iz + der;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    int num_naves;

    // Leer los datos de la entrada
    cin >> num_naves;

    if (!cin) // Fin de la entrada
        return false;

    vector<int> v(num_naves);
    for (int &i : v)
        cin >> i;

    // Resolver problema
    int sol = ordenarNaves(v, 0, v.size());

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
