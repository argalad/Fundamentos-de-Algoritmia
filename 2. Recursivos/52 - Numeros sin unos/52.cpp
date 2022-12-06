// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>

using namespace std;

// long long int = almacena el número de elementos sin 1
// bool = true si el valor actual tiene un 1
pair<long long int, bool> numerosSinUnos(long long int n)
{
    if (n < 10)
        if (n == 0)
            return {1, false};
        else if (n == 1)
            return {1, true};
        else
            return {n, false};
    else
    {
        pair<long long int, bool> sol = numerosSinUnos(n / 10);
        sol.first *= 9;
        if (sol.second) 
            return sol;
        else
        {
            if (n % 10 > 1)
                sol.first -= (9 - n % 10);
            else
                sol.first -= 8;
            if (n % 10 == 1)
                sol.second = true;

            return sol;
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    long long int n;

    // Leer los datos de la entrada
    cin >> n;
    if (!cin) // Fin de la entrada
        return false;

    // Resolver problema
    pair<long long int, bool> sol = numerosSinUnos(n);

    // Escribir sol
    cout << sol.first << endl;
    
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
