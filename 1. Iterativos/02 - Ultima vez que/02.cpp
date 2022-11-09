// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int resolver(vector<string> const &v, string s)
{
    bool found = false;
    int i = v.size() - 1;
    int ret = 0;

    // Recorremos el vector de fin a principio y dejamos de recorrerlo
    // cuando encontramos la primera aparición de nacionalidad buscada.
    while (!found && i >= 0)
    {
        if (s == v.at(i))
        {
            found = true;
            return v.size() - i;
        }
        else
            i--;
    }

    return 0;
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    int anyos;
    string nacionalidad, aux;
    vector<string> nacion_ganadores;

    // Leer los datos de la entrada
    cin >> anyos;
    if (anyos == 0)
        return false;
    cin >> nacionalidad;

    for (int i = 0; i < anyos; i++)
    {
        cin >> aux;
        nacion_ganadores.push_back(aux);
    }
    
    // Resolver problema
    int sol = resolver(nacion_ganadores, nacionalidad);

    // Escribir sol
    if (sol != 0)
        cout << sol << endl;
    else
        cout << "NUNCA" << endl;

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
