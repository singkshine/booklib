#include "mng.h"
#include "screen.h"
#include "connection.h" 
int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    SYSTEM_ALL_FILE_READ();
    welcome_screen();
    SYSTEM_ALL_FILE_STORAGE();
    SYSTEM_ALL_FREE();
return 0;
}
