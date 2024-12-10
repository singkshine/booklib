#include "Linkmake.h"
#ifndef MATCH_STATIC_
#define MATCH_STATIC_ 0
static int one_book_check(BOOK *book, char serch_ch[]) ;
static int check_str_(char serch_ch[], char serched_ch[]) ;
#endif

int match_search(char serch_ch[])
{
    if(serch_ch==NULL)
    return SYSTEM_FALSE;
    BOOK*book=head;
    if(head==NULL)
    return SYSTEM_FALSE;
    while(book!=NULL){
        if(one_book_check(book,serch_ch)==SYSTEM_RIGHT)
        stack_push(book);
        book=book->NEXT;
    }
    return SYSTEM_RIGHT;
}

static int one_book_check(BOOK*book,char serch_ch[]){
    if(check_str_(serch_ch,book->name)==SYSTEM_RIGHT)
    return SYSTEM_RIGHT;
    if (check_str_(serch_ch, book->writer) == SYSTEM_RIGHT)
    return SYSTEM_RIGHT;
    return SYSTEM_FALSE;
}

static int check_str_(char serch_ch[],char serched_ch[]){
    int i=0,j=0;
    for(i=0;i<strlen(serch_ch);i++){
        for(;j<strlen(serched_ch);j++){
            if(serch_ch[i]==serched_ch[j])
            break;
        }
        if(j>=strlen(serched_ch))
        return SYSTEM_FALSE;
    }
    if(j<strlen(serched_ch))
    return SYSTEM_RIGHT;
    return SYSTEM_FALSE;
}
