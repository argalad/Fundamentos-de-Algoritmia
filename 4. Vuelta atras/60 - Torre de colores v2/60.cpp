// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define stringify(name) #name

using namespace std;

enum colores
{
    azul,
    rojo,
    verde
};

const char *convert_enum[] =
    {
        stringify(azul),
        stringify(rojo),
        stringify(verde)};

void escribirSolucion(vector<colores> const &v)
{
    for (colores c : v)
        cout << convert_enum[c] << " ";
    cout << endl;
}

bool esValida(vector<colores> const &v, int k)
{
    if (k >= 2) // No 2 verdes seguidos
        if (v[k - 1] == verde && v[k] == verde)
            return false;
    return true;
}

// Altura/etapas del árbol = n (número de piezas por torre)
// Ramas = 3ˆ(k - 1) + 2ˆ(k - 1) - 2  (siendo k el número de etapas/altura)
// Vector solución = torres
void torresDeColores(int altura_torre, int piezas, int k, vector<colores> &torres)
{
    for (int i = 0; i < piezas; ++i)
    {
        torres[k] = static_cast<colores>(i);
        if (esValida(torres, k))
        {
            if (k == altura_torre)
            {
                escribirSolucion(torres);
                i = piezas;
            }
            else
                torresDeColores(altura_torre, piezas, k + 1, torres);
        }
    }
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    int n;

    // Leer los datos de la entrada
    cin >> n;

    if (n == 0)
        return false;

    vector<colores> torres(n);

    // Resolver problema
    torres[0] = rojo;
    if (n == 1)
        escribirSolucion(torres);
    else
        torresDeColores(n, 3, 1, torres);
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
