#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "ArrayEmployees.h"

int menu()
{
    int retorno;

    printf("1- Alta\n");
    printf("2- Baja\n");
    printf("3- Modificar\n");
    printf("4- Informar\n\n");
    printf("5- Salir\n");

    printf("\nSelecciona una opcion: ");
    scanf("%d",&retorno);

    return retorno;
}


int initEmployees(employee array[],int tam)
{
    int retorno = 0;
    int i;

    for(i=0;i<tam;i++)
    {
      array[i].isEmpty = 1;
    }

    return retorno;
}


void hardcodear(employee array[],int tam)
{
    int i;

    int auxId[5] = {100,101,102,103,104};
    char auxName[5][20] = {"Carlos","Maria","Patricia","Zaira","Belen"};
    char auxLastName[5][20] = {"Perez","Santos","Gomez","Gonzalez","Aragon"};
    float auxSalary[5] = {15000,20500,17500,26000,13275};
    int auxSector[5] = {1,4,3,2,1};
    int auxIsEmpty [5] = {0,0,0,0,0};

    for(i=0;i<tam;i++)
    {
        array[i].id = auxId[i];
        strcpy(array[i].name, auxName[i]);
        strcpy(array[i].lastname,auxLastName[i]);
        array[i].salary = auxSalary[i];
        array[i].sector = auxSector[i];
        array[i].isEmpty = auxIsEmpty[i];
    }

}

int printEmployees(employee array[],int tam)
{
    int retorno = 0;
    int i;

    for(i=0;i<tam;i++)
    {
        if(array[i].isEmpty == 0)
        {
            printf("%d%10s%12s%10.2f%5d\n",array[i].id,array[i].name,array[i].lastname,array[i].salary,array[i].sector);
        }
    }

    return retorno;
}

int findEmployeeById(employee array[],int tam, int id)
{
    int retorno = -1;
    int i;

    for(i=0;i<tam;i++)
    {
        if(array[i].isEmpty == 0 && array[i].id == id)
        {
            retorno = i;
        }
    }

    return retorno;
}

int removeEmployee(employee array[],int tam, int id)
{
    int retorno = -1;
    int auxInt;
    char rta;

    auxInt = findEmployeeById(array,tam,id);

    if(auxInt != -1)
    {
        system("cls");

        printf("Se ha encontrado al usuario:\n\n");
        printf("%d%10s%10s%10.2f%10d\n\n",array[auxInt].id,array[auxInt].name,array[auxInt].lastname,array[auxInt].salary,array[auxInt].sector);

        printf("Desea eliminar al usuario? S/N");
        fflush(stdin);
        rta = toupper(getch());

        while(rta != 'S' && rta != 'N')
        {
            printf("\nERROR. reingrese una opcion valida.\n");
            fflush(stdin);
            rta = toupper(getch());
        }

        if(rta == 'S')
        {
            array[auxInt].isEmpty = 1;
            printf("\n\nEmpleado dado de baja correctamente!\n\n");
            retorno = 0;
        }

        else if(rta == 'N')
        {
            printf("\n\nBaja cancelada.\n");
            retorno = 0;
        }

    }


    return retorno;
}


void modEmployee(employee array[],int tam)
{
    int i,opcion;
    int auxInt;

    printEmployees(array,tam);

    printf("\nIngrese ID de empleado que desea modificar:");
    scanf("%d",&auxInt);

    for(i=0;i<tam;i++)
    {
        if(auxInt == array[i].id && array[i].isEmpty == 0)
        {
            system("cls");
            printf("Se ha encontrado el usuario correspondiente al ID ingresado:\n\n");
            printf("%d%10s%10s%10.2f%10d\n\n",array[i].id,array[i].name,array[i].lastname,array[i].salary,array[i].sector);
            printf("Que desea modificar?\n\n1-Nombre\n2-Apellido\n3-Sueldo\n4-Sector\n5-Cancelar\n\n");
            scanf("%d",&opcion);

            switch(opcion)
            {
                case 1:
                    system("cls");
                    printf("Ingrese nuevo nombre:");
                    fflush(stdin);
                    gets(array[i].name);
                    printf("\nSe ha modificado el nombre!\n");
                    break;
                case 2:
                    system("cls");
                    printf("Ingrese nuevo apellido:");
                    fflush(stdin);
                    gets(array[i].lastname);
                    printf("\nSe ha modificado el apellido!\n");
                    break;
                case 3:
                    system("cls");
                    printf("Ingrese nuevo salario:");
                    scanf("%f",&array[i].salary);
                    printf("\nSe ha modificado el salario!\n");
                    break;
                case 4:
                    system("cls");
                    printf("Ingrese nuevo sector:");
                    scanf("%d",&array[i].sector);
                    printf("\nSe ha modificado el sector!\n");
                    break;
                case 5:
                    system("cls");
                    printf("Modificacion cancelada!\n");
                    break;
                default:
                    system("cls");
                    printf("\nERROR. Opcion invalida\n");
                    break;
            }
        }
    }
}


