// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>

using namespace std;

int sumaDigitos(int num, int suma)
{
    if (num == 0)
        return suma;
    else
        return sumaDigitos(num / 10, suma + num%10);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    int n, num;

    // Leer los datos de la entrada
    cin >> n >> num;
    // Resolver problema
    int suma = sumaDigitos(num, 0);
    // Escribir solución
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (sumaDigitos(num, 0) == suma)
            cout << num << " ";
    }
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
