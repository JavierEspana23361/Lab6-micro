/*Desarrolle un programa que utilice Pthreads de C++, que permita determinar los números de la
serie Fibonacci que hay entre 0 y un número, el cual debe ser ingresado por el usuario. Indicar
que el número debe de estar entre 0 y 100. El programa debe de evaluar cada uno de los
números dentro del rango establecido.
Se debe calcular e imprimir el valor de la suma total de los números encontrados, en la rutina
principal, debe implementar paso de parámetros por medio de estructuras (de ser necesario).
La impresión debe ser amigable, para que pueda asociarse la iteración y el valor de la serie de
Fibonacci obtenido.
La serie de Fibonacci es una secuencia de números en la cual cada número es la suma de los
dos números anteriores. Comienza con 0 y 1, y a partir de ahí, cada número subsiguiente es la
suma de los dos anteriores.*/

#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

struct datos{
    int num;
    int suma;
};

void *fibonacci(void *arg){
    datos *datos = (struct datos *)arg;
    int a = 0, b = 1, c;
    for(int i = 0; i < datos->num; i++){
        c = a + b;
        a = b;
        b = c;
        if(c <= datos->num){
            datos->suma += c;
            cout << "Iteracion: " << i+1 << " - Valor: " << c << endl;
        }
    }
    pthread_exit(NULL);
}

int main(){
    pthread_t hilo;
    datos datos;
    datos.suma = 0;
    cout << "Ingrese un numero entre 0 y 100: ";
    cin >> datos.num;
    if(datos.num < 0 || datos.num > 100){
        cout << "Numero fuera de rango" << endl;
        exit(0);
    }
    pthread_create(&hilo, NULL, fibonacci, (void *)&datos);
    pthread_join(hilo, NULL);
    cout << "Suma total: " << datos.suma << endl;
    return 0;
}