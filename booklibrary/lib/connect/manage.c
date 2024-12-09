#include "screen.h"
#include"Linkmake.h"
#include "mng.h"
#ifndef MANAGER_C
#define MANAGER_C
static int admin_stobook_name();
static int admin_stobook_writer();
static int admin_stobook_sum();
static void error_mng(char *temp);
static void miaomiaomiao();
static int admin_stobook_ID();
static void admin_stobook_ISBOW();
static int admin_stobook_last(BOOK *temp);
static int book_show(BOOK *temp);
static void admin_stobook_last_show();
static void book_modify_show();
static int modify_book(BOOK *temp) ;
static int modify_name(BOOK *book_);
static int modify_writer(BOOK *book_);
static int modify_sum(BOOK *book_);
static int modify_IS_BOW(BOOK *book_);
static void all_books_views();
static void no_book_serch();
static void serch_book_view(usr *temper);
static void change_books(usr *temper);
static void stack_book_all_view();
static void s_number_search();
static void s_match_search();
static void admin_chanbook_show(usr *temper);
static void search_show_usr() ;
static int check(char str1[], char str2[]);
#endif

    static int admin_stobook_name(){
    while(1==1){
        CLEAR_SCREEN();
        s_admin_stobook();
        printf("输个书名吧(不要超过30个字符):");
        char temp[50];
        gets(temp);
        if(symbol_mode1(temp)==SYSTEM_FALSE){
        error_mng("不要包含\"[\"和\"]\"");
        continue;
        }
        if(strlen(temp)>30){
        error_mng("书名太长啦~");
        continue;
        }

        book_name_input(temp);
        break;
    }
    return SYSTEM_RIGHT;
}

static int admin_stobook_writer()
{
    while (1 == 1)
    {
        CLEAR_SCREEN();
        s_admin_stobook();
        printf("输入作者吧(不要超过30个字符):");
        char temp[50];
        gets(temp);
        if (symbol_mode1(temp) == SYSTEM_FALSE)
        {
            error_mng("不要包含\"[\"和\"]\"");
            continue;
        }
        if (strlen(temp) > 30)
        {
            error_mng("作者怎么会有这么长的名字？");
            continue;
        }

        book_writer_input(temp);
        break;
    }
    return SYSTEM_RIGHT;
}

static int admin_stobook_sum()
{
    while (1 == 1)
    {
        CLEAR_SCREEN();
        s_admin_stobook();
        printf("书有多少？(不要超过30个字符):");
        char temp[50];
        gets(temp);
        if (symbol_mode1(temp) == SYSTEM_FALSE)
        {
            error_mng("不要包含\"[\"和\"]\"");
            continue;
        }
        if(type_input(temp)){
            error_mng("都问了是书有多少？不是让你输字符!");
            continue;
        }
        if (strlen(temp) > 30)
        {
            error_mng("这么多书你家装得下吗？");
            continue;
        }
        book_sum_input(temp);
        break;
    }
    return SYSTEM_RIGHT;
}

static void error_mng(char*temp){
    CLEAR_SCREEN();
    miaomiaomiao();
    printf("%s\n",temp);
    printf("输入任意字符继续输入吧！\n");
    char m[1024];
    gets(m);
}
static void miaomiaomiao(){
printf("⣿⣿⣿⠟⠛⠛⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⢋⣩⣉⢻                喵~\n");
printf("⣿⣿⣿⠀⣿⣶⣕⣈⠹⠿⠿⠿⠿⠟⠛⣛⢋⣰⠣⣿⣿⠀⣿\n");
printf("⣿⣿⣿⠀⣿⣶⣕⣈⠹⠿⠿⠿⠿⠟⠛⣛⢋⣰⠣⣿⣿ ⣿          喵~\n");
printf("⣿⣿⣿⣷⠘⣿⣿⣿⢏⣿⣿⣋⣀⣈⣻⣿⣿⣷⣤⣤⣿⡐⢿\n");
printf("⣿⣿⣿⣿⣆⢩⣝⣫⣾⣿⣿⣿⣿⡟⠿⠿⠦⠀⠸⠿⣻⣿⡄⢻  喵~\n");
printf("⣿⣿⣿⣿⣿⡄⢻⣿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣾⣿⣿⣿⣿⠇⣼\n");
printf("⣿⣿⣿⣿⣿⣿⡄⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⣰\n");
printf("⣿⣿⣿⣿⣿⣿⠇⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢀⣿\n");
printf("⣿⣿⣿⣿⣿⠏⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿\n");
printf("⣿⣿⣿⣿⠟⣰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⣿\n");
printf("⣿⣿⣿⠋⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⣿\n");
printf("⣿⣿⠋⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⢸\n");
}


