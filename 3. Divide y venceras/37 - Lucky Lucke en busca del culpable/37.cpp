// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int buscaIz(vector<int> const &v, int altura, int ini, int fin)
{
    if (ini >= fin)
        return ini;
    else if (ini + 1 == fin)
        return ini;
    else
    {
        int mitad = (ini + fin - 1) / 2;
        if (v[mitad] < altura)
            return buscaIz(v, altura, mitad + 1, fin);
        else
            return buscaIz(v, altura, ini, mitad + 1);
    }
}

int buscaDr(vector<int> const &v, int altura, int ini, int fin)
{
    if (ini >= fin)
        return ini;
    else if (ini + 1 == fin)
        return ini;
    else
    {
        int mitad = (ini + fin) / 2;
        if (altura < v[mitad])
            return buscaDr(v, altura, ini, mitad);
        else
            return buscaDr(v, altura, mitad, fin);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    int n, altura;

    cin >> n;

    if (!cin) // Fin de la entrada
        return false;

    cin >> altura;

    // Leer los datos de la entrada
    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    // Resolver problema
    int posIz = buscaIz(v, altura, 0, v.size());
    if (posIz == v.size() || v[posIz] != altura)
        cout << "NO EXISTE" << endl;
    else
    {
        int posDr = buscaDr(v, altura, 0, v.size());
        if (posIz == posDr)
            cout << posIz << endl;
        else
            cout << posIz << " " << posDr << endl;
    }

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
