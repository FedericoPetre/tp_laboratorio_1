#include "Employee.h"


/**
 * @fn Employee employee_new*()
 * @brief Para retornar un puntero a una posición de memoria libre de una variable de tipo Employee
 *
 * @return
 */
Employee* employee_new()
{
	Employee* pEmpleado = NULL;
	pEmpleado = (Employee*) malloc(sizeof(Employee));

	return pEmpleado;
}

/**
 * @fn Employee employee_newParametros*(char*, char*, char*)
 * @brief Retornar un puntero a empleado con los parametros ingresados cargados en la direccion de memoria apuntada por el puntero
 *
 * @param idStr Parametro ID (por puntero)
 * @param nombreStr Parametro Nombre (por puntero)
 * @param horasTrabajadasStr Parametro horas trabajadas (por puntero)
 * @return
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* punteroAEmpleado = NULL;
	punteroAEmpleado = employee_new();

	int idTransformado;
	int horasTrabajadasTransformadas;
	int sueldoTransformado;
	int retornoNombre;

	idTransformado = funciones_imput_transformarAEntero(idStr);
	retornoNombre = funciones_imput_verificarCadena(nombreStr);
	horasTrabajadasTransformadas = funciones_imput_transformarAEntero(horasTrabajadasStr);
	sueldoTransformado = funciones_imput_transformarAEntero(sueldoStr);

	if(punteroAEmpleado != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
	{
		if(retornoNombre == -1)
		{
			employee_setNombre(punteroAEmpleado,nombreStr);
		}
		else
		{
			printf("Error al cargar el nombre al nuevo empleado\nEl nombre debe estar sin espacios (solo letras)\n");
		}

		if(horasTrabajadasTransformadas != -1)
		{
			employee_setHorasTrabajadas(punteroAEmpleado, horasTrabajadasTransformadas);
		}
		else
		{
			printf("Error al cargar las horas trabajadas al nuevo empleado\n");
		}

		if(sueldoTransformado != -1)
		{
			employee_setSueldo(punteroAEmpleado, sueldoTransformado);
		}
		else
		{
			printf("Error al cargar el sueldo al nuevo empleado\n");
		}

		if(idTransformado != -1)
		{
			employee_setId(punteroAEmpleado, idTransformado);
		}
		else
		{
			printf("Error al cargar el ID al nuevo empleado\n");
		}

	}

	return punteroAEmpleado;
}

/**
 * @fn void employee_delete(Employee*)
 * @brief Para eliminar los datos del puntero empleado ingresado (limpiar la memoria//liberarla)
 *
 * @param this parametro Employee* puntero a eliminar
 */
void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
		this = NULL;
	}
}

/**
 * @fn int employee_setId(Employee*, int)
 * @brief Para asignarle un ID al campo ID del parametro Empleado pasado por puntero
 *
 * @param this parametro Empleado pasado por puntero
 * @param id ID a asignar al parametro empleado
 * @return Retorna 0 en caso de que el parametro this sea NULL y no poder asignar ID, caso contrario retorna 1
 */
int employee_setId(Employee* this,int id)
{
	int retorno = 0;

	if(this != NULL)
	{
		this->id = id;
		retorno = 1;
	}
	return retorno;
}

/**
 * @fn int employee_getId(Employee*, int*)
 * @brief Para obtener el ID del parámetro empleado pasado por referencia (puntero)
 *
 * @param this Parametro employee al cual se le tomara el valor ID
 * @param id puntero a ID que será retornado
 * @return Retorna 0 si this es NULL y id es NULL (parametros inválidos). Retorna 1 caso contrario, y el ID lo devolverá por el referencia id.
 */
int employee_getId(Employee* this,int* id)
{
	int retorno = 0;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 1;
	}
	return retorno;
}

/**
 * @fn int employee_setNombre(Employee*, char*)
 * @brief Para asignar un nombre al parámetro empleado ingresado (con el parámetro nombre)
 *
 * @param this parametro Employee ingresado
 * @param nombre Nombre a asignar al Employee ingresado
 * @return Retorna 0 si this es NULL o Nombre es NULL (o ambos). Caso contrario pudo asignar el nombre y retorna 1.
 */
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = 0;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 1;
	}
	return retorno;
}

/**
 * @fn int employee_getNombre(Employee*, char*)
 * @brief Para retornar el nombre del Employee this a través del puntero nombre
 *
 * @param this Employee* empleado al cual se obtiene el nombre
 * @param nombre char* se retorna por este puntero el nombre del empleado
 * @return Retorna 0 si hay error (this NULL). Caso contrario retorna 1 y devuelve el nombre por puntero nombre
 */
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = 0;

	if(this != NULL)
	{
		nombre = this->nombre;
		retorno = 1;
	}
	return retorno;
}

