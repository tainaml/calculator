#include <stdio.h>
#include "calculadora.h"

int calculadora (char operador, float num1, float num2){

    float resultado = 0;

    switch( operador ){

        case '+':
                resultado = num1 + num2;
                break;
        case '-':
                resultado = num1 - num2;
                break;
        case '*':
                resultado =num1 * num2;
                break;
        case '/':
                if(num2 != 0)
                    resultado = num1 / num2;
                else
                    printf("Nao existe divisao por 0\n\n");;
                break;
        case '%':
                resultado = (int)num1 % (int)num2;
                break;
        default:
                if(num1 != 0 && operador != '0' && num2 != 0)
                    printf(" Operador invalido\n\n ");
                else
                    printf(" Fechando calculadora!\n ");
    }
    return resultado;
}
