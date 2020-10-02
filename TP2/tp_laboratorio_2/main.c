#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"

#define TAM 1001
#define ASC 0
#define DESC 1

char menu();

int main()
{
    eEmployee empleado[TAM];
    char seguir = 's';
    char confirma;
    int primerId=1000;
    int respuesta;
    char orden;

    if(initEmployees(empleado, TAM)==0)//Inicia el programa verificando que sea un vector y que el indice no sea menor a 0
    {
        printf("Personas inicializadas con exito!!!\n\n");
        system("pause");
    }
    else//En caso de que unos de los datos no se valido el programa va a dar error
    {
        printf("Problemas al inicializar personas....\n\n");
        system("pause");
    }

    do
    {
        switch(menu())//Desarrollo del menu
        {

        case 'a':
            system("cls");
            printf(" ******** AGREGAR EMPLEADO *********\n\n");
            if(addEmployee(empleado, TAM, primerId)==0)
            {
                primerId++;
                printf("Alta exitosa!!!!\n\n");
            }
            else
            {
                printf("Problema al realizar el alta.....\n");
            }
            break;
        case 'b':
            respuesta= modifyEmployees(empleado, TAM);//Se le da un valor a respuesta para verificar si hay algun problema en los datos ingresados
            if(respuesta==0)
            {
                printf("Se realizo la modificacion con exito!!!");
            }
            else if(respuesta==1)
            {
                printf("Problemas al intentar modificar la persona\n");
            }
            else
            {
                printf("Modificacion cancelada por el usuario");
            }
            break;
        case 'c':
            system("cls");
            removeEmployee(empleado, TAM);
            respuesta= removeEmployee(empleado, TAM);//Se le da un valor a respuesta para verificar si hay algun problema en los datos ingresados
            if(respuesta==0)
            {
                printf("Se realizo la baja con exito!!!");
            }
            else if(respuesta==1)
            {
                printf("Problemas al intentar realizar la baja");
            }
            else
            {
                printf("Baja cancelada por el usuario");
            }
            break;
        case 'd':
            system("cls");
            printf("*** ABM Personas ***\n\n");
            printEmployees(empleado, TAM);//Se imprime la lista de empleados cargados
            printf(" ******** INFORMES *********\n\n");
            printf("1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector\n");
            printf("2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n");
            printf("Que opcion desea?: ");
            scanf("%d", &respuesta);

            switch(respuesta)
            {
            case 1:
                printf("Desea ordenarlo ascendente(a) o decendente(d)?: ");//se decide que criterio se le va a dar a la funcion
                fflush(stdin);
                scanf("%c", &orden);
                switch(orden)
                {


                case 'a':
                    if(sortEmployees(empleado, TAM, ASC) ==0)
                    {
                        printf("Se ordeno correctamente el vector\n\n");
                        printEmployees(empleado, TAM);
                    }
                    else
                    {
                        printf("Se produjo un error tratando de ordenar el vector\n\n");

                    }
                    break;
                case 'd':
                    if(sortEmployees(empleado, TAM, DESC) ==0)
                    {
                        printf("Se ordeno correctamente el vector\n");
                        printEmployees(empleado, TAM);
                    }
                    else
                    {
                        printf("Se produjo un error tratando de ordenar el vector\n");
                    }
                    break;
                }
                break;
            case 2:
                printf(" ******** SALARIOS *********\n\n");
                salario(empleado, TAM);//Saca promedio de los salarios, el total de todos, la cantidad de empleados y devuelve todos los resultados
                break;
            }
            break;
        case 'e':
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }

            break;
        default:
            printf("Opcion invalida!!!\n");

        }

        system("pause");

    }
    while( seguir == 's');


    return 0;
}

char menu()
{
    char opcion;
    system("cls");

    printf("*** ABM Personas ***\n\n");
    printf("a Alta\n");
    printf("b Modificar\n");
    printf("c Baja\n");
    printf("d Informar\n");
    printf("e Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());

    return opcion;
}
