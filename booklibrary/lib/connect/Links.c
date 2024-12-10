//connect screen and sto
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

int symbol_mode1(char ch[])
{ // book
    if (ch == NULL)
        return SYSTEM_FALSE;
    int i = 0;
    while (ch[i] != '\0' && ch[i] != '\n')
    {
        if (ch[i] == '[' || ch[i] == ']')
            return SYSTEM_FALSE;
        i++;
    }
    if (i == 0)
        return SYSTEM_FALSE;
    return SYSTEM_RIGHT;
}
int symbol_mode2(char ch[])
{ // usr
    if (ch == NULL)
        return SYSTEM_FALSE;
    int i = 0;
    if (symbol_mode1(ch) == SYSTEM_FALSE)
        return SYSTEM_FALSE;
    while (ch[i] != '\0' && ch[i] != '\n')
    {
        if ((int)ch[i] < 32 || (int)ch[i] > 176)
            return SYSTEM_FALSE;
        i++;
    }
    if (i == 0)
        return SYSTEM_FALSE;
    return SYSTEM_RIGHT;
}

int symbol_mode3(char ch[], char btm_min, char top_max)
{ // int min to max
    if (ch == NULL||strlen(ch)>1)
        return SYSTEM_FALSE;
    int i = 0;
    while (ch[i] != '\n' && ch[i] != '\0')
    {
        if (ch[i] < btm_min || ch[i] > top_max)
            return SYSTEM_FALSE;
            i++;
    }
    if (i == 0)
        return SYSTEM_FALSE;
    return SYSTEM_RIGHT;
}


void SYSTEM_ALL_FREE(){
    stack_cls();
    while(usr_pop()!=SYSTEM_FALSE);
    FULL_FREE_STO();
}

void SYSTEM_ALL_FILE_READ(){
    file_usr_read();
    file_book_read();
}

void SYSTEM_ALL_FILE_STORAGE(){
    file_book_sto();
    file_usr_sto();
}
