// Nombre del alumno: Alberto Rodriguez - Rabadan Manzanares
// Usuario del Juez: A77

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// T(n) = c1             si n = 1
// T(n) = T(n/2) + c2    si n > 1

// Coste: T(n/2) + c1 = T(n/2^2) + c1 + c1 = ... = T(n/2^k) + k*c1 = ... = 
// = T(1) + log(n) * c1 ∈ O(log(n))

// Función que resuelve el problema
int numValoresCiertos(vector<bool> const &v, int ini, int fin)
{
    if (ini + 1 == fin)
        return ini;
    else
    {
        int mitad = (ini + fin - 1) / 2;
        if (!v[mitad])
            return numValoresCiertos(v, mitad + 1, fin);
        else
            return numValoresCiertos(v, ini, mitad + 1);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    int n;
    vector<bool> v;
    bool valor;

    cin >> n;

    if (!cin)
        return false;

    for (int i = 0; i < n; i++)
    {
        cin >> valor;
        v.push_back(valor);
    }

    int sol = numValoresCiertos(v, 0, v.size());

    if (!v[sol] && sol == n - 1)
        cout << 0 << endl;
    else if (sol == 0)
        cout << n << endl;
    else
        cout << n - sol << endl;

    return true;
}

int main()
{
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso())
        ;

        // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}