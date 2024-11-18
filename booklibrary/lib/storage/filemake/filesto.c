//规定写入格式 10个位次
//使用地址传递book信息
#include"sto.h"
#ifndef BOOK_LIB
#define BOOK_LIB "booklist.txt"
typedef int FILE_BOOL;
static FILE_BOOL file_write(void *books);
#endif

static FILE_BOOL file_write(void *books){
    BOOK *book=(BOOK*)books;
    FILE*storage=fopen(BOOK_LIB,"a");
    if(storage==NULL||book==NULL){
        fclose(storage);
      return SYSTEM_FALSE;  
    }
    //调用显示模块  返回文件不存在提示 重新初始化系统；
        fprintf(storage,"%-15s",book->ID );
        fprintf(storage,"%-15s",book->name);
        fprintf(storage,"%-15s",book->writer);
        fprintf(storage,"%-15s",book->sum);
        fprintf(storage,"%-15d\n",book->IS_BOW);
        fclose(storage);
        return SYSTEM_RIGHT;
}
FILE_BOOL file_book_sto(){
    BOOK *book=head;
    do{
        if(file_write(book)==SYSTEM_RIGHT)
        book=book->NEXT;
    }while(book!=NULL);
    return SYSTEM_RIGHT;
}

static void nofile(){

}

