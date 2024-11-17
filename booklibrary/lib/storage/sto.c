#include "sto.h"
#ifndef BOOK_TYPE_
#define BOOK_TYPE_EXIT 1
#define BOOK_TYPE_EMPTY 0
typedef int BOOK_TYPE;
#endif

#ifndef BOOK_TYPE_MAKE
#define BOOK_TYPE_MAKE 0
static BOOK * new_book=NULL;
static BOOK_TYPE new_book_name = BOOK_TYPE_EMPTY;
static BOOK_TYPE new_book_ID = BOOK_TYPE_EMPTY;
static BOOK_TYPE new_book_sum = BOOK_TYPE_EMPTY;
static BOOK_TYPE new_book_writer = BOOK_TYPE_EMPTY;
static void reset();
#endif
//是否做同名不同ID的部分
//********************** */
//同名处理对serch类需要更改
BOOK_TYPE book_name_input(char *name){
    if(new_book==NULL)
    new_book=(BOOK*)malloc(sizeof(BOOK));
    if(new_book==NULL)
    return SYSTEM_FALSE;
    new_book->name=name;
    new_book_name=BOOK_TYPE_EXIT;
    return SYSTEM_RIGHT;
}
BOOK_TYPE book_ID_input(char *ID)
{
    if (new_book == NULL)
        new_book = (BOOK *)malloc(sizeof(BOOK));
    if (new_book == NULL)
        return SYSTEM_FALSE;
    new_book->ID = ID;
    new_book_ID = BOOK_TYPE_EXIT;
    return SYSTEM_RIGHT;
}
BOOK_TYPE book_sum_input(char *sum)
{
    if (new_book == NULL)
        new_book = (BOOK *)malloc(sizeof(BOOK));
    if (new_book == NULL)
        return SYSTEM_FALSE;
    new_book->sum = sum;
    new_book_sum = BOOK_TYPE_EXIT;
    return SYSTEM_RIGHT;
}
BOOK_TYPE book_writer_input(char *writer)
{
    if (new_book == NULL)
        new_book = (BOOK *)malloc(sizeof(BOOK));
    if (new_book == NULL)
        return SYSTEM_FALSE;
    new_book->writer = writer;
    new_book_writer = BOOK_TYPE_EXIT;
    return SYSTEM_RIGHT;
}
static void reset(){
    new_book = NULL;
    new_book_name = BOOK_TYPE_EMPTY;
    new_book_ID = BOOK_TYPE_EMPTY;
    new_book_sum = BOOK_TYPE_EMPTY;
}