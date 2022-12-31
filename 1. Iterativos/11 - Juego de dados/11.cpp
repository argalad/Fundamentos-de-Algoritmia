// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/* 

Coste
Recorremos tres bucles de coste O(n) por lo tanto O(3n) = O(n)

*/

vector<int> juegoDeDados(vector<int> const &tiradas, int const &valorMax)
{
    int maximo = 0;
    vector<int> sol;
    vector<int> aux(valorMax + 1, 0); // Vector donde almacenamos el número de veces que aparece un valor (valorMax + 1, el 0 no cuenta)

    // Sumo las veces que aparece un valor en el vector tiradas
    for (int i = 0; i < tiradas.size(); i++)
        aux[tiradas[i]]++;

    // Buscamos el valor máximo de repeticiones de uno o varios números
    for (int i = 1; i < aux.size(); i++)
        if (aux[i] > maximo)
            maximo = aux[i];
    
    // Guardo en el vector solución los valores que coinciden con el máximo
    for (int i = aux.size() - 1; i > 0; i--)
        if (aux[i] == maximo)
            sol.push_back(i);
    
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    int numTiradas, valorMax;

    // Leer los datos de la entrada
    cin >> numTiradas >> valorMax;

    if (numTiradas == -1)
        return false;

    // Vector donde almacenamos las tiradas
    vector<int> tiradas(numTiradas);
    for (int &i : tiradas)
        cin >> i;

    // Resolver problema
    vector<int> sol = juegoDeDados(tiradas, valorMax);

    // Escribir sol
    for (int i = 0; i < sol.size(); i++)
        cout << sol[i] << ' ';
    cout << endl;

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
