// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Coste lineal O(n), recorremos el vector una sola vez
vector<int> resolver(vector<int> const &v, int anio)
{
   int max = v[0];
   vector<int> sol;

   for (int i = 0; i < v.size(); i++)
   {
      if (v[i] > max)
         sol.push_back(anio + i);
      if (max < v[i])
         max = v[i];
   }

   return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
   int n, m, num;
   vector<int> v;
   // Leer los datos de la entrada
   cin >> n >> m;
   for (int i = 0; i <= m - n; i++)
   {
      cin >> num;
      v.push_back(num);
   }
   // Resolver problema
   vector<int> sol = resolver(v, n);
   // Escribir solución
   for (auto n : sol)
        cout << n << " ";

    cout << endl;
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
