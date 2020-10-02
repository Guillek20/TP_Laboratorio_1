#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} typedef eEmployee;


/** \brief Inicia el programa verificando que sea un vector y que el indice no sea menor a 0
 *
 * \param eEmployee empleado[] se carga el vector
 * \param int tam Se carga el tamaño del vector
 * \return Devuelvo 0 si no hay errores y 1 si no se pudo iniciar
 *
 */
int initEmployees(eEmployee empleado[], int tam);


/** \brief Carga a un nuevo empleado
 *
 * \param eEmployee empleado[] se carga el vector
 * \param int tam Se carga el tamaño del vector
 * \param int id Se carga nuevo id para el nuevo empleado
 * \return Devuelvo 0 si no hay errores y 1 hubo un error
 *
 */
int addEmployee(eEmployee empleado[], int tam, int id);


/** \brief Busca un indice libre para agregar un empleado
 *
 * \param eEmployee empleado[] se carga el vector
 * \param int tam Se carga el tamaño del vector
 * \return Devuelve el valor del indice libre en el vector
 *
 */
int indiceLibre(eEmployee empleado[], int tam);


/** \brief Modifica los datos de un empleado cargado en el sistema
 *
 * \param eEmployee empleado[] se carga el vector
 * \param int tam Se carga el tamaño del vector
 * \return Devuelvo 0 si no hay errores y 1 hubo un error
 *
 */
int modifyEmployees(eEmployee empleado[], int tam);

/** \brief  Imprime columna de empleado
 *
 * \param eEmployee empleado[] se carga el vector
 * \return No devuelve nada
 *
 */
void printfEmployees(eEmployee empleado);

/** \brief imprime la columna de todos los empleados cargados
 *
 * \param eEmployee empleado[] se carga el vector
 * \param int tam Se carga el tamaño del vector
 * \return Devuelvo 0 si no hay errores y 1 hubo un error
 *
 */
int printEmployees(eEmployee empleado[], int tam);

/** \brief Busca a un empleado por su id
 *
 * \param eEmployee empleado[] se carga el vector
 * \param int tam Se carga el tamaño del vector
 * \param int id Se carga nuevo id para el nuevo empleado
 * \return retorna el valor del indice donde esta ubicado el empleado segun su id
 *
 */
int findEmployeeById(eEmployee empleado[], int tam, int id);

/** \brief Borrar los datos del indice indicado en un vector
 *
 * \param eEmployee empleado[] se carga el vector
 * \param int tam Se carga el tamaño del vector
 * \return retorna -1 si no hay lugares vacios, 0 si se elimino correctamente y 1 si el usuario cancela
 *
 */
int removeEmployee(eEmployee empleado[], int tam);

/** \brief Para ordenar empleados mayor a menor/menor a mayor dependiendo del criterio ingresado  ASC o DESC
 *
 * \param eEmployee empleado[] se carga el vector
 * \param int tam Se carga el tamaño del vector
 * \param int criterio se carga el criterio ya definido ASC para ascendente y DESC para descendente
 * \return Devuelvo 0 si no hay errores y 1 hubo un error
 *
 */
int sortEmployees(eEmployee empleado[], int tam, int criterio);

/** \brief  Saca promedio de los salarios, el total de todos y la cantidad de empleados que superan promedio de salarios e imprime todos los resultados
 *
 * \param eEmployee empleado[] se carga el vector
 * \param int tam Se carga el tamaño del vector
 * \return No devuelve nada
 *
 */
void salario(eEmployee empleado[], int tam);
#endif // ARRAYEMPLOYEES_H_INCLUDED
#define ASC 0
#define DESC 1
