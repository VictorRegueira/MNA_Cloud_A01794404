// ProgParalelaTarea1_A01794404.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

//Incluímos las librerías 
#include <iostream>
#include <omp.h>

//Eliminar los 'std::' de todos los comandos c
using namespace std;

//Definimos las constantes del programa
#define N 1000 //Cambia el tamaño de los arreglos.
#define chunk 500 //Es la cantidad de partes en que se distribuirá la carga de trabajo.
#define mostrar 12 //Valores del arreglo que se mostrarán.

//Función para imprimir valor de los arreglos
void imprimeArreglo(float *d);

int main()
{
    //Color de la terminal blanco con negro
    system("color f0");

    //Título
    cout << "_____Sumando Arreglos en paralelo_____\n\n";
    //Variables
    float a[N], b[N], c[N];//arreglos
    int i; //iterador
    int pedazos = chunk;//división de carga

    //Llenado de arreglos a y b
    for ( i = 0; i < N; i++)
    {
        //Aquí podemos cambiar el cálculo para tener distintos valores
        a[i] = (i + 25) * 13;
        b[i] = (i + 8) * 45;
    }
    //Definimos que la instrucción 'for' va a ser realizada en paralelo 
    #pragma omp parallel for \
    shared(a,b,c, pedazos) private(i) \
    schedule(static, pedazos)

    //El siguiente ciclo suma los valores de a + b y son guardados en c
    for (i = 0; i < N; i++)
        c[i] = a[i] + b[i];

    //Imprimimos los resultados
    cout << "Primeros " << mostrar << " valores del arreglo a: " << endl;
    imprimeArreglo(a);
    cout << "Primeros " << mostrar << " valores del arreglo b: " << endl;
    imprimeArreglo(b);
    cout << "Primeros " << mostrar << " valores del arreglo c: " << endl;
    imprimeArreglo(c);
}

//Declaramos la función vacía para imprimir los valores del arreglo
//La variable 'mostrar' controla el número de valores a mostrar
void imprimeArreglo(float* d) {
    int separador = 0;
    for (int x = 0; x < mostrar; x++)
    {
        cout <<"|" << d[x] << "|\t";
    }
    cout << endl;
}