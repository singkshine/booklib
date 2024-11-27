#ifndef LINK_
#define LINK_ 0
#define NUMBER 0
#define STR 1
#endif


//Link 组件中临时缓存部分，用于将serch[搜索满足要求的书]存储进临时栈列
#ifndef STACK_BOOK
#define STACK_BOOK 0
#include"sto.h"
int stack_push(BOOK* books);//栈入，存入一本书，如果该书为空即NULL，返回SYSTEM_FALSE [0],反之..._RIGHT
BOOK *stack_top();//提取栈顶元素
int stack_pop();//抹去栈顶元素，如果栈空，返回FALSE[0]
//如需提取所有书，请使用 top+pop 
//没有将其合二为一是便于后续更改
int stack_cls();//清除所有栈内元素
int str_trans_int(char *str_in_);
int int_trans_str(char *trans, int i) ;
int type_input(char str[]);
#endif

#ifndef SERCH_MATCH
#define SERCH_MATCH 0
int match_serch(char serch_ch[]);
#endif