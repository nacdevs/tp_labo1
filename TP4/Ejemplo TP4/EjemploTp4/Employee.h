#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
typedef struct{
    char nombre[128];
    int id;
    int horasTrabajadas;
    int sueldo;
}Employee;


Employee* Employee_new();
void Employee_delete();
Employee* Employee_newConParametros(char* nombre,int id,int horasTrabajadas,int sueldo);

int Employee_setNombre(Employee* this,char* nombre);
int Employee_getNombre(Employee* this,char* nombre);

int Employee_setId(Employee* this,int id);
int Employee_getId(Employee* this,int* id);

int Employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int Employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int Employee_setSueldo(Employee* this,int sueldo);
int Employee_getSueldo(Employee* this,int* sueldo);

int Employee_Comp(void* emp1 ,void* emp2 );
#endif // EMPLOYEE_H_INCLUDED
