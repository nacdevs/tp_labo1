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
    int option = 1;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    utn_getInt(&option,"Menu: \n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n3. Alta empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10. Salir\n","Ingrese opcion valida\n",0,10,1500);
        switch(option)
        {
            case 1:
                if(controller_loadFromText("data (copy).csv",listaEmpleados)==0){ // Traigo la informacion de texto desde un backup para poder
                    system("clear");
                    printf("Lista cargada correctamente\n");
                }else{
                    system("clear");
                    printf("Error\n");
                }
                break;


           case 2:
                ll_clear(listaEmpleados);
                if(controller_loadFromBinary("data.csv",listaEmpleados)==0){
                    system("clear");
                    printf("Lista cargada correctamente\n");
                }else{
                    system("clear");
                    printf("Error\n");
                }
                break;


           case 3:
                if(controller_addEmployee(listaEmpleados)==0){
                    system("clear");
                    printf("Nuevo empleado cargado correctamente\n");
                }else{
                    system("clear");
                    printf("Error\n");
                }
                   //works but check
                break;

           case 4:
                if(controller_editEmployee(listaEmpleados)==0){
                        system("clear");
                        printf("Empleado modificado\n");
                }else{
                        system("clear");
                        printf("Error\n");
                }

                    //works but check
                break;

           case 5:
                if(controller_removeEmployee(listaEmpleados)==0){
                            system("clear");
                            printf("Empleado modificado\n");
                }else{
                            system("clear");
                            printf("Error\n");
                }
                    //works but check
                 break;

           case 6:
                controller_ListEmployee(listaEmpleados); // works
                break;

           case 7:
                if(controller_sortEmployee(listaEmpleados)==0){
                      system("clear");
                      printf("Lista ordenada\n");
                }else{
                      system("clear");
                      printf("Error\n");
                }
                break;

           case 8:
                if(controller_saveAsText("data.csv",listaEmpleados)==0){
                       system("clear");
                       printf("Lista Guardada en Txt\n");
                }else{
                       system("clear");
                       printf("Error\n");
                }

                break;


           case 9:
                if(controller_saveAsBinary("data.csv",listaEmpleados)==0){
                       system("clear");
                       printf("Lista Guardada en Binario\n");
                }else{
                       system("clear");
                       printf("Error\n");
                }
                     //works
                break;

           case 10:

                break;




        }
    }while(option != 10);
    return 0;
}
