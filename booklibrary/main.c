#include"sto.h"
#include"Linkmake.h"

int main(){
   file_book_read();
   if(serch_name("Version32")==SYSTEM_RIGHT)
   {
        while(stack_top()!=SYSTEM_FALSE){
            printf("ID%s\n",stack_top()->ID);
            stack_pop();
        }
   }

    file_book_sto();
    return 0;
    
    
return 0;
}
