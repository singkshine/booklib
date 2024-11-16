#include"sto.h"
BOOK*head=NULL,*tail=NULL,*book=NULL;
#ifndef CHAIN_RIGHT
#define CHAIN_RIGHT 1
#define CHAIN_FALSE 0
#define UN_MATCH 0
#define MATCH 1
typedef int CHAIN_BOOL;
static void resets();
static CHAIN_BOOL check(char str1[], char str2[]);
#endif

    CHAIN_BOOL push(void *books){
    book=(BOOK*)books;
    if(book==NULL)
    return CHAIN_FALSE;
    if(head==NULL)
    {
        head=book;
        tail=book;
        book->NEXT=NULL;
        book=NULL;
    }else{
    book->NEXT=NULL;
    tail->NEXT=book;
    tail=tail->NEXT;
    book=NULL; 
    }
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
        head=head->NEXT;
        free(book);
        bfdel=NULL;
        book=NULL;
        return CHAIN_RIGHT;
    }
    if(book==tail){
        free(tail);
        tail=bfdel;
        tail->NEXT=NULL;
    }else{
        bhdel = head;
        while (book->NEXT != bhdel)
        {
            bhdel = bhdel->NEXT;
        }
        free(book);
        bfdel->NEXT = bhdel->NEXT;
    }
    book=NULL;
    bfdel=NULL;
    bhdel=NULL;
    return CHAIN_RIGHT;
}

BOOK *serch_name(char* name){
    if(head==NULL)
    return NULL;
    book=head;
    do{///
        if(book!=NULL)
        if(check(book->name,name)==MATCH)
        return book;
        book=book->NEXT;
    }while(book!=NULL);
    return NULL;
}

BOOK *serch_ID(char *ID)
{
    if (head == NULL)
        return NULL;
    book = head;
    do
    { ///
        if (book != NULL)
            if (check(book->ID,ID) == MATCH)
                return book;
        book = book->NEXT;
    } while (book != NULL);
    return NULL;
}

static CHAIN_BOOL check(char str1[], char str2[])
{
    if(strlen(str1)!=strlen(str2))
    return UN_MATCH;
    int i=0;
    while(str1[i]!='\0'){
        if(str1[i]!=str2[i])
        return UN_MATCH;
        i++;
    }
    return MATCH;
}
