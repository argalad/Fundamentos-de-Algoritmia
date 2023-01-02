// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/*
    N = puntuaciones.size() (número de páginas del libro)

    ESPECIFICACIÓN FORMAL
    ----------------------
    P = { 1 < N ⋀ 1 < L < N ⋀ (∀w : 0 ≤ w < N : 0 ≤ puntuaciones[w] ≤ 10) }
    fun resolver(puntuaciones[0..N] de int, L : int) ret sol : int
    Q = { ∀i,j : 0 ≤ i < j ≤ N ⋀ j - i = L ⋀ tieneMaximo(puntuaciones, N, i, j) : (suma(puntuaciones, i, j) < suma(puntuaciones, sol, sol + L)) ⋁ 
                (suma(puntuaciones, i, j) = suma(puntuaciones, sol, sol + l) ⋀ i ≤ sol) }
    
    donde:
    tieneMaximo(v, n, i, j) = (∃w : i ≤ w < j : v[w] = maximo(v, 0, n))
    maximo(v, i, j) = (max w : i ≤ j : v[w])

    INVARIANTE
    ----------
    - Primer bucle:
        I = { u ≤ p + L ⋀ suma = suma(puntuaciones, p, u) ⋀ (numMax = #w : p ≤ w < u : puntuaciones[w] = maximo(puntuaciones, p, u)) }
        B = u < p + L
    - Segundo bucle:
        I = { u ≤ N ⋀ suma = suma(puntuaciones, p, u) ⋀ (maxSuma = suma(puntuaciones, sol, sol + L)) ⋀ 
            (∀i,j : 0 ≤ i < j ≤ u ⋀ j - i = L ⋀ tieneMaximo(puntuaciones, N, i, j) : (suma(puntuaciones, i, j) < suma(puntuaciones, sol, sol + L)) ⋁
            (suma(puntuaciones, i, j) = suma(puntuaciones, sol, sol + L) ⋀ i ≤ sol)) ⋀ (numMax = #w : p ≤ w < u : puntuaciones[w] = maximo(puntuaciones, p, u)) }
        B = u < N
    
    FUNCIÓN DE COTA
    ---------------
    - Primer bucle:
        C = (p + L) - u
            • C ≥ 0 al empezar el bucle ((p + L) - u = 0 + L - 1 = L - 1 ≥ 1 (por la precondición) > 0)
            • C decrece al avanzar el bucle (aumenta u --> disminuye N - u)
    - Segundo bucle:
        C = N - u
            • C ≥ 0 al empezar el bucle (N - u = N - (p + L) = N - (0 + L) = N - L ≥ 1 (por la precondición) > 0)
            • C decrece al avanzar el bucle (aumenta u --> disminuye N - u)

    COSTE
    -----
    El coste asintótico en tiempo de la función será del orden O(N), dado que entre los dos bucles se recorre el vector
    entero pasando por cada elemento 1 única vez. Ambos aumentan el "contador" u y esta variable puede tomar a lo sumo
    el valor de N. Poniendo un caso límite, si L = N el primer bucle dará N vueltas, pero el segundo dará 0. Además, las 
    operaciones interiores de los bucles son todas de coste O(1), por lo que no suponen un cambio en el coste asintótico
    de la función.

    La función máximo también tiene coste O(N), pero no afecta al coste asintótico total de la función, dado que O(2N) está
    en el orden de O(N) 
*/

int maximo(vector<int> const &v)
{
    int m = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] > m)
            m = v[i];
    }
    return m;
}

int resolver(vector<int> const &puntuaciones, int L)
{
    int max = maximo(puntuaciones);
    int suma = 0, numMax = 0;
    int maxSuma = -1;
    int p = 0, u = 0, sol = 0;

    while (u < p + L)
    {
        suma += puntuaciones[u];
        if (puntuaciones[u++] == max)
            numMax++;
    }

    if (numMax > 0)
        maxSuma = suma;

    while (u < puntuaciones.size())
    {
        suma -= puntuaciones[p];
        if (puntuaciones[p++] == max)
            numMax--;

        suma += puntuaciones[u];
        if (puntuaciones[u++] == max)
            numMax++;

        if (numMax > 0 && suma >= maxSuma)
        {
            maxSuma = suma;
            sol = p;
        }
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    int n, L;

    // Leer los datos de la entrada
    cin >> n >> L;
    if (n == 0 && L == 0)
        return false;

    vector<int> puntuaciones(n);
    for (int &i : puntuaciones)
        cin >> i;

    // Resolver problema
    int sol = resolver(puntuaciones, L);

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
