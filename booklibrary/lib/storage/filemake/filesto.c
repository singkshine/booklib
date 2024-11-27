//规定写入格式 10个位次
//使用地址传递book信息
#include"sto.h"
#include"Linkmake.h"
#ifndef BOOK_LIB
#define BOOK_LIB "booklist.txt"
typedef int FILE_BOOL;
static FILE_BOOL file_write(void *books);
static FILE_BOOL book_read(int Line_i);
static char* msg;
#endif
/*typedef struct CHAR_STO{
    char ch;
    CHAR*NEXT;
}CHAR;
static CHAR*front=NULL,*back=NULL,*p=NULL;*/
static FILE_BOOL file_write(void *books){
    BOOK *book=(BOOK*)books;
    FILE*storage=fopen(BOOK_LIB,"a");
    if(storage==NULL||book==NULL){
        fclose(storage);
      return SYSTEM_FALSE;  
    }
    //调用显示模块  返回文件不存在提示 重新初始化系统；
        fprintf(storage,"[%s][%s][%s][%s][%s]\n",book->name,book->writer,book->sum,book->ID,book->IS_BOW);
        fclose(storage);
        return SYSTEM_RIGHT;
}
FILE_BOOL file_book_sto(){
    BOOK *book=head;
    FILE*new_lib=fopen(BOOK_LIB,"w");
    fclose(new_lib);
    do{
        if(file_write(book)==SYSTEM_RIGHT)
        book=book->NEXT;
    }while(book!=NULL);
    return SYSTEM_RIGHT;
}
FILE_BOOL file_book_read(){
    int i=1;
    while(book_read(i)!=SYSTEM_FALSE){
        i++;
    }
    return SYSTEM_RIGHT;
}
static FILE_BOOL book_read(int Line_i){
    int j=0;
    char temp[1024];
    FILE *storage=fopen(BOOK_LIB,"r");
    if(storage==NULL){
        FILE *storage=fopen(BOOK_LIB,"w");
        fclose(storage);
        return SYSTEM_FALSE;
    }
    for(j=1;j<=Line_i;j++){
        if(fgets(temp,1024,storage)==NULL)
        break;
    }
    if(j<=Line_i){
        fclose(storage);
        return SYSTEM_FALSE;
    }
    fclose(storage);
    j=0;
    int k=0;
    char chs[100];
    while(temp[j]!='\0'&&temp[j]!='\n'){
        if(temp[j]=='['){
            j++;
            int i=0;
            while(temp[j]!=']'){
                chs[i]=temp[j];
                i++;
                j++;
            }
            if(i==0)
            strcpy(chs,"error\0");
            else
            chs[i]='\0';
            switch (k){
                case 0:{
                    book_name_input(chs);
                    break;
                }
                case 1:{
                    book_writer_input(chs);
                    break;
                }
                case 2:{
                    book_sum_input(chs);
                    break;
                }
                case 3:{
                    book_ID_input(chs);
                    break;
                }
                case 4:{
                    book_IS_BOW_input(chs);
                    break;
                }
                default :break;
            }
            k++;
        }
        j++;
    }
    return SYSTEM_RIGHT;
}
