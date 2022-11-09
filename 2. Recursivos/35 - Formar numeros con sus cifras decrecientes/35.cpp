// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>

using namespace std;

// eliminarDecrecientes(num, max) = 0   si num == 0
// eliminarDecrecientes(num, max) = eliminarDecrecientes(num / 10, max)   si num % 10 < max
// eliminarDecrecientes(num, max) = eliminarDecrecientes(num / 10, max) * 10 + (num % 10)    si num % 10 >= max

int eliminarDecrecientes_nofinal(int num, int max)
{
    if (num == 0)
        return 0;
    else if (num % 10 < max)
        return eliminarDecrecientes_nofinal(num / 10, max);
    else
    {
        if (num % 10 > max)
            max = num % 10;
        return eliminarDecrecientes_nofinal(num / 10, max) * 10 + (num % 10);
    }
}

int eliminarDecrecientes_final(int num, int max, int result, int pot)
{
    if (num == 0)
        return result;
    else if (num % 10 < max)
        return eliminarDecrecientes_final(num / 10, max, result, pot);
    else
    {
        if (num % 10 >= max)
            max = num % 10;
        return eliminarDecrecientes_final(num / 10, max, (num%10)*pot + result, 10 * pot);
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
    int sol_nofinal = eliminarDecrecientes_nofinal(num, 0);
    int sol_final = eliminarDecrecientes_final(num, 0, 0, 1);
    // Escribir solución
    cout << sol_nofinal << " " << sol_final << endl;
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
