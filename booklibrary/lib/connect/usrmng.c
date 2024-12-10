#include "screen.h"
#include "Linkmake.h"
#include "mng.h"
#ifndef USRMNG_C
#define USRMNG_C
static int check(char str1[], char str2[]);
static void error_usr(char *temp);
static int check_str_(char serch_ch[], char serched_ch[]);
static int usr_mng_match(char *strpart);
static void usr_mng_view();
static void usr_mng_modify();
static void usr_name_designer(char usr_name[]);
static void usr_pass_designer(char usr_pass[]);
static void mng_book_(usr *temp);
static void mng_main_show_();
#endif

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

static void error_usr(char *temp){
    CLEAR_SCREEN();
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
    printf("%s\n",temp);
    printf("输入任意继续:");
    char p[1024];
    gets(p);
}

static int check_str_(char serch_ch[], char serched_ch[])
{
    int i = 0, j = 0;
    for (i = 0; i < strlen(serch_ch); i++)
    {
        for (; j < strlen(serched_ch); j++)
        {
            if (serch_ch[i] == serched_ch[j])
                break;
        }
        if (j >= strlen(serched_ch))
            return SYSTEM_FALSE;
    }
    if (j < strlen(serched_ch))
        return SYSTEM_RIGHT;
    return SYSTEM_FALSE;
}

static int usr_mng_match(char *strpart){
    int i=0;
    usr*usr_head=get_usr_head();
    usr*usr_tail=usr_top();
    if(usr_head==NULL){
        error_usr("没有用户!");
        return SYSTEM_FALSE;
    }
    usr*temp=usr_head;
    while(temp!=NULL){
        if(check_str_(strpart,temp->usr)==SYSTEM_RIGHT){
            printf("usr name:%30s\n",temp->usr);
            i++;
        }
        temp=temp->NEXT;
    }
    if(i==0){
        error_usr("没有用户!");
    return SYSTEM_FALSE;
    }
    return SYSTEM_RIGHT;
}


void usr_mng(){
    char chose_[1024];
    while(1==1){
        CLEAR_SCREEN();
        usr_mng_view();
        printf("请选择操作:");
        gets(chose_);
        if(symbol_mode3(chose_,'1','2')==SYSTEM_FALSE){
            error_usr("请按照要求输入!");
            continue;
        }
        switch(str_trans_int(chose_))
        {
            case 1:{
                usr_mng_modify();
                break;
            }
            case 2:{
                return;
            }
        }
    }
}



static void usr_mng_view(){
    
    printf("+======================================+\n");
    printf("|         用户信息管理系统              |\n");
    printf("+======================================+\n");
    printf("|         1.查看修改用户信息            |\n");
    printf("|         2.退出该系统                  |\n");
    printf("+======================================+\n");
}


static void usr_mng_modify(){
    CLEAR_SCREEN();
    printf("请输入你想查找用户的关键词(如若全部展示请回车):");
    char p[1024];
    gets(p);
    if(usr_mng_match(p)==SYSTEM_FALSE)
    return;
    while(1==1){
        printf("如需删除用户请输入用户id,退出请输入exit:");
        gets(p);
        if(check(p,"exit")==SYSTEM_RIGHT)
            return;
        usr*temp=search_usr(p);
        if(temp==NULL){
            error_usr("没有该用户！");
            continue;
        }
        if(check(temp->type,MNG_TYPE)==SYSTEM_RIGHT){
            error_usr("权限不足!");
            continue;
        }
        usr_del(search_usr(p));
        file_usr_sto();
        file_usr_read();
        
    }
}

void usr_designer()
{
    char usr_name[20];
    usr_name_designer(usr_name);
    char usr_pass[20];
    usr_pass_designer(usr_pass);
    usr*temper=(usr*)malloc(sizeof(usr));
    strcpy(temper->usr,usr_name);
    strcpy(temper->pass,usr_pass);
    strcpy(temper->type,TUR_TYPE);
    temper->NEXT=NULL;
    usr_push(temper);
    file_usr_sto();
    file_usr_read();
}

static void usr_pass_designer(char usr_pass[]){
    char temp_pass[20];
    while(1==1){
        CLEAR_SCREEN();
        printf("请输入密码(不多于19个字符):");
        gets(usr_pass);
        if(symbol_mode2(usr_pass)==SYSTEM_FALSE||strlen(usr_pass)>=20){
            error_usr("密码过长或包含违禁字符!");
            continue;
        }
        printf("请确认密码:");
        gets(temp_pass);
        if(check(temp_pass,usr_pass)==SYSTEM_FALSE){
            error_usr("两次密码不符!");
            continue;
        }
        return;
    }
}

static void usr_name_designer(char usr_name[])
{
    CLEAR_SCREEN();
    printf("请输入用户名(不多于19个字符):");
    gets(usr_name);
    if(symbol_mode2(usr_name)==SYSTEM_FALSE||strlen(usr_name)>=20){
        error_usr("用户名过长或包含违禁字符!");
        return usr_name_designer(usr_name);
    }

    if(search_usr(usr_name)!=NULL){
        error_usr("用户名已注册！");
        return usr_name_designer(usr_name);
    }
    
    return ;
}

static void mng_main_show_(){
    printf("+======================================+\n");
    printf("|             管理员界面               |\n");
    printf("+======================================+\n");
    printf("|           1. 图书管理系统            |\n");
    printf("|           2. 用户管理系统            |\n");
    printf("|           3.退出当前系统             |\n");
    printf("+======================================+\n");
}

void usr_main_show(usr *temp)
{
    char p[1024];
    if (check(temp->type,MNG_TYPE)){

        while(1==1){
            CLEAR_SCREEN();
            mng_main_show_();
                printf("请输入选项:");
            gets(p);
            if(symbol_mode3(p,'1','3')==SYSTEM_FALSE){
                error_usr("请按照要求输入!");
                continue;
            }
            switch(str_trans_int(p)){
                case 1:{
                    mng_book_(temp);
                    break;
                }
                case 2:{
                    usr_mng_modify();
                    break;
                }
                case 3:{
                    return ;
                }
            }
        }
    }
    else{
        admin_chanbook(temp);
    }
}


static void mng_book_(usr*temp){
    char p[1024];
    while (1 == 1)
    {
        CLEAR_SCREEN();
        s_manage_books();
        printf("请输入选择:");
        gets(p);
        if (symbol_mode3(p, '1', '3') == SYSTEM_FALSE)
        {
            error_usr("请按照要求输入!");
            continue;
        }
        switch (str_trans_int(p))
        {
        case 1:
        {
            admin_stobook();
            break;
        }
        case 2:
        {
            admin_chanbook(temp);
            break;
        }
        case 3:
        {
            return;
        }
        }
    }
}