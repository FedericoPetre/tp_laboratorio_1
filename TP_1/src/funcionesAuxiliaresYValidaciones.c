/*
 * funcionMenuYValidaciones.c
 *
 *  Created on: 18 sep. 2021
 *      Author: Owner
 */

#include "funcionesAuxiliaresYValidaciones.h"
/**
 * @fn void mostrarMensaje(int, float, char*, char*)
 * @brief Esta funcion muestra, dependiendo el valor ingresado de la bandera, un mensaje u otro (incluyendo el numero ingresado).
 *
 * @param bandera: esta bandera representa el estado del ingreso del numero en el menu, si se ingresó el numero vale 1, sino vale 0
 * @param numero : Numero que se muestra junto con el segundo mensaje.
 * @param mensaje1 mensaje que se muestra si la bandera vale 0
 * @param mensaje2 mensaje mostrado si la bandera no vale 0 (es decir, si la bandera vale 1), este mensaje hay que incluirlo con la mascara del numero flotante, ya que parte del mensaje es mostrar el numero ingresado
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
 * @fn void mensajeIngresoNumero(char*, char*)
 * @brief Esta funcion muestra dos mensajes en forma consecutiva para avisar al usuario que ya se ingreso el numero
 *
 * @param mensaje1
 * @param mensaje2
 */
void mensajeIngresoNumero(char* mensaje1, char* mensaje2)
{
	printf(mensaje1);
	printf(mensaje2);
	fflush(stdin);
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

