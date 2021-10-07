/*
 * funcionesInputs.c
 *
 *  Created on: 25 sep. 2021
 *      Author: Federico Petre
 */

#include "funcionesInputs.h"

/**
 * @fn void pedirYValidarCadena(char*, char*, int, char*)
 * @brief Pide, valida y retorna una cadena de caracteres
 *
 * @param mensaje Mensaje que se muestra para pedir la cadena de caracteres
 * @param mensajeError Mensaje que se muestra en caso de que la cadena de caracteres ingresada no es v�lida
 * @param max Cantidad m�xima de caracteres que puede poseer la cadena
 * @param cadenaDeRetorno Cadena de caracteres que retorna la funcion (a trav�s de un puntero)
 */
void pedirYValidarCadena(char* mensaje, char* mensajeError, int max, char* cadenaDeRetorno)
{
	char cadenaAux[300];
	int numeroValidacion1;
	int largoCadena;
	int numeroDeValidacion2;

	if(mensaje != NULL && mensajeError != NULL && cadenaDeRetorno != NULL && max>0)
	{
		printf("%s",mensaje);
		fflush(stdin);

		numeroValidacion1 = scanf("%[^\n]", cadenaAux);
		largoCadena = strlen(cadenaAux);
		numeroDeValidacion2 = verificarCadena(cadenaAux);

		while(numeroValidacion1 == 0 || largoCadena > max || numeroDeValidacion2 != -1)
		{
			printf("%s",mensajeError);
			fflush(stdin);

			numeroValidacion1 = scanf("%[^\n]", cadenaAux);
			largoCadena = strlen(cadenaAux);
			numeroDeValidacion2 = verificarCadena(cadenaAux);
		}
		strcpy(cadenaDeRetorno, cadenaAux);
	}
}

/**
 * @fn int verificarCadena(char*)
 * @brief Verifica que en todas las posiciones de la cadena no haya ningun caracter no valido (es decir que no sea una letra)
 *
 * @param cadena Cadena que se verifica toda sus posiciones
 * @return Si la cadena tiene alguna posicion cargada con un elemento que no sea un caracter, la funcion retorna esa posicion. De lo contrario retorna -1 (todo est� Ok).
 */
int verificarCadena(char* cadena)
{
	int index = -1;
	int longitudCadena;
	int i;

	longitudCadena = strlen(cadena);

	for(i=0; i<longitudCadena; i++)
	{
		if(isalpha(cadena[i]) == 0)
		{
			index = i;
			break;
		}

	}
	return index;
}

/**
 * @fn int pedirYValidarEntero(char*, char*, int, int, int*)
 * @brief pide, valida y retorna un numero entero, en un rango determinado
 *
 * @param mensaje Mensaje mostrado al usuario para pedir el ingreso de un n�mero entero
 * @param mensajeError Mensaje mostrado al usuario para avisar que el n�mero ingresado no es v�lido
 * @param min Valor m�nimo del rango en el que se debe encontrar el n�mero
 * @param max Valor m�ximo del rango en el que se debe encontrar el n�mero
 * @param numeroRetornado n�mero que retorna la funci�n (a trav�s de un puntero)
 * @return
 */
int pedirYValidarEntero(char* mensaje, char* mensajeError, int min, int max, int* numeroRetornado)
{
	int retorno = -1;
	int numeroValidacion;
	int numeroAux;

	if(mensaje != NULL && mensajeError != NULL && numeroRetornado != NULL && min < max)
	{
		printf("%s",mensaje);
		fflush(stdin);

		numeroValidacion = scanf("%d", &numeroAux);

		while(numeroValidacion == 0 || numeroAux < min || numeroAux > max)
		{
			printf("%s",mensajeError);
			fflush(stdin);

			numeroValidacion = scanf("%d", &numeroAux);
		}
		*numeroRetornado = numeroAux;
		retorno = 0;
	}
	return retorno;
}

/**
 * @fn int pedirYValidarFlotante(char*, char*, float, float, float*)
 * @brief pide valida y retorna un flotante en un rango determinado
 *
 * @param mensaje Mensaje mostrado al usuario para el ingreso del n�mero flotante
 * @param mensajeError Mensaje mostrado al usuario para avisar de que el n�mero ingresado no es v�lido
 * @param min Minimo valor del rango en el que se debe encontrar el n�mero
 * @param max M�ximo valor del rango en el que se debe encontrar el n�mero
 * @param numeroRetornado Numero flotante retornado por la funci�n (por puntero).
 * @return
 */
int pedirYValidarFlotante(char* mensaje, char* mensajeError, float min, float max, float* numeroRetornado)
{
	int retorno = -1;
	int numeroValidacion;
	float numeroAux;

	if(mensaje != NULL && mensajeError != NULL && numeroRetornado != NULL && min < max)
	{
		printf("%s",mensaje);
		fflush(stdin);

		numeroValidacion = scanf("%f", &numeroAux);

		while(numeroValidacion == 0 || numeroAux < min || numeroAux > max)
		{
			printf("%s",mensajeError);
			fflush(stdin);

			numeroValidacion = scanf("%f", &numeroAux);
		}
		*numeroRetornado = numeroAux;
		retorno = 0;
	}
	return retorno;
}

int pedirYValidarCaracter(char* mensaje, char* mensajeError, char* letraDeRetorno)
{
	int retorno = -1;
	char letra;
	int numeroValidacion;

	if(mensaje != NULL && mensajeError != NULL && letraDeRetorno != NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		numeroValidacion = scanf("%c", &letra);

		while(numeroValidacion == 0 || isalpha(letra) == 0)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			numeroValidacion = scanf("%c", &letra);
		}

		*letraDeRetorno = letra;
		retorno = 0;
	}
	return retorno;
}

int pedirYValidarEnteroSinRango(char* mensaje, char* mensajeError, int* numeroRetornado)
{
	int retorno = -1;
	int numeroValidacion;
	int numeroAux;

	if(mensaje != NULL && mensajeError != NULL && numeroRetornado != NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		numeroValidacion = scanf("%d", &numeroAux);

		while(numeroValidacion == 0)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			numeroValidacion = scanf("%d", &numeroAux);
		}

		*numeroRetornado = numeroAux;
		retorno = 0;
	}
	return retorno;
}

