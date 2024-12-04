#include "screen.h"
#if defined(_WIN32)||defined(_WIN64)
    #include <windows.h>
    #define OS_TYPE 1
    #define CLEAR_SCREEN() system("cls")
#elif defined(__linux__) || defined(__unix__)
    #include<unisted.h>
    #define OS_TYPE 0
    #define CLEAR_SCREEN() system("clear") 
#endif

void shadow() {
    if(OS_TYPE){
        SetConsoleOutputCP(65001);
    }
    welcome_screen();
}

void display_status(int seconds_left) {
    for (int i = 0; i < (5 - seconds_left); i++) {
        printf(".");
    }
}
void status(){
    int total_time = 5;
    for (int i = total_time; i >= 0; i--) {
        display_status(i); 
        sleep(1); 
    }
    CLEAR_SCREEN();
}
//显示界面
void show(int a){
printf("show test!");
}

// 欢迎界面
void s_welcome_screen() {
    printf("*****************************************\n");
    printf("*         图书馆管理系统               *\n");
    printf("*****************************************\n");
    printf("*         1. 注册                      *\n");
    printf("*         2. 登录                      *\n");
    printf("*         3. 退出                      *\n");
    printf("*****************************************\n");
    printf("请输入选项：");
}
void s_register_enroll(){
    printf("*****************************************\n");
    printf("*         图书馆注册系统               *\n");
    printf("*****************************************\n");
    printf("*         1. 游客注册                  *\n");
    printf("*         2. 退出                      *\n");
    printf("*****************************************\n");
    printf("请输入选项：");
}
// 登录界面
void s_login_screen() {
    printf("*****************************************\n");
    printf("*         登录界面                     *\n");
    printf("*****************************************\n");
    printf("*         1. 游客登录                  *\n");
    printf("*         2. 管理员登录                *\n");
    printf("*****************************************\n");
    printf("请输入选项：");
}

//游客登录
void s_enroll_visitor(){
    printf("测试中\n");
    status();
    visitor_menu();
}

//管理员登录
void s_enroll_admin(){
    printf("测试中\n");
    status();
    admin_menu();
}
// 游客菜单
void s_visitor_menu() {
    printf("*****************************************\n");
    printf("*         游客菜单                     *\n");
    printf("*****************************************\n");
    printf("*         1. 查看所有图书              *\n");
    printf("*         2. 返回主菜单                *\n");
    printf("*****************************************\n");
    printf("请输入选项：");

}

// 管理员菜单
void s_admin_menu() {
    printf("*****************************************\n");
    printf("*         管理员菜单                   *\n");
    printf("*****************************************\n");
    printf("*         1. 查看所有图书              *\n");
    printf("*         2. 查看用户信息              *\n");
    printf("*         3. 返回主菜单                *\n");
    printf("*****************************************\n");
    printf("请输入选项：");

}

// 查看所有图书（模拟数据）
void s_display_books_visitor() {
    printf("*****************************************\n");
    printf("*         图书列表                     *\n");
    printf("*****************************************\n");
    printf("1. 《C语言程序设计》 - 谭浩强\n");
    printf("2. 《数据结构与算法》 - 严蔚敏\n");
    printf("3. 《计算机组成原理》 - 唐朔飞\n");
    printf("*****************************************\n");
    printf("*         1. 借书                      *\n");
    printf("*         2. 还书                      *\n");
    printf("*         3. 返回游客菜单              *\n");
    printf("*****************************************\n");
    printf("请输入选项：");
    
}
void s_display_books_admin() {
    printf("*****************************************\n");
    printf("*         图书列表                     *\n");
    printf("*****************************************\n");
    printf("1. 《C语言程序设计》 - 谭浩强\n");
    printf("2. 《数据结构与算法》 - 严蔚敏\n");
    printf("3. 《计算机组成原理》 - 唐朔飞\n");
    printf("*****************************************\n");
    printf("*         1. 管理图书信息              *\n");
    printf("*         2. 返回管理员菜单              *\n");
    printf("*****************************************\n");
    printf("请输入选项：");
   
}

// 借书
void s_borrow_book() {
    printf("*****************************************\n");
    printf("*         借书界面                     *\n");
    printf("*****************************************\n");
    printf("请输入要借的图书编号：");
    int book_id;
    scanf("%d", &book_id);
    printf("成功借阅图书编号：%d。\n", book_id);
    printf("按任意键返回。\n");
    getchar();
    getchar();
}

// 还书
void s_return_book() {
    printf("*****************************************\n");
    printf("*         还书界面                     *\n");
    printf("*****************************************\n");
    printf("请输入要归还的图书编号：");
    int book_id;
    scanf("%d", &book_id);
    printf("成功归还图书编号：%d。\n", book_id);
    printf("按任意键返回。\n");
    getchar();
    getchar();
    CLEAR_SCREEN();
}

// 管理/修改图书信息
void s_manage_books() {
    printf("*****************************************\n");
    printf("*         管理图书                     *\n");
    printf("*****************************************\n");
    printf("功能暂未实现。\n");
    printf("按任意键返回。\n");
    getchar();
    getchar();
    CLEAR_SCREEN();
    
}

// 查看用户信息
void s_view_users() {
    printf("*****************************************\n");
    printf("*         用户信息                     *\n");
    printf("*****************************************\n");
    printf("功能暂未实现。\n");
    printf("按任意键返回。\n");
    getchar();
    getchar();
    CLEAR_SCREEN();
    
}
void s_zhuce_visitor(){
printf("*****************************************");
printf("请输入账号：");
}