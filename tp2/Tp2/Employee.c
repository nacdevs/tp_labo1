#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "Employee.h"

int id=0;

int initEmployees(Employee* list, int len){

    int i;
    for(i=0; i<len;i++){

        list[i].isEmpty=1;

    }

 return 0;
}

int addEmployee(Employee* list, int len, char name[],char lastName[],float salary,int sector){
    int i;
    int ret=-1;

    for(i=0; i<len;i++){
      if(list[i].isEmpty==1){
                break;
        }
    }

    strcpy(list[i].name, name);
    strcpy(list[i].lastName, lastName);
    list[i].salary=salary;
    list[i].sector=sector;
    id=id+1;
    list[i].id=id;
    list[i].isEmpty=0;
    ret=0;
    system("clear");
    printf("Empleado agregado!");
 return ret;
}
//Encuentra empleado por ID

int findEmployeeById(Employee* list, int len,int id){
    int i;
    int ret=-1;
    for(i=0; i<len;i++){
      if(list[i].id==id){
            ret=i;
            break;
        }
    }

    return ret;
}

//Se le pasa id y borra empleado

int removeEmployee(Employee* list, int len, int id){

    int ret=-1;
    int pos;
    pos=findEmployeeById(list,len,id);
    if(pos!=-1){
        list[pos].isEmpty=1;
        ret=0;
    }

    system("clear");
    printf("Empleado dado de baja");

 return ret;
}

//0 y 1 cambia en el orden entre mayor y menor

int sortEmployees(Employee* list, int len){
    int i;
    int order=1;
    Employee aux;
    int flagOrdenar=0;

    while(flagOrdenar!=1){
        flagOrdenar=1;
        for(i=0;i<len-1;i++){
        char idAct=list[i].lastName[0];
        char idSig=list[i+1].lastName[0];
        if(order==1){
            if(idAct>idSig){
                aux=list[i];
                list[i]=list[i+1];
                list[i+1]=aux;
                flagOrdenar=0;
            }}else{
               if(idAct<idSig){
                aux=list[i];
                list[i]=list[i+1];
                list[i+1]=aux;
                flagOrdenar=0;

            }
        }

    }
    }


    return 0;
}

int printEmployees(Employee* list, int len){

    system("clear");

    int i;
    printf("Nombre\t\tApellido\t\tID\t\tSector\n");
    for(i=0;i<len;i++){
        if(list[i].isEmpty==0){
        printf("\n%s\t\t%s\t\t\t%d\t\t%d\n",list[i].name,list[i].lastName,list[i].id,list[i].sector);
        }

    }

    //Suma salarios
    int j;
    float suma=0.0;
    int contadorEmpleados=0;
    for(j=0;j<len;j++){
       if(list[j].isEmpty==0){
            suma=suma+list[j].salary;
            contadorEmpleados=contadorEmpleados+1;
       }

    }

    float promedio=(suma/contadorEmpleados);

    printf("La suma de los salarios %.2f y el promedio es %.2f\n",suma,promedio);


 return 0;
}

int modifyEmployee(Employee* list, int i, char name[],char lastName[],float salary,int sector){

    strcpy(list[i].name, name);
    strcpy(list[i].lastName, lastName);
    list[i].salary=salary;
    list[i].sector=sector;
    list[i].isEmpty=0;
    system("clear");
    printf("Empleado Modificado");

    return 0;
}
