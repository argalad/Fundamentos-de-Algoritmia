// Nombre y Apellidos: Alberto Rodríguez - Rabadán Manzanares
// Número de juez: 77

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct tCancion
{
    int duracion;
    int satisfaccion;
};

struct tDatos
{
    int numCanciones;
    int tiempoViajeIda;
    int tiempoViajeVuelta;
    vector<tCancion> canciones;
};

istream &operator>>(istream &in, tCancion &c)
{
    in >> c.duracion >> c.satisfaccion;
    return in;
}

void playlistIdeal(tDatos const& datos, int k, vector<int> &playlist, int duracionViajeIda, int duracionViajeVuelta,
                   int &satisAct, vector<int> &playlistMejor, int &satisMejor, bool &haySol)
{
    // La selecciono para viaje ida
    playlist[k] = 1;
    duracionViajeIda += datos.canciones[k].duracion;
    satisAct += datos.canciones[k].satisfaccion;

    if (duracionViajeIda <= datos.tiempoViajeIda) // Si es válida
    {
        if (k == playlist.size() - 1) // Si hay solución
        {
            if (duracionViajeIda == datos.tiempoViajeIda &&
                duracionViajeVuelta == datos.tiempoViajeVuelta)
            {
                haySol = true;
                if (satisAct > satisMejor)
                {
                    satisMejor = satisAct;
                    playlistMejor = playlist;
                }
            }
        }
        else
            playlistIdeal(datos, k + 1, playlist, duracionViajeIda, duracionViajeVuelta, satisAct, playlistMejor, satisMejor, haySol);
    }

    duracionViajeIda -= datos.canciones[k].duracion;
    satisAct -= datos.canciones[k].satisfaccion;

    // La selecciono para viaje vuelta
    playlist[k] = 2;
    duracionViajeVuelta += datos.canciones[k].duracion;
    satisAct += datos.canciones[k].satisfaccion;

    if (duracionViajeVuelta <= datos.tiempoViajeVuelta)
    {
        if (k == playlist.size() - 1)
        {
            if (duracionViajeIda == datos.tiempoViajeIda &&
                duracionViajeVuelta == datos.tiempoViajeVuelta)
            {
                haySol = true;
                if (satisAct > satisMejor)
                {
                    satisMejor = satisAct;
                    playlistMejor = playlist;
                }
            }
        }
        else
            playlistIdeal(datos, k + 1, playlist, duracionViajeIda, duracionViajeVuelta, satisAct, playlistMejor, satisMejor, haySol);
    }

    duracionViajeVuelta -= datos.canciones[k].duracion;
    satisAct -= datos.canciones[k].satisfaccion;

    // No la selecciono
    playlist[k] = 0;
    if (k == playlist.size() - 1)
    {
        if (duracionViajeIda == datos.tiempoViajeIda &&
            duracionViajeVuelta == datos.tiempoViajeVuelta)
        {
            haySol = true;
            if (satisAct > satisMejor)
            {
                satisMejor = satisAct;
                playlistMejor = playlist;
            }
        }
    }
    else
        playlistIdeal(datos, k + 1, playlist, duracionViajeIda, duracionViajeVuelta, satisAct, playlistMejor, satisMejor, haySol);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    tDatos datos;

    // Leer los datos de la entrada
    cin >> datos.numCanciones >> datos.tiempoViajeIda >> datos.tiempoViajeVuelta;
    if (datos.numCanciones == 0 && datos.tiempoViajeIda == 0 && datos.tiempoViajeVuelta == 0)
        return false;

    for (int i = 0; i < datos.numCanciones; i++)
    {
        tCancion c;
        cin >> c;
        datos.canciones.push_back(c);
    }

    // Preparación datos para VA
    vector<int> playlist(datos.numCanciones, 0);
    vector<int> playlistMejor(datos.numCanciones);
    int duracionViajeIda = 0, duracionViajeVuelta = 0;
    int satisAct = 0, satisMejor = 0;
    bool haySol = false;

    // Resolver problema
    playlistIdeal(datos, 0, playlist, duracionViajeIda, duracionViajeVuelta, satisAct, playlistMejor, satisMejor, haySol);

    // Escribir sol
    if (haySol)
        cout << satisMejor << endl;
    else
        cout << "Imposible" << endl;

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
