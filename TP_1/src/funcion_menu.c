/*
 * funcion_menu.c
 *
 *  Created on: 23 sep. 2021
 *      Author: Federico Petre
 */

#include "funcion_menu.h"

void funcion_Menu(void)
{
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
	long long int factorialPrimerOperando;
	long long int factorialSegundoOperando;

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


		pedirNumeroEntero("Opcion elegida?: ", "Error, opción no valida: elija una opcion (1-5)\n", 1, 5, &opcion);
		printf("-----------------------------------\n");

		switch(opcion)
		{
			case 1:
				pedirYValidarFlotante("Elejiste ingresar el primer operando\nIngrese numero:\n", "Error, ingrese el primer operando \n", &primerOperando);
				banderaPrimerOperando = 1; //la bandera cambia a 1 porque ya se ingreso el primer operando
				printf("Se ingreso el primer operando exitosamente");
				break;
			case 2:
				pedirYValidarFlotante("Elejiste ingresar el segundo operando\nIngrese numero:\n", "Error, ingrese el segundo operando \n", &segundoOperando);
				banderaSegundoOperando = 1; // la bandera cambia a 1 porque ya se ingreso el segundo operando
				printf("Se ingreso el segundo operando exitosamente");
				break;
			case 3:
				printf("Elejiste calcular todas las operaciones\n");
				if(mostrarMensajeFaltaOperando(banderaPrimerOperando, banderaSegundoOperando) == 0)
				{
					banderaCalculos = 1; // la bandera cambia de estado porque ya estamos en condiciones de calcular todas las operaciones
					printf("Calcular la suma (%.2f+%.2f)\nCalcular la resta (%.2f-%.2f)\nCalcular la division (%.2f/%.2f)\nCalcular la multiplicacion (%.2f*%.2f)\nCalcular el factorial (%.2f!) y (%.2f!)\n",primerOperando, segundoOperando, primerOperando, segundoOperando, primerOperando, segundoOperando, primerOperando, segundoOperando, primerOperando, segundoOperando); // perdon por esta linea tan larga
					sumar(primerOperando, segundoOperando, &resultadoSuma);
					restar(primerOperando, segundoOperando, &resultadoResta);
					dividir(primerOperando, segundoOperando, &resultadoDivision);
					multiplicacion(primerOperando, segundoOperando, &resultadoMultiplicacion);
					factorial(primerOperando, &factorialPrimerOperando);
					factorial(segundoOperando, &factorialSegundoOperando);
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
					if(factorial(primerOperando, &factorialPrimerOperando) == 0 && factorial(segundoOperando, &factorialSegundoOperando) == 0)
					{
						printf("El factorial de %.2f es: %I64d y El factorial de %.2f es: %I64d\n",primerOperando ,factorialPrimerOperando ,segundoOperando, factorialSegundoOperando);
					}
					else
					{
						if(factorial(primerOperando, &factorialPrimerOperando) == 0 && factorial(segundoOperando, &factorialSegundoOperando) == -1)
						{
							printf("El factorial de %.2f es: %I64d\n", primerOperando, factorialPrimerOperando);
							printf("No es posible calcular el factorial de %.2f\n", segundoOperando);
						}
						else
						{
							if(factorial(primerOperando, &factorialPrimerOperando) == -1 && factorial(segundoOperando, &factorialSegundoOperando) == 0)
							{
								printf("No es posible calcular el factorial de %.2f\n", primerOperando);
								printf("El factorial de %.2f es: %I64d\n", segundoOperando, factorialSegundoOperando);
							}
							else
							{
								printf("No es posible calcular el factorial de %.2f\n", primerOperando);
								printf("No es posible calcular el factorial de %.2f\n", segundoOperando);
							}

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


}
