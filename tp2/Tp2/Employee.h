#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;

int initEmployees(Employee* list, int len);

int addEmployee(Employee* list, int len, char name[],char lastName[],float salary,int sector);

int findEmployeeById(Employee* list, int len,int id);

int removeEmployee(Employee* list, int len, int id);

int sortEmployees(Employee* list, int len);

int printEmployees(Employee* list, int len);

int modifyEmployee(Employee* list, int i, char name[],char lastName[],float salary,int sector);


#endif // EMPLOYEE_H_INCLUDED
