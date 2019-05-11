typedef struct
{
    int id;
    char name[51];
    char lastname[51];
    float salary;
    int sector;
    int isEmpty;

}employee;


/** \brief Muestra un menu con opciones
 *
 * \param No recibe parametros
 *
 * \return Devuelve la opcion en un valor entero
 *
 */
int menu();

/** \brief Inicializa todas las posiciones del array de empleados en 1
 *
 * \param Array de tipo employee
 * \param variable de control tamaño
 * \return valor entero 0 si se inicializo correctamente, -1 si no pudo inicializar
 *
 */
int initEmployees(employee[],int);

/** \brief Agrega un empleado al array de empleados
 *
 * \param array de tipo employee
 * \param variable de control de tamaño
 * \param array de char para el nombre
 * \param array de char para el apellido
 * \param flotante para el salario
 * \param entero para el sector
 * \return retorno -1 si no puede agregar el usuario, 0 si logra cargar el usuario correctamente
 *
 */
int addEmployee(employee[],int,char[],char[],float,int);

/** \brief Encuentra un empleado por el ID como referencia
 *
 * \param array de tipo employee
 * \param variable de control de tamaño
 * \param variable tipo int. representa el id a buscar
 * \return retorna el indice del usuario encontra o -1 si no logra encontrar nada
 *
 */

int findEmployeeById(employee[],int,int);

/** \brief Muestra la lista de empleados por pantalla
 *
 * \param array de tipo employee
 * \param variable de control de tamaño
 * \return retorna 0 si pudo mostrar correctamente, retorna -1 si no pudo mostrar.
 *
 */

int printEmployees(employee[],int);

/** \brief Elimina una empleado del array
 *
 * \param array de tipo employee
 * \param variable de control de tamaño de array
 * \param variable entera, representa el id del usuario a eliminar
 * \return retorna -1 en caso de error. 0 si logra dar de baja correctamente
 *
 */

int removeEmployee(employee[],int, int);

/** \brief Ordena el array ascendente o descendentemente
 *
 * \param array de tipo employee
 * \param variable de control de tamaño
 * \param variable entera. 1 para ordenar ascendetenmete, 0 para ordenar descendetemente
 * \return -1 en caso de error. 0 en caso de funcionar correctamente
 *
 */

int sortEmployee(employee[],int,int);

/** \brief Modifica datos del empleado
 *
 * \param array de tipo empleado
 * \param variable entera de control de tamaño
 * \return
 *
 */

void modEmployee(employee[],int);

/** \brief Calcula el promedio de salario y la cantidad de salarios sobre el promedio
 *
 * \param array de tipo employee
 * \param variable de control de tamaño
 * \return
 *
 */

void salarioTotalPromedio(employee[],int);

/** \brief hardcodea datos de usuarios para testeo de programa
 *
 * \param array de tipo employee
 * \param variable de control de tamaño
 * \return
 *
 */

void hardcodear(employee[],int);

