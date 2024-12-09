#include "screen.h"


void shadow() {
    if(OS_TYPE){
        SetConsoleOutputCP(65001);
    }
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
    printf("+======================================+\n");
    printf("|         图书馆管理系统               |\n");
    printf("+--------------------------------------+\n");
    printf("|         1. 注册                      |\n");
    printf("|         2. 登录                      |\n");
    printf("|         3. 退出                      |\n");
    printf("+======================================+\n");
    printf("请输入选项：");
}
void s_register_enroll(){
    printf("+======================================+\n");
    printf("|         图书馆注册系统               |\n");
    printf("+--------------------------------------+\n");
    printf("|         1. 游客注册                  |\n");
    printf("|         2. 退出                      |\n");
    printf("+======================================+\n");
    printf("请输入选项：");
}
// 登录界面
void s_login_screen() {
    printf("+======================================+\n");
    printf("|         登录界面                     |\n");
    printf("+--------------------------------------+\n");
    printf("|         1. 游客登录                  |\n");
    printf("|         2. 管理员登录                |\n");
    printf("+======================================+\n");
    printf("请输入选项：");
}

// 游客菜单
void s_visitor_menu() {
    printf("+======================================+\n");
    printf("|         游客菜单                     |\n");
    printf("+--------------------------------------+\n");
    printf("|         1. 查看所有图书              |\n");
    printf("|         2. 返回主菜单                |\n");
    printf("+======================================+\n");
    printf("请输入选项：");

}

// 管理员菜单
void s_admin_menu() {
    printf("+======================================+\n");
    printf("|         管理员菜单                   |\n");
    printf("+--------------------------------------+\n");
    printf("|         1. 查看所有图书              |\n");
    printf("|         2. 查看用户信息              |\n");
    printf("|         3. 返回主菜单                |\n");
    printf("+======================================+\n");
    printf("请输入选项：");

}

// 查看所有图书（模拟数据）
void s_display_books_visitor() {
    printf("+======================================+\n");
    printf("|         图书列表                     |\n");
    printf("+--------------------------------------+\n");
}
void s_display_books_visitor_2() {
    printf("+======================================+\n");
    printf("|         1. 借书                      |\n");
    printf("|         2. 还书                      |\n");
    printf("|         3. 返回游客菜单              |\n");
    printf("+======================================+\n");
    printf("请输入选项：");
    
}
void s_display_books_admin() {
    printf("+======================================+\n");
    printf("|         图书列表                     |\n");
    printf("+--------------------------------------+\n");
}
void s_display_books_admin_2() {
    printf("+======================================+\n");
    printf("|         1. 管理图书信息              |\n");
    printf("|         2. 返回管理员菜单            |\n");
    printf("+======================================+\n");
    printf("请输入选项：");
}

// 借书
void s_borrow_book() {
    printf("+======================================+\n");
    printf("|         借书界面                     |\n");
    printf("+======================================+\n");
    printf("请输入要借的图书编号：");
    int book_id;
    scanf("%d", &book_id);
    printf("成功借阅图书编号：%d。\n", book_id);
    printf("按任意键返回。\n");
}

// 还书
void s_return_book() {
    printf("+======================================+\n");
    printf("|         还书界面                     |\n");
    printf("+======================================+\n");
    printf("请输入要归还的图书编号：");
    int book_id;
    scanf("%d", &book_id);
    printf("成功归还图书编号：%d。\n", book_id);
    printf("按任意键返回。\n");
}

// 管理/修改图书信息
void s_manage_books() {
    printf("+======================================+\n");
    printf("|         管理图书                     |\n");
    printf("+======================================+\n");
    printf("|         1. 存入书籍                |\n");
    printf("|         2. 删除书籍               |\n");
    printf("|         3. 更改图书信息             |\n");
    printf("|         4. 返回管理员菜单            |\n");
    printf("+======================================+\n");
    
}

// 查看用户信息
void s_view_users() {
    printf("+======================================+\n");
    printf("|         用户信息                     |\n");
    printf("+======================================+\n");
    printf("功能暂未实现。\n");
    printf("按任意键返回。\n");
    getchar();
    getchar();
    CLEAR_SCREEN();
    
}
void s_zhuce_visitor(){
     printf("---------------用户注册中--------------------");
}

void s_enroll_visitor(){
    printf("+======================================+\n");
    printf("|         用户登录界面                 |\n");
    printf("+--------------------------------------+\n");
    printf("|         请输入用户名和密码           |\n");
    printf("+======================================+\n");
}

void s_enroll_admin(){
    printf("+======================================+\n");
    printf("|         管理员登录界面               |\n");
    printf("+--------------------------------------+\n");
    printf("|         请输入账号和密码             |\n");
    printf("+======================================+\n");
}

void s_admin_stobook(){
    printf("+======================================+\n");
    printf("|         存入书籍                  |\n");
    printf("+======================================+\n");
}

void s_admin_delbook(){
    printf("+======================================+\n");
    printf("|         删除书籍                  |\n");
    printf("+======================================+\n");
}

void s_admin_chanbook(){
    printf("+======================================+\n");
    printf("|       修改书籍信息                  |\n");
    printf("+======================================+\n");
}

// 判断字符是否为中文（UTF-8 编码）
int is_chinese(const unsigned char *c) {
    return (*c >= 0x80 && *c <= 0xEF); // 中文字符在UTF-8下以0x80-0xEF开头
}

// 获取字符串的显示宽度（中文占2，英文占1）
int get_display_width(const char *str) {
    int width = 0;
    for (int i = 0; str[i] != '\0';) {
        if (is_chinese((unsigned char *)&str[i])) {
            width += 2; // 中文字符占2个宽度
            i += 3;     // UTF-8 中文字符占3个字节
        } else {
            width += 1; // 英文字符占1个宽度
            i += 1;
        }
    }
    return width;
}

// 对齐打印字符
void print_aligned(const char *str, int total_width) {
    int str_width = get_display_width(str); // 计算字符串的显示宽度
    int padding = total_width - str_width;  // 计算需要填充的空格数

    if (padding < 0) {
        // 字符串超出总宽度时，截断
        for (int i = 0, width = 0; str[i] != '\0';) {
            if (is_chinese((unsigned char *)&str[i])) {
                if (width + 2 > total_width) break;
                printf("%.*s", 3, &str[i]);
                width += 2;
                i += 3;
            } else {
                if (width + 1 > total_width) break;
                printf("%c", str[i]);
                width += 1;
                i += 1;
            }
        }
    } else {
        // 正常对齐，先打印字符串，再打印空格
        printf("%s", str);
        for (int i = 0; i < padding; i++) {
            printf(" ");
        }
    }
    printf("\n"); // 换行
}
// int main() {
//     char str1[] = "Hello世界";
//     char str2[] = "测试中文";
//     char str3[] = "AlignTest";

//     int width = 16; // 对齐的总宽度

//     printf("对齐显示:\n");
//     print_aligned(str1, width);
//     print_aligned(str2, width);
//     print_aligned(str3, width);

//     return 0;
// }