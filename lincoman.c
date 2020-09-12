#include "lincoman.h"


int sumar(int num1, int num2)
{
    int resultado;
    int suma;

    suma= num1+num2;
}


float promedioEnteros(int num1, int num2)
{
    float promedio;
    promedio = (float) (num1+num2)/2;
    return promedio;
}

 int dividir(int num1, int num2)
 {
    float division;

    division= num1/num2;
    return division;
 }

 int restar(int num1, int num2)
 {
    int resta;

    resta= (float)num1-num2;
    return resta;

 }

 int multiplicar(int num1, int num2)
 {
    int multiplicacion;

    multiplicacion= num1*num2;
    return multiplicacion;
 }

long long factorialNum(int num1)
 {
    long long int factorial=1;

    for(int i = 1; i<=num1; i++)
    {

        factorial=factorial*i;
    }
    return factorial;
 }
