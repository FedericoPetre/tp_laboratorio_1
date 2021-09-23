/*
 * funcionMenuYValidaciones.h
 *
 *  Created on: 18 sep. 2021
 *      Author: Owner
 */

#ifndef FUNCIONESAUXILIARESYVALIDACIONES_H_
#define FUNCIONESAUXILIARESYVALIDACIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include "funcionesMatematicas.h"

int pedirYValidarFlotante(char* mensaje, char* mensajeError, float* numeroDeRetorno);
int pedirNumeroEntero(char* mensaje, char* mensajeError, int min, int max, int* numeroRetornado);
void mostrarMensaje(int bandera, float numero, char* mensaje1, char* mensaje2);
int mostrarMensajeFaltaOperando(int bandera1, int bandera2);



#endif /* FUNCIONESAUXILIARESYVALIDACIONES_H_ */