int sortEmployee(employee array[],int tam, int option)
{
    int retorno = -1;
    int i,j;
    employee auxStruct;


    switch(option)
    {
        case 1:
            for(i=0;i<tam-1;i++)
            {
                for(j=i+1;j<tam;j++)
                {
                    if(strcmp(array[i].lastname,array[j].lastname)<0)
                    {
                        auxStruct = array[j];
                        array[j] = array[i];
                        array[i] =  auxStruct;
                    }

                    if(strcmp(array[i].lastname,array[j].lastname)==0)
                    {
                        if(array[i].sector < array[j].sector)
                        {
                            auxStruct = array[j];
                            array[j] = array[i];
                            array[i] = auxStruct;
                        }
                    }
                }
            }

            system("cls");

            for(i=0;i<tam;i++)
            {
                if(array[i].isEmpty == 0)
                {
                    printf("%d%10s%12s%10.2f%5d\n",array[i].id,array[i].name,array[i].lastname,array[i].salary,array[i].sector);
                }

            }

            retorno = 0;

            break;


        case 2:
            for(i=0;i<tam-1;i++)
            {
                for(j=i+1;j<tam;j++)
                {
                    if(strcmp(array[i].lastname,array[j].lastname)>0)
                    {
                        auxStruct = array[j];
                        array[j] = array[i];
                        array[i] =  auxStruct;
                    }
                    if(strcmp(array[i].lastname,array[j].lastname) == 0)
                    {
                        if(array[i].sector > array[j].sector)
                        {
                            auxStruct = array[j];
                            array[j] = array[i];
                            array[i] = auxStruct;
                        }
                    }
                }
            }

            system("cls");

            for(i=0;i<tam;i++)
            {
                if(array[i].isEmpty == 0)
                {
                    printf("%d%10s%12s%10.2f%5d\n",array[i].id,array[i].name,array[i].lastname,array[i].salary,array[i].sector);
                }

            }

            retorno = 0;


            break;
        default:
            printf("OPCION INVALIDA");
            break;
    }


    return retorno;
}


void salarioTotalPromedio(employee array[],int tam)
{
    int contMasDinero = 0;
    float contador = 0;
    float acumulador = 0;
    float promedio;
    int i;

    for(i=0;i<tam;i++)
    {
        if(array[i].isEmpty == 0)
        {
            acumulador = acumulador + array[i].salary;
            contador++;
        }
    }

    promedio = acumulador / contador;

    for(i=0;i<tam;i++)
    {
        if(array[i].isEmpty == 0 && array[i].salary > promedio)
        {
            contMasDinero++;
        }
    }

    printf("\nEl promedio de sueldos es: %.2f\n",promedio);
    printf("\nCantidad de personas que cobran mas que el sueldo promedio: %d\n",contMasDinero);
}



int addEmployee(employee array[], int tam, char nombre[],char apellido[],float sueldo, int sector)
{
    int retorno = -1;
    int i;
    int auxId = 100;

    for(i=0;i<tam;i++)
    {
        if(array[i].isEmpty == 1)
        {
            strcpy(array[i].name,nombre);
            strcpy(array[i].lastname,apellido);
            array[i].salary = sueldo;
            array[i].sector = sector;
            array[i].id = auxId + i;
            array[i].isEmpty = 0;

            retorno = 0;
            break;
        }
    }

    return retorno;
}


