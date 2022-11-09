// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Complejidad lineal, se recorre el vector una vez
int resolver (vector<int> const &v, int k)
{
    int posIz = 0, posDer = 0, result = 0;

    for (int i = 0; i < k/2; i++)
    {
        if (v[i] > 0)
            posIz++;
    }

    for (int i = k/2; i < k; i++)
    {
        if (v[i] > 0)
            posDer++;
    }

    if (posIz >= posDer)
            result++;

    for (int i = k; i < v.size(); i++)
    {
        // Para el lado izquierdo
        // Si el siguiente elemento es positivo y el que hemos dejado es negativo, sumamos uno.
        if (v[i - k/2] > 0 && v[i - k] < 0 && posIz < k/2)
            posIz++;
        // Si el siguiente elemento es negativo y el que hemos dejado es positivo, restamos uno.
        else if (v[i - k/2] < 0 && v[i - k] > 0 && posIz != 0)
            posIz--;
        // Para el lado derecho
        // Igual que antes
        if (v[i] > 0 && v[i - k/2] < 0 && posDer < k/2)
            posDer++;
        else if (v[i] < 0 && v[i - k/2] > 0 && posDer != 0)
            posDer--;

        if (posIz >= posDer)
            result++;
    }

    return result;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso () 
{
    int n, k, num;

   // Leer los datos de la entrada
   cin >> n;
   
   if (n == 0)
      return false;

   cin >> k;

   vector<int> v(n);
   for (int &i:v) cin >> i;
   
   // Resolver problema
   int sol = resolver (v, k);
   
   // Escribir sol
   cout << sol << endl;
   
   return true;
}

int main () 
{
   // Ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   ifstream in ("casos.txt");
   auto cinbuf = cin.rdbuf (in.rdbuf ());
#endif
   
   while (resuelveCaso ());
   
   // Para dejar todo como estaba al principio
#ifndef DOMJUDGE
   cin.rdbuf (cinbuf);
   system ("PAUSE");
#endif
   return 0;
}
