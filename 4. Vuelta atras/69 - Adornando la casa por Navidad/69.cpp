// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Se utiliza un vector de pares para almacenar el coste y la superficienpara facilitar el ordenarlo 
// por superficie por unidad de coste
struct tDatos
{
    int costeMax;
    vector<pair<int, int>> costeSuperf;
};

// Para ordenar los objetos hacemos una sobrecarga el operador parentesis
class comparador
{
public:
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        return (float)p1.second / p1.first > (float)p2.second / p2.first;
    }
};

// Para escribir la solución
ostream &operator<<(ostream &salida, vector<bool> const &v)
{
    for (int i = 0; i < v.size(); i++)
        if (v[i])
            cout << i << ' ';
    cout << endl;

    return salida;
}

// Para estimar la mayor superficie que se puede conseguir desde este momento
int estimar(tDatos const &datos, int costeAct, int k)
{
    int i = k + 1;
    int sumaCoste = costeAct;
    int sumaSuperf = 0;

    while (i < datos.costeSuperf.size() && sumaCoste + datos.costeSuperf[i].first <= datos.costeMax)
    {
        sumaCoste += datos.costeSuperf[i].first;
        sumaSuperf += datos.costeSuperf[i].second;
        i++;
    }

    // La parte que queda sin completar. Como la división es entera se suma 1 al resultado para asignar una cota superior
    // a la variable entera
    if (i < datos.costeSuperf.size() && sumaCoste < datos.costeMax)
        sumaSuperf += datos.costeSuperf[i].second * (datos.costeMax - sumaCoste) / datos.costeSuperf[i].first + 1;

    return sumaSuperf;
}

// Parametros
//           datos  -> datos de entrada
//               k  -> etapa
//             sol  -> vector con dimensión el número de adornos, guarda la solución actual
//        costeAct  -> coste de la solución actual
//   superficieAct  -> superficie de la solución actual
//        solMejor  -> solución mejor hasta el momento
// superficieMejor  -> superficie de la solución mejor
void adornandoNavidad(tDatos const &datos, int k, vector<bool> &sol, int costeAct, int superficieAct,
                      vector<bool> &solMejor, int &superficieMejor)
{
    sol[k] = true; // Compra el objeto
    costeAct += datos.costeSuperf[k].first;
    superficieAct += datos.costeSuperf[k].second;

    if (costeAct <= datos.costeMax) // Si es válida
    {
        if (k == sol.size() - 1) // Si es solución
        {
            if (superficieAct > superficieMejor)
            {
                superficieMejor = superficieAct;
                solMejor = sol;
            }
        }
        else
            adornandoNavidad(datos, k + 1, sol, costeAct, superficieAct, solMejor, superficieMejor);
    }
    costeAct -= datos.costeSuperf[k].first;       // Recupera el valor
    superficieAct -= datos.costeSuperf[k].second; // Recupera el valor

    sol[k] = false; // No compra el objeto
    // Siempre el válido
    if (k == sol.size() - 1) // Es solución
    {
        if (superficieAct > superficieMejor) // Solución mejor
        {
            superficieMejor = superficieAct;
            solMejor = sol;
        }
    }
    else if (estimar(datos, costeAct, k) + superficieAct > superficieMejor)
        adornandoNavidad(datos, k + 1, sol, costeAct, superficieAct, solMejor, superficieMejor);
}

int inicializarSuperficie(tDatos const &Obj, int costeMax)
{
    int i = 0;
    int sumaSuperficie = 0;
    int sumaCoste = 0;

    while (i < Obj.costeSuperf.size() && sumaCoste + Obj.costeSuperf[i].first <= costeMax)
    {
        sumaCoste += Obj.costeSuperf[i].first;
        sumaSuperficie += Obj.costeSuperf[i].second;
        i++;
    }

    return sumaSuperficie;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    int numObjetos;
    tDatos datos;

    // Leer los datos de la entrada
    cin >> numObjetos >> datos.costeMax;
    if (!cin) // Fin de la entrada
        return false;

    // Lee el coste y la superficie de cada adorno
    for (int i = 0; i < numObjetos; i++)
    {
        int coste, superficie;
        cin >> coste >> superficie;
        datos.costeSuperf.push_back({coste, superficie});
    }

    // Ordena los datos de superficie por unidad de coste
    sort(datos.costeSuperf.begin(), datos.costeSuperf.end(), comparador());
    vector<bool> sol(numObjetos);
    int costeAct = 0;
    int superficieAct = 0;
    int superficieMejor = inicializarSuperficie(datos, datos.costeMax);
    vector<bool> solMejor;

    // Resolver problema
    adornandoNavidad(datos, 0, sol, costeAct, superficieAct, solMejor, superficieMejor);

    // Escribir sol
    cout << superficieMejor << endl;

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
