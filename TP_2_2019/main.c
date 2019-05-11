#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "ArrayEmployees.h"

#define TAME 7


int main()
{
    char rta = 's';
    int opcion, aux;

    int auxIdentificador;
    char auxNombre[20];
    char auxApellido[20];
    float auxSalario;
    int auxSector;
    int flagHayEmpleados = 0;

    employee empleados[TAME];

    aux = initEmployees(empleados, TAME);
    if(aux == 0)
    {
        printf("Empleados inicializados correctamente");
    }
    else
    {
        printf("No se han podido inicializar los empleados");
    }

    hardcodear(empleados,5);
    flagHayEmpleados = 1;

    system("cls");

    while(rta == 's')
    {
        system("cls");

        opcion = menu();

        switch(opcion)
        {
            case 1:
                system("cls");
                printf("Ingrese nombre:");
                fflush(stdin);
                gets(auxNombre);

                printf("Ingrese apellido:");
                fflush(stdin);
                gets(auxApellido);

                printf("Ingrese salario:");
                scanf("%f",&auxSalario);

                printf("Ingrese sector (1-4):");
                scanf("%d",&auxSector);

                while(auxSector < 1 || auxSector > 4)
                {
                    printf("Opcion invalida, reingrese opcion");
                    scanf("%d",&auxSector);
                }

                aux = addEmployee(empleados,TAME,auxNombre,auxApellido,auxSalario,auxSector);

                if(aux == -1)
                {

                    printf("\nNo se ha podido dar de alta al empleado\n\n");
                    system("pause");
                }

                else if(aux == 0)
                {

                    printf("\nAlta dada correctamente!\n\n");
                    system("pause");
                }


                break;

            case 2:
                system("cls");

                if(flagHayEmpleados ==1)
                {
                    printEmployees(empleados,TAME);
                    printf("\nSeleccione el ID del empleado a dar de baja:");
                    scanf("%d",&auxIdentificador);
                    removeEmployee(empleados,TAME,auxIdentificador);
                    printf("\n");
                    system("pause");
                }
                else
                {
                    printf("No hay empleados para dar de baja\n\n");
                    system("pause");
                }
                break;

            case 3:
                system("cls");

                if(flagHayEmpleados == 1)
                {
                    modEmployee(empleados,TAME);
                    printf("\n");
                    system("pause");
                }
                else
                {
                    printf("No hay empleados para modificar\n\n");
                    system("pause");
                }

                break;

            case 4:
                system("cls");

                if(flagHayEmpleados == 1)
                {


                printf("Elija una opcion:\n\n1-Listar empleados por apellido y sector\n2-Calcular promedio de sueldos\n\n");
                scanf("%d",&opcion);
                    switch(opcion)
                    {
                        case 1:
                            system("cls");
                            printf("Ordenamiento:\n\n1-Ascendente\n2-Descendente\n\n");
                            scanf("%d",&opcion);
                            while(opcion != 1 && opcion != 2)
                            {
                                printf("Opcion invalida, reingrese una opcion valida\n");
                                scanf("%d",&opcion);
                            }

                            if(opcion == 1)
                            {
                                sortEmployee(empleados,TAME,1);
                                printf("\n");
                                system("pause");
                            }
                            if(opcion == 2)
                            {
                                sortEmployee(empleados,TAME,2);
                                printf("\n");
                                system("pause");
                            }


                            break;
                        case 2:
                            system("cls");
                            salarioTotalPromedio(empleados,TAME);
                            printf("\n");
                            system("pause");
                            break;
                        default:
                            break;
                    }
                }
                else
                {
                    printf("No hay empleados cargados\n\n");
                    system("pause");
                }
                printf("\n");

                break;

            case 5:
                system("cls");
                rta = 'n';
                break;
        }

    }

    return 0;
}
