// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void resolver(vector<int> const &v, int k, int &maxDesnivel, int &ini, int &mismo)
{
    int desnivelAct = 0;
    for (int i = 0; i < k; i++)
        desnivelAct += v[i];
    maxDesnivel = desnivelAct;
    for (int i = k; i < v.size(); i++)
    {
        desnivelAct -= v[i - k];
        desnivelAct += v[i];
        if (desnivelAct > maxDesnivel)
        {
            maxDesnivel = desnivelAct;
            ini = i - k + 1;
            mismo = ini;
        }
        else if (desnivelAct == maxDesnivel)
            mismo = i - k + 1;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    int n, k;
    int maxDesnivel = 0, ini = 0, mismo = 0;

    // Leer los datos de la entrada
    cin >> n >> k;
    if (n == 0 && k == 0)
        return false;

    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    // Resolver problema
    resolver(v, k, maxDesnivel, ini, mismo);

    // Escribir sol
    cout << maxDesnivel << ' ' << ini << ' ' << mismo << endl;

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
