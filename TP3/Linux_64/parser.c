#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int ret=-1;
    char auxBufferId[50];
    int bufferId;
    char bufferNombre[125];

    char auxBufferHoras[50];
    int bufferHoras;

    char auxBufferSueldo[50];
    int bufferSueldo;
    int flagFirstLine=0;
    Employee* auxEmployee;


     if(pFile != NULL)
    {
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxBufferId,bufferNombre,auxBufferHoras,auxBufferSueldo)==4 && flagFirstLine!=0)
            {
                bufferId= atoi(auxBufferId);
                bufferHoras = atoi(auxBufferHoras);
                bufferSueldo= atoi(auxBufferSueldo);
                auxEmployee=Employee_newConParametros(bufferNombre,bufferId,bufferHoras,bufferSueldo);
                ll_add(pArrayListEmployee,(Employee*)auxEmployee);

            }
            if(flagFirstLine==0){
                flagFirstLine++;
                ret=0;
            }

        } while(!feof(pFile));




    }
    return ret;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{   int ret=-1;
     Employee* pEmpleado;
     if(pArrayListEmployee!=NULL){

    do{
        pEmpleado = Employee_new();
        if(pEmpleado!=NULL){
            fread(pEmpleado,sizeof(Employee),1,pFile);
            ll_add(pArrayListEmployee, pEmpleado);
            ret=0;
        }

    }while(!feof(pFile));
    }
    return ret;

}
