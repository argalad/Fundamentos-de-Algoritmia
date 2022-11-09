// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/*
Especificación

P = {n > 0 ∧ ordenado(v, n) ∧ 0 <= ini <= fin <= n }
fun juegoBongo(int v[0..n], int num, int ini, int fin) ret int sol
Q = {!hayQueTachar(v, num, ini, fin) --> sol = -1 ∧ hayQueTachar(v, num, ini, fin) --> (sol = v[i] ∧ ini <= i < fin ∧ v[i] = num + i)}

donde

    ordenado(v, n) = (∀w : 0 <= w < n - 1 : v[w] < v[w + 1])
    hayQueTachar(v, num, i, j) = (Existe w : i <= w < j : v[w] = num + w)

Recurrencia

T(n) = c1             si n = 0
T(n) = T(n/2) + c2    si n > 0

Coste

T(n/2) + c1 = T(n/2^2) + c1 + c1 = ... = T(n/2^k) + k*c1 = ... =
= T(1) + log(n) * c1 ∈ O(log(n))
*/

int juegoBongo(vector<int> const &v, int num, int ini, int fin)
{
    if (ini == fin)
        return -1;

    int mitad = (ini + fin) / 2;
    if (v[mitad] == mitad + num)
        return v[mitad];
    else if (v[mitad] > mitad + num)
        return juegoBongo(v, num, ini, mitad);
    else
        return juegoBongo(v, num, mitad + 1, fin);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    int n, num;

    // Leer los datos de la entrada
    cin >> n >> num;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    // Resolver problema
    int sol = juegoBongo(v, num, 0, v.size());
    // Escribir solución
    if (sol == -1)
        cout << "NO" << endl;
    else
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
