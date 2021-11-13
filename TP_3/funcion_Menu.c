/*
 * funcion_Menu.c
 *
 *  Created on: 13 nov. 2021
 *      Author: Federico Petre
 */

#include "funcion_Menu.h"

void funcionMenu(void)
{
	setbuf(stdout, NULL);
    int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    int banderaEmpleadosModoTexto = 0;
    int banderaEmpleadosModoBinario = 0;
    int cantidadEmpleados = 0;

    do{
    	funciones_imput_pedirYValidarEntero("Ingrese opcion:\n1-Cargar los datos de los empleados(modo texto)\n2-Cargar los datos de los empleados(modo binario)\n3-Alta de empleado\n4-Modificar datos de empleado\n5-Baja de empleado\n6-Listar empleados\n7-Ordenar empleados\n8-Guardar los datos de los empleados(modo texto)\n9-Guardar los datos de los empleados(modo binario)\n10-Salir\n", "Error, opcion no valida, reingrese opcion:\n1-Cargar los datos de los empleados(modo texto)\n2-Cargar los datos de los empleados(modo binario)\n3-Alta de empleado\n4-Modificar datos de empleado\n5-Baja de empleado\n6-Listar empleados\n7-Ordenar empleados\n8-Guardar los datos de los empleados(modo texto)\n9-Guardar los datos de los empleados(modo binario)\n10-Salir\n", 1, 10, &option);

    	switch(option)
        {
            case 1:
            	printf("Elejiste la opcion 1-Cargar los datos de los empleados(modo texto)\n");
            	if(banderaEmpleadosModoBinario == 1)
            	{
            		printf("Error al cargar los datos modo texto: los datos de los empleados ya estan cargados en modo binario\n");
            	}
            	else
            	{
                    controller_loadFromText("data.csv",listaEmpleados);
                    cantidadEmpleados = ll_len(listaEmpleados);
                    banderaEmpleadosModoTexto = 1;
            	}
                break;
            case 2:
            	printf("Elejiste la opcion 2-Cargar los datos de los empleados(modo binario)\n");
            	if(banderaEmpleadosModoTexto == 1)
            	{
            		printf("Error al cargar los datos modo binario: los datos de los empleados ya estan cargados en modo texto\n");
            	}
            	else
            	{
            		controller_loadFromBinary("dataBinario.csv",listaEmpleados);
            		cantidadEmpleados = ll_len(listaEmpleados);
                	banderaEmpleadosModoBinario = 1;
            	}
                break;
            case 3:
            	printf("Elejiste la opcion 3-Alta de empleado\n");
            	if(banderaEmpleadosModoTexto != 1 && banderaEmpleadosModoBinario != 1)
            	{
            		printf("Error al elegir alta de empleados, lista de empleados sin cargar en texto ni binario\n");
            	}
            	else
            	{
            		if(controller_addEmployee(listaEmpleados) == 0)
            		{
            			printf("Empleado dado de alta con exito\n");
            			cantidadEmpleados++;
            		}
            		else
            		{
            			printf("Error al dar de alta al nuevo empleado\n");
            		}
            	}

                break;
            case 4:
            	printf("Elejiste la opcion 4-Modificar datos de empleado\n");
            	if(banderaEmpleadosModoTexto != 1 && banderaEmpleadosModoBinario != 1)
            	{
            		printf("Error al elegir modificación, no hay empleados cargados en el sistema\n");
            	}
            	else
            	{
            		controller_editEmployee(listaEmpleados);
            	}
                break;
            case 5:
            	printf("Elejiste la opcion 5-Baja de empleado\n");
            	if(banderaEmpleadosModoTexto == 1 || banderaEmpleadosModoBinario == 1)
            	{
            		controller_removeEmployee(listaEmpleados);
            		cantidadEmpleados--;
            	}
            	else
            	{
            		printf("Error al elegir baja empleados, lista vacia\n");
            	}
                break;
            case 6:
            	printf("Elejiste la opcion 6-Listar empleados\n");
            	if((banderaEmpleadosModoTexto == 1 && cantidadEmpleados != 0)|| (banderaEmpleadosModoBinario == 1 && cantidadEmpleados != 0))
            	{
            		printf("Mostrando lista de empleados...\n");
                	controller_ListEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("Error al listar los empleados, lista vacia\n");
            	}
                break;
            case 7:
            	printf("Elejiste la opcion 7-Ordenar empleados\n");
            	if(banderaEmpleadosModoTexto != 1 && banderaEmpleadosModoBinario != 1)
            	{
            		printf("Error al ordenar, no hay empleados cargados en el sistema\n");
            	}
            	else
            	{
            		controller_sortEmployee(listaEmpleados);
            	}


                break;
            case 8:
            	printf("Elejiste la opcion 8-Guardar los datos de los empleados(modo texto)\n");
            	if(banderaEmpleadosModoTexto != 1 && banderaEmpleadosModoBinario != 1)
            	{
            		printf("Error, no hay empleados cargados en el sistema\n");
            	}
            	else
            	{
            		if(banderaEmpleadosModoTexto != 1 && banderaEmpleadosModoBinario == 1)
            		{
            			printf("Error al guardar modo texto: los datos de los empleados estan cargados en modo binario\n");
            		}
            		else
            		{
            			if(banderaEmpleadosModoTexto == 1 && banderaEmpleadosModoBinario != 1)
            			{
                    		controller_saveAsText("data.csv",listaEmpleados);
            			}
            		}
            	}
                break;
            case 9:
            	printf("Elejiste la opcion 9-Guardar los datos de los empleados(modo binario)\n");
            	if(banderaEmpleadosModoTexto != 1 && banderaEmpleadosModoBinario != 1)
            	{
            		printf("Error, no hay empleados cargados en el sistema\n");
            	}
            	else
            	{
            		if(banderaEmpleadosModoTexto == 1 && banderaEmpleadosModoBinario != 1)
            		{
            			printf("Error al guardar en modo binario: los datos de los empleados estan cargados en modo texto\n");
            		}
            		else
            		{
            			if(banderaEmpleadosModoTexto != 1 && banderaEmpleadosModoBinario == 1)
            			{
                    		controller_saveAsBinary("dataBinario.csv",listaEmpleados);
            			}
            		}
            	}
                break;
            case 10:
            	printf("Elejiste la opcion 10-Salir\nSaliendo del sistema....\nHas salido del sistema\n");
            	ll_deleteLinkedList(listaEmpleados);
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

}

