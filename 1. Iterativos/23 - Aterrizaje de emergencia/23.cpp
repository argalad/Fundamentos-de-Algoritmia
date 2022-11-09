// Nombre del alumno: Alberto Rodríguez - Rabadán Manzanares
// Usuario del Juez: A77

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tSol 
{
    vector<int> comienzo_superficies;
    int num_superficies = 0;
};

// Función que resuelve el problema
tSol resolver(vector<int> const &v, int valor)
{
    int n = 1, pos = 0;
    tSol sol;

    for (int i = 1; i < v.size(); i++)  // Recorremos el vector de principio a fin
    {
        if (abs(v[i - 1] - v[i]) <= 1)
        {
            n++;

            if (n == valor)
            {
                sol.num_superficies++;
                sol.comienzo_superficies.push_back(pos);
            }
        }
        else
        {
            n = 1;
            pos = i;
        }
    }

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    
    int num_datos, casi_iguales, num;
    vector<int> datos;
    tSol solucion;

    // Leer los datos de la entrada
    cin >> num_datos >> casi_iguales;

    if (num_datos == 0 && casi_iguales == 0)
        return false;

    for (int i = 0; i < num_datos; i++)
    {
        cin >> num;
        datos.push_back(num);
    }

    // Resolver problema
    solucion = resolver(datos, casi_iguales);

    // Escribir solución
    cout << solucion.num_superficies << " ";
    for (int i = 0; i < solucion.comienzo_superficies.size(); i++)
    {
        cout << solucion.comienzo_superficies[i] << " ";
    }
    cout << endl;

    return true;
}

int main()
{
// Para la entrada por fichero.
// Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso())
        ;

        // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
