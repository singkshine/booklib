#include "sto.h"
#include "Linkmake.h"
int main(){
file_book_read();
BOOK* news=(BOOK*)malloc(sizeof(BOOK));
strcpy(news->name,"first");    
strcpy(news->writer,"first");
strcpy(news->ID,"f123");
strcpy(news->IS_BOW,"1");
strcpy(news->sum,"100000");


new_in_book(news);
match_search("f");
while(stack_top()!=NULL){
 printf("%s   %s   %s\n",stack_top()->name,stack_top()->writer,stack_top()->sum);   
 stack_pop();
}

stack_cls();
file_book_sto();
    return 0;
}
