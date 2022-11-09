// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>

using namespace std;

// eliminarDigitosPares(num) = 0   si num < 10 && num % 0 == 0
// eliminarDigiosPares(num) = num  si num < 10 && num % 0 != 0
// eliminarDigitosPares(num) = eliminarDigitosPares(num / 10) si num > 10 && num % 2 == 0
// eliminarDigitosPares(num) = eliminarDigitosPares(num / 10) * 10 + (num % 10)

long long int eliminarDigitosPares_nofinal(long long int num)
{
    if (num < 10)
    {
        if (num % 2 == 0)
            return 0;
        else
            return num;
    }
    if (num % 2 == 0)
        return eliminarDigitosPares_nofinal(num / 10);
    else
        return eliminarDigitosPares_nofinal(num / 10) * 10 + (num % 10);
}

long long int eliminarDigitosPares_final(long long int num, long long int num_sin_pares, long long int pot)
{
    long long int digito;
    int mul;

    if (num == 0)
        return num_sin_pares;

    if (num % 2 == 0)
    {
        mul = 1;
        digito = 0;
    }
    else
    {
        mul = 10;
        digito = num % 10;
    }
    return eliminarDigitosPares_final(num / 10, digito * pot + num_sin_pares, mul * pot);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    long long int num;

    // Leer los datos de la entrada
    cin >> num;
    if (!cin) // Fin de la entrada
        return false;
    // Resolver problema
    long long int sol_nofinal = eliminarDigitosPares_nofinal(num);
    long long int sol_final = eliminarDigitosPares_final(num, 0, 1);
    // Escribir sol
    cout << sol_nofinal << " " << sol_final << endl;

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
