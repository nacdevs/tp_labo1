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

 return -1;
}

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


int sortEmployees(Employee* list, int len, int order){

    int flagOrden=1;
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

int printEmployees(Employee* list, int length){
    int i;
      printf("Nombre\tApellido\tID\tSector\n");
    for(i=0;i<length;i++){
    if(list[i].isEmpty==0){
        printf("%s\t%s\t\t%d\t%d\t%.2f\n",list[i].name,list[i].lastName,list[i].id,list[i].sector,list[i].salary);
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
