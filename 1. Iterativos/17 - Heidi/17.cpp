// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> resolver(vector<int> const &v, int l, int &longMax)
{
    vector<int> sol;
    int longAct = 1, maxDerecha = v[v.size() - 1];
    
    for (int i = v.size() - 2; i >= 0; i--)
    {
        if (v[i] > maxDerecha)
        {
            longAct = 1;
            maxDerecha = v[i];
        }
        else if (v[i] == maxDerecha)
            longAct++;
        else
            longAct = 0;

        if (longAct == l) sol.push_back(i + longAct - 1);
        if (longAct > longMax && longAct >= l) longMax = longAct;
    }

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    int n, l, longMax = 0;

    // Leer los datos de la entrada
    cin >> n >> l;
    if (!cin) // Fin de la entrada
        return false;

    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    // Resolver problema
    vector<int> sol = resolver(v, l, longMax);

    // Escribir sol
    cout << longMax << ' ' << sol.size() << ' ';
    for (int i = 0; i < sol.size(); i++)
        cout << sol[i] << ' ';
    cout << endl;

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