static int admin_stobook_ID(){
    if(full_show()==SYSTEM_FALSE){
        stack_cls();
        book_ID_input("1");
        return 1;
    }else{
        int ID_max=1;
        if (type_input(stack_top()->ID)==NUMBER)
           ID_max = str_trans_int(stack_top()->ID);
        while (stack_top() != NULL)
        {
            if (str_trans_int(stack_top()->ID) > ID_max)
            ID_max = str_trans_int(stack_top()->ID);
            stack_pop();
        }
    char new_ID[30];
    int_trans_str(new_ID,ID_max+1);
    book_ID_input(new_ID);
        return str_trans_int(new_ID);
    }
}

static void admin_stobook_ISBOW(){
    char p[30];
    int_trans_str(p,SYSTEM_RIGHT);
    book_IS_BOW_input(p);
}

int admin_stobook(){
    BOOK*temp_;
    do{
    FULL_FREE_STO();
    file_book_read();
    admin_stobook_name();
    admin_stobook_writer();
    admin_stobook_sum();
    int ID_=admin_stobook_ID();
    admin_stobook_ISBOW();
    CLEAR_SCREEN();
    s_admin_stobook();
    char p[30];
    int_trans_str(p,ID_);
    temp_=serch_ID(p);
    if(book_show(temp_)==SYSTEM_FALSE)
    error_mng("图书已经存在数量已自动累加！");
    file_book_sto();
    } while (admin_stobook_last(temp_)!=SYSTEM_FALSE);
    return SYSTEM_RIGHT;
}


static int admin_stobook_last(BOOK*temp){
    char p[1024];
    while(1==1){
    CLEAR_SCREEN();
    s_admin_stobook();
    book_show(temp);
    admin_stobook_last_show();
        printf("输入您想更改的信息:");
        gets(p);
        if (symbol_mode3(p, '1', '3') == SYSTEM_FALSE)
        {
            error_mng("请输入给定的字符信息！");
            return admin_stobook_last(temp);
        }
        switch (str_trans_int(p))
        {
            case 1:
            {   if(temp==NULL){
                error_mng("图书已经存在如要更改请在修改系统内更改！");
            //return admin_stobook_last(temp);
                break;
            }
                modify_book(temp);
            // return admin_stobook_last(temp);
                break;
            }
            case 2:
            {   
                return SYSTEM_RIGHT;//admin_stobook();
                //return admin_stobook_last(temp);
                break;
            }
            case 3:
            {
                return SYSTEM_FALSE;
                break;
            }
        }
    }
    return SYSTEM_RIGHT;
}

static void admin_stobook_last_show(){
    printf("+====================+\n");
    printf("|修改当前图书请输入:1|\n");
    printf("|继续存入图书请输入:2|\n");
    printf("|退出存储系统请输入:3|\n");
    printf("+====================+\n");
}





static int book_show(BOOK* temp){
    SetConsoleOutputCP(65001);
    if(temp==NULL)
    return SYSTEM_FALSE;
    printf("+========+=======================================+\n");
    printf("|%s    |%39s|\n","书名",temp->name);
    printf("|%s    |%39s|\n", "作者", temp->writer);
    printf("|%s    |%39s|\n", "数量", temp->sum);
    printf("|%s      |%39s|\n", "ID", temp->ID);
    printf("|%s|%39s|\n", "可否外借", temp->IS_BOW);
    printf("+==============+=================================+\n");
    return SYSTEM_RIGHT;
}

static void book_modify_show(){
    CLEAR_SCREEN();
    s_admin_chanbook();
    printf("+===============+\n");
    printf("|修改书名请输入:1|\n");
    printf("|修改作者请输入:2|\n");
    printf("|修改数量请输入:3|\n");
    printf("|修改展示请输入:4|\n");
    printf("|退出修改请输入:5|\n");
    printf("+===============+\n");
}




static int modify_book(BOOK*temp){
    CLEAR_SCREEN();
    s_admin_chanbook();
    if(book_show(temp)==SYSTEM_FALSE){
    error_mng("图书不存在！");
    return SYSTEM_FALSE;
    }
    book_modify_show();
    printf("输入您想更改的信息:");
    char p[1024];
    gets(p);
    if(symbol_mode3(p,'1','5')==SYSTEM_FALSE){
        error_mng("请输入给定的字符信息！");
        return modify_book(temp);
    }
    switch(str_trans_int(p)){
        case 1:{
            modify_name(temp);
            break;
        }
        case 2:{
            modify_writer(temp);
            break;
        }case 3:{
            modify_sum(temp);
            break;
        }case 4:{
            modify_IS_BOW(temp);
            break;
        }case 5:{
            break;
        }
    }
    file_book_sto();
    return SYSTEM_RIGHT;
}

static  int modify_name(BOOK*book_){
    s_admin_chanbook();
    book_show(book_);
    printf("请输入更改后的书名:");
    char temp[50];
    gets(temp);
    if (symbol_mode1(temp) == SYSTEM_FALSE)
    {
        error_mng("不要包含\"[\"和\"]\"");
        return modify_name(book_);
    }
    if (strlen(temp) > 30)
    {
        error_mng("书名太长啦~");
        return modify_name(book_);
    }
    strcpy(book_->name,temp);
    return SYSTEM_RIGHT;
}

static int modify_writer(BOOK *book_)
{
    s_admin_chanbook();
    book_show(book_);
    printf("请输入更改后的作者:");
    char temp[50];
    gets(temp);
    if (symbol_mode1(temp) == SYSTEM_FALSE)
    {
        error_mng("不要包含\"[\"和\"]\"");
        return modify_writer(book_);
    }
    if (strlen(temp) > 30)
    {
        error_mng("作者太长啦~");
        return modify_writer(book_);
    }
    strcpy(book_->writer, temp);
    return SYSTEM_RIGHT;
}

static int modify_sum(BOOK *book_)
{
    s_admin_chanbook();
    book_show(book_);
    printf("请输入更改后的数量:");
    char temp[50];
    gets(temp);
    if (symbol_mode1(temp) == SYSTEM_FALSE)
    {
        error_mng("不要包含\"[\"和\"]\"");
        return modify_sum(book_);
    }
    if (strlen(temp) > 30)
    {
        error_mng("数量名太长啦~");
        return modify_sum(book_);
    }
    if(type_input(temp)!=NUMBER){
        error_mng("请输入数字！");
        return modify_sum(book_);
    }
    strcpy(book_->sum, temp);
    return SYSTEM_RIGHT;
}

static int modify_IS_BOW(BOOK *book_)
{
    s_admin_chanbook();
    book_show(book_);
    printf("可展示请输入%d,不可展示请输入%d:",SYSTEM_RIGHT,SYSTEM_FALSE);
    char temp[50];
    gets(temp);

    if(strlen(temp)>1){

        error_mng("只能输入0或者1!");
        return modify_IS_BOW(book_);
    }
    if(str_trans_int(temp)!=0&&str_trans_int(temp)!=1){
        error_mng("只能输入0或者1!");
        return modify_IS_BOW(book_);
    }
    strcpy(book_->IS_BOW, temp);
    return SYSTEM_RIGHT;
}




