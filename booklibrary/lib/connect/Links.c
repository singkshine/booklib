//connect screen and sto
#include "sto.h"
#include "Linkmake.h"
#ifndef TURE_NUB
typedef int TYPE_STR;
static TYPE_STR char_trans_int(char char_in_);
#endif

TYPE_STR str_trans_int(char *str_in_){
    int i=0,ten=10,sum=0;
    for(i=strlen(str_in_)-1;i>=0;i--){
        sum+=ten*char_trans_int(str_in_[i])/10;
        ten*=10;
    }
    return sum;
}

static TYPE_STR char_trans_int(char char_in_){
    return (int)char_in_-(int)'0';
}

TYPE_STR type_input(char str[]){
    int result=STR;
    int i=0;
    while(str[i]!='\0'&&str[i]!='\n'){
        if(str[i]>='0'&&str[i]<='9'){
            result=NUMBER;
        }else{
            result=STR;
            break;
        }
        i++;
    }
    return result;
}