//connect screen and sto
#include "sto.h"
#include "Linkmake.h"
#ifndef FULL
#define FULL SYSTEM_RIGHT
#endif
#ifndef EMPTY
#define EMPTY SYSTEM_FALSE
#endif
#ifndef TURE_NUB
typedef int TYPE_STR;
static TYPE_STR char_trans_int(char char_in_);
static int num_s[100], nsi = EMPTY, *nst = num_s;
static void push_numb_trans(int i);
static int pop_numb_trans();
static int top_numb_trans();
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

TYPE_STR int_trans_str(char*trans,int i){

    char temp_tr[100];
    if(i<0)
    return SYSTEM_FALSE;
    while(i!=0){
        int sum=i%10;
        push_numb_trans(sum);
        i=(i-sum)/10;        
    }
    i=0;
    while(nsi!=EMPTY){
        temp_tr[i]=(char)((int)'0'+top_numb_trans());
        pop_numb_trans();
        i++;
    }
    temp_tr[i]='\0';
    strcpy(trans,temp_tr);
    return SYSTEM_RIGHT;
    
}



static void push_numb_trans(int i){
    if(nsi==EMPTY){
        *nst=i;
        nsi=FULL;
        return;
    }
    nst++;
    *nst=i;
    return;
}
static int pop_numb_trans(){
    if(nst==num_s&&nsi==EMPTY){
    return SYSTEM_FALSE;
    }
    if(nst==num_s&&nsi==FULL){
    nsi=EMPTY;
    return SYSTEM_RIGHT;
    }
    nst--;
    return SYSTEM_RIGHT;
}
static int top_numb_trans(){
    return *nst;
}