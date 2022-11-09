// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// T(n) = c1             si n = 1
// T(n) = T(n/2) + c2    si n > 1

// Coste: T(n/2) + c1 = T(n/2^2) + c1 + c1 = ... = T(n/2^k) + k*c1 = ... = 
// = T(1) + log(n) * c1 ∈ O(log(n))

char busqueda(vector<char> const &presos, int ini, int fin, char c)
{
   if (ini > fin)
      return c;
   int mitad = (ini + fin) / 2;

   if (presos[mitad] <= mitad + presos[0])
      return busqueda(presos, mitad + 1, fin, presos[mitad] + 1);
   else
      return busqueda(presos, ini, mitad - 1, presos[mitad] - 1);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
   char ini, fin;
   int n;

   // Leer los datos de la entrada
   cin >> ini >> fin;
   n = fin - ini;

   vector<char> presos(n);
   for (char &i : presos)
        cin >> i;
   // Resolver problema
   if (presos[0] != ini)
      cout << ini << endl;
   else if (presos[presos.size() - 1] != fin)
      cout << fin << endl;
   else
   {
      char sol = busqueda(presos, 0, presos.size() - 1, presos[0]);
      cout << sol << endl;
   }
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
