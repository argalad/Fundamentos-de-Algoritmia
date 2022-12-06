// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/*
Recurrencia

    T(n) = c1                    si n == 0
    T(n) = a * T(n/b) + c*nˆk    si n > 0

Coste
    Caso base: O(1)
    Caso recursivo: realizamos una llamada recursiva cada vez (a = 1), reduciendo el tamaño del problema a la mitad (b = 2)
    coste de preparacion y combinacion de resultados es cte. (k = 0) (para que c*nˆk = O(1))
    Como a = bˆk, T(n) pertenece a O(nˆk * log(n)) = log(n)
*/

int imparSuperviviente(vector<int> const &v, int ini, int fin)
{
    if (ini == fin)
    {
        if (v[ini] % 2 != 0)
            return v[ini];
        else
            return 0;
    }
    else
    {
        int mitad = (ini + fin) / 2;

        if (v[mitad] % 2 != 0)
            return v[mitad];
        else
        {
            if (v[ini] % 2 != 0)
                return v[ini];
            else
            {
                if (v[mitad] - v[ini] == (mitad - ini) * 2)
                    return imparSuperviviente(v, mitad + 1, fin);
                else
                    return imparSuperviviente(v, ini, mitad);
            }
        }
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

    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    // Resolver problema
    int sol = imparSuperviviente(v, 0, v.size());

    // Escribir sol
    cout << sol << endl;

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
