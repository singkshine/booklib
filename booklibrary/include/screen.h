#ifndef SCREEN_H
#define SCREEN_H

#if defined(_WIN32)||defined(_WIN64)
    #include <windows.h>
    #define OS_TYPE 1
    #define CLEAR_SCREEN() system("cls")
#elif defined(__linux__) || defined(__unix__)
    #include<unistd.h>
    #define OS_TYPE 0
    #define CLEAR_SCREEN() system("clear") 
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void s_welcome_screen();
void s_login_screen();
void s_visitor_menu();
void s_admin_menu();
void s_display_books_visitor();
void s_display_books_visitor();
void s_display_books_admin();
void s_display_books_admin_2();
void s_borrow_book();
void s_return_book();
void s_manage_books();
void s_view_users();
void s_register_enroll();
void s_enroll_visitor();
void s_enroll_admin();
void s_zhuce_visitor();
void s_status();
void s_show();
void s_admin_stobook();
void s_admin_delbook();
void s_admin_chanbook();
void shadow();
void printf_aligned();

#endif