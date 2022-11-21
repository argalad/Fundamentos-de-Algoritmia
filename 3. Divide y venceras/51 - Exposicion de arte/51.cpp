// Nombre y Apellidos: Alberto Rodr�guez - Rabad�n Manzanares
// N�mero de juez: 77

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int galeriaArte(vector<int> const &pesos, int viajes, int ini, int fin)
{
    if (ini == fin)
        return ini;
    else
    {
        int mitad = (ini + fin) / 2;
        int v = 1, p = pesos[0];
        for (int i = 1; i < pesos.size(); ++i)
        {
            if (p + pesos[i] <= mitad)
                p += pesos[i];
            else
            {
                ++v;
                p = pesos[i];
            }
        }
        if (v <= viajes) return galeriaArte(pesos, viajes, ini, mitad);
        else return galeriaArte(pesos, viajes, mitad + 1, fin);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso()
{
    int n, v;

    // Leer los datos de la entrada
    cin >> n >> v;
    if (n == 0 && v == 0)
        return false;

    vector<int> p(n);
    int min = 0, maxi = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i];
        if (p[i] > min) min = p[i];
        maxi += p[i];
    }

    // Resolver problema
    int sol = galeriaArte(p, v, min, maxi);

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

