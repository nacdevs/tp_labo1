#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include "utnH.h"

int main()
{
    int opcion;
    int errorDivision;
    float primerOperando;
    float segundoOperando;
    float resultadoSuma;
    float resultadoResta;
    float resultadoMultiplicacion;
    float resultadoDivision;
    int factorial1;
    int factorial2;

    while(opcion!=5){
    printf("1.Ingresar 1er operando(A= %.2f)\n2.Ingresar 2do operando(B= %.2f)\n3.Calcular todas las operaciones\n4.Informar resultados\n5.Salir\n",primerOperando,segundoOperando);
    scanf("%d", &opcion);
     switch (opcion){
            case 1 :
                printf("Ingresar primer operando:\n");
                scanf("%f", &primerOperando);
                system("clear");
                break;

            case 2 :
                printf("Ingresar segundo operando:\n");
                scanf("%f", &segundoOperando);
                system("clear");
                break;

            case 3 :
                system("clear");
                sumar(&resultadoSuma,&primerOperando, &segundoOperando);
                restar(&resultadoResta,&primerOperando, &segundoOperando);
                multiplicar(&resultadoMultiplicacion,&primerOperando, &segundoOperando);
                factorial(&factorial1, &factorial2 ,&primerOperando, &segundoOperando);

                if(dividir(&resultadoDivision,&primerOperando, &segundoOperando)!=0){
                       errorDivision=-1;
                    }


                printf("Todo calculado\n");
                break;

            case 4:
                system("clear");
                printf("La suma es: %.2f\n",resultadoSuma);
                printf("La resta es: %.2f\n",resultadoResta);
                printf("La multiplicacion es: %.2f\n",resultadoMultiplicacion);

                if(errorDivision==-1){
                    printf("El segundo operando no puede ser 0 (cero)\n\n");
                }else{
                    printf("Division: %.2f\n\n",resultadoDivision);
                }

                printf("El factorial del primer operando es: %d y el del segundo es: %d \n\n", factorial1,factorial2);

                break;

            case 5:
                system("clear");
                printf("Usted ha salido");
                break;

            default:
                system("clear");
                printf("Elija una opcion valida!\n");

        }
        __fpurge(stdin);


    }




    return 0;
}
