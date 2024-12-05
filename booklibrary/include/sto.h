//规定对所有的更改只能以字符串格式
//除了 IS_BOW 主要懒写字符转数字部分
#ifndef SYSTEM_RIGHT
#define SYSTEM_RIGHT 1
#define SYSTEM_FALSE 0
#endif
//定义外部链接时函数返回的结果，所有内置函数[int]型函数 都是如此
//成功执行返回1
//失败返回0

#ifndef BLOCK
#define BLOCK 15
#define INCLUDE_SUM 5//弃案 原本准备写存储在file中时的间距，暂时未想到解决方案
#endif

//存储组件，主要是从运行到存储到文件过度时的存储函数，也包括与链接部分接轨的函数
#ifndef STO_H
#define STO_H 0
#define ON_BOW SYSTEM_RIGHT
#define OFF_BOW SYSTEM_FALSE
//BOW --借书状态，可否外借的定义，用int类型存储主要省事
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//结构体 书所具有的全部信息
typedef struct bookmsg
{   char name[30];
    char writer[30];
    char sum[30];
    char ID[30];
    char IS_BOW[30];
    struct bookmsg *NEXT;
} BOOK;
//操作临时存储时的链表基本结构
extern BOOK *head;
extern BOOK *tail;
//这个book貌似有漏洞，可能存储多次定义的情况，后续做更改
#endif

#ifndef FILE_STO_H
#define FILE_STO_H
int file_book_sto();
int file_book_read();//读取部分有bug
//将链表中的书全部存入txt文件
//目前准备留几个位置分别初始化外部存储的txt文件
//将其做成静态存储的模式，即程序结束重新归零存储[将链表中的文件全部重新存储]
//还有一个文件提取的模块，从txt导入全部书到链表
#endif

#ifndef STO_MAIN_H
#define STO_MAIN_H 0// 占个位置没什么用暂时
int new_in_book(void *books);//新存入一本书，只能输入书，书就是上方结构体模块
//书空返回0
//返回都同上
int delete_book(void *books);//删除一本书，通常搭配下发serch可进行很多操作
int serch_name(char *name);//寻找与输入name相符的书，存储到Link中的栈中
int serch_writer(char *writer);//同上找作者符合的
BOOK *serch_ID(char *ID);//找ID，ID唯一分配//分配还没写好，返回不同上，返回的是书，一个结构体指针
BOOK *serch_book(void *books);//同上，具体通过作者加书名的方式查找，为了避免对于借阅出去的书，sum可能不符合的情况
//sum组件有bug，还得做一个沟槽的字符转化数字组件，后续完善
#endif

#ifndef STO_MASSAGE
#define STO_MASSAGE 0
int book_name_input(char *name);//衔接组件，创建一个新book所有基本信息
int book_ID_input(char *ID);//当然IS_BOW没做，等我把字符转数字组件做了再做
int book_sum_input(char *sum);
int book_writer_input(char *writer);
int book_IS_BOW_input(char *IS_BOW);
int book_new_input();
#endif


#ifndef USR_FILE
#define USR_FILE
#define LIM_INPUT 15
typedef struct usr_{
    char type[LIM_INPUT];
    char usr[LIM_INPUT];
    char pass[LIM_INPUT];
    struct usr_ *NEXT;
}usr;
int usr_push(usr *stu);
int usr_pop();
int usr_del(usr *usr_);
usr *usr_top();
int file_usr_read();
int file_usr_sto();
#endif

