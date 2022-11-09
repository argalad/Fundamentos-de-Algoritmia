// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Solucion resolver(Datos datos)
{
    ...
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    int p, u, n, m, num;
    vector<int> v;
    // Leer los datos de la entrada
    cin >> p >> u;
    if (p == 0 && u == 0)
        return false;
    n = u - p + 1;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    cin >> m;
    
    // Resolver problema
    Solucion sol = resolver(datos);

    // Escribir sol

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
