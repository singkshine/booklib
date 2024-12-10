#include "connection.h"
#include "Linkmake.h"
#include "mng.h"
// 欢迎界面
static usr *now_usr_;
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

static void error_systems(char *p){
    printf("%s\n",p);
    printf("输入任意以继续:");
}



void welcome_screen() {
    char input[10];
    while (1) {
        CLEAR_SCREEN();
    s_welcome_screen();
        gets(input); 
        if (symbol_mode3(input, '1', '3') == SYSTEM_RIGHT) {
            int choice = str_trans_int(input); 

            switch (choice) {
                case 1:
                    CLEAR_SCREEN();
                    usr_designer();
                    break;
                case 2:
                    CLEAR_SCREEN();
                    login_screen();
                    break;
                case 3:
                    CLEAR_SCREEN();
                    printf("感谢使用，再见！\n");
                    exit(0);
            }
        } else {
            printf("无效输入，请重新选择。\n");
        }
    }
}
// 登录界面
void login_screen() {//+++
    char input[10];
    while (1==1) {
    CLEAR_SCREEN();
    s_login_screen();
        gets(input); 
        if (symbol_mode3(input, '1', '2') == SYSTEM_RIGHT) {
            int choice = str_trans_int(input); 
            switch (choice) {
                case 1:
                    CLEAR_SCREEN();
                    enroll_visitor();
                    break;
                case 2:
                    CLEAR_SCREEN();
                    return;
                    break;        
            }
        } else {
            printf("无效输入，请重新选择。\n");
        }
    }
}



//登录
void enroll_visitor(){ 
    s_enroll_visitor();
    char usr_name[20];
    char usr_pass[20];
    while(1==1){
        int i=0;
        CLEAR_SCREEN();
        printf("请输入账号:");
        gets(usr_name);
        usr*pass_usr=search_usr(usr_name);
        if(pass_usr==NULL){
            error_systems("用户名不存在!");
            printf("退出请输入exit:");
            char p[1024];
            gets(p);
            if(check(p,"exit")==SYSTEM_RIGHT)
            return;
        continue;
        }
        while(1==1){
            printf("请输入密码(密码输入五次错误自动退出):");
            gets(usr_pass);
            if(check(usr_pass,search_usr(usr_name)->pass)==SYSTEM_RIGHT){
                i=99;
                break;
            }
            error_systems("密码错误!");
            i++;
            if(i>5){
                i=66;
                break;
            }
        }
        printf("%d\n",i);
        if(i==99){
            usr_main_show(search_usr(usr_name));
        }
        if(i==66){
            error_systems("密码错误过多!");
            return;
        }
    }
    return;
    
}