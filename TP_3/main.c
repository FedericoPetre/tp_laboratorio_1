#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	funciones_imput_pedirYValidarEntero("Ingrese opcion:\n1-Cargar los datos de los empleados(modo texto)\n2-Cargar los datos de los empleados(modo binario)\n3-Alta de empleado\n4-Modificar datos de empleado\n5-Baja de empleado\n6-Listar empleados\n7-Ordenar empleados\n8-Guardar los datos de los empleados(modo texto)\n9-Guardar los datos de los empleados(modo binario)\n10-Salir\n", "Error, opcion no valida, reingrese opcion:\n1-Cargar los datos de los empleados(modo texto)\n2- Cargar los datos de los empleados(modo binario)\n3-Alta de empleado\n4-Modificar datos de empleado\n5-Baja de empleado\n6-Listar empleados\n7-Ordenar empleados\n8-Guardar los datos de los empleados(modo texto)\n9-Guardar los datos de los empleados(modo binario)\n10-Salir\n", 1, 10, &option);

    	switch(option)
        {
            case 1:
            	printf("Elejiste la opcion 1-Cargar los datos de los empleados(modo texto)\n");
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
            	printf("Elejiste la opcion 2-Cargar los datos de los empleados(modo binario)\n");
            	//controller_loadFromBinary("data.csv",listaEmpleados);

                break;
            case 3:
            	printf("Elejiste la opcion 3-Alta de empleado\n");

                break;
            case 4:
            	printf("Elejiste la opcion 4-Modificar datos de empleado\n");

                break;
            case 5:
            	printf("Elejiste la opcion 5-Baja de empleado\n");

                break;
            case 6:
            	printf("Elejiste la opcion 6-Listar empleados\n");

                break;
            case 7:
            	printf("Elejiste la opcion 7-Ordenar empleados\n");

                break;
            case 8:
            	printf("Elejiste la opcion 8-Guardar los datos de los empleados(modo texto)\n");
            	//controller_saveAsText("data.csv",listaEmpleados);

                break;
            case 9:
            	printf("Elejiste la opcion 9-Guardar los datos de los empleados(modo binario)\n");
            	//controller_saveAsBinary("data.csv",listaEmpleados);

                break;
            case 10:
            	printf("Elejiste la opcion 10-Salir\nSaliendo del sistema....\nHas salido del sistema\n");

                break;
            default:
            	printf("Error - Opcion no válida, reingrese opcion\n");
            	break;
        }

        if(option!=10)
        {
        	system("pause");
        }

    }while(option != 10);

    return 0;
}

