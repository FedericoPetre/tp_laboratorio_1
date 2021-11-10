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
	Employee* pEmpleados = NULL;
	pEmpleados = (Employee*) malloc (sizeof(Employee)*1000);
	char id[20];
	char nombre[40];
	char horasTrabajadas[20];
	char sueldo[20];
	int i=0;

	if(pFile != NULL && pEmpleados != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]", id, nombre, horasTrabajadas, sueldo);
		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]", id, nombre, horasTrabajadas, sueldo);
			Employee* empleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

			*(pEmpleados + i) = *empleado;
			empleado = NULL;
			i++;
		}
		fclose(pFile);

		pArrayListEmployee -> pFirstNode -> pElement= pEmpleados;
		pArrayListEmployee -> size = i;
	}

    return 1;
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

    return 1;
}
