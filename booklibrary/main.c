#ifdef _WIN32
#define MK "mkdir files"
#endif
#include"sto.h"
int main(){
    
    BOOK*mid=(BOOK*)malloc(sizeof(BOOK));
     mid->name = "clldweduwwufjwfwjefwwef";
     mid->ID="10";
     mid->sum="11";
     BOOK*mid1=(BOOK*)malloc(sizeof(BOOK));
     mid1->name="jaddkq";
     mid1->ID="129";
     mid1->sum="123";
    push(mid);
    push(mid1);
    if(serch_name(mid->name)!=NULL)
    {printf("name%-20s\n",serch_name(mid->name)->name);
    printf("ID%-20s\n",serch_name(mid->name)->ID);
    printf("%-20s\n", serch_name(mid->name)->sum);
    }
    if (serch_name(mid1->name) != NULL){
        printf("name%-20s\n", serch_name(mid1->name)->name);
    printf("ID%-20s\n", serch_name(mid1->name)->ID);
    printf("%-20s\n", serch_name(mid1->name)->sum);
    }
    pop(serch_name(mid->name));
    pop(serch_name(mid1->name));
    free(mid);
    free(mid1);
    //sto();
    
    return 0;
    

}
