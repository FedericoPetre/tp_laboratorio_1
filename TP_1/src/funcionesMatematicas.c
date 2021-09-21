/*
 * funcionesMatematicas.c
 *
 *  Created on: 11 sep. 2021
 *      Author: Owner
 */

#include "funcionesMatematicas.h"
/**
 * @fn int sumar(float, float, float*)
 * @brief Esta funcion suma dos numeros y retorna el resultado a traves del puntero resultado
 *
 * @param numeroA: primer numero a sumar
 * @param numeroB : segundo numero a sumar
 * @param resultado : el resultado de la suma se guarda dentro de la direccion de memoria de este parametro
 * @return
 */
int sumar(float numeroA, float numeroB, float* resultado)
{
	int retorno;
	retorno = -1;
	float suma;
	if(resultado != NULL)
	{
		suma = numeroA + numeroB;
		retorno = 0;

		*resultado = suma;
	}
	return retorno;
}
/**
 * @fn int restar(float, float, float*)
 * @brief Esta funcion resta dos numeros y retorna el resultado a través del puntero resultado
 *
 * @param numeroA : primer numero a restar
 * @param numeroB : segundo numero a restar
 * @param resultado: el resultado de la resta se guarda dentro de la direccion de memoria de este parametro
 * @return
 */
int restar(float numeroA, float numeroB, float* resultado)
{
	int retorno;
	retorno = -1;
	float resta;

	if(resultado != NULL)
	{
		resta = numeroA - numeroB;
		retorno = 0;
		*resultado = resta;
	}
	return retorno;
}
/**
 * @fn int dividir(float, float, float*)
 * @brief Esta funcion divide dos numeros, siempre y cuando el segundo parametro no sea cero
 *
 * @param numeroA : Numero a ser dividido (dividendo)
 * @param numeroB: Numero que divide (divisor)
 * @param resultado el resultado de la division se guarda dentro de la direccion de memoria de este parametro
 * @return
 */
int dividir(float numeroA, float numeroB, float* resultado)
{
	int retorno;
	float division;
	retorno = -1;

	if(numeroB != 0 && resultado != NULL)
	{
		division = numeroA / numeroB;
		*resultado = division;
		retorno = 0;
	}

	return retorno;
}
/**
 * @fn int multiplicacion(float, float, float*)
 * @brief Esta funcion realiza la multiplicacion de los numeros ingresados
 *
 * @param numeroA : Primer numero a ser multiplicado
 * @param numeroB : Segundo numero a ser multplicado
 * @param resultado : el resultado de la multiplicacion entre ambos numeros se guarda dentro de la direccion de memoria de este parametro
 * @return
 */
int multiplicacion(float numeroA, float numeroB, float* resultado)
{
	int retorno;
	float multiplicacion;
	retorno = -1;

	if(resultado != NULL)
	{
		multiplicacion = numeroA * numeroB;
		retorno = 0;

		*resultado = multiplicacion;
	}

	return retorno;
}
/**
 * @fn int factorial(float, long*)
 * @brief Esta funcion calcula el factorial de un numero (solo funciona con numeros enteros y positivos)
 *
 * @param numero: Numero al que se le calcula el factorial (Por más que sea flotante, se chequea en la funcion de que sea entero, es decir sin parte decimal, y que sea positivo) (si es cero, por defincion matemática el factorial vale 1)
 * @param resultadoFactorial: El resultado obtenido de calcular el factorial del numero ingresado se guarda bajo la direccion de memoria de este parametro
 * @return
 */
int factorial(float numero, long* resultadoFactorial)
{
	int retorno= -1;
	int numeroConvertidoAEntero;
	long factorialNumero;
	int indice;
	factorialNumero = 1;

	numeroConvertidoAEntero = (int) numero;

	if(resultadoFactorial != NULL)
	{
		if(numero == numeroConvertidoAEntero && numero > 0)
		{
			retorno = 0;
			for(indice = 1; indice < numero+1; indice++)
			{
				factorialNumero = factorialNumero*indice;
			}
		}
		else
		{
			if(numero == 0)
			{
				factorialNumero = 1;
				retorno = 0;
			}
		}

		*resultadoFactorial = factorialNumero;
	}

	return retorno;
}
