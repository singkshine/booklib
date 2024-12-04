#include "connection.h"


// 欢迎界面
void welcome_screen() {
    s_welcome_screen();
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
        CLEAR_SCREEN();
            register_enroll();
            break;
        case 2:
        CLEAR_SCREEN();
            login_screen();
            break;
        case 3:
        CLEAR_SCREEN();
            printf("感谢使用，再见！\n");
            exit(0);
            
        default:
        CLEAR_SCREEN();
            printf("无效输入，请重新选择。\n");
            welcome_screen();
    }
}
void register_enroll(){
    s_register_roll():
     int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
        CLEAR_SCREEN();
            zhuce_visitor();
            break;
        case 2:
        CLEAR_SCREEN();
            welcome_screen();
            break;
        default:
        CLEAR_SCREEN();
            printf("无效输入，请重新选择。\n");
            welcome_screen();
    }
}

//用户注册界面
void zhuce_visitor(){
    char username[51];
    char password[51];
    s_zhuce_visitor();
    scanf("%50s",username);
    printf("请输入密码(最多50个字符):")；
    scanf("%50s",password);
    //这儿还没写好
    printf("注册中");
    status();
    if(save_user(username,password)){
        printf("注册成功！\n");
    }else{
        printf("注册失败。\n");
    }

}

// 登录界面
void login_screen() {
    s_login_screen();
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
        CLEAR_SCREEN();
            enroll_visitor();
            break;
        case 2:
        CLEAR_SCREEN();
            enroll_admin();
            break;
        default:
        CLEAR_SCREEN();
            printf("无效输入，请重新选择。\n");
            login_screen();
    }
}

//游客登录
void enroll_visitor(){
    char login_username[51];
    char login_password[51];
    s_enroll_visitor();
    printf("请输入用户名：");
    scanf("%50s",login_username);
    printf("请输入密码：");
    scanf("%50s",login_password);
    //这儿没写好
    if(?){
        visitor_menu;
    }
    
}

//管理员登录
void enroll_admin(){
    s_enroll_admin();
    printf("请输入账号：");
    scanf("%50s",??);
    printf("请输入密码：");
    scanf("%50s",??);
    //这儿没写好
    if(?){
        admin_menu;
    }
}
// 游客菜单
void visitor_menu() {
    s_visitor_menu();
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
             CLEAR_SCREEN();
            display_books_visitor();
            break;
        case 2:
            CLEAR_SCREEN();
            welcome_screen();
            break;
        default:
            CLEAR_SCREEN();
            printf("无效输入，请重新选择。\n");
            visitor_menu();
    }
}

// 管理员菜单
void admin_menu() {
    s_admin_menu();
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            CLEAR_SCREEN();
            display_books_admin();
            break;
        case 2:
            CLEAR_SCREEN();
            view_users();
            break;
        case 3:
            CLEAR_SCREEN();
            welcome_screen();
            break;
        default:
            CLEAR_SCREEN();
            printf("无效输入，请重新选择。\n");
            admin_menu();
    }
}

// 查看所有图书（模拟数据）
void display_books_visitor() {
    s_display_books_visitor();
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            CLEAR_SCREEN();
            borrow_book();
            break;
        case 2:
            CLEAR_SCREEN();
            return_book();
            break;
        case 3:
            CLEAR_SCREEN();
            visitor_menu();
            break;
        default:
            CLEAR_SCREEN();
            printf("无效输入，请重新选择。\n");
    }
    
}
void display_books_admin() {
    s_display_books_admin();
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            CLEAR_SCREEN();
            manage_books();
            break;
        case 2:
            CLEAR_SCREEN();
            admin_menu();
            break;
        default:
            CLEAR_SCREEN();
            printf("无效输入，请重新选择。\n");
    }
   
}

// 借书
void borrow_book() {
    s_borrow_book();
    int book_id;
    scanf("%d", &book_id);
    printf("成功借阅图书编号：%d。\n", book_id);
    printf("按任意键返回。\n");
    getchar();
    getchar();
    visitor_menu();
}

// 还书
void return_book() {
    s_return_book();
    int book_id;
    scanf("%d", &book_id);
    printf("成功归还图书编号：%d。\n", book_id);
    printf("按任意键返回。\n");
    getchar();
    getchar();
    CLEAR_SCREEN();
    visitor_menu();
}

// 管理/修改图书信息
void manage_books() {
    s_manage_books();
    printf("功能暂未实现。\n");
    printf("按任意键返回。\n");
    getchar();
    getchar();
    CLEAR_SCREEN();
    admin_menu();
}

// 查看用户信息
void view_users() {
    s_view_users();
    printf("功能暂未实现。\n");
    printf("按任意键返回。\n");
    getchar();
    getchar();
    CLEAR_SCREEN();
    admin_menu();
}
