#ifndef SCREEN_H
#define SCREEN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void s_welcome_screen();
void s_login_screen();
void s_visitor_menu();
void s_admin_menu();
void s_display_books_visitor();
void s_display_books_admin();
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
void shadow();

#endif