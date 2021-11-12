#include "parser.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int estado = 1;

	char id[20];
	char nombre[30];
	char horasTrabajadas[20];
	char sueldo[20];
	int i=0;

	if(pFile != NULL)
	{
		fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^\n]", id, nombre, horasTrabajadas, sueldo);
		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^\n]", id, nombre, horasTrabajadas, sueldo);
			if(feof(pFile) != 0)
			{
				break;
			}

			Employee* empleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

			ll_add(pArrayListEmployee, empleado);
			empleado = NULL;
			i++;
		}
		estado = 0;
		fclose(pFile);
	}

	return estado;
}

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int estado = 1;
	int i = 0;

	if(pFile != NULL)
	{
		while(!feof(pFile))
		{
			if(feof(pFile) == 0)
			{
				Employee* punteroAEmpleado = employee_new();

				fread(punteroAEmpleado, sizeof(Employee), 1, pFile);

				ll_set(pArrayListEmployee, i, punteroAEmpleado);
				punteroAEmpleado = NULL;
				i++;
			}
		}
		estado = 1;
	}

	return estado;
}
