//
// Created by Michel on 31/07/2017.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){

    int fine=0;
    float prev=0;
    char operatore,op1s[16],op2s[16];
    while(!fine){
        scanf("%c",&operatore);
        if(operatore!='+' && operatore!='-' && operatore!='*' && operatore!='/'){
            printf("\nfine\n");
            fine=1;
        }else{
            scanf("%s %s",op1s,op2s);
            fflush();
            switch (operatore){
                case '+':
                    prev= operando(op1s,prev) + operando(op2s,prev);
                    break;
                case '-':
                    prev= operando(op1s,prev) - operando(op2s,prev);
                    break;
                case '*':
                    prev= operando(op1s,prev) * operando(op2s,prev);
                    break;
                case '/':
                    prev= operando(op1s,prev) / operando(op2s,prev);
                    break;
                default:break;
            }
        }
    }

    return;
}

float operando(char* op,float prev){
    if(!strcmp(op,"PREV"))return prev;
    return (flaot) atof(op);
}