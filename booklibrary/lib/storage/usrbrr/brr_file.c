#include "Linkmake.h"

static brr*brr_head,*brr_tail;

static brr*sbr_head,*sbr_tail;
int sbr_push(brr*new_brr){
    if(new_brr==NULL)
    return SYSTEM_FALSE;
    new_brr->NEXT=NULL;
    if(sbr_head==NULL){
        sbr_head=new_brr;
        sbr_tail=new_brr;
        new_brr=NULL;
        return SYSTEM_RIGHT;
    }
    return SYSTEM_RIGHT;
}




int brr_push(brr*new_brr){
    if(new_brr==NULL)
    return SYSTEM_FALSE;
    new_brr->NEXT=NULL;
    if(brr_head==NULL){
        brr_head=new_brr;
        brr_tail=new_brr;
        return SYSTEM_RIGHT;
    }
    brr_tail->NEXT=new_brr;
    return SYSTEM_RIGHT;

}

brr* brr_top(){
    return brr_tail;
}

int brr_pop(){
    if(brr_tail==NULL)
    return SYSTEM_FALSE;
    if(brr_tail==brr_head){
        free(brr_tail);
        brr_head=NULL;
        brr_tail=NULL;
        return SYSTEM_RIGHT;
    }
    brr*brr_temp=brr_head;
    while(brr_temp->NEXT!=brr_tail){
        brr_temp=brr_temp->NEXT;
    }
    free(brr_tail);
    brr_tail=brr_temp;
    brr_tail->NEXT=NULL;
    brr_temp=NULL;
    return SYSTEM_RIGHT;


}

int brr_delete(brr*brr_){
    if(brr_==NULL||brr_head==NULL)
    return SYSTEM_FALSE;
    brr*del_front=brr_head;
    if(brr_head==brr_tail)
    brr_pop();
    brr*temp=brr_head;
    while(temp->NEXT!=brr_){
        temp=temp->NEXT;
    }
    temp->NEXT=brr_->NEXT;
    free(brr_);
    brr_=NULL;
    temp=NULL;
    return SYSTEM_RIGHT;    
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


