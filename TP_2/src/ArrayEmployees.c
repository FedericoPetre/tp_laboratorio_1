/*
 * ArrayEmployees.c
 *
 *  Created on: 30 sep. 2021
 *      Author: Federico Petre
 */

#include "ArrayEmployees.h"

/**
 * @fn int initEmployees(Employee*, int)
 * @brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int initEmployees(Employee* list, int len)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > -1)
	{
		for(i=0; i<len; i++)
		{
			list[i].isEmpty = TRUE;
			retorno = 0;
		}
	}
	return retorno;
}

/**
 * @fn int findEmptyPosition(Employee*, int)
 * @brief To find the first empty position in the array employee
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @return int emptyPosition (-1) if ERROR [not found it, Invalid length or NULL pointer] - (0) if OK
 */
int findEmptyPosition(Employee* list, int len)
{
	int emptyPosition = -1;
	int i;

	if(list != NULL && len > -1)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty == TRUE)
			{
				emptyPosition = i;
				break;
			}
		}
	}

	return emptyPosition;
}

/**
 * @fn int addEmployee(Employee*, int, int, char[], char[], float, int)
 * @brief add in a existing list of employees the values received as parameters in the first empty position
 *
 * @param list employee*
 * @param len int
 * @param id int
 * @param name[] char
 * @param lastName[] char
 * @param salary float
 * @param sector int
 * @return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if OK.
 */
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
	int retorno = -1;

	if(list != NULL && len > -1 && name != NULL && lastName != NULL)
	{
		int emptyPosition;
		char answer;

		emptyPosition = findEmptyPosition(list, len);

		if(emptyPosition != -1)
		{
			list[emptyPosition].id = id;
			strcpy(list[emptyPosition].name, name);
			strcpy(list[emptyPosition].lastName, lastName);
			list[emptyPosition].salary = salary;
			list[emptyPosition].sector = sector;
			list[emptyPosition].isEmpty = FALSE;
			retorno = 0;

			printf("%-10s %-20s %-20s %-20s %-20s\n", "ID", "NOMBRE", "APELLIDO", "SALARIO", "SECTOR");
			showEmployee(list[emptyPosition]);
			pedirYValidarCaracter("Esta seguro que desea ingresarlo en el sistema? (s/n)\n", "Error, esta seguro que desea ingresarlo en el sistema? (s/n)\n", &answer);

			if(answer != 's')
			{
				list[emptyPosition].isEmpty = TRUE;
				retorno = -1;
			}
			else
			{
				printf("el empleado ha sido dado de alta exitosamente\n");
			}
		}
		else
		{
			printf("Error, no ha sido posible registrar al empleado, lugares llenos\n");
		}

	}
	return retorno;
}

/**
 * @fn int showEmployee(Employee)
 * @brief show an exist employee on the list of employees
 *
 * @param subject employee that will be showed
 * @return int Return (-1) if the subject is empty . (0) if ok
 */
int showEmployee(Employee subject)
{
	int retorno = -1;

	if(subject.isEmpty == FALSE)
	{
		printf("%-10d %-20s %-20s %-20.2f %-20d\n", subject.id, subject.name, subject.lastName, subject.salary, subject.sector);
		retorno = 0;
	}

	return retorno;
}

/**
 * @fn int printEmployees(Employee*, int)
 * @brief print the content of employee array
 *
 * @param list Employee*
 * @param lenght int
 * @return int Return (-1) if ERROR [Invalid length or NULL pointer] (0) if OK.
 */
int printEmployees(Employee* list, int lenght)
{
	int retorno = -1;
	int i;

	if(list != NULL && lenght > -1)
	{
		printf("%-10s %-20s %-20s %-20s %-20s\n", "ID", "NOMBRE", "APELLIDO", "SALARIO", "SECTOR");
		for(i=0; i<lenght; i++)
		{
			showEmployee(list[i]);
			retorno = 0;
		}
	}
	return retorno;
}

/**
 * @fn int registerEmployee(Employee*, int, int)
 * @brief to register an employee in the employee list
 *
 * @param list Employee* pointer to array of employees
 * @param len int length of the employee list
 * @param lastId Last registered id of the employee list
 * @return int (-1) if ERROR [NULL list or INVALID length or decide not to register employee]
 */
