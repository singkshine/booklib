#include "sto.h"
#include "Linkmake.h"
#ifndef STACK_
#define STACK_ int
static BOOK *fbook = NULL, *tbook = NULL, *mbook = NULL;
static void copy_book(BOOK *book, BOOK *books);
#endif

STACK_ stack_push(BOOK *books){
    BOOK*book=(BOOK*)malloc(sizeof(BOOK));
    if(book==NULL)
    return SYSTEM_FALSE;
    strcpy(book->ID,books->ID);
    if(book==NULL){
        free(book);
        return SYSTEM_FALSE;
    }
    copy_book(book,books);
    if (fbook == NULL)
    {
        fbook=book;
        tbook=book;
        return SYSTEM_RIGHT;
    }
    tbook->NEXT=book;
    tbook=book;
    book=NULL;
    return SYSTEM_RIGHT;
}

BOOK* stack_top(){
    return tbook;
}

STACK_ stack_pop(){
    if(tbook==NULL)
    return SYSTEM_FALSE;
    mbook=fbook;
    if(mbook==tbook){
        free(mbook);
        mbook=NULL;
        tbook=NULL;
        fbook=NULL;
        return SYSTEM_RIGHT;
    }
    while(mbook->NEXT!=tbook){
        mbook=mbook->NEXT;
    }
    free(tbook);
    tbook=mbook;
    mbook=NULL;
    return SYSTEM_RIGHT;
}
STACK_ stack_cls(){
    while(stack_pop()!=SYSTEM_FALSE);
    return SYSTEM_RIGHT;
}

static void copy_book(BOOK*book,BOOK*books){
    strcpy(book->name,books->name);
    strcpy(book->ID,books->ID);
    strcpy(book->writer,books->writer);
    strcpy(book->IS_BOW,books->IS_BOW);
    strcpy(book->sum,books->sum);
    book->NEXT=NULL;
}