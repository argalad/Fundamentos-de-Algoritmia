// Nombre y Apellidos: Alberto Rodr�guez - Rabad�n Manzanares
// N�mero de juez: 77

#include <iostream>
#include <fstream>

using namespace std;
 
// Ecuaciones
// suma_nofinal(op1, op2) = op1     si op2 == 0
// suma_nofinal(op1, op2) = op2     si op1 == 0
// suma_nofinal(op1, op2) = suma_nofinal(op1 / 10, op2 / 10) * 10 + (op1 % 10 + op2 % 10)    si (op1 % 10 + op2 % 10) < 10
// suma_nofinal(op1, op2) = suma_nofinal(op1 / 10, op2 / 10) * 10 + (op1 % 10 + op2 % 10) % 10    si (op1 % 10 + op2 % 10) >= 10

int suma_nofinal (int op1, int op2)
{
    if (op1 == 0) return op2;
    else if (op2 == 0) return op1;
    else
    {
        int digito;
        digito = op1 % 10 + op2 % 10;
        if (digito > 9)
            digito = digito % 10;
        return suma_nofinal(op1 / 10, op2 / 10) * 10 + digito;
    }
}

// Ecuaciones
// suma_final(op1, op2, suma, pot) = suma    si (op1 == 0 && op2 == 0)
// suma_final(op1, op2, suma, pot) = suma_final(op1 / 10, op2 / 10, (op1 % 10 + op2 % 10) * pot + suma, 10 * pot)   si (op1 % 10 + op2 % 10) < 10
// suma_final(op1, op2, suma, pot) = suma_final(op1 / 10, op2 / 10, ((op1 % 10 + op2 % 10) % 10) * pot + suma, 10 * pot)   si (op1 % 10 + op2 % 10) >= 10


int suma_final(int op1, int op2, int suma, int pot)
{
    int digito;
    digito = op1 % 10 + op2 % 10;
    if (digito > 9)
        digito = digito % 10;
    if (op1 == 0 && op2 == 0)
        return suma;
    else
        return suma_final(op1 / 10, op2 / 10, digito * pot + suma, 10 * pot);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci�n, y escribiendo la respuesta
void resuelveCaso()
{
    int op1, op2;
    // Leer los datos de la entrada
    cin >> op1 >> op2;

    // Resolver problema
    int sol_nofinal = suma_nofinal(op1, op2);
    int sol_final = suma_final(op1, op2, 0, 1);

    // Escribir soluci�n
    cout << sol_nofinal << " " << sol_final << endl;
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