int registerEmployee(Employee* list, int len, int lastId)
{
	int retorno = -1;
	int idAux;
	char nameAux[51];
	char lastNameAux[51];
	float salaryAux;
	int sectorAux;
	int validacionRegistro;

	if(list != NULL && len > -1)
	{
		idAux = lastId + 1; // esta linea es para implementar el id incremental
		pedirYValidarCadena("Ingrese nombre de/la empleado/a (max 51 caracteres)", "Error, reingrese nombre de/la empleado/a (max 51 caracteres)", 51, nameAux);
		pedirYValidarCadena("Ingrese apellido de/la empleado/a (max 51 caracteres)", "Error, reingrese apellido de/la empleado/a (max 51 caracteres)", 51, lastNameAux);
		pedirYValidarFlotante("Ingrese salario a registrar (0-300000)", "Error, reingrese salario a registrar (0-300000)", 0, 300000, &salaryAux);
		pedirYValidarEntero("Ingrese sector del empleado (0-20)", "Error, reingrese sector del empleado (0-20)", 0, 20, &sectorAux);

		validacionRegistro = addEmployee(list, len, idAux, nameAux, lastNameAux, salaryAux, sectorAux);

		if(validacionRegistro != -1)
		{
			retorno = 0;
		}

	}
	return retorno;
}

/**
 * @fn int findEmployeeById(Employee*, int, int)
 * @brief find an Employee by Id end returns the index position in array.
 *
 * @param list Employee*
 * @param len int
 * @param id int
 * @return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 */
int findEmployeeById(Employee* list, int len, int id)
{
	int indexFound = -1;
	int i;

	if(list != NULL && len > -1)
	{
		for(i=0; i< len; i++)
		{
			if(list[i].id == id)
			{
				indexFound = i;
				break;
			}
		}
	}

	return indexFound;
}

/**
 * @fn int removeEmployee(Employee*, int, int)
 * @brief Remove an Employee by Id (plut isEmpty Flag in 1)
 *
 * @param list Employee*
 * @param len int
 * @param id int
 * @return int Return (-1) if Error [Invalid length or NULL pointer or if can't find an employee] (0) if OK.
 */
int removeEmployee(Employee* list, int len, int id)
{
	int retorno = 0;
	int indexRemove;

	if(list != NULL && len > -1)
	{
		indexRemove = findEmployeeById(list, len, id);

		if(indexRemove != -1)
		{
			list[indexRemove].isEmpty = TRUE;
			printf("El empleado fue dado de baja del sistema exitosamente\n");
			retorno = 1;
		}

	}
	return retorno;
}

/**
 * @fn int getDownEmployee(Employee*, int)
 * @brief get down an Employee by ID (ID taken from the console)
 *
 * @param list Employee*
 * @param len int length of the employee list
 * @return int return (-1) if Error [NULL list or invalid length or employee cannot be removed by id or employee not found] (0) if OK.
 */
int getDownEmployee(Employee* list, int len)
{
	int retorno = -1;
	int id;
	int indexRemove;
	char answer;

	if(list != NULL && len > 0)
	{
		pedirYValidarEnteroSinRango("Ingrese ID del empleado a dar de baja", "Error, reingrese ID entero, numérico, del empleado a dar de baja", &id);
		indexRemove = findEmployeeById(list, len, id);

		if(indexRemove != -1)
		{
			printf("Mostrando empleado a dar de baja....\n");
			printf("%-10s %-20s %-20s %-20s %-20s\n", "ID", "NOMBRE", "APELLIDO", "SALARIO", "SECTOR");
			showEmployee(list[indexRemove]);
			pedirYValidarCaracter("Esta seguro que desea darlo de baja del sistema? (s/n)\n", "Error, esta seguro que desea darlo de baja del sistema? (s/n)\n", &answer);

			if(answer != 'n' && list[indexRemove].isEmpty == FALSE)
			{
				removeEmployee(list, len, id);
				retorno = 0;
			}
			else
			{
				if(answer != 'n' && list[indexRemove].isEmpty == TRUE)
				{
					printf("Error, ese empleado ya fue dado de baja\n");
				}
			}
		}
		else
		{
			printf("Error, el empleado no fue encontrado\n");
			retorno = -1;
		}
	}
	return retorno;
}

/**
 * @fn int sortEmployees(Employee*, int, int)
 * @brief Sort the elements in the array of employees, the argument order indicates UP or DOWN order
 *
 * @param list Employee*
 * @param len int
 * @param order int [1] indicate UP - [0] indicate DOWN
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
 */
