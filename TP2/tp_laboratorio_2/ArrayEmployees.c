#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"

#define TAM 1001
#define ASC 0
#define DESC 1


//Inicializar personas
int initEmployees(eEmployee empleado[], int tam)
{
    int error=1; //comienza con un error

    if(empleado != NULL && tam > 0)//verifica que el primer dato sea un vector y el segundo el tamaño mayor a 0
    {
        for(int i=0; i<tam; i++)//recorre los isEmpty del vector
        {
            empleado[i].isEmpty=1; //el lugar esta vacio
        }
        error= 0; //error 0 el programa funciona
    }
    return error;
}
//Agregar persona
int addEmployee(eEmployee empleado[], int tam, int id)
{
    int error=1;
    eEmployee addPersona;//auxiliar para cargar una nueva persona
    int indice;
    if(empleado != NULL && tam > 0 && id>0)//validacion de datos de entrada
    {
        indice = indiceLibre(empleado, tam); //se le da a indice el valor que retorna la funcion buscarLibre
        if(indice==-1)//Si indice devuelve -1 significa que no hay mas lugares libres en el sistema
        {
            printf("No hay lugar, sistema completo\n");
        }
        else //Si no....
        {
            addPersona.id = id;//1Se toma el dato de nuevo id que se da al principio y se asigna al primer empleado ingresado

            addPersona.isEmpty=0;//2Se declara isEmpty en 0 para indicar que el indice esta cargado

            printf("Ingrese nombre: ");
            fflush(stdin);
            scanf("%s", addPersona.name);//3se guarda el nombre

            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(addPersona.lastName);//3se guarda el apellido

            printf("Ingrese salario(00000.00): ");
            scanf("%f", &addPersona.salary);//4se guarda el salario

            while(addPersona.salary<0)
            {
                printf("Error, ingrese salario(00000.00): ");
                scanf("%f", &addPersona.salary);//4se guarda el salario
            }

            printf("Ingrese el sector: ");
            scanf("%d", &addPersona.sector);//5se guarda el sector

            empleado[indice]=addPersona;//Se pasan todos los datos guardados en el auxiliar hacia el vector usando la variable indice para marcar el lugar del indice
            error =0;//se retornan 0 errores
            }
        }

        return error;
    }
//Busca indice libre para agregar persona
    int indiceLibre(eEmployee empleado[], int tam)
    {
        int indice=-1;//Dentro del tamaño de la funcion el indice puede ser 0 o mayor
        for(int i=0; i<tam; i++)
        {
            if(empleado[i].isEmpty==1)//Cuando el valor de i sea ==1(lugar vacio) indice va a valer la direccion vacia del vector
            {
                indice=i;
                break;
            }
        }
        return indice;//retorna el valor del indice vacio en el vector
    }

//Modificar datos de empleado cargado
    int modifyEmployees(eEmployee empleado[], int tam)
    {
        int error=1;
        int indice;
        int id;
        char confirmar;
        char modificar;

        if(empleado !=NULL && tam >0)//validacion de datos de entrada
        {
            system("cls");//Se limpia la pantalla
            printf(" ******** MODIFICAR EMPLEADO *********\n\n");
            printEmployees(empleado, tam);//Funcion MostrarPersonas para ver los numeros de legajo
            printf("Ingrese id: ");
            scanf("%d", &id);

            indice = findEmployeeById(empleado, tam, id);//la variable indice toma el valor retornado por la funcion buscarPersona

            if(indice==-1)//Si no hay nada cargado se le da el valor -1
            {
                printf("No se encontro el legajo\n\n");
            }
            else//Si no....
            {
                printf("a Nombre\n");
                printf("b Apellido\n");
                printf("c Salario\n");
                printf("d Sector\n");
                printf("Que desea modificiar?: ");
                fflush(stdin);
                scanf("%c", &modificar);

                switch(modificar)
                {
                case 'a':
                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    gets(empleado[indice].name);
                    break;

                case 'b':
                    printf("Ingrese nuevo apellido: ");
                    fflush(stdin);
                    gets(empleado[indice].lastName);
                    break;
                case 'c':
                    printf("Ingrese nuevo salario: ");
                    scanf("%f", &empleado[indice].salary);

                    while(empleado[indice].salary<0)
                    {
                    printf("Error, ingrese salario(00000.00): ");
                    scanf("%f", &empleado[indice].salary);//4se guarda el salario
                    }

                    break;

                case 'd':
                    printf("Ingrese nuevo sector: ");
                    scanf("%d", &empleado[indice].sector);
                    break;
                }
                printf("Desea confirmar el cambio?(s=Si o n=No): ");
                fflush(stdin);
                scanf("%c", &confirmar);
                if(confirmar=='s')
                {
                    error=0;
                }
                else
                {
                    error=1;
                }
            }
        }
        return error;
    }
//Mostrar Todos los Empleados
    int printEmployees(eEmployee empleado[], int tam)
    {
        int error=1;//comienza con un error hasta que la funcion dia lo contrario
        int flag=0;

        if(empleado!= NULL && tam > 0)//verifica que el primer dato sea un vector y el segundo el tamaño mayor a 0
        {
            printf("   ID     NOMBRE      APELLIDO   SALARIO  SECTOR\n");
            printf(" -----------------------------------------------\n");
            for(int i=0; i<tam; i++)//analiza el tamaño del vector
            {
                if(empleado[i].isEmpty==0)// Si isEmpty dentro del vector es 0 entonces muestra la funcion mostrar persona
                {
                    printfEmployees(empleado[i]);
                    flag=1;//Si encuentra datos cargados en la lista el valor de la flag es 1
                }
            }
            printf("\n\n");
            if(flag==0)//Si no encuentra datos cargados en la lista el valor de la flag es 0
            {
                printf("    No hay personas en la lista\n\n");
            }
            error= 0;//Una vez verificado que sea un vector de tamaño mayor a 0 devuelvo 0 errores
        }

        return error;
    }


