/*
 * funcionMenuYValidaciones.c
 *
 *  Created on: 18 sep. 2021
 *      Author: Federico Petre
 */

#include "funcionesAuxiliaresYValidaciones.h"
/**
 * @fn int pedirYValidarFlotante(char*, char*, float*)
 * @brief Esta funcion pide y valida la entrada de un numero Flotante
 * @param mensaje mensaje que se muestra al usuario para pedir que ingrese un numero
 * @param mensajeError mensaje que se muestra en caso de que el usuario ingresó erroneamente el numero (es decir, si ingreso una variable no numerica)
 * @param numeroDeRetorno Se retorna el numero validado que el usuario ingreso a traves de un puntero
 * @return retorna 0 si todo salio bien, -1 si no
 */
int pedirYValidarFlotante(char* mensaje, char* mensajeError, float* numeroDeRetorno)
{
	float numeroPedido;
	int numeroValidacion;
	int retorno = -1;

	printf(mensaje);
	fflush(stdin);
	numeroValidacion = scanf("%f",&numeroPedido);

	while(numeroValidacion == 0)
	{
		printf(mensajeError);
		fflush(stdin);
		numeroValidacion = scanf("%f",&numeroPedido);

		if(numeroValidacion == 1)
		{
			break;
		}
	}

	retorno = 0;
	*numeroDeRetorno = numeroPedido;
	return retorno;
}
/**
 * @fn int pedirNumeroEntero(char*, char*, int, int, int*)
 * @brief Esta funcion pide y valida el ingreso de un numero entero
 *
 * @param mensaje Mensaje que se muestra para que el usuario ingrese un numero entero
 * @param mensajeError Mensaje que se muestra en caso de que el usuario ingrese una variable no numerica o un numero fuera del rango determinado
 * @param min Valor minimo del rango en que se debe encontrar el numero
 * @param max Valor maximo del rango en que se debe encontrar el numero
 * @param numeroRetornado Variable en la que se retornará el numero pedido (a través de un puntero)
 * @return retorno 0 salió todo bien
 */
int pedirNumeroEntero(char* mensaje, char* mensajeError, int min, int max, int* numeroRetornado)
{
	int retorno = -1;
	int numero;
	int numeroValidacion;

	if(mensaje != NULL && mensajeError != NULL && min<max)
	{
		printf(mensaje);
		fflush(stdin);
		numeroValidacion = scanf("%d",&numero);

		while(numeroValidacion == 0 || numero>max || numero<min)
		{
			printf(mensajeError);
			fflush(stdin);
			numeroValidacion = scanf("%d",&numero);
		}

		retorno = 0;
		*numeroRetornado = numero;
	}

	return retorno;
}

/**
 * @fn void mostrarMensaje(int, float, char*, char*)
 * @brief Esta funcion muestra, dependiendo el valor ingresado de la bandera, un mensaje u otro (incluyendo el numero ingresado).
 *
 * @param bandera: esta bandera representa el estado del ingreso del numero en el menu, si se ingresó el numero vale 1, sino vale 0
 * @param numero : Numero que se muestra junto con el segundo mensaje.
 * @param mensaje1 mensaje que se muestra si la bandera vale 0
 * @param mensaje2 mensaje mostrado si la bandera vale 1, este mensaje hay que incluirlo con la mascara del numero flotante, para que pueda mostrarlo
 */
void mostrarMensaje(int bandera, float numero, char* mensaje1, char* mensaje2)
{
	if(bandera == 0)
	{
		printf(mensaje1);
	}
	else
	{
		printf(mensaje2, numero);
	}
}
/**
 * @fn void mostrarMensajeFaltaOperando(int, int)
 * @brief Esta funcion avisa al usuario que operando falta ingresar, a traves del valor de las banderas de cada operando (retorna -1 en caso de que falte alguna o ambas). En caso de que no falte ingresar ningun operando, no muestra ningun mensaje y retorna 0.
 *
 * @param bandera1 : bandera que representa el estado del primer operando (si se ingresó o no)
 * @param bandera2: bandera que representa el estado del segundo operando (si se ingresó o no)
 * @return valor que retorna la funcion: 0 si ambos operandos ya fueron cargados, y -1 si falta uno o ambos
 */
int mostrarMensajeFaltaOperando(int bandera1, int bandera2)
{
	int retorno;
	retorno = -1;
	if(bandera1 == 0 && bandera2 == 0)
	{
		printf("Error, faltan ingresar ambos operandos\n");
	}
	else
	{
		if(bandera1 == 0 && bandera2 !=0)
		{
			printf("Error, falta ingresar el primer operando\n");
		}
		else
		{
			if(bandera2 == 0 && bandera1 != 0)
			{
				printf("Error, falta ingresar el segundo operando\n");
			}
			else
			{
				retorno = 0;
			}

		}
	}
	return retorno;
}

