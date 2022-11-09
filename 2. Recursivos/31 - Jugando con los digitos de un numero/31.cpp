// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>

using namespace std;

int transformarDigitos(int num)
{
    if (num < 10)
    {
        if (num % 2 == 0)
            return num % 10 + 1;
        else
            return num % 10 - 1;
    }
    else
    {
        if (num % 2 == 0)
            return transformarDigitos(num / 10) * 10 + (num % 10 + 1);
        else
            return transformarDigitos(num / 10) * 10 + (num % 10 - 1);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    int num;

    // Leer los datos de la entrada
    cin >> num;
    // Resolver problema
    int sol = transformarDigitos(num);
    // Escribir solución
    cout << sol << endl;
}

int main()
{
    // Ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casos.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

        // Para dejar todo como estaba al principio
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
