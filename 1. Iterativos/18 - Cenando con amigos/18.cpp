// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void resolver(vector<int> const &v, int &suma, int &dia, int &lon)
{
    int sumaAct = 0, sumaMax = 0, ultMax = 0, lonAct = 0;
    suma = 0, dia = 0, lon = 0;

    for (int i = 0; i < v.size(); i++)
    {
        sumaAct += v[i];
        if (sumaAct > 0)
        {
            lonAct++;
            if (sumaMax < sumaAct || (sumaMax == sumaAct && lonAct < lon))
            {
                sumaMax = sumaAct;
                ultMax = i;
                lon = lonAct;
            }
        }
        else
        {
            sumaAct = 0;
            lonAct = 0;
        }
    }
    suma = sumaMax;
    dia = ultMax - lon + 1;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    int n;
    int suma, dia, lon;
    // Leer los datos de la entrada
    cin >> n;
    if (!cin) // Fin de la entrada
        return false;

    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    // Resolver problema
    resolver(v, suma, dia, lon);

    // Escribir sol
    cout << suma << ' ' << dia << ' ' << lon << endl;

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
