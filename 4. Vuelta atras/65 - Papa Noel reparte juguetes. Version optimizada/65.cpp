// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void repartir(const int &numJuguetes, const int &numNinios, vector<vector<int>> const &satisfacciones, int k, vector<int> &sol, 
                int &sumaS, vector<bool> &asignados, int &satisMejor, vector<int> const &acumulados)
{
    for (int i = 0; i < numJuguetes; i++)
    {
        sol[k] = i;
        if (!asignados[i]) // Si es válida
        {
            sumaS += satisfacciones[k][i];
            asignados[i] = true; // Marcar
            if (k == sol.size() - 1) // Si es solución
            {
                if (sumaS > satisMejor) // Si es la mejor
                    satisMejor = sumaS;
            }
            else
                if (sumaS + acumulados[k + 1] > satisMejor) // Estimación
                    repartir(numJuguetes, numNinios, satisfacciones, k + 1, sol, sumaS, asignados, satisMejor, acumulados);
            
            asignados[i] = false; // Desmarcar
            sumaS -= satisfacciones[k][i];
        }
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    int numJuguetes, numNinios;
    vector<vector<int>> satisfacciones;

    // Leer los datos de la entrada
    cin >> numJuguetes >> numNinios;

    if (!cin) // Fin de la entrada
        return false;

    // Lectura de satisfacciones
    for (int i = 0; i < numNinios; i++)
    {
        vector<int> aux(numJuguetes);
        for (int j = 0; j < numJuguetes; j++)
            cin >> aux[j];
        satisfacciones.push_back(aux);
    }

    // Calcular vector de máximos
    vector<int> acumulados(numNinios);

    for (int i = 0; i < numNinios; i++)
    {
        int auxMax = satisfacciones[i][0];
        for (int j = 1; j < numJuguetes; j++)
            if (auxMax < satisfacciones[i][j])
                auxMax = satisfacciones[i][j];
        acumulados[i] = auxMax;
    }

    // Vector de acumulados
    for (int i = (int)acumulados.size() - 1; i > 0; i--)
        acumulados[i - 1] += acumulados[i];

    // Inicialización posible para mejor solución
    int satisMejor = 0;
    for (int i = 0; i < numNinios; i++)
        satisMejor += satisfacciones[i][i];

    // Preparar datos de la funcion
    vector<int> sol(numNinios, 0);
    int sumaS = 0;
    vector<bool> asignados(numJuguetes, false);

    // Resolver sol
    repartir(numJuguetes, numNinios, satisfacciones, 0, sol, sumaS, asignados, satisMejor, acumulados);

    // Escribir sol
    cout << satisMejor << endl;

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
