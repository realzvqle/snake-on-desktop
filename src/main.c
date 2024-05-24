#include "headers/main.h"
#include "headers/tools.h"
#include "headers/snake.h"
#include "headers/apple.h"
#include "headers/collision.h"
#include <winuser.h>




void _entry(){
    MessageBoxW(NULL, L"Snake Game By Zvqle\nOnly rule is to not go beyond the screen!\nTo Exit Click ESC\n\nHave Fun!!", L"Snake Game", MB_OK | MB_ICONINFORMATION);
RESTART:
    data* dta = alloc_mem(sizeof(data));
    dta->sHeight = GetSystemMetrics(SM_CYSCREEN);
    dta->sWidth = GetSystemMetrics(SM_CXSCREEN);
    dta->dc = GetDC(NULL);
    dta->background = CreateSolidBrush(RGB(0, 0, 0));
    snake* snke = setup_snake(dta);
    apple* aple = setup_apple();
    while(1){
        draw_snake(dta, snke);
        if(GetAsyncKeyState(VK_ESCAPE)) goto CLEANUP;
        int stat = check_collision(dta, aple, snke);
        if(stat == 1){
            ExitProcess(1);
        }
        if(stat == 2){
            end_apple(aple);
            end_snake(snke);
            ReleaseDC(NULL, dta->dc);
            DeleteObject(dta->background);
            free_mem(dta);
            goto RESTART;
        }
        draw_apple(dta, aple);

        Sleep(500);
    }


CLEANUP:
    end_apple(aple);
    end_snake(snke);
    ReleaseDC(NULL, dta->dc);
    DeleteObject(dta->background);
    free_mem(dta);
    ExitProcess(0);
}