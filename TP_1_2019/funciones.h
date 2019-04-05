/** \brief Funcion que pide un numero flotante para su utilizacion
 *
 * \param Recibe un mensaje.
 *
 * \return Un numero flotante
 *
 */

float pedirNumero(char[50]);

/** \brief Funcion que suma dos numeros flotantes
 *
 * \param un numero flotante
 * \param un numero flotante
 * \return el resultado de la suma entre dos numeros.
 *
 */

float funcionSuma(float,float);

/** \brief Funcion que resta dos numeros flotantes
 *
 * \param   un numero flotante
 * \param   un numero flotante
 * \return  el resultado de la esta entre el primer numero y el segundo
 *
 */

float funcionResta(float,float);

/** \brief Multiplica dos numeros flotantes
 *
 * \param un numero flotante
 * \param un numero flotante
 * \return el producto de la multiplicacion entre 2 numeros flotantes
 *
 */

float funcionMultiplicacion(float,float);

/** \brief Divide dos numeros flotantes
 *
 * \param un numero flotante
 * \param un numero flotante
 * \return el resultado de la division entre el primer y el segundo numero
 *
 */

float funcionDivision(float,float);

/** \brief Verifica si el numero pasado como parametro es un numero entero o un flotante
 *
 * \param el numero a verificar
 *
 * \return Retorna 0 si el numero es un numero flotante, si tiene numeros distintos a 0 detras de la coma. Retorna 1 si es un numero entero
 *
 */

int verificarEntero(float);


/** \brief Calcula el factorial de un numero
 *
 * \param el numero del que se quiere calcular el factorial
 *
 * \return el resultado del factorial del numero ingresado.
 *
 */

long long int funcionFactorial(int);
