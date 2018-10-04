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
      printf("<Array init>\n");
 return 0;
}

int addEmployee(Employee* list, int len, char name[],char lastName[],float salary,int sector){
    int i;
    int ret=-1;

    for(i=0; i<len;i++){
      if(list[i].isEmpty=1){
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
 return ret;
}
//Encuentra empleado por ID

int findEmployeeById(Employee* list, int len,int id){
    int i;
    int ret=-1;
    for(i=0; i<len;i++){
      if(list[i].id=id){
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


 return ret;
}

//0 y 1 cambia en el orden entre mayor y menor

int sortEmployees(Employee* list, int len, int order){
    int i;
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

    /*int flagOrden=1;
    Employee aux;
    int i;

    for(i=0;i<len;i++){
        aux=list[i];
        list[i]=list[len-i];
        list[len-i]=aux;
    }

   /* while(flagOrden==1)
    {
        flagOrden=0;
        for(i=0;i<len-1;i++)
        {
            if((order==1 && list[i]>list[i+1]) || (order==0 && list[i]<list[i+1]))
            {
                aux=list[i];
                list[i]=list[i+1];
                list[i+1]=aux;
                flagOrden=1;
            }
        }
    }*/

    return 0;
}

int printEmployees(Employee* list, int len){
    int i=0;
    printf("Nombre\tApellido\tID\tSector\n");
    for(i=0;i<len;i++){
        if(list[i].isEmpty==0){
        printf("\n%s\t%s\t%d\t%d\n",list[i].name,list[i].lastName,list[i].id,list[i].sector);
        }

    }

 return 0;
}

int modifyEmployee(Employee* list, int i, char name[],char lastName[],float salary,int sector){

    strcpy(list[i].name, name);
    strcpy(list[i].lastName, lastName);
    list[i].salary=salary;
    list[i].sector=sector;
    list[i].isEmpty=0;


}
