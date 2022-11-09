// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema:
// Se recorre el vector desde la primera posición hasta la
// indicada y almacenamos el valor máximo. Después lo volvemos
// a recorrer desde la siguiente posición hasta el final y
// guardamos el valor mínimo. Para finalizar comparamos ambos
// valores y devolvemos true si el máximo es menor que el mínimo,
// es decir, que todas las temperaturas de la izquierda son menores
// que las de la derecha.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int NUM_MAX_TEMPS = 10000;
const int MAX_TEMP = -50;
const int MIN_TEMP = 60;

// Función que resuelve el problema
// La complejidad es lineal O(n) pues sólo recorremos el vector entero una vez.
/*
PRECONDICIÓN:
P = {N > 0 ∧ 0 ≤ pos < N}
*/
bool resolver(vector<int> const &temperaturas, int pos)
{
    bool divide;

    if (pos == temperaturas.size() - 1)
        divide = true;
    else
    {
        int maxIz = temperaturas[0];
        int minDer = temperaturas[pos + 1];

        /*
        INVARIANTE:
        Inv = {∀j : 0 < j ≤ i : maxIz ≥ temperaturas[j] }
        FUNCIÓN DE COTA:
        c(i) = pos + 1 - i
        */
        for (int i = 0; i < pos + 1; i++)
            if (temperaturas[i] > maxIz)
                maxIz = temperaturas[i];

        /*
        INVARIANTE:
        Inv = {∀j : pos + 1 < j ≤ i}
        FUNCIÓN DE COTA:
        c(i) = N - (pos + 1) - i
        */
        for (int i = pos + 1; i < temperaturas.size(); i++)
            if (temperaturas[i] < minDer)
                minDer = temperaturas[i];

        if (maxIz < minDer)
            divide = true;
        else
            divide = false;
    }

    return divide;
}
/*
POSTCONDICIÓN:
Q = {divide = ∀i,j : 0 ≤ i ≤ pos ∧ pos < j < N : temperaturas[i] < temperaturas[j]}
*/

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    int tam, pos, valor;
    vector<int> temperaturas;

    // Leer los datos de la entrada
    cin >> tam >> pos;

    for (int i = 0; i < tam; i++)
    {
        cin >> valor;
        temperaturas.push_back(valor);
    }

    // Resolver problema y escribir solución
    if (resolver(temperaturas, pos))
        cout << "SI" << endl;
    else
        cout << "NO" << endl;
}

int main () 
{
   // Ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   ifstream in ("casos.txt");
   auto cinbuf = cin.rdbuf (in.rdbuf());
#endif
   
   int numCasos;
   cin >> numCasos;
   for (int i = 0; i < numCasos; ++i)
      resuelveCaso ();
   
   // Para dejar todo como estaba al principio
#ifndef DOMJUDGE
   cin.rdbuf (cinbuf);
   system ("PAUSE");
#endif
   return 0;
}
