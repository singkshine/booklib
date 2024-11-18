#ifdef _WIN32
#define MK "mkdir files"
#endif
#include"sto.h"
#include"Linkmake.h"
#define stq 1
#define spq stq
int main(){
    printf("%d\n",spq);
    BOOK*mid=(BOOK*)malloc(sizeof(BOOK));
    //printf("mid%d\n",strlen(mid->name));
    char *p="你是谁";
    printf("%s\n",p);
     mid->name = "你好";
     printf("%s\n",mid->name);
     mid->ID="10";
     mid->sum="11";
     BOOK*mid1=(BOOK*)malloc(sizeof(BOOK));
     mid1->name="book";
     mid1->sum="10";
     mid1->ID="1331";
     mid1->writer = "nis" ;
     new_in_book(mid);
     mid->name="BUG";
     new_in_book(mid1);
     file_book_sto();
     if(serch_book(mid)!=NULL)
     printf("%s\n",serch_book(mid)->name);
     delete_book(serch_book(mid));
     delete_book(serch_book(mid1));
     printf("hear");
     // sto();

     return 0;
    

}
