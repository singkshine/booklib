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
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef struct bookmsg
{   char *sum;
    char *ID;
    char *name;
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
int push(void *books);
int pop(void *books);
BOOK *serch_name(char *name);
#endif
