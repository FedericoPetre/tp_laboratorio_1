/*
 ============================================================================
 Name        : TP_1.c
 Author      : Federico Petre
 Version     :
 Copyright   : Y
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "funcionesAuxiliaresYValidaciones.h"
#include "funcionesMatematicas.h"

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	float primerOperando;
	float segundoOperando;
	int banderaPrimerOperando;
	int banderaSegundoOperando;
	int banderaCalculos;
	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	float resultadoMultiplicacion;
	long factorialPrimerOperando;
	long factorialSegundoOperando;

	banderaPrimerOperando = 0; // las tres banderas indican si ya se ingresaron los operandos y si ya se realizaron los calculos (en ese caso valen 1)
	banderaSegundoOperando = 0;
	banderaCalculos = 0;

	printf("Bienvenidx a la calculadora FedepX\n");
	printf("-----------------------------------\n");

	while(opcion != 5)
	{
		printf("Elija una opcion:\n");
		mostrarMensaje(banderaPrimerOperando, primerOperando, "1- Ingresar 1er operando (A=x)\n", "1- Ingresar 1er operando (A=%.2f)\n");
		mostrarMensaje(banderaSegundoOperando, segundoOperando,"2- Ingresar 2do operando (B=y)\n", "2- Ingresar 2do operando (B=%.2f)\n");

		printf("3- Calcular todas las operaciones \n4- Informar resultados\n5- Salir\n");
		fflush(stdin);


		scanf("%d", &opcion);
		printf("-----------------------------------\n");

		switch(opcion)
		{
			case 1:
				mensajeIngresoNumero("Elejiste ingresar el primer operando\n", "Ingrese numero:\n");
				scanf("%f", &primerOperando);
				printf("Ingresaste el primer operando, ingrese el segundo operando o calcule todas las operaciones\n");
				banderaPrimerOperando = 1; //la bandera cambia a 1 porque ya se ingreso el primer operando
				break;
			case 2:
				printf("Elejiste ingresar el segundo operando\n");
				printf("Ingrese numero:\n");
				fflush(stdin);
				scanf("%f", &segundoOperando);
				printf("Ingresaste el segundo operando, ingrese el primer operando o calcule todas las operaciones\n");
				banderaSegundoOperando = 1; // la bandera cambia a 1 porque ya se ingreso el segundo operando
				break;
			case 3:
				printf("Elejiste calcular todas las operaciones\n");
				if(mostrarMensajeFaltaOperando(banderaPrimerOperando, banderaSegundoOperando) == 0)
				{
					sumar(primerOperando, segundoOperando, &resultadoSuma);
					restar(primerOperando, segundoOperando, &resultadoResta);
					dividir(primerOperando, segundoOperando, &resultadoDivision);
					multiplicacion(primerOperando, segundoOperando, &resultadoMultiplicacion);
					factorial(primerOperando, &factorialPrimerOperando);
					factorial(segundoOperando, &factorialSegundoOperando);

					banderaCalculos = 1; // la bandera cambia a 1 porque ya se calcularon todas las operaciones
					printf("se calcularon todas las operaciones");
				}
				break;
			case 4:
				printf("Elejiste informar los resultados\n");
				if(banderaCalculos == 0)
				{
					printf("error, primero hay que calcular las operaciones\n");
				}
				else
				{
					printf("El resultado de %.2f+%.2f es: %.2f\n",primerOperando, segundoOperando, resultadoSuma);
					printf("El resultado de %.2f-%.2f es: %.2f\n",primerOperando, segundoOperando, resultadoResta);
					if(dividir(primerOperando, segundoOperando, &resultadoDivision) == -1)
					{
						printf("No es posible dividir por cero\n");
					}
					else
					{
						printf("El resultado de %.2f/%.2f es: %.2f\n",primerOperando, segundoOperando, resultadoDivision);
					}
					printf("El resultado de %.2f*%.2f es: %.2f\n",primerOperando, segundoOperando, resultadoMultiplicacion);
					if(factorial(primerOperando, &factorialPrimerOperando) != -1 && factorial(segundoOperando, &factorialSegundoOperando) != -1)
					{
						printf("El factorial de %.2f es: %ld y El factorial de %.2f es: %ld\n",primerOperando ,factorialPrimerOperando ,segundoOperando, factorialSegundoOperando);
					}
					else
					{
						if(factorial(primerOperando, &factorialPrimerOperando) != -1 && factorial(segundoOperando, &factorialSegundoOperando) == -1)
						{
							printf("El factorial de %.2f es: %ld\n", primerOperando, factorialPrimerOperando);
							printf("No es posible calcular el factorial de %.2f\n", segundoOperando);
						}
						else
						{
							printf("No es posible calcular el factorial de %.2f\n", primerOperando);
							printf("El factorial de %.2f es: %ld\n", segundoOperando, factorialSegundoOperando);
						}

					}

				}
				break;
			case 5:
				printf("elejiste salir, fin del programa\n");
				break;
			default:
				printf("opcion no valida, ingrese otra opcion (1-5)\n");
				break;
		}
		if(opcion != 5)
		{
			printf("\n-----------------------------------\n");
			system("pause");
			printf("\n\n\n");
		}
	}//fin del while

	return EXIT_SUCCESS;
}
