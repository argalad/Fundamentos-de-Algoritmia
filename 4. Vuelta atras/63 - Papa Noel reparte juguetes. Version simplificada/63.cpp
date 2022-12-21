// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void escribirSolucion(vector<int> const &sol)
{
    for (int i : sol)
        cout << i << " ";
    cout << endl;
}

bool esValida(vector<string> const &tiposJuguetes, int k, vector<int> const &sol)
{
    if (k % 2 != 0)
    {
        if (tiposJuguetes[sol[k - 1]] == tiposJuguetes[sol[k]])
            return false;
        else if (sol[k - 1] > sol[k])
            return false;
    }

    return true;
}

void repartir(int n, vector<string> const &tiposJuguetes, int k, vector<int> &sol, bool &haySol)
{
    for (int i = 0; i < n; i++)
    {
        sol[k] = i;
        if (esValida(tiposJuguetes, k, sol))
        {
            if (k == sol.size() - 1)
            {
                escribirSolucion(sol);
                haySol = true;
            }
            else
                repartir(n, tiposJuguetes, k + 1, sol, haySol);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    int n, m;
    bool haySol;

    // Leer los datos de la entrada
    cin >> m >> n;

    if (!cin) // Fin de la entrada
        return false;

    vector<string> tiposJuguetes(m);
    for (string &s : tiposJuguetes)
        cin >> s;
    vector<int> sol(n * 2);

    // Resolver problema
    repartir(n, tiposJuguetes, 0, sol, haySol);

    if (!haySol)
        cout << "SIN SOLUCION" << endl;

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
