
#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>


using namespace std;

struct datos{ //Estructura para pasar los datos a la función
    int num; //Numero ingresado por el usuario
    double suma; //Sumatoria de la serie
};

void *sumatoria(void *arg){ //Función que realiza la sumatoria
    datos *datos = (struct datos *)arg; //Casteo de la estructura
    double operate, operation = 0; //Variables para la operación
    for(int j = 0; j < datos->num; j++){ //Ciclo para realizar la sumatoria
        operate = pow(-1, j + 1)/j; //Operación de la serie
        operation += operate; //Sumatoria de la serie
    }
    datos->suma = operation; //Asignación de la sumatoria a la estructura
    pthread_exit(NULL); //Salida del hilo
}

int main(){
    pthread_t hilo; //Declaración del hilo
    datos datos; //Declaración de la estructura
    datos.suma = 0; //Inicialización de la sumatoria
    cout << "Ingrese un numero: "; //Solicitud de datos al usuario
    cin >> datos.num;  //Ingreso de datos
    if(datos.num < 0){ //Validación de los datos
        cout << "Numero fuera de rango" << endl; //Mensaje de error
        exit(0); //Salida del programa
    }
    pthread_create(&hilo, NULL, sumtaoria, (void *)&datos); //Creación del hilo
    pthread_join(hilo, NULL); //Espera a que el hilo termine
    cout << "Valor de la sumatoria: " << datos.suma << endl; //Impresión del resultado
    return 0; //Retorno del programa
}

