// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

/*
Recurrencia

T(n) = c1              si n == 2
T(n) = 2T(n/2) + c2    si n >= 4

Coste
    O(n)
*/

struct tSol
{
    int partidos_jugados;
    bool presentado;
    int ronda;
};

tSol torneoTenis(vector<string> const &jugadores, int ronda_final, int ini, int fin)
{
    if (ini + 2 == fin) // Caso base para dos jugadores
    {
        if (jugadores[ini] == "NP" && jugadores[fin - 1] == "NP")
            return {0, false, 1};
        else if (jugadores[ini] == "NP" || jugadores[fin - 1] == "NP")
            return {0, true, 1};
        else
            return {1, true, 1};
    }
    else // Caso recursivo para más de dos jugadores
    {
        int mitad = (ini + fin) / 2;
        tSol iz = torneoTenis(jugadores, ronda_final, ini, mitad);
        tSol der = torneoTenis(jugadores, ronda_final, mitad, fin);
        if (iz.ronda != ronda_final) // No se ha alcanzado la ronda final
        {
            if (iz.presentado && der.presentado)
                return {iz.partidos_jugados + der.partidos_jugados + 1, true, iz.ronda + 1};
            else
                return {iz.partidos_jugados + der.partidos_jugados, iz.presentado || der.presentado, iz.ronda + 1};
        }
        else
            return {iz.partidos_jugados + der.partidos_jugados, iz.presentado && der.presentado, iz.ronda};
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    int n, ronda_final;
    // Leer los datos de la entrada
    cin >> n >> ronda_final;
    if (!cin) // Fin de la entrada
        return false;

    vector<string> jugadores(n);
    for (string &i : jugadores)
        cin >> i;

    // Resolver problema
    tSol sol = torneoTenis(jugadores, ronda_final, 0, jugadores.size());

    // Escribir sol
    cout << sol.partidos_jugados << endl;
    
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
