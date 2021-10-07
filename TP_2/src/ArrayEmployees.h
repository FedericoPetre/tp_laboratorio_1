/*
 * ArrayEmployees.h
 *
 *  Created on: 30 sep. 2021
 *      Author: Federico Petre
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesInputs.h"

#define TRUE 1
#define FALSE 0
#define CANTIDADEMPLEADOS 5

typedef struct {
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
} Employee;


int initEmployees(Employee* list, int len);
int findEmptyPosition(Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);
int showEmployee(Employee subject);
int printEmployees(Employee* list, int lenght);
int registerEmployee(Employee* list, int len, int lastId);
int findEmployeeById(Employee* list, int len, int id);
int removeEmployee(Employee* list, int len, int id);
int getDownEmployee(Employee* list, int len);
int sortEmployees(Employee* list, int len, int order);
int sortEmployeesBySectorAndLastName(Employee* list, int len, int order);
int calculateTotalAndAverageSalaries(Employee* list, int len);


#endif /* ARRAYEMPLOYEES_H_ */
