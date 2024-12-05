
#ifndef CONNECTION_H
#define CONNECTION_H
#endif
#include "Linkmake.h"
#include  "sto.h"
#include "screen.h"

#ifndef RUN
#define RUN_T 1
#define RUN_F 0
#define RUN int
#endif
void welcome_screen();
void login_screen();
void visitor_menu();
void admin_menu();
void display_books_visitor();
void display_books_admin();
void borrow_book();
void return_book();
void manage_books();
void view_users();
void register_enroll();
void enroll_visitor();
void enroll_admin();
void zhuce_visitor();
void status();
void show();
void admin_stobook();
void admin_delbook();
void admin_chanbook();
void display_status();