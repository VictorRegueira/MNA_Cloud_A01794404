// ProgParalelaTarea1_A01794404.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

//Incluímos las librerías 
#include <iostream>
#include <omp.h>

//Eliminar los 'std::' de todos los comandos c
using namespace std;

//Definimos las constantes del programa
#define N 1000 //Cambia el tamaño de los arreglos.
#define chunk 100 //Es la cantidad de partes en que se distribuirá la carga de trabajo.
#define mostrar 10 //Valores del arreglo que se mostrarán.

//Función para imprimir valor de los arreglos
void imprimeArreglo(float* d);

int main()
{
    //Título
    cout << "_____Sumando Arreglos en paralelo_____\n";
    //Variables
    float a[N], b[N], c[N];//arreglos
    int i; //iterador
    int pedazos = chunk;//división de carga

    //Llenado de arreglos a y b
    for ( i = 0; i < N; i++)
    {
        //Aquí podemos cambiar el cálculo para tener distintos valores
        a[i] = i * 36;
        b[i] = (i + 3) * 10;
    }
       
    #pragma omp parallel for \
    shared(a,b,c, pedazos) private(i) \
    schedule(static, pedazos)

    for (i = 0; i < N; i++)
        c[i] = a[i] + b[i];
    
    cout << "Imprimiendo los primeros " << mostrar << "valores del arreglo a: " << endl;
    imprimeArreglo(a);
    cout << "Imprimiendo los primeros " << mostrar << "valores del arreglo b: " << endl;
    imprimeArreglo(b);
    cout << "Imprimiendo los primeros " << mostrar << "valores del arreglo c: " << endl;
    imprimeArreglo(c);
}

void imprimeArreglo(float* d) {
    for (int x = 0; x < mostrar; x++)
    {
        cout << d[x] << "-\t";
        
    }
    cout << endl;
}