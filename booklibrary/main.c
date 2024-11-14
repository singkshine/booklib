#include<stdlib.h>
#ifdef _WIN32
#define MK "mkdir files"
#endif
#include"sto.h"
int main(){
    mid=(BOOK*)malloc(sizeof(BOOK));
    mid->name="system";
    mid->ID=1;
    mid->sum=1;
    printf("%s", mid->name);
    file_write(mid);
    free(mid);
    return 0;
}