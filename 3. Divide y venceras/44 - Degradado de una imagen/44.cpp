// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/*
Especificación

P = {(Existe i : 0 <= i : m = 2^i) ∧ 0 <= ini < fin <= m}
fun esDegradado(int v[0..n], int num, int ini, int fin) ret <degradado : bool, sum : int>
Q = {m = (ini + fin / 2) ∧ degradado = (suma(fila, ini, mitad) < suma(fila, mitad) ∧ degradado(fila, ini, mitad) ∧ degradado(fila, mitad, fin)) ∧ sum = suma(fila, ini, fin)}

donde

   suma(v, i, j) = SUM w : i <= w < j : v[w]

Recurrencia

T(m) = c1             si n = 1
T(m) = 2T(m/2) + c2    si m > 1

Coste

O(n*m)
*/

pair<bool, int> esDegradado(vector<int> const &v, int ini, int fin)
{
   if (ini + 1 == fin)
      return {true, v[ini]};
   else
   {
      int mitad = (ini + fin) / 2;
      pair<bool, int> iz = esDegradado(v, ini, mitad);
      pair<bool, int> der = esDegradado(v, mitad, fin);
      return {iz.first && der.first && iz.second < der.second, iz.second + der.second};
   }
}

bool resolver(vector<vector<int>> const &matriz, int n, int m)
{
   bool degradado = true;
   int fila = 0;

   while (degradado && fila < n)
      degradado = esDegradado(matriz[fila++], 0, m).first;

   return degradado;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
   int n, m;

   // Leer los datos de la entrada
   cin >> n;
   if (!cin) // Fin de la entrada
      return false;
   cin >> m;
   vector<vector<int>> matriz(n, vector<int>(m));
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
         cin >> matriz[i][j];
   }
   // Resolver problema
   bool sol = resolver(matriz, n, m);
   // Escribir sol
   if (sol)
      cout << "SI" << endl;
   else
      cout << "NO" << endl;
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