int sortEmployees(Employee* list, int len, int order)
{
	int retorno = -1;

	if(list != NULL && len>-1)
	{
		sortEmployeesBySectorAndLastName(list, len, order);
		retorno = 0;
	}

	return retorno;
}

/**
 * @fn int sortEmployeesBySectorAndLastName(Employee*, int, int)
 * @brief Sort employees list. First sort by sector and then by alphabetic last name
 *
 * @param list Employee*
 * @param len int
 * @param order int (0) to DOWN - (1) to UP
 * @return int Return (-1) if Error [Null list or invalid lenght] (0) if Ok.
 */
int sortEmployeesBySectorAndLastName(Employee* list, int len, int order)
{
	int retorno = -1;
	Employee employeeAux;
	int i;
	int flagSwap;
	int nuevoLimite;

	if(list != NULL && len > -1)
	{
		switch(order)
		{
		case 0:
			printf("Has elejido el orden 0- descendente\n");
			nuevoLimite = len -1;
			do{
				flagSwap = 0;
				for(i=0; i<nuevoLimite; i++)
				{
					if(list[i].sector <= list[i+1].sector)
					{
						employeeAux = list[i];
						list[i] = list[i+1];
						list[i+1] = employeeAux;
						flagSwap = 1;
					}
				}
				nuevoLimite--;
			}while(flagSwap);

			do{
				flagSwap = 0;
				for(i=0; i<nuevoLimite; i++)
				{
					if(list[i].sector == list[i+1].sector && strcmp(list[i].lastName, list[i+1].lastName) >= 0)
					{
						employeeAux = list[i];
						list[i] = list[i+1];
						list[i+1] = employeeAux;
						flagSwap = 1;
					}
				}
				nuevoLimite--;
			}while(flagSwap);

			break;
		case 1:
			printf("Has elejido el orden 1- ascendente\n");
			nuevoLimite = len -1;
			do{
				flagSwap = 0;
				for(i=0; i<nuevoLimite; i++)
				{
					if(list[i].sector >= list[i+1].sector)
					{
						employeeAux = list[i];
						list[i] = list[i+1];
						list[i+1] = employeeAux;
						flagSwap = 1;
					}
				}
				nuevoLimite--;
			}while(flagSwap);

			do{
				flagSwap = 0;
				for(i=0; i<nuevoLimite; i++)
				{
					if(list[i].sector == list[i+1].sector && strcmp(list[i].lastName, list[i+1].lastName) <= 0)
					{
						employeeAux = list[i];
						list[i] = list[i+1];
						list[i+1] = employeeAux;
						flagSwap = 1;
					}
				}
				nuevoLimite--;
			}while(flagSwap);

			break;
		default:
			printf("error de ordenación de empleados\n");
			break;
		}
	}
	return retorno;
}

/**
 * @fn int calculateTotalAndAverageSalaries(Employee*, int)
 * @brief To Calculate the total salary and the average salary of employee list
 *
 * @param list Employee* employee list
 * @param len int (list length)
 * @return Return (-1) if Error [Null list or invalid length] (0) if Ok.
 */
int calculateTotalAndAverageSalaries(Employee* list, int len)
{
	int retorno = -1;
	int i;
	int contadorSalarios=0;
	float acumuladorSalarios =0;
	float salarioPromedio;
	int contadorSalariosQueSuperanElPromedio=0;

	if(list != NULL && len > -1)
	{
		for(i=0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				acumuladorSalarios = acumuladorSalarios + list[i].salary;
				contadorSalarios++;
			}
		}

		if(contadorSalarios != 0)
		{
			salarioPromedio = acumuladorSalarios/contadorSalarios;
		}
		else
		{
			salarioPromedio = 0;
		}


		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].salary > salarioPromedio)
			{
				contadorSalariosQueSuperanElPromedio++;
			}
		}
		retorno = 0;

		printf("%-20s %-20s %-43s\n", "TOTAL SALARIO", "SALARIO PROMEDIO", "EMPLEADOS QUE SUPERAN EL SALARIO PROMEDIO");
		printf("%-20.2f %-20.2f %-43d\n", acumuladorSalarios, salarioPromedio, contadorSalariosQueSuperanElPromedio);
	}
	return retorno;
}