/**
 * @fn int employee_setHorasTrabajadas(Employee*, int)
 * @brief Para asignarle horas trabajadas a un empleado
 *
 * @param this Employee* empleado al cual se le asignan las horas trabajadas
 * @param horasTrabajadas int, horas trabajadas a asignar
 * @return Retorna 0 si hay error (this NULL o horas trabajadas inválidas). Retorna 1 si las pudo asignar.
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = 0;

	if(this != NULL && horasTrabajadas > 0)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 1;
	}
	return retorno;
}

/**
 * @fn int employee_getHorasTrabajadas(Employee*, int*)
 * @brief Para retornar las horas trabajadas de un empleado
 *
 * @param this *Employee empleado al cual se obtienen sus horas trabajadas
 * @param horasTrabajadas int* puntero, a través de el se retornan las horas trabajadas del empleado
 * @return Retorna 0 si hay algun parametro invalido (this NULL). Si pudo devolver las horas trabajadas retorna 1.
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = 0;

	if(this != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 1;
	}
	return retorno;
}

/**
 * @fn int employee_setSueldo(Employee*, int)
 * @brief Para asignarle un sueldo al empleado ingresado
 *
 * @param this Employee* empleado ingresado
 * @param sueldo int. Sueldo a asignar
 * @return Retorna 0 si hay algun parametro invalido (this NULL o sueldo negativo o cero). Caso contrario asigna el sueldo y retorna 1.
 */
int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = 0;

	if(this != NULL && sueldo > 0)
	{
		this->sueldo = sueldo;
		retorno = 1;
	}
	return retorno;
}

/**
 * @fn int employee_getSueldo(Employee*, int*)
 * @brief Para obtener el sueldo del empleado ingresado
 *
 * @param this Employee* empleado ingresado a traves de un puntero
 * @param sueldo int* se guarda el sueldo del empleado y se retorna por este puntero
 * @return Retorna 0 si el parametro this es NULL. Caso contrario retorna 1 y el sueldo a traves del puntero sueldo.
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = 0;

	if(this != NULL)
	{
		*sueldo = this->sueldo;
		retorno = 1;
	}
	return retorno;
}

/**
 * @fn int employee_showEmpleado(Employee* this)
 * @brief Para mostrar los datos de la estructura employee ingresada
 *
 * @param this Employee* empleado ingresado a traves de un puntero
 * @return Retorna 0 si el parametro this es NULL. Caso contrario retorna 1.
 */
int employee_showEmpleado(Employee* this)
{
	int retorno= 0;

	if(this != NULL)
	{
		printf("%-5d %-12s %-16d %-9d\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
		retorno = 1;
	}
	return retorno;
}

/**
 * @fn int employee_comparateByID(Employee* this1, Employee* this2)
 * @brief Para comparar los IDS de los empleados ingresados a traves de punteros void (se castean a employee dentro de la funcion)
 *
 * @param this1 void*
 * @param this2 void*
 * @return Retorna -1 si el id del empleado casteado de this1 es mayor que el de this2. Retorna 0 si son iguales. Retorna 1 si el de this2 es mayor.
 */
int employee_comparateByID(void* this1, void* this2)
{
	int retorno;

	Employee* pEmpleadoAux1;
	Employee* pEmpleadoAux2;

	if(this1 != NULL && this2 != NULL)
	{
		pEmpleadoAux1 = (Employee*) this1;
		pEmpleadoAux2 = (Employee*) this2;

		if((pEmpleadoAux1->id) > (pEmpleadoAux2->id))
		{
			retorno = -1;
		}
		else
		{
			if((pEmpleadoAux1->id) == (pEmpleadoAux2->id))
			{
				retorno = 0;
			}
			else
			{
				retorno = 1;
			}
		}
	}
	return retorno;
}


/**
 * @fn int employee_comparateByNombre(void* this1, void* this2)
 * @brief Para comparar los nombres de los empleados ingresados a traves de punteros void (se castean a employee dentro de la funcion)
 *
 * @param this1 void*
 * @param this2 void*
 * @return Retorna 1 si el nombre de this1 casteado a empleado esta antes alfabeticamente. Retorna 0 si es igual al de this2. Retorna -1 si está despues alfabeticamente.
 */
int employee_comparateByNombre(void* this1, void* this2)
{
	int retorno;
	int retornoComparacion;

	Employee* pEmpleadoAux1;
	Employee* pEmpleadoAux2;

	if(this1 != NULL && this2 != NULL)
	{
		pEmpleadoAux1 = (Employee*) this1;
		pEmpleadoAux2 = (Employee*) this2;

		retornoComparacion = strcmp((pEmpleadoAux1)->nombre, (pEmpleadoAux2)->nombre);

		if(retornoComparacion == -1)
		{
			retorno = 1;
		}
		else
		{
			if(retornoComparacion == 0)
			{
				retorno = 0;
			}
			else
			{
				retorno = -1;
			}
		}

	}
	return retorno;
}


