#include "connection.h"
typedef struct usr_ {
    char usr[LIM_INPUT];
    char pass[LIM_INPUT];
    struct usr_ *NEXT;
} usr;
usr*usr_head=NULL;

// 欢迎界面
void welcome_screen() {
    s_welcome_screen();
    char input[10];
    while (1) {
        gets(input); 
        if (symbol_mode3(input, '1', '3') == SYSTEM_RIGHT) {
            int choice = str_to_int(input); 

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
            }
        } else {
            printf("无效输入，请重新选择。\n");
        }
    }
}
void register_enroll(){
    s_register_enroll();
    char input[10];
    while (1) {
        gets(input); 
        if (symbol_mode3(input, '1', '2') == SYSTEM_RIGHT) {
            int choice = str_to_int(input); 
            switch (choice) {
                case 1:
                    CLEAR_SCREEN();
                    zhuce_visitor();
                    break;
                case 2:
                    CLEAR_SCREEN();
                    welcome_screen();
                    break;
            }
        } else {
            printf("无效输入，请重新选择。\n");
            
        }
    }
}

//用户注册界面
void zhuce_visitor() {
    s_zhuce_visitor();  
    char username[20];
    char password[20];
    printf("请输入账号: ");
    while (1) {
        gets(username); 
        if (symbol_mode2(username) == SYSTEM_RIGHT) { 
            username[strcspn(username, "\n")] = 0; 

            
            usr *current = usr_head;
            while (current != NULL) {
                if (strcmp(current->usr, username) == 0) {
                    printf("账号已经被使用，请重新输入！\n");
                    return;  
                }
                current = current->NEXT;
            }

            printf("请输入密码: ");
            while (1) {
                gets(password);
                if (symbol_mode2(password) == SYSTEM_RIGHT) { 
                    password[strcspn(password, "\n")] = 0;  

                   
                    usr *new_user = (usr *)malloc(sizeof(usr));  
                    if (new_user == NULL) {
                        printf("内存分配失败!\n");
                        return; 
                    }

                    strcpy(new_user->usr, username);
                    strcpy(new_user->pass, password);
                    new_user->NEXT = usr_head; 
                    usr_head = new_user;
                   
                    if (file_usr_sto() == SYSTEM_FALSE) {
                        printf("保存用户信息失败！\n");
                        return;  
                    }

                    printf("注册成功！\n");
                    return;  
                } else {
                    printf("密码输入无效，请重新输入：\n");
                }
            }
        } else {
            printf("账号输入无效，请重新输入！\n");
        }
    }
}
// 登录界面
void login_screen() {
    s_login_screen();
    char input[10];
    while (1) {
        gets(input); 
        if (symbol_mode3(input, '1', '2') == SYSTEM_RIGHT) {
            int choice = str_to_int(input); 
            switch (choice) {
                case 1:
                    CLEAR_SCREEN();
                    enroll_visitor();
                    break;
                case 2:
                    CLEAR_SCREEN();
                    enroll_admin();
                    break;        
            }
        } else {
            printf("无效输入，请重新选择。\n");
        }
    }
}

//游客登录
void enroll_visitor(){ 
    s_enroll_visitor();
    //完善中
    printf("完善中\n");
    visitor_menu;
    
}

//管理员登录
void enroll_admin(){
    s_enroll_admin();
    printf("请输入账号：");
    printf("\n");
    printf("请输入密码：");
    
}
// 游客菜单
void visitor_menu() {
    s_visitor_menu();
    char input[10];
    while (1) {
        gets(input); 
        if (symbol_mode3(input, '1', '2') == SYSTEM_RIGHT) {
            int choice = str_to_int(input); 
            switch (choice) {
                case 1:
                    CLEAR_SCREEN();
                    display_books_visitor();
                    break;
                case 2:
                    CLEAR_SCREEN();
                    welcome_screen();
                    break;
            }
        } else {
            printf("无效输入，请重新选择。\n");
        }
    }
}

// 管理员菜单
void admin_menu() {
    s_admin_menu();
    char input[10];
    while (1) {
        gets(input); 
        if (symbol_mode3(input, '1', '3') == SYSTEM_RIGHT) {
            int choice = str_to_int(input); 
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
            }
        } else {
            printf("无效输入，请重新选择。\n");
        }
    }
}

// 查看所有图书
void display_books_visitor() {
    s_display_books_visitor();
//这里要加输出
    s_display_books_visitor_2();
    char input[10];
    while (1) {
        gets(input); 
        if (symbol_mode3(input, '1', '3') == SYSTEM_RIGHT) {
            int choice = str_to_int(input); 
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
            }
        } else {
            printf("无效输入，请重新选择。\n");

        }
    }
    
}
void display_books_admin() {
    s_display_books_admin();
//这里要加输出
    s_display_books_admin_2();
    char input[10];
    while (1) {
        gets(input); 
        if (symbol_mode3(input, '1', '3') == SYSTEM_RIGHT) {
            int choice = str_to_int(input); 
            switch (choice) {
                case 1:
                    CLEAR_SCREEN();
                    manage_books();
                    break;
                case 2:
                    CLEAR_SCREEN();
                    admin_menu();
                    break;
            }
        } else {
            printf("无效输入，请重新选择。\n");
        }
    }
   
}

// 借书
void borrow_book() {
    s_borrow_book();
    //完善中
    printf("完善中");
    visitor_menu();
}

// 还书
void return_book() {
    s_return_book();
    //完善中
    printf("完善中");
    visitor_menu();
}

// 管理图书
void manage_books() {
    s_manage_books();
    char input[10];
    while (1) {
        gets(input); 
        if (symbol_mode3(input, '1', '4') == SYSTEM_RIGHT) {
            int choice = str_to_int(input); 
            switch (choice) {
                case 1:
                    CLEAR_SCREEN();
                    admin_stobook();
                    break;
                case 2:
                    CLEAR_SCREEN();
                    admin_delbook();
                    break;
                case 3:
                    CLEAR_SCREEN();
                    admin_chanbook();
                    break;
                case 4:
                    CLEAR_SCREEN();
                    admin_menu();
                    break;
            }
        } else {
            printf("无效输入，请重新选择。\n");
        }
    }
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

//管理员存入书籍
void admin_stobook(){
    s_admin_stobook();
    printf("请输入要存入的书籍书名和作业，并设定数量");
}

//管理员删除书籍
void admin_delbook(){
    s_admin_delbook();
}

//管理员更改图书信息
void admin_chanbook(){

}
