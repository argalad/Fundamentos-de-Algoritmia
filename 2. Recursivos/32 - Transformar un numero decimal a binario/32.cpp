// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string decimalBinario_nofinal (int n)
{
    if (n == 0)
        return "0";
    else if (n == 1)
        return "1";
    else
        return decimalBinario_nofinal(n / 2) + char('0' + n % 2);
}

string decimalBinario_final (int n, string bin)
{
    if (n == 0) return '0' + bin;
    else if (n == 1) return '1' + bin;
    else return decimalBinario_final(n/2, char('0'+n%2)+bin);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    int n;

    // Leer los datos de la entrada
    cin >> n;
    // Resolver problema
    string sol = decimalBinario_nofinal(n);
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
