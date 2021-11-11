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
	char id[20];
	char nombre[30];
	char horasTrabajadas[20];
	char sueldo[20];
	int i=0;

	if(pFile != NULL)
	{
		fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^\n]", id, nombre, horasTrabajadas, sueldo);
		do{
			fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^\n]", id, nombre, horasTrabajadas, sueldo);
			printf("%s - %s - %s - %s\n", id, nombre, horasTrabajadas, sueldo);
			Employee* empleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
			ll_add(pArrayListEmployee, empleado);
			empleado = NULL;
			i++;
		}while(!feof(pFile));
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
