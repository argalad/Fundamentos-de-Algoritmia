// Nombre y Apellidos: Alberto Rodr�guez - Rabad�n Manzanares
// N�mero de juez: 77

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Recorremos el espacio de posibles soluciones hasta que damos con la adecuada
int viajeAbuelo(vector<int> const &tiempos, int paradas_max, int ini, int fin)
{
    if (ini == fin)
        return ini;
    else
    {
        int mitad = (ini + fin) / 2;
        int paradas = 0, aguante = tiempos[0];
        for (int i = 1; i < tiempos.size(); ++i)
        {
            if (aguante + tiempos[i] <= mitad) // Vamos sumando el tiempo y si superamos la mitad, hacemos parada
                aguante += tiempos[i];
            else
            {
                ++paradas;
                aguante = tiempos[i];
            }
        }

        if (paradas <= paradas_max)
            return viajeAbuelo(tiempos, paradas_max, ini, mitad);
        else
            return viajeAbuelo(tiempos, paradas_max, mitad + 1, fin);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci�n, y escribiendo la respuesta
bool resuelveCaso()
{
    int n, p;

    // Leer los datos de la entrada
    cin >> n >> p;
    if (n == 0 && p == 0)
        return false;

    vector<int> t(n);
    int min = 0, maxi = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> t[i];
        if (t[i] > min)
            min = t[i]; // El tiempo más largo que el abuelo tendría que aguantar entre paradas
        maxi += t[i];   // Total de tiempo sin paradas
    }

    // Resolver problema
    int sol = viajeAbuelo(t, p, min, maxi);

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
