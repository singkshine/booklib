//规定对所有的更改只能以ID的形式
#ifndef SYSTEM_RIGHT
#define SYSTEM_RIGHT 1
#endif

#ifndef SYSTEM_FALSE
#define SYSTEM_FALSE 0
#endif

#ifndef BLOCK
#define BLOCK 15
#endif


#ifndef STO_H
#define STO_H 0
#define ON_BOW SYSTEM_RIGHT
#define OFF_BOW SYSTEM_FALSE
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef struct bookmsg
{   char *sum;
    char *ID;
    char *name;
    char *writer;
    int IS_BOW;
    struct bookmsg *NEXT;
} BOOK;

extern BOOK *head;
extern BOOK *tail;
extern BOOK *book;
#endif

#ifndef FILE_STO_H
#define FILE_STO_H
int file_write(void *books);
#endif

#ifndef STO_MAIN_H
#define STO_MAIN_H
void sto();
int new_in_book(void *books);
int delete_book(void *books);
int serch_name(char *name);
int serch_writer(char *writer);
BOOK *serch_ID(char *ID);
BOOK *serch_book(void *books);
#endif
