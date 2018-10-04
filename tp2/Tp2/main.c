#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "Employee.h"
#include "Funciones.h"

int main()
{
    int option;
    Employee employeeArray[1000];
    initEmployees(&employeeArray,1000);



    while(option!=5){
        printf("\n---Menu---\n1.ALTAS\n2.MODIFICAR\n3.BAJA\n4.INFORMAR\n5.SALIR");
        utn_getInt(&option,"\nIngrese una opcion\n","Las opciones son del 1 al 5, 5 cierra el programa\n",1,5,15);
        char name[50];
        char lastName[50];
        float salary=11000.00;
        int sector;
        int id;
        int index;


        switch(option){
            case 1:
                utn_getLetras(&name,50,5,"Ingrese nombre\n","El nombre debe ser una palabra de no mas de 50 caracteres\n");
                utn_getLetras(&lastName,50,5,"Ingrese apellido\n","El apellido debe ser una palabra de menos de 50 caracteres\n");
                utn_getInt(&sector,"Ingrese número de sector(1 a 150)\n","El sector debe ser un numero entero\n",1,150,5);
                utn_getFloat(&salary,"Ingrese salario en numero con punto (ej 4.5)\n","Error\n",1,999999999,5);




                addEmployee(&employeeArray,1000,name,lastName,salary,sector);

                break;
            case 2:
                utn_getInt(&id,"\nIngrese numero de ID","El numero debe ser un entero\n",0,1000,5);

                index=findEmployeeById(&employeeArray,1000,id);

                utn_getLetras(&name,50,5,"Ingrese nombre\n","El nombre debe ser una palabra de no mas de 50 caracteres\n");
                utn_getLetras(&lastName,50,5,"Ingrese apellido\n","El apellido debe ser una palabra de menos de 50 caracteres\n");
                utn_getFloat(&salary,"Ingrese salario en numero con punto (ej 4.5)\n","El salario debe ser un numero con punto\n",0,999999999999,5);
                utn_getInt(&sector,"Ingrese número de sector (1 a 150)\n","El sector debe ser un numero entero\n",1,150,5);

                modifyEmployee(&employeeArray,index,name,lastName,salary,sector);

                break;

            case 3:
                utn_getInt(&id,"\nIngrese numero de ID\n","El numero debe ser un entero\n",0,1000,5);
                removeEmployee(&employeeArray,1000,id);
                break;
            case 4:

                sortEmployees(&employeeArray,1000);
                printEmployees(&employeeArray,1000);
                break;
            case 5:

                break;



        }



    }


    return 0;
}
