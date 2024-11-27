#include"sto.h"
#include"Linkmake.h"

int main(){
file_book_read();
/*BOOK* news=(BOOK*)malloc(sizeof(BOOK));
strcpy(news->name,"first");    
strcpy(news->writer,"first");
strcpy(news->ID,"f123");
strcpy(news->IS_BOW,"1");
strcpy(news->sum,"100000");
new_in_book(news);*/
file_book_sto();
    return 0;
}