static void all_books_views(){
    if(head==NULL){
        no_book_serch();
        return;
    }
    else{
        BOOK*temp=head;
        while(temp!=NULL){
            book_show(temp);
            temp=temp->NEXT;
        }
    }
    char p[1024];
    printf("输入任意继续:");
    gets(p);
    return;
}

static void no_book_serch(){
    CLEAR_SCREEN();
    printf("+=============================+\n");
    printf("|                             |\n");
    printf("|           暂无图书           |\n");
    printf("|                             |\n");
    printf("+=============================+\n");
    printf("输入任意继续:");
    char p[1024];
    gets(p);
}



int admin_chanbook(usr*temper){
    char p[1024];
    while(1==1){
        CLEAR_SCREEN();
        admin_chanbook_show(temper);
        //all_books_views();
        gets(p);
        if(symbol_mode3(p,'1','3')==SYSTEM_FALSE){
            error_mng("请按要求输入!");
        continue;
        }
        switch (str_trans_int(p))
        {
        case 1:{
            all_books_views();
            break;
        }
        case 2:{
            serch_book_view(temper);
            break;
        }
        case 3:{
            return SYSTEM_RIGHT;
        }
        }
    }

}

static void search_show_usr(){
    CLEAR_SCREEN();
    printf("+======================================+\n");
    printf("|           1.关键词模糊搜索            |\n");
    printf("|           2.书籍数量搜索              |\n");
    printf("|           3.退出当前系统              |\n");
    printf("+======================================+\n");
}


static void serch_book_view(usr*temper){
        CLEAR_SCREEN();
    while(1==1){
        search_show_usr();
        char p[1024];
        gets(p);
        if(symbol_mode3(p,'1','3')==SYSTEM_FALSE){
            error_mng("请按要求输入!");
            continue;
        }
        switch(str_trans_int(p)){
            case 1:{
                s_match_search(temper);
                break;
            }
            case 2:{
                s_number_search();
                break;
            }
            case 3:{
                return ;
            }
        }
        change_books(temper);
    }
}

static void change_books(usr*temper){
    if(check(temper->type,MNG_TYPE)==SYSTEM_FALSE){
        printf("输入任意以继续:");
        char Donk[666];
        gets(Donk);
        return;
    }else{
        char p[1024];
        printf("请输入要更改书籍的ID:");
        gets(p);
        modify_book(serch_ID(p));
    }
}


static void stack_book_all_view(){
    if(stack_top()==NULL){
        no_book_serch();
        return;
    }
    while(stack_top!=NULL){
        book_show(stack_top());
        if(stack_pop()==SYSTEM_FALSE)
        break;
    }
    stack_cls();
    return;
}

static void s_number_search(){
    char p[1024];
    printf("请输入图书数量:");
    gets(p);
    if(type_input(p)==STR){
        error_mng("请输入数字!");
        return ;
    }
    serch_num(p);
    stack_book_all_view();
}

static void s_match_search(){
    char p[1024];
    printf("请输入关键词:");
    gets(p);
    match_search(p);
    stack_book_all_view();
    return;
}


static void admin_chanbook_show(usr*temper){
    CLEAR_SCREEN();
    if(check(temper->type,MNG_TYPE)==SYSTEM_RIGHT){
    printf("+======================================+\n");
    printf("|         修改查看书籍信息系统          |\n");
    printf("+======================================+\n");
    }
    else{
    printf("+======================================+\n");
    printf("|           书籍信息查看系统            |\n");
    printf("+======================================+\n");  
    }
    printf("+======================================+\n");
    printf("|           1.查看全部书籍              |\n");
    printf("|           2.书籍相关信息搜索          |\n");
    printf("|           3.退出当前系统              |\n");
    printf("+======================================+\n");

}

static int check(char str1[], char str2[])
{
    if (strlen(str1) != strlen(str2))
        return SYSTEM_FALSE;
    int i = 0;
    while (str1[i] != '\0' && str1[i] != '\n')
    {
        if (str1[i] != str2[i])
            return SYSTEM_FALSE;
        i++;
    }
    return SYSTEM_RIGHT;
}





