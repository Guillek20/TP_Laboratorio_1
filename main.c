
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "lincoman.h"
int main()
{
    int num1;
    int num2;
    int opciones;
    int flagOp1= 0;
    int flagOp2=0;
    int flagCalculo=0;
    int flagResultado=0;
    int suma;
    int resta;
    float division;
    int multiplicacion;
    int factoreo1;
    int factoreo2;



    char continuar = 's';


    do
    {
        printf("Calculadora - Trabajo Practico 1\n\n");
        if(flagOp1==0)
        {
            printf("1. Ingresar 1er operando (A=x)\n");
        }else
        {
                if(flagOp1==1)
                {
                    printf("1. Ingresar 1er operando (A=%d)\n", num1);
                }
        }
            if(flagOp2==0)
        {
                printf("2. Ingresar 2do operando (B=y)\n\n");
        }else
        {
            if(flagOp2==1)
            {
                printf("2. Ingresar 2do operando (B=%d)\n\n", num2);
            }

        }
        if(flagCalculo==0)
        {
            printf("3. Calcular todas las operaciones\n\n");
            printf("a) Calcular la suma (A+B)\n");
            printf("b) Calcular la resta (A-B)\n");
            printf("c) Calcular la division (A/B)\n");
            printf("d) Calcular la multiplicacion (A*B)\n");
            printf("e) Calcular el factorial (A!)\n\n");
        }else
        {
            if(flagCalculo==1)
            {
            printf("Calulo realizado con exito....\n");
            }

        }
        if(flagResultado==0)
        {
            printf("4. Informar resultados\n\n");
        }else
        {
            if(flagResultado==1)
            {
            printf("4. Informar resultados\n\n");
            printf("a) El resultado de A+B es: %d\n", suma);
            printf("b) El resultado de A-B es: %d\n", resta);
            if(division>0)
            {
                printf("c) El resultado de A/B es: %.2f\n", division);
            }else
            {
                    printf("c) El resultado de A/B es: negativo\n");

            }
            printf("d) El resultado de A*B es: %d\n", multiplicacion);
            printf("e) El factorial de A es: %d y El factorial de B es: %d\n\n", factoreo1, factoreo2);

            }
        }
        printf("5. Salir\n\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opciones);
        system("cls");

        switch(opciones)
        {
        case 1:
            printf("Ingrese el primer operador: \n");
            scanf("%d", &num1);
            flagOp1=1;
            system("cls");
            break;
        case 2:
            printf("Ingrese el segundo operador: \n");

            scanf("%d", &num2);
            flagOp2=1;
            system("cls");
            break;
        case 3:
            flagCalculo=1;
            break;
        case 4:
            suma=sumar(num1, num2);
            resta=restar(num1, num2);
            division=dividir(num1, num2);
            multiplicacion=multiplicar(num1, num2);
            factoreo1=factorialNum(num1);
            factoreo2=factorialNum(num2);
            flagResultado=1;
            break;
        case 5:
            return 0;
            break;
        default:
            printf("Error, ingrese un dato valido: \n");
            break;
    }
    }while(continuar=='s');
    return 0;
}












