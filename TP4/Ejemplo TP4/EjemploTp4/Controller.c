#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int ret=-1;
    FILE *pArchivo;
    pArchivo = fopen(path,"r");
    if(parser_EmployeeFromText(pArchivo, pArrayListEmployee)==0){
        ret=0;
    }
    fclose(pArchivo);




    return ret;
}




/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int ret=-1;
    FILE* pArchivo= fopen(path,"rb");
    Employee* pEmpleado;
    if(parser_EmployeeFromBinary(pArchivo,pArrayListEmployee)==0){
        ret=0;
    }

    return ret;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int ret=-1;
    Employee* auxEmployee;
    char auxNombre [128];
    int auxHoras;
    int auxSueldo;
    auxEmployee=NULL;
    auxEmployee=Employee_new();



    utn_getLetras(&auxNombre,128,5,"Ingrese nombre\n","El nombre deben ser letras\n");
    utn_getInt(&auxHoras,"Ingrese horas trabajads\n","Las horas deben ser un numero entero\n",0,99999999999,5);
    utn_getInt(&auxSueldo,"Ingrese sueldo\n","El sueldo debe ser un numero entero\n",0,99999999999,5);

    Employee_setNombre(auxEmployee,auxNombre);
    Employee_setHorasTrabajadas(auxEmployee,auxHoras);
    Employee_setSueldo(auxEmployee,auxSueldo);
    Employee_setId(auxEmployee,-1);
    ll_add(pArrayListEmployee,(Employee*)auxEmployee);
    if(auxEmployee!=NULL){
        ret=0;
    }




    return ret;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int ret=-1;
    int index;
    int id;
    Employee* auxEmployee;
    char auxNombre [128];
    int auxHoras;
    int auxSueldo;

    utn_getInt(&id,"Ingrese Id\n","El id debe ser un entero entre 1 y 1000",0,1000,5);
    index=Employee_SearchId(pArrayListEmployee,id);
    auxEmployee=(Employee*) ll_get(pArrayListEmployee,index);
       if(index!=-1&&auxEmployee!=NULL){
            utn_getLetras(&auxNombre,128,5,"Ingrese nombre\n","El nombre deben ser letras\n");
            utn_getInt(&auxHoras,"Ingrese horas trabajadas\n","Las horas deben ser un numero entero\n",0,99999999999,5);
            utn_getInt(&auxSueldo,"Ingrese sueldo\n","El sueldo debe ser un numero entero\n",0,99999999999,5);

            Employee_setNombre(auxEmployee,auxNombre);
            Employee_setHorasTrabajadas(auxEmployee,auxHoras);
            Employee_setSueldo(auxEmployee,auxSueldo);
            Employee_setId(auxEmployee,id);
            if(auxEmployee!=NULL){
                ret=0;
            }
    }
    return ret;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int ret=-1;
    int id;
    int index;
    if(!utn_getInt(&id,"Ingrese Id\n","El id debe ser un entero entre 1 y 1000",0,1000,5)){
        index=Employee_SearchId(pArrayListEmployee,id);
        ll_remove(pArrayListEmployee,index);
        ret=0;
    }
    return ret;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{

    int i;
    int len = ll_len(pArrayListEmployee);
    Employee* auxEmployee;
    char bufferNombre[128];
    int  bufferHoras;
    int  bufferSueldo;
    int bufferId;
    for(i=0; i<len;i++){
        auxEmployee=ll_get(pArrayListEmployee,i);
        Employee_getNombre(auxEmployee,&bufferNombre);
        Employee_getSueldo(auxEmployee,&bufferHoras);
        Employee_getHorasTrabajadas(auxEmployee,&bufferSueldo);
        Employee_getId(auxEmployee,&bufferId);
        printf("%d - %s - %d - %d\n",bufferId,bufferNombre,bufferHoras,bufferSueldo);


    }
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int ret=-1;

    if(pArrayListEmployee!=NULL){
        ll_sort(pArrayListEmployee,Employee_Comp,0);
        ret=0;
    }

    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int ret=-1;
    int len=ll_len(pArrayListEmployee);
    FILE*pArchivo;
    pArchivo=fopen(path,"w");
    Employee* auxEmployee;
    char auxNombre[128];
    int auxId;
    int auxHoras;
    int auxSueldo;
    int i;

    if(pArchivo!=NULL)
        {
            fprintf(pArchivo,"%s","ID - NOMBRE - HORAS TRABAJO - SUELDO\n");
          for(i=0;i<len;i++)
            {
                auxEmployee=(Employee*)ll_get(pArrayListEmployee,i);
                Employee_getId(auxEmployee,&auxId);
                Employee_getNombre(auxEmployee,auxNombre);
                Employee_getSueldo(auxEmployee,&auxSueldo);
                Employee_getHorasTrabajadas(auxEmployee,&auxHoras);


                fprintf(pArchivo,"\n%d,%s,%d,%d\n",auxId,auxNombre,auxHoras,auxSueldo);

            }
          if(i>2){
            ret=0;
          }
        }
        fclose(pArchivo);
    return ret;

}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int ret=-1;
    FILE* pArchivo= fopen(path,"wb");
    Employee* pEmpleado;
    int i;
    int lenArray=ll_len(pArrayListEmployee);
    if(pArchivo != NULL){
        for(i=0;i<lenArray;i++){
                pEmpleado = ll_get(pArrayListEmployee,i);
                fwrite(pEmpleado,sizeof(Employee),1,pArchivo);
                }
        if(i>5){
            ret=0;
            }
     }
    fclose(pArchivo);
    return ret;

}

int Employee_SearchId(LinkedList* list,int id)
{
    int index=-1;
    int len=ll_len(list);
    int i;
    Employee* auxEmployee;
    int idEmp;

    if(list!=NULL)
    {
        for(i=0;i<len;i++)
        {
            auxEmployee=(Employee*)ll_get(list,i);
            Employee_getId(auxEmployee,&idEmp);
            if(idEmp==id)
                {
                    index=i;
                    break;
                }
        }
    }
    return index;
}
