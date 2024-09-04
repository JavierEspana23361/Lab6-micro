
#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std; //Se utiliza el espacio de nombres std

struct datos{ //Estructura para pasar los datos a la función
    int num; //Numero ingresado por el usuario
    int suma; //Sumatoria de la serie
};

void *fibonacci(void *arg){ //Función que realiza la sumatoria
    datos *datos = (struct datos *)arg; //Casteo de la estructura
    int a = 0, b = 1, c; //Variables para la operación
    for(int i = 0; i < datos->num; i++){ //Ciclo para realizar la sumatoria
        c = a + b; //Operación de la serie
        a = b; //Asignación de valores
        b = c; //Asignación de valores
        if(c <= datos->num){ //Validación de los datos
            datos->suma += c; //Sumatoria de la serie
            cout << "Iteracion: " << i+1 << " - Valor: " << c << endl; //Impresión de los valores
        }
    }
    pthread_exit(NULL); //Salida del hilo
}

int main(){
    pthread_t hilo; //Declaración del hilo
    datos datos; //Declaración de la estructura
    datos.suma = 0; //Inicialización de la sumatoria
    cout << "Ingrese un numero entre 0 y 100: "; //Solicitud de datos al usuario
    cin >> datos.num; //Ingreso de datos
    if(datos.num < 0 || datos.num > 100){ //Validación de los datos
        cout << "Numero fuera de rango" << endl; //Mensaje de error
        exit(0); //Salida del programa
    }
    pthread_create(&hilo, NULL, fibonacci, (void *)&datos); //Creación del hilo
    pthread_join(hilo, NULL); //Espera a que el hilo termine
    cout << "Suma total: " << datos.suma << endl; //Impresión del resultado
    return 0; //Retorno del programa
}