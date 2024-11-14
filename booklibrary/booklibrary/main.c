#include<stdlib.h>
#ifdef _WIN32
#define MK "mkdir files"
#endif
#include"sto.h"
int main(){
    
    BOOK*mid=(BOOK*)malloc(sizeof(BOOK));
     mid->name = "cll";
     mid->ID=1;
     mid->sum=1;
    file_write(mid);
    free(mid);
    sto();
    return 0;
}