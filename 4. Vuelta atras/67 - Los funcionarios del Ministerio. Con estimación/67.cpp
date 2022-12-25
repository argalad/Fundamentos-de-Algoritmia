// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Altura/etapas del árbol = n (número de funcionarios)
// Ramas = 
// Vector solución = 

void asignacionTrabajos(vector<vector<int>> const &tiempos_por_funcionario, const int &num_funcionarios, const int &k, vector<bool> &trabajos, vector<bool> &funcionarios, int &tiempo_total, int &tiempo_actual, vector<int> const &tiempos_acumulados)
{
    for (int i = 0; i < num_funcionarios; i++)
    {
        tiempo_actual += tiempos_por_funcionario[i][k];
        if (k < 0 || !trabajos[k] && !funcionarios[i]) // Es válida
        {
            trabajos[k] = true;
            funcionarios[i] = true;
            if (k == num_funcionarios - 1)
            {
                if (tiempo_actual < tiempo_total)
                    tiempo_total = tiempo_actual;
            }
            else
            {
                if (tiempos_acumulados[k + 1] + tiempo_actual < tiempo_total)
                    asignacionTrabajos(tiempos_por_funcionario, num_funcionarios, k + 1, trabajos, funcionarios, tiempo_total, tiempo_actual, tiempos_acumulados);
            }
            trabajos[k] = false;
            funcionarios[i] = false;
        }
        tiempo_actual -= tiempos_por_funcionario[i][k];
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    int n;

    // Leer los datos de la entrada
    cin >> n;
    if (n == 0)
        return false;
    vector<vector<int>> tiempos_por_funcionario(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> tiempos_por_funcionario[i][j];

    vector<bool> trabajos(n);
    vector<bool> funcionarios(n);
    int tiempo_actual = 0;
    int tiempo_total = 1000000;

    vector<int> tiempos_minimos(n);
    for (int i = 0; i < n; i++)
    {
        tiempos_minimos[i] = tiempos_por_funcionario[0][i];
        for (int j = 0; j < n; j++)
            if (tiempos_minimos[i] > tiempos_por_funcionario[j][i])
                tiempos_minimos[i] = tiempos_por_funcionario[j][i];
    }

    vector<int> tiempos_acumulados(n);
    for (int i = n - 2; i >= 0; i--)
        tiempos_acumulados[i] += tiempos_minimos[i];

    // Resolver problema
    asignacionTrabajos(tiempos_por_funcionario, n, 0, trabajos, funcionarios, tiempo_total, tiempo_actual, tiempos_acumulados);

    // Escribir sol
    cout << tiempo_total << endl;

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
