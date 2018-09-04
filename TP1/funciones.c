#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

/*

/////NO TE OLVIDES DE HACER EL ARCHIVO CON LOS HEADERSSSS!!!!//

*/
void sumar(float* pSuma, float* pOperador1, float* pOperador2){
     float suma;
     float operador1 = *pOperador1;
     float operador2 = *pOperador2;
     suma = operador1+operador2;
     *pSuma=suma;
}

void restar(float* pResta, float* pOperador1, float* pOperador2){

    float resta;

    float operador1 = *pOperador1;
    float operador2 = *pOperador2;
    resta = operador1-operador2;
    *pResta=resta;

}

void multiplicar(float* pMulti,float* pOperador1, float* pOperador2){

    float multiplicar;
    float operador1 = *pOperador1;
    float operador2 = *pOperador2;
    multiplicar = operador1*operador2;
    *pMulti=multiplicar;
}

int dividir(float* pDivision, float* pOperador1, float* pOperador2){

    int retorno=0;
    float dividir;
    float operador1 = *pOperador1;
    float operador2 = *pOperador2;

    if(operador2==0){
        retorno=-1;
    }else{
         dividir = operador1/operador2;
        *pDivision= dividir;
    }

    return retorno;
    }

int factorial(int* pFactorial1, int* pFactorial2, float* pOperador1, float* pOperador2){

    int operador1 = *pOperador1;
    int operador2 = *pOperador2;

    int factorial=1;
    int factorial2=1;


    for(int i=1; i<operador1; i++){
            factorial=factorial*(i+1);

    }

    for(int i=1; i<operador2; i++){
            factorial2=factorial2*(i+1);

    }

    *pFactorial1=factorial;
    *pFactorial2=factorial2;

    return 0;
}

