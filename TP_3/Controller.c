#include "Controller.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile = NULL;
	pFile = fopen(path, "r");

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		parser_EmployeeFromText(pFile , pArrayListEmployee);
	}
	fclose(pFile);

    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int tamArrayEmpleados;
	tamArrayEmpleados = ll_len(pArrayListEmployee);

	Employee* pEmpleados = NULL;
	pEmpleados = (Employee*) malloc (sizeof(Employee)*tamArrayEmpleados);

	if(pArrayListEmployee != NULL && tamArrayEmpleados > 0)
	{
		for(int i=0; i<tamArrayEmpleados; i++)
		{
			Employee* pEmpleado = ll_get(pArrayListEmployee, i);
			*(pEmpleados + i) = *pEmpleado;

			pEmpleado = NULL;
		}

		for(int j=0; j<tamArrayEmpleados; j++)
		{
			if(j==0)
			{
				printf("%-5s %-12s %-16s %-9s\n", "ID", "NOMBRE", "HORAS TRABAJO", "SUELDO");
			}
			printf("%-5d %-12s %-16d %-9d\n", (pEmpleados+j)->id, (pEmpleados+j)->nombre, (pEmpleados+j)->horasTrabajadas, (pEmpleados+j)->sueldo);
		}
	}

    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

