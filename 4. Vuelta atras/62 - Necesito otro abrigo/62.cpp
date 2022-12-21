// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool esValida(int k, int i, vector<int> const &tiposAbrigos, vector<int> const &probPrecipitaciones,
              vector<int> const &sol, vector<int> const &marcas)
{
    if (tiposAbrigos[i] < probPrecipitaciones[k]) // El abrigo soporta la cantidad de lluvia
        return false;
    else if (k > 0 && sol[k] == sol[k - 1]) // No llevo dos días seguidos el mismo abrigo
        return false;
    else if (marcas[i] > k / 3 + 2) // No me pongo un abrigo muchos más días que otro
        return false;
    else
        return true;
}

int abrigos(vector<int> const &tiposAbrigos, vector<int> const &probPrecipitacion, int k,
            vector<int> &sol, vector<int> &marcas)
{
    int numSoluciones = 0; // Número de soluciones diferentes encontradas
    for (int i = 0; i < tiposAbrigos.size(); i++)
    {
        sol[k] = i;
        // Marcar
        marcas[i]++;
        if (esValida(k, i, tiposAbrigos, probPrecipitacion, sol, marcas))
        {
            if (k == probPrecipitacion.size() - 1)
            {
                if (sol[0] != sol[k])
                {
                    numSoluciones++;

                    // Para escribir las soluciones cuando se pidan 
                    // for (int x : sol) cout << x << endl;
                }
            }
            else
                numSoluciones += abrigos(tiposAbrigos, probPrecipitacion, k + 1, sol, marcas);
        }
        // Desmarcar
        marcas[i]--;
    }

    return numSoluciones;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    int n; // Número de días
    int a; // Número de abrigos

    // Leer los datos de la entrada
    cin >> n >> a;

    if (n == 0 && a == 0)
        return false;

    vector<int> probPrecipitacion(n); // Probabilidades de precipitación
    vector<int> tiposAbrigos(a);      // Características de los abrigos

    for (int &i : probPrecipitacion)
        cin >> i;
    for (int &i : tiposAbrigos)
        cin >> i;

    vector<int> sol(n);    // Abrigo que me pondré cada día
    vector<int> marcas(a); // Días que me he puesto cada abrigo

    // Resolver problema
    int numSoluciones = abrigos(tiposAbrigos, probPrecipitacion, 0, sol, marcas);

    // Escribir sol
    if (numSoluciones == 0)
        cout << "Lo puedes comprar" << endl;
    else
        cout << numSoluciones << endl;

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
