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
typedef struct bookmsg
{   int sum;
    int ID;
    char *name;
    struct bookmsg *NEXT;
} BOOK;
extern BOOK *head;
extern BOOK *tail;
extern BOOK *mid;
#endif

#ifndef FILE_STO_H
#define FILE_STO_H
int file_write(void *books);
#endif
