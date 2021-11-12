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

	int estado = 1;
	int retornoParser;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		retornoParser = parser_EmployeeFromText(pFile , pArrayListEmployee);
	}

	fclose(pFile);

	if(retornoParser == 0)
	{
		printf("Se cargaron los datos desde el archivo, en modo texto\n");
		estado = 0;
	}
	else
	{
		printf("Error al cargar los datos desde el archivo en modo texto\n");
	}

    return estado;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee) // terminar esta funcion y el parser binary tambien (cargar los datos al archivo binario tmb)
{
	FILE* pFile = NULL;
	pFile = fopen(path, "rb");

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		parser_EmployeeFromBinary(pFile, pArrayListEmployee);
	}
	fclose(pFile);

	printf("Se cargaron los datos desde el archivo, modo binario\n");

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
	int retorno = 1;

	int nuevoID;
	char nuevoIDTransformado[20];
	char nombreEmpleado[20];
	int horasTrabajadasEmpleado;
	char horasTrabajadasTransformadas[20];
	int sueldoEmpleado;
	char sueldoEmpleadoTransformado[20];
	int ultimoID;

	Employee* pNuevoEmpleado;

	if(pArrayListEmployee != NULL)
	{
		ultimoID = nexusEmployee_and_Ll_findLastID(pArrayListEmployee);
		nuevoID = ultimoID + 1;
		itoa(nuevoID, nuevoIDTransformado, 10);

		funciones_imput_pedirYValidarCadena("Ingrese nombre del nuevo empleado\n", "Error, reingrese nombre del nuevo empleado (solo letras, espacios o guiones)\n", 127, nombreEmpleado);

		funciones_imput_pedirYValidarEntero("Ingrese horas trabajadas del nuevo empleado (1-9999)\n", "Error, reingrese horas trabajadas del nuevo empleado (min: 1. max: 9999)\n", 1, 9999, &horasTrabajadasEmpleado);
		itoa(horasTrabajadasEmpleado, horasTrabajadasTransformadas, 10);

		funciones_imput_pedirYValidarEntero("Ingrese sueldo del nuevo empleado (1-200000)\n", "Error, reingrese sueldo del nuevo empleado (1-200000)\n", 1, 200000, &sueldoEmpleado);
		itoa(sueldoEmpleado, sueldoEmpleadoTransformado, 10);

		pNuevoEmpleado = employee_newParametros(nuevoIDTransformado, nombreEmpleado, horasTrabajadasTransformadas, sueldoEmpleadoTransformado);

		ll_add(pArrayListEmployee, pNuevoEmpleado);

		retorno = 0;

	}

    return retorno;
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
	int estado = 1;
	int opcion = -1;

	char* nombreAux = (char*) malloc(sizeof(char)*128);
	int* sueldoAux = (int*) malloc(sizeof(int));
	int* horasTrabajadasAux = (int*) malloc(sizeof(int));

	char* letraRespuesta = (char*) malloc(sizeof(char));
	int* pNumeroPedido = (int*) malloc(sizeof(int));

	Employee* pEmpleadoAux = (Employee*) malloc(sizeof(Employee));
	int indexEmpleado;

	int tamListEmployee = ll_len(pArrayListEmployee);

	funciones_imput_pedirYValidarEntero("Ingrese el id del empleado a modificar datos", "Error, ingrese el id del empleado a modificar datos (solo numeros)", 1, tamListEmployee, pNumeroPedido);

	indexEmpleado = nexusEmployee_and_Ll_findEmployeeByID(pArrayListEmployee, *pNumeroPedido);

		if(indexEmpleado != -1)
		{
			Employee* pEmpleado = ll_get(pArrayListEmployee, indexEmpleado);
			printf("Se encontro el empleado\nMostrando datos...\n");
			printf("%-5s %-12s %-16s %-9s\n", "ID", "NOMBRE", "HORAS TRABAJO", "SUELDO");
			employee_showEmpleado(pEmpleado);
			employee_setId(pEmpleadoAux,*pNumeroPedido);
			employee_setNombre(pEmpleadoAux, pEmpleado->nombre);
			employee_setHorasTrabajadas(pEmpleadoAux, pEmpleado->horasTrabajadas);
			employee_setSueldo(pEmpleadoAux, pEmpleado->sueldo);


			funciones_imput_pedirYValidarEntero("Que dato desea modificar?\n1- Nombre\n2- Horas trabajadas\n3- Sueldo\n4- Atras\n", "Error al elejir opcion, reingrese (opc: 1, opc: 2, opc: 3, opc: 4):\n1- Nombre\n2- Horas trabajadas\n3- Sueldo\n4- Atras\n", 1, 4, &opcion);
			switch(opcion)
			{
			case 1:
				printf("Elejiste modificar nombre\n");
				funciones_imput_pedirYValidarCadena("Ingrese nuevo nombre\n", "Error, reingrese nuevo nombre (letras, espacios y guiones solamente)\n", 128, nombreAux);
				employee_setNombre(pEmpleadoAux, nombreAux);
				printf("Mostrando Datos modificados:\n%-5s %-12s %-16s %-9s\n", "ID", "NOMBRE", "HORAS TRABAJO", "SUELDO");
				employee_showEmpleado(pEmpleadoAux);
				funciones_imput_pedirYValidarCaracter("Desea guardar la modificacion? (s: si, n: no)\n", "Error, desea guardar la modificacion anterior al empleado? (s: si, n: no) (ingrese una de las dos letras)\n", letraRespuesta);
				if(*letraRespuesta == 's')
				{
					ll_set(pArrayListEmployee, indexEmpleado, pEmpleadoAux);
					printf("Modificacion guardada con exito\n");
					estado = 0;
				}
				else
				{
					printf("Se ha cancelado la modificacion\n");
				}
				break;
			case 2:
				printf("Elejiste modificar horas trabajadas\n");
				funciones_imput_pedirYValidarEntero("Ingrese nuevas horas trabajadas (min: 1 max: 10000)\n","Error. reingrese nuevas horas trabajadas (min: 1 max: 10000)\n", 1, 10000, horasTrabajadasAux);
				employee_setHorasTrabajadas(pEmpleadoAux,*horasTrabajadasAux);
				printf("Mostrando Datos modificados:\n%-5s %-12s %-16s %-9s\n", "ID", "NOMBRE", "HORAS TRABAJO", "SUELDO");
				employee_showEmpleado(pEmpleadoAux);
				funciones_imput_pedirYValidarCaracter("Desea guardar la modificacion? (s: si, n: no)\n", "Error, desea guardar la modificacion anterior al empleado? (s: si, n: no) (ingrese una de las dos letras)\n", letraRespuesta);
				if(*letraRespuesta == 's')
				{
					ll_set(pArrayListEmployee, indexEmpleado, pEmpleadoAux);
					printf("Modificacion guardada con exito\n");
					estado = 0;
				}
				else
				{
					printf("Se ha cancelado la modificacion\n");
				}

				break;
			case 3:
				printf("Elejiste modificar sueldo\n");
				funciones_imput_pedirYValidarEntero("Ingrese nuevo sueldo (min: 0 max: 999999)\n","Error, reingrese nuevo sueldo (min: 0 max: 999999)\n", 0, 999999, sueldoAux);
				employee_setSueldo(pEmpleadoAux,*sueldoAux);
				printf("Mostrando Datos modificados:\n%-5s %-12s %-16s %-9s\n", "ID", "NOMBRE", "HORAS TRABAJO", "SUELDO");
				employee_showEmpleado(pEmpleadoAux);
				funciones_imput_pedirYValidarCaracter("Desea guardar la modificacion? (s: si, n: no)\n", "Error, desea guardar la modificacion anterior al empleado? (s: si, n: no) (ingrese una de las dos letras)\n", letraRespuesta);
				if(*letraRespuesta == 's')
				{
					ll_set(pArrayListEmployee, indexEmpleado, pEmpleadoAux);
					printf("Modificacion guardada con exito\n");
					estado = 0;
				}
				else
				{
					printf("Se ha cancelado la modificacion\n");
				}

				break;
			case 4:
				printf("Elejiste volver al menu principal\n");
				break;
			}
		}
	return estado;
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
	int* idEmpleado = (int*)malloc(sizeof(int));
	int indexEmpleado;
	int tamListEmpleados;
	int retorno = 1;

	char* respuesta = (char*)malloc(sizeof(char));

	Employee* pEmpleadoBuscado = NULL;

	if(pArrayListEmployee != NULL)
	{
		tamListEmpleados = ll_len(pArrayListEmployee);

		funciones_imput_pedirYValidarEntero("Ingrese el id del empleado a eliminar del sistema\n", "Error, reingrese el id del empleado a eliminar del sistema\n", 1, tamListEmpleados, idEmpleado);

		indexEmpleado = nexusEmployee_and_Ll_findEmployeeByID(pArrayListEmployee, *idEmpleado);

		if(indexEmpleado != -1)
		{
			printf("Empleado encontrado\n");
			pEmpleadoBuscado = ll_get(pArrayListEmployee, indexEmpleado);

			printf("%-5s %-12s %-16s %-9s\n", "ID", "NOMBRE", "HORAS TRABAJO", "SUELDO");
			employee_showEmpleado(pEmpleadoBuscado);

			funciones_imput_pedirYValidarCaracter("Esta seguro que desea eliminar este empleado del sistema? (s: si, n: no)\n", "Error, esta seguro que desea eliminar este empleado del sistema? (s: si, n: no) (ingrese una de las dos letras)\n", respuesta);

			if(*respuesta == 's')
			{
				ll_remove(pArrayListEmployee, indexEmpleado);
				printf("Empleado dado de baja del sistema exitosamente\n");
				retorno = 0;
			}
			else
			{
				printf("Se ha cancelado la baja del empleado del sistema\n");
			}
		}
	}
    return retorno;
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
			if(pEmpleado != NULL)
			{
				*(pEmpleados + i) = *pEmpleado;
			}
			pEmpleado = NULL;
		}

		for(int j=0; j<tamArrayEmpleados; j++)
		{
			if(j==0)
			{
				printf("%-5s %-12s %-16s %-9s\n", "ID", "NOMBRE", "HORAS TRABAJO", "SUELDO");
			}
			employee_showEmpleado((pEmpleados + j));
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
	FILE* pFile = NULL;
	pFile = fopen(path, "w");

	if(pFile != NULL)
	{
		fprintf(pFile,"%s,%s,%s,%s\n", "id", "nombre", "horasTrabajadas", "sueldo");
		fclose(pFile);
	}

	FILE* pFile1 = NULL;
	pFile1 = fopen(path, "a");
	int i;
	int tamLinkedList;

	if(pFile1 != NULL && pArrayListEmployee != NULL)
	{

		tamLinkedList = ll_len(pArrayListEmployee);

		for(i=0; i<tamLinkedList; i++)
		{
			Employee* pEmpleado = ll_get(pArrayListEmployee, i);

			if(pEmpleado != NULL)
			{
				fprintf(pFile,"%d,%s,%d,%d\n", pEmpleado->id, pEmpleado->nombre, pEmpleado->horasTrabajadas, pEmpleado->sueldo);
			}
			pEmpleado = NULL;

		}
		fclose(pFile1);
		printf("El archivo fue guardado exitosamente\n");
	}
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

