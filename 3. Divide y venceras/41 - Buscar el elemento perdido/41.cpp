// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
/* 
Especificación

P = {n > 0 ∧ m = n - 1 ∧ ordenado_sin_repetidos(a, n) ∧ copia_ordenada_sin_repetidos(b, m, a, n)
∧ falta_uno(b, m, a[0], a[n - 1])}
fun elementoPerdido(int a[0..n], int b[0..m], int ini, int fin) ret int perdido
Q = {a[0] <= perdido <= a[n - 1] ∧ !pertenece(b, m, perdido) ∧ pertenece(a, n, perdido)}

donde

ordenado(v, n) = (∀w : 0 <= w < n - 1 : v[w] < v[w + 1])

*/
// T(n) = c1             si n = 1
// T(n) = T(n/2) + c2    si n > 1

// Coste: T(n/2) + c1 = T(n/2^2) + c1 + c1 = ... = T(n/2^k) + k*c1 = ... = 
// = T(1) + log(n) * c1 ∈ O(log(n))

int elementoPerdido(vector<int> const &a, vector<int> const &b, int ini, int fin)
{
    if (ini >= fin) // Caso base
        return a[ini];
    else // Caso recursivo
    {
        int mitad = (ini + fin) / 2;
        if (b[mitad] > a[mitad])
            return elementoPerdido(a, b, ini, mitad);
        else
            return elementoPerdido(a, b, mitad + 1, fin);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    int n;

    // Leer los datos de la entrada
    cin >> n;
    vector<int> a(n);
    vector<int> b(n - 1);
    for (int &i:a) cin >> i;
    for (int &j:b) cin >> j;
    // Resolver problema
    int sol = elementoPerdido(a, b, 0, b.size());
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
