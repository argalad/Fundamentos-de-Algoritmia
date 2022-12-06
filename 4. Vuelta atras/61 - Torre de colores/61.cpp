// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define stringify(name) #name

using namespace std;

// Altura/etapas del árbol = n (número de piezas por torre)

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

void tratarTorre(vector<colores> const &torre, vector<int> const &piezas_usadas, bool &sin_sol)
{
    if (piezas_usadas[1] > piezas_usadas[0] + piezas_usadas[2]) // Si el número de piezas rojas es mayor a la suma de azules y verdes
    {
        escribirSolucion(torre);
        sin_sol = false;
    }
}

bool esValida(vector<colores> const &torre, int k, vector<int> const &num_piezas, vector<int> const &piezas_usadas)
{
    if (torre[0] != rojo) // Si el primero no es rojo
        return false;
    if (piezas_usadas[torre[k]] >= num_piezas[torre[k]]) // Si tenemos piezas disponibles
        return false;
    if (k >= 2) // No 2 verdes seguidos
        if (torre[k - 1] == verde)
            return false;
    if (torre[k] == 2) // Si hay más verdes que azules
        if (piezas_usadas[0] < piezas_usadas[2] + 1)
            return false;
    return true;
}

void torresDeColores(int altura_torre, int k, vector<colores> &torre, vector<int> const &num_piezas, 
                        vector<int> &piezas_usadas, bool &sin_sol)
{
    for (int i = 0; i < num_piezas.size(); ++i) // # de piezas distintas
    {
        torre[k] = static_cast<colores>(i);
        if (esValida(torre, k, num_piezas, piezas_usadas))
        {
            piezas_usadas[torre[k]]++;
            if (k == altura_torre - 1)
                tratarTorre(torre, piezas_usadas, sin_sol);
            else
                torresDeColores(altura_torre, k + 1, torre, num_piezas, piezas_usadas, sin_sol);
            piezas_usadas[torre[k]]--;
        }
    }
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    int n, a, r, v;

    // Leer los datos de la entrada
    cin >> n >> a >> r >> v;

    if (n == 0 && a == 0 &&
        r == 0 && v == 0)
        return false;

    vector<int> num_piezas = {a, r, v};
    vector<colores> torre(n);
    vector<int> piezas_usadas(3, 0); // 0 = azul, 1 = rojo, 2 = verde
    bool sin_sol = true;
    // Resolver problema
    torresDeColores(n, 0, torre, num_piezas, piezas_usadas, sin_sol);
    if (sin_sol)
        cout << "SIN SOLUCION" << endl;
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