//Mostrar columna con datos de empleado
    void printfEmployees(eEmployee empleado)
    {
        printf("  %4d%12s%12s   %5.2f    %d\n", empleado.id, empleado.name, empleado.lastName, empleado.salary, empleado.sector);//Imprime los datos de la persona segun su posicion en el vector
    }

//Buscar empleado
    int findEmployeeById(eEmployee empleado[], int tam, int id)
    {
        int indice;//

        for(int i=0; i<tam; i++)
        {
            if(empleado[i].id==id&&empleado[i].isEmpty==0)//se revisa los id del vector ingresado hasta encontrar el que es igual al numero de id ingresado y que el indice este cargado"0"
            {
                indice=i;//Se le da el valor a indice donde esta cargado el numero de legajo que buscamos
                break;
            }
            else
            {
                indice= -1;
            }
        }
        return indice;
    }
//Eliminar del sistema a un empleado
    int removeEmployee(eEmployee empleado[], int tam)
    {
        int error=1;
        int indice;
        int id;
        char confirma;

        if(empleado !=NULL && tam >0)//validacion de datos de entrada
        {
            system("cls");//Se limpia la pantalla
            printf(" ******** ELIMINAR EMPLEADO *********\n\n");
            printEmployees(empleado, tam);//Funcion MostrarPersonas para ver los numeros de id
            printf("Ingrese id: ");
            scanf("%d", &id);

            indice = findEmployeeById(empleado, tam, id);//la variable indice toma el valor retornado por la funcion findEmployeeById

            if(indice==-1)//Si no hay nada cargado se le da el valor -1
            {
                printf("No hay ninguna peresona con ese id\n\n");
            }
            else
            {
                printfEmployees(empleado[indice]);//Se muestra la persona guardada en el indice indicado
                printf("Confirma eliminar a la persona?: ");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma=='s')
                {
                    empleado[indice].isEmpty=1;//Se vacia isEmpty en el indice indicado dentro del vector
                    error=0;//0errores
                }
                else
                {
                    error=2;//si el usuario cancela la baja devuelve un 2
                }
            }
        }
        return error;
    }
//Ordenar por alfabeticamente por apellido y sector
    int sortEmployees(eEmployee empleado[], int tam, int criterio)
    {
        int error=-1;
        eEmployee auxEmpleado;
        if(empleado!= NULL&&tam>0&&criterio>=0&&criterio<=1)//verificacion de parametros ingresados
        {
            for(int i=0; i<tam-1; i++)
            {
                for(int j=i+1; j<tam; j++)
                {
                    if(criterio==0&&empleado[i].lastName>empleado[j].lastName)//Si criterio sector es =0 y sexo i es menor a mayor
                    {
                        auxEmpleado=empleado[i];
                        empleado[i]=empleado[j];
                        empleado[j]=auxEmpleado;
                    }
                    else if(criterio==1&&empleado[i].lastName<empleado[j].lastName)//Si criterio sector es =0 y sexo i es mayor a sexo j mayor a menor
                    {
                        auxEmpleado=empleado[i];
                        empleado[i]=empleado[j];
                        empleado[j]=auxEmpleado;
                    }
                    else if(empleado[i].lastName==empleado[j].lastName&&empleado[i].sector>empleado[j].sector&&criterio==0)//si sexo i es == sexo j se deefine por altura menor a mayor
                    {
                        auxEmpleado=empleado[i];
                        empleado[i]=empleado[j];
                        empleado[j]=auxEmpleado;
                    }
                    else if(empleado[i].lastName==empleado[j].lastName&&empleado[i].sector<empleado[j].sector&&criterio==1)//si sexo i es == sexo j se deefine por altura menor a mayor
                    {
                        auxEmpleado=empleado[i];
                        empleado[i]=empleado[j];
                        empleado[j]=auxEmpleado;
                    }
                }
            }
            error=0;
        }
        return error;
    }

//Salario
    void salario(eEmployee empleado[], int tam)
    {
        float totalSalarios=0;     //acumulador de salarios
        float promedioSalarios;
        int contSalario=0;         //contador de salarios
        int salariosCargados=0;

        for(int i=0; i<tam; i++)
        {
            totalSalarios = totalSalarios + empleado[i].salary; //se suman todos los salarios

        }
        for(int i=0; i<tam; i++)
        {
            if(empleado[i].salary > 0)//Si el salario es mayor a 0 se cuenta como persona cargada para sacar el promerio
            {
                salariosCargados++;
            }
        }

        promedioSalarios=totalSalarios/salariosCargados; //el total de salarios se divide por el tamaño del vector
        for(int i=0; i<tam; i++)
        {
            if(empleado[i].salary > promedioSalarios)
            {
                contSalario++;//se cuenta la cantidad de salarios que superan el promedio de salarios
            }
        }
        printf("El total de todos los salarios es: %.2f\n", totalSalarios);
        printf("El promedio de los salarios es: %.2f\n", promedioSalarios);
        printf("La cantidad de salarios que superan el promedio son: %d\n", contSalario);
    }
