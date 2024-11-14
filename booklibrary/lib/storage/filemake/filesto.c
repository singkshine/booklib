//规定写入格式 10个位次
//使用地址传递book信息
#include"sto.h"
#ifndef BOOK_LIB
#define BOOK_LIB "booklist.txt"
typedef int FILE_BOOL;
#endif

FILE_BOOL file_write(void *books){
    BOOK *book=(BOOK*)books;
    FILE*storage=fopen(BOOK_LIB,"a");
    if(storage==NULL||book==NULL)
    return SYSTEM_FALSE;//调用显示模块  返回文件不存在提示 重新初始化系统；
    printf("%s", book->name);
        fprintf(storage,"%15s",book->name);
        fprintf(storage,"%15d",book->ID );
        fprintf(storage,"%15d\n",book->sum);
        fclose(storage);
        return SYSTEM_RIGHT;
}
static void nofile(){

}