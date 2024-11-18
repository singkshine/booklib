#include <stdlib.h>
int main(){
    system("clang ./main.c -Iinclude ./lib/connect/bookStack.c ./lib/connect/Links.c ./lib/storage/basic.c ./lib/storage/filemake/filesto.c ./lib/storage/sto.c -o first.exe");
    return 0;
}