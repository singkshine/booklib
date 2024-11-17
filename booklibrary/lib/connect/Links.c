//connect screen and sto
#include "sto.h"
#include "Linkmake.h"
#ifndef TURE_NUB
#define NUMBER 0
#define STR 1
typedef int TYPE_STR;
#endif




static TYPE_STR type_input(char str[]){
    int result=NUMBER;
    int i=0;
    while(str[i]!='\0'){
        if(str[i]>='0'&&str[i]<='9'){
            result==NUMBER;
        }else{
            result=STR;
            break;
        }
    }
    return result;
}