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
     mid->name = "clldweduwwufjwfwjefwwef";
     mid->ID="10";
     mid->sum="11";
     BOOK*mid1=(BOOK*)malloc(sizeof(BOOK));
     BOOK*q=mid1;
     mid1->name=mid->name;
     mid1->name = "nis" ;
     new_in_book(mid);
     new_in_book(mid1);
     if(serch_book(mid)!=NULL)
     printf("%s\n",serch_book(mid)->name);
     delete_book(serch_book(mid));
     delete_book(mid1);
     free(q);
     printf("hear");

     // sto();

     return 0;
    

}
