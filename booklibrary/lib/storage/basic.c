#include "sto.h"
#include "Linkmake.h"
BOOK*head=NULL,*tail=NULL,*book=NULL;//book有bug，涉及很多部分，是个没用的组件
#ifndef CHAIN_RIGHT
#define CHAIN_RIGHT SYSTEM_RIGHT
#define CHAIN_FALSE SYSTEM_FALSE
#define UN_MATCH SYSTEM_FALSE
#define MATCH SYSTEM_RIGHT
typedef int CHAIN_BOOL;
static void resets();
static CHAIN_BOOL check(char str1[], char str2[]);
#endif

CHAIN_BOOL sum_add_book(void *books){//增加对应书的数量
    book=(BOOK*)books;
    book->sum=book->sum+1;
    return CHAIN_RIGHT;
}
CHAIN_BOOL sum_reduce_book(void *books)//减少对应书的数量
{
    book = (BOOK *)books;
    if(book->sum>0)
    book->sum = book->sum-1;
    else
    return CHAIN_FALSE;
    return CHAIN_RIGHT;
}

CHAIN_BOOL new_in_book(void *books){
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

CHAIN_BOOL delete_book(void *books){//删除对应的书,没有返回删除失败
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

CHAIN_BOOL serch_name(char* name){//有书名将书存储到栈，结果返回有书，没书不做处理，
//返回无书
    stack_cls();
    if (head == NULL) return CHAIN_FALSE;
    book=head;
    do{///
        if(book!=NULL)
        if(check(book->name,name)==MATCH)
        stack_push(book);
        book=book->NEXT;
    }while(book!=NULL);
    if(stack_top()==NULL)
    return CHAIN_FALSE;
    return CHAIN_RIGHT;
}

CHAIN_BOOL serch_writer(char *writer)
{ // 有书名将书存储到栈，结果返回有书，没书不做处理，
    // 返回无书
    stack_cls();
    if (head == NULL)
        return CHAIN_FALSE;
    book = head;
    do
    { ///
        if (book != NULL)
            if (check(book->writer, writer) == MATCH)
                stack_push(book);
        book = book->NEXT;
    } while (book != NULL);
    if (stack_top() == NULL)
        return CHAIN_FALSE;
    return CHAIN_RIGHT;
}

BOOK* serch_ID(char *ID)//有书返回书，无书返回NULL
{
    stack_cls();
    if (head == NULL) 
    return NULL;
    book = head;
    do{
        if (book != NULL)
            if (check(book->ID,ID) == MATCH)
                return book;
        book = book->NEXT;
    } while (book != NULL);
    return NULL;
}

BOOK *serch_book(void *books){
    BOOK* book=(BOOK*)books;
    BOOK*blook =head;
    if(book==NULL||blook==NULL)
    return NULL;
    do{
        if(book->name==blook->name&&book->writer==blook->writer)
        printf("%s\n",book->name);
        return book;
        blook=blook->NEXT;
    }while(blook!=NULL);
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
