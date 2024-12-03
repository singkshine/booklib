#include "Linkmake.h"
#ifndef USR_C
#define USR_C
static int usr_push(usr *stu);
static int usr_pop();
static int usr_del(usr *usr_);
static usr *usr_top();
static void reset();
int file_usr_read();
static int file_usr_write(usr *usr_);
static int usr_read(int Line_i);
#endif

    static usr *usr_head = NULL,
               *usr_tail = NULL;

static int usr_push(usr *stu){
    if(usr_head==NULL){
        usr_head=stu;
        usr_tail=stu;
    }else{
        usr_tail->NEXT=stu;
        usr_tail=stu;
    }
    stu=NULL;
    return SYSTEM_RIGHT;
    
}

static int usr_pop(){
    if(usr_head==NULL)
    return SYSTEM_FALSE;
    if(usr_tail==usr_head){
        free(usr_head);
        reset();
    }
    usr*usr_f=usr_head;
    while(usr_f->NEXT!=usr_tail)
    usr_f=usr_f->NEXT;
    free(usr_tail);
    usr_tail=usr_f;
    usr_tail->NEXT=NULL;
    return SYSTEM_RIGHT;
}

static int usr_del(usr*usr_){
    usr*usr_f=usr_head;
    if(usr_f==NULL||usr_==NULL)
    return SYSTEM_FALSE;
    if(usr_f==usr_){
        free(usr_);
        usr_=NULL;
        reset();
        return SYSTEM_RIGHT;
    }else{
        while(usr_f->NEXT!=usr_){
            usr_f=usr_f->NEXT;
        }
        usr_f->NEXT=usr_->NEXT;
        if(usr_==usr_tail)
        usr_tail=usr_f;
        free(usr_);
    }
    return SYSTEM_RIGHT;
}

static usr* usr_top(){
    return usr_tail;
}

static void reset(){
    usr_head=NULL;
    usr_tail=NULL;
}

int file_usr_read(){
    int i=0;
    while(usr_read(i)!=SYSTEM_FALSE){
        i++;
    }
}



int file_usr_sto(){

}
static int file_usr_write(usr*usr_){
    if(usr_==NULL)
    return SYSTEM_FALSE;
    FILE*usr_files=fopen("usr.txt","a");
    if(usr_files==NULL){
        fclose(usr_files);
        usr_files=fopen("usr.txt","w+");
    }

}
static int usr_read(int Line_i){
    FILE*usr_files=fopen("usr.txt","r");
    if(usr_files==NULL){
        usr_files=fopen("usr.txt","w");
        fclose(usr_files);
        return SYSTEM_FALSE;
    }
    char str_usr[1024];
    int i=1,turns=0;
    for(i=1;i<=Line_i;i++){
        if(fgets(str_usr,1024,usr_files)==NULL)
        break;
    }
    if(i<=Line_i){
        fclose(usr_files);
        return SYSTEM_FALSE;
    }
    usr*new_usr=(usr*)malloc(sizeof(usr));
    char msg[100];
    i=0;
    while(str_usr[i]!='\0'||str_usr[i]!='\n'){
        if(str_usr[i]=='['){
            i++;
            int j=0;
            while(str_usr[i]!=']'){
                msg[j]=str_usr[i];
                i++;
                j++;
            }
            
            switch(turns){
                case 0:{
                    break;   
                }
                case 1:{
                    break;
                }

            }
        }
        i++;

    }


return SYSTEM_RIGHT;
}










