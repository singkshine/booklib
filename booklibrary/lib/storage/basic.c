#include"sto.h"
BOOK*head=NULL,*tail=NULL,*book=NULL;
#ifndef CHAIN_RIGHT
#define CHAIN_RIGHT 1
#define CHAIN_FALSE 0
typedef int CHAIN_BOOL;
static void resets();
#endif

CHAIN_BOOL push(void *books){
    book=(BOOK*)books;
    if(book==NULL)
    return CHAIN_FALSE;
    book->NEXT=NULL;
    tail->NEXT=book;
    tail=tail->NEXT;
    book=NULL;
    return CHAIN_RIGHT;
}

CHAIN_BOOL pop(void *books){
    BOOK *bfdel=NULL,*bhdel=NULL;
    book=(BOOK*)books;
    if(book==NULL)
    return CHAIN_FALSE;
    bfdel=head;
    if(bfdel!=book){
        while(bfdel->NEXT!=book){
            bfdel=bfdel->NEXT;
        }
    }
    else{
        free(book);
        head=NULL;
        tail=NULL;
    }
    if(book->NEXT==NULL){
        free(book);
        tail=bfdel;
        tail->NEXT=NULL;
    }else{
        bhdel=head;
        while(book->NEXT!=bhdel){
            bhdel=bhdel->NEXT;
        }
        free(book);
        bfdel->NEXT=bhdel->NEXT;
    }
    book=NULL;
    bfdel=NULL;
    bhdel=NULL;
    return CHAIN_RIGHT;
}



