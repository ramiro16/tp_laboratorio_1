#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{

    float num1,num2;
    float resultadoSuma,resultadoResta,resultadoMultiplicacion,resultadoDivision;
    char seguir = 's';
    int opcion;
    int flag1=0;
    int flag2=0;
    int flag3=0;
    int auxNumFactorial;
    long long int resultadoFactorial;
    long long int resultadoFactorial2;

    while(seguir == 's')
    {
        system("cls");

        printf("Elija una opcion\n\n");

        if(flag1 == 0)
        {
            printf("1-Ingresar 1er operando(A=x)\n");
        }
        else
        {
            printf("1-Ingresar 1er operando(A=%.2f)\n",num1);
        }

        if(flag2 == 0)
        {
            printf("2-Ingresar 2do operando(B=y)\n");
        }
        else
        {
            printf("2-Ingresar 2do operando(B=%.2f)\n",num2);
        }

        printf("3-Calcular todas las operaciones\n");
        printf("4-Informar resultados\n\n");
        printf("5-Salir\n\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                num1 = pedirNumero("Ingrese un valor para el primer numero: ");
                flag1 = 1;
                break;



            case 2:
                system("cls");
                num2 = pedirNumero("Ingrese un valor para el segundo numero: ");
                flag2 = 1;
                break;



            case 3:
                system("cls");

                if(flag1 != 0 && flag2 != 0)
                {
                    resultadoSuma = funcionSuma(num1,num2);
                    resultadoResta = funcionResta(num1,num2);
                    resultadoDivision = funcionDivision(num1,num2);
                    resultadoMultiplicacion = funcionMultiplicacion(num1,num2);
//--------------------------------------------------------------------------------------------------------//


                    auxNumFactorial = verificarEntero(num1);
                    if(auxNumFactorial == 0 || num1 > 20)
                    {
                        resultadoFactorial == -1;
                    }
                    else
                    {
                        resultadoFactorial = funcionFactorial(num1);
                    }


//-----------------------------------------------------------------------------------------------------//
                    auxNumFactorial = verificarEntero(num2);
                    if(auxNumFactorial == 0 || num2 > 20)
                    {
                        resultadoFactorial2 == -1;
                    }
                    else
                    {
                        resultadoFactorial2 = funcionFactorial(num2);
                    }



                    printf("Se han calculado los resultados con exito!\n\n");
                    flag3 = 1;
                    system("pause");
                }
                else if(flag1 == 0 || flag2 == 0)
                {
                    printf("No se pueden realizar las operaciones por falta de operandos.\n\n");
                    system("pause");
                }

                break;



            case 4:
                system("cls");

                if(flag3 != 0)
                {
                    printf("El resultado de %.2f + %.2f = %.2f\n",num1,num2,resultadoSuma);
                    printf("El resultado de %.2f - %.2f = %.2f\n",num1,num2,resultadoResta);

                    if(num2 == 0)
                    {
                        printf("No se puede dividir por 0\n");
                    }
                    else
                    {
                        printf("El resultado de %.2f / %.2f = %.2f\n",num1,num2,resultadoDivision);
                    }

                    printf("El resultado de %.2f * %.2f = %.2f\n",num1,num2,resultadoMultiplicacion);


                    if(resultadoFactorial == -1 || num1 > 20)
                    {
                        printf("No se puede realizar el factorial del primer numero\n");
                    }
                    else
                    {
                        printf("El resultado de %d ! es %lli\n",(int)num1,resultadoFactorial);
                    }

                    if(resultadoFactorial2 == -1 || num2 > 20)
                    {
                        printf("No se puede realizar el factorial del segundo numero\n\n");
                    }
                    else
                    {

                        printf("El resultado de %d! es %lld\n\n",(int)num2,resultadoFactorial2);
                    }

                    system("pause");
                }
                else
                {
                    printf("No hay resultados calculados para mostrar.\n\n");
                    system("pause");
                }

                break;
            case 5:
                seguir = 'n';
                break;
            default:
                system("cls");
                printf("ERROR. Reingrese una opcion valida.");
                system("pause");
                break;
        }
    }


    return 0;
}



