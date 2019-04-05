float pedirNumero(char mensaje[50])
{
    float numero;

    printf("%s",mensaje);
    scanf("%f",&numero);

    return numero;
}


float funcionSuma(float a, float b)
{
    float retorno;

    retorno = a + b;

    return retorno;
}

float funcionResta(float a, float b)
{
    float retorno;

    retorno = a - b;

    return retorno;
}

float funcionMultiplicacion(float a, float b)
{
    float retorno;

    retorno = a * b;

    return retorno;
}

float funcionDivision(float a, float b)
{
    float retorno;

    retorno = a / b;

    return retorno;
}

long long int funcionFactorial(int numeroA)
{
    long long int resultado;

    if(numeroA == 0)
    {
        return 1;
    }
    else
    {
    resultado = numeroA * funcionFactorial(numeroA-1);

    return resultado;

    }
}

int verificarEntero(float a)
{
    int auxiliarFact;
    int entero = 0;

    auxiliarFact = (int)a;

    if(a - auxiliarFact == 0)
    {
        entero = 1;
    }

    return entero;
}
