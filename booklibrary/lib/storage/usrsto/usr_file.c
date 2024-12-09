#include "Linkmake.h"
#ifndef USR_C
#define USR_C
static usr *usr_head = NULL,*usr_tail = NULL;
static void reset();
int file_usr_read();
static int file_usr_write(usr *usr_);
static int usr_read(int Line_i);
static int check(char str1[], char str2[]);
#endif
usr*get_usr_head(){
    return usr_head;
}

int usr_push(usr *stu){
    stu->NEXT=NULL;
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
int usr_pop(){
    if(usr_head==NULL)
    return SYSTEM_FALSE;
    if(usr_tail==usr_head){
        free(usr_head);
        reset();
        return SYSTEM_RIGHT;
    }
    usr*usr_f=usr_head;
    while(usr_f->NEXT!=usr_tail)
    usr_f=usr_f->NEXT;
    free(usr_tail);
    usr_tail=usr_f;
    usr_tail->NEXT=NULL;
    return SYSTEM_RIGHT;
}


int usr_del(usr*usr_){
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
usr* usr_top(){
    return usr_tail;
}
static void reset(){
    usr_head=NULL;
    usr_tail=NULL;
}
int file_usr_read(){
    int i=1;
    while(usr_read(i)!=SYSTEM_FALSE){
        i++;
    }
    return SYSTEM_RIGHT;
}
int file_usr_sto(){
    FILE *usr_files = fopen(".bookusr", "w+");
    fclose(usr_files);
    while(usr_top()!=NULL){
         file_usr_write(usr_top());
         usr_pop();
    }  
    return SYSTEM_RIGHT;
}
static int file_usr_write(usr*usr_){
    if(usr_==NULL)
    return SYSTEM_FALSE;
    FILE*usr_files=fopen(".bookusr","a");
    fprintf(usr_files,"[%s][%s][%s]\n",usr_->usr,usr_->pass,usr_->type);
    return SYSTEM_RIGHT;
}
static int usr_read(int Line_i){
    FILE*usr_files=fopen(".bookusr","r");
    if(usr_files==NULL){
        FILE*usr_files=fopen(".bookusr","w");
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
    int book_i=0;
    while(str_usr[i]!='\0'&&str_usr[i]!='\n'){
        if(str_usr[i]=='['){
            i++;
            int j=0;
            while(str_usr[i]!=']'){
                msg[j]=str_usr[i];
                i++;
                j++;
            }
            msg[j]='\0';
            switch(turns){
                case 0:{
                    strcpy(new_usr->usr,msg);
                    break;   
                }
                case 1:{
                    strcpy(new_usr->pass,msg);
                    break;
                }
                case 2:{
                    strcpy(new_usr->type,msg);
                    break;
                }

            }
            turns++;
        }
        i++;

    }
    usr_push(new_usr);
    new_usr=NULL;
return SYSTEM_RIGHT;
}




usr* search_usr(char *usr_){
    usr*usr_s=usr_head;
    if(usr_head==NULL)
    return NULL;
    while(check(usr_,usr_s->usr)==SYSTEM_FALSE){
        printf("1");
        usr_s=usr_s->NEXT;
        if(usr_s==NULL)
        break;
    }
    if(usr_s==NULL)
    return NULL;
    return usr_s;
}
static int check(char str1[], char str2[])
{
    if (strlen(str1) != strlen(str2))
        return SYSTEM_FALSE;
    int i = 0;
    while (str1[i] != '\0' && str1[i] != '\n')
    {
        if (str1[i] != str2[i])
            return SYSTEM_FALSE;
        i++;
    }
    return SYSTEM_RIGHT;
}



