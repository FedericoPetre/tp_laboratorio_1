/*
 * funcionMenu.c
 *
 *  Created on: 7 oct. 2021
 *      Author: Owner
 */

#include "funcionMenu.h"

/**
 * @fn void funcionMenu_mostrarMenu(void)
 * @brief Se muestra el menu interactivo por consola
 *
 */
void funcionMenu_mostrarMenu(void)
{
	Employee empleados[CANTIDADEMPLEADOS];
	int option = -1;
	int lastEmployee = -1; // para implemetar el ID incremental
	int registers; // para saber si el empleado se registro o no en el sistema
	int empleadosEnElSistema = 0; // contador de empleados que se encuentran registrados en el sistema

	printf("-----Bienvenido al sistema de empleados de la empresa-----\n");
	initEmployees(empleados,CANTIDADEMPLEADOS);

	while(option != 5)
	{
		funcionesInputs_pedirYValidarEntero("Ingrese una opcion:\n1- ALTAS\n2- MODIFICAR\n3- BAJA\n4- INFORMAR\n5-SALIR\n", "Error, reingrese una opcion:\n1- ALTAS\n2- MODIFICAR\n3- BAJA\n4- INFORMAR\n5-SALIR\n", 1, 5, &option);

		switch(option)
		{
			case 1:
				printf("Elejiste la opcion 1-ALTAS\n");
				printf("Dando de alta un empleado\n");
				registers = registerEmployee(empleados, CANTIDADEMPLEADOS, lastEmployee);
				lastEmployee++;
				empleadosEnElSistema++;
				if(registers == -1)
				{
					empleadosEnElSistema--;
				}
				break;
			case 2:
				if(empleadosEnElSistema == 0)
				{
					printf("Error de opcion, primero hay que cargar un empleado\n");
				}
				else
				{
					printf("Elejiste la opcion 2- MODIFICAR\n");
					editEmployeeMenu(empleados, CANTIDADEMPLEADOS);
				}

				// Hacer el pedido del id, permitiendo modificar: o nombre o apellido o salario o sector
				break;
			case 3:
				if(empleadosEnElSistema == 0)
				{
					printf("Error de opcion, primero hay que cargar un empleado\n");
				}
				else
				{
					printf("Elejiste la opcion 3- BAJA\n");
					registers = getDownEmployee(empleados, CANTIDADEMPLEADOS);
					if(registers == 0)
					{
						empleadosEnElSistema--;
					}
				}
				break;
			case 4:
				if(empleadosEnElSistema == 0)
				{
					printf("Error de opcion, primero hay que cargar un empleado\n");
				}
				else
				{
					printf("Elejiste la opcion 4- INFORMAR\nInformando empleados del sistema....\nListado de empleados alfabeticamente por Apellido y Sector:\n");
					funcionSubmenuInformarEmpleados(empleados, CANTIDADEMPLEADOS);
					printf("Total y promedio de los salarios y cuantos superan el salario promedio:\n");
					calculateTotalAndAverageSalaries(empleados, CANTIDADEMPLEADOS);
				}
				break;
			case 5:
				printf("Elejiste la opcion 5- SALIR\nSaliendo del sistema...\nHas salido del sistema\n");
				break;
			default:
				printf("Error del sistema al registrar la opcion\n");
				break;
		}


		if(option != 5)
		{
			system("pause");
		}
	}

}
