/*
 * funcionesMenuYSubmenus.c
 *
 *  Created on: 2 oct. 2021
 *      Author: Federico Petre
 */

#include "funcionesMenuYSubmenus.h"

/**
 * @fn void funcionSubmenuInformarEmpleados(Employee*, int)
 * @brief To print the employees under a condition (condition: 1- UP, 0- DOWN)
 *
 * @param list Employee* list. If employe isEmpty is FALSE, its will be shown
 * @param cantidadEmpleados Int (list length)
 */
void funcionSubmenuInformarEmpleados(Employee* list, int cantidadEmpleados)
{
	int opcionSubmenu;

	pedirYValidarEntero("Informar empleados de manera creciente o decrecientemente por apellido y sector? (Crec: 1 - Decrec: 0)\n", "Error, numero no v�lido, ingrese '1' para informar crecientemente, '0' para informar decrecientemente)\n", 0, 1, &opcionSubmenu);
	sortEmployees(list, cantidadEmpleados, opcionSubmenu);
	printEmployees(list, cantidadEmpleados);
}

void editEmployeeMenu(Employee* list, int len)
{
	int idWanted;
	int editOption;
	int indexFound;
	char answer;
	char nameAux[51];
	char lastNameAux[51];
	float salaryAux;
	int sectorAux;

	if(list != NULL && len > -1)
	{
		pedirYValidarEnteroSinRango("Ingrese el ID del empleado a modificar datos\n", "Ingrese un ID valido (numerico) del empleado a modificar\n", &idWanted);

		indexFound = findEmployeeById(list, len, idWanted);

		if(indexFound != -1)
		{
			printf("%-10s %-20s %-20s %-20s %-20s\n", "ID", "NOMBRE", "APELLIDO", "SALARIO", "SECTOR");
			showEmployee(list[indexFound]);

			pedirYValidarEntero("Que dato quiere modificar?\nElija opcion:\n1- Nombre\n2- Apellido\n3- Salario\n4- Sector\n", "Error, que dato quiere modificar?\nElija opcion (1-4):\n1- Nombre\n2- Apellido\n3- Salario\n4- Sector\n", 1, 4, &editOption);

			switch(editOption)
			{
				case 1:
					printf("Ha elejido la opcion 1-Modificar Nombre\n");
					pedirYValidarCaracter("Esta seguro que desea modificar el nombre? (s/n)\n", "Error, esta seguro que desea modificar el nombre? ('s'-si, 'n'-no)\n", &answer);
					if(answer == 's')
					{
						pedirYValidarCadena("Ingrese nuevo nombre\n", "Error, ingrese nuevo nombre (max 51 caracteres)", 52, nameAux);
						strcpy(list[indexFound].name, nameAux);
					}
					break;
				case 2:
					printf("Ha elejido la opcion 2-Modificar Apellido\n");
					pedirYValidarCaracter("Esta seguro que desea modificar el apellido? (s/n)\n", "Error, esta seguro que desea modificar el apellido? ('s'-si, 'n'-no)\n", &answer);
					if(answer == 's')
					{
						pedirYValidarCadena("Ingrese nuevo apellido\n", "Error, ingrese nuevo apellido (max 51 caracteres)", 52, lastNameAux);
						strcpy(list[indexFound].lastName, lastNameAux);
					}

					break;
				case 3:
					printf("Ha elejido la opcion 3-Modificar Salario\n");
					pedirYValidarCaracter("Esta seguro que desea modificar el salario? (s/n)\n", "Error, esta seguro que desea modificar el salario? ('s'-si, 'n'-no)\n", &answer);
					if(answer == 's')
					{
						pedirYValidarFlotante("Ingrese nuevo salario (0-300000)\n", "Error, reingrese nuevo salario (0-300000)\n", 0, 300000, &salaryAux);
						list[indexFound].salary = salaryAux;
					}
					break;
				case 4:
					printf("Ha elejido la opcion 4-Modificar Sector\n");
					pedirYValidarCaracter("Esta seguro que desea modificar el sector? (s/n)\n", "Error, esta seguro que desea modificar el sector? ('s'-si, 'n'-no)\n", &answer);
					if(answer == 's')
					{
						pedirYValidarEntero("Ingrese nuevo sector del empleado (0-20)", "Error, reingrese nuevo sector del empleado (0-20)", 0, 20, &sectorAux);
						list[indexFound].sector = sectorAux;
					}
					break;
				default:
					printf("Error al registrar la opcion elegida\n");
					break;
			}
			printf("Se ha realizado la modificacion con exito\n");
		}
		else
		{
			printf("Error, no se ha encontrado ese empleado\n");
		}
	}
	else
	{
		printf("Error en la modificacion del empleado\n");
	}
}

