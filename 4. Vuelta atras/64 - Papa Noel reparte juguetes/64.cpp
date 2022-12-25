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

bool esValida(vector<int> const &juguetes, vector<string> const &tiposJuguetes, int k, vector<int> const &sumaJ, vector<int> const &sumaS, int satisMin, vector<int> const &sol)
{
    if (k % 2 != 0)
    {
        if (tiposJuguetes[sol[k - 1]] == tiposJuguetes[sol[k]]) // Comprobamos que dos tipos consecutivos no sean iguales
            return false;
        else if (sol[k - 1] > sol[k]) // Comprobamos que los tipos estén en orden
            return false;
        else if (sumaS[k / 2] < satisMin) // Comprobamos que cumple la satisfacción mínima
            return false;
    }

    if (sumaJ[sol[k]] > juguetes[sol[k]]) // Si se han asignado más juguetes de los disponibles
        return false;
    else
        return true;
}

void repartir(vector<int> const &juguetes, vector<string> const &tiposJuguetes, int n, int satisMin, vector<int> const &satisfacciones, int k, vector<int> &sol, vector<int> &sumaJ, vector<int> &sumaS, bool &haySol)
{
    for (int i = 0; i < n; i++)
    {
        sol[k] = i;
        sumaJ[i]++;
        sumaS[k / 2] += satisfacciones[i + (k / 2) * n];

        if (esValida(juguetes, tiposJuguetes, k, sumaJ, sumaS, satisMin, sol)) // Si es válida
        {
            if (k == sol.size() - 1) // Si es solución
            {
                escribirSolucion(sol);
                haySol = true;
            }
            else
                repartir(juguetes, tiposJuguetes, n, satisMin, satisfacciones, k + 1, sol, sumaJ, sumaS, haySol);
        }
        sumaJ[i]--;
        sumaS[k / 2] -= satisfacciones[i + (k / 2) * n];
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    int m;        // Numero de juguetes
    int n;        // Número de niños
    int satisMin; // Satisfacción mínima
    bool haySol = false;

    // Leer los datos de la entrada
    cin >> m >> n >> satisMin;

    if (!cin) // Fin de la entrada
        return false;

    vector<int> juguetes(m); // Vector número de juguetes disponibles
    for (int &i : juguetes)
        cin >> i;
    vector<string> tiposJuguetes(m); // Vector tipos de juguetes
    for (string &s : tiposJuguetes)
        cin >> s;
    vector<int> satisfacciones(m * n); // Vector de satisfacciones por niño
    for (int &j : satisfacciones)
        cin >> j;

    vector<int> sol(n * 2); // Vector solución
    vector<int> sumaJ(m);   // Vector suma de los juguetes
    vector<int> sumaS(n);   // Suma de la satisfacción

    // Resolver problema
    repartir(juguetes, tiposJuguetes, m, satisMin, satisfacciones, 0, sol, sumaJ, sumaS, haySol);

    if (!haySol)
        cout << "SIN SOLUCION" << endl;
    else
        haySol = false;

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
