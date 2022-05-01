#include "a.h"


int drawStartMenu(void) {   // show start menu. 메인화면. 
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);  // 표준콘솔출력의 핸들을 반환.
    SetConsoleTextAttribute(hand, 13);  // 콘솔에서의 글자색을 분홍색(13)으로 변경한다.
    gotoxy(DEFAULT_X, DEFAULT_Y);       // 커서를 (0, 0) 좌표로 이동.
    printf("============================================");
    SetConsoleTextAttribute(hand, 14);  // 콘솔에서의 글자색을 노란색(14)으로 변경한다.
    printf("================ Snake Game ================");
    SetConsoleTextAttribute(hand, 11);  // 콘솔에서의 글자색을 하늘색(11)으로 변경한다.
    printf("============================================");
    SetConsoleTextAttribute(hand, 15);  // 콘솔에서의 글자색을 짙은 하얀색(15)으로 변경한다.
    gotoxy(DEFAULT_X, DEFAULT_Y + 4);   // 커서를 (0, 4) 좌표로 이동.
    printf("> Key  : up, down, left, right,");
    gotoxy(DEFAULT_X, DEFAULT_Y + 5);   // 커서를 (0, 5) 좌표로 이동.
    printf("> Exit : 't'");

    gotoxy(DEFAULT_X + 11, DEFAULT_Y + 14);     // 커서를 (11, 14) 좌표로 이동.
    printf("<Made by BlockDMask.>");
    gotoxy(DEFAULT_X + 11, DEFAULT_Y + 15);     // 커서를 (11, 15) 좌표로 이동.
    printf("<BlockDMask@gmail.com>");


    SetConsoleTextAttribute(hand, 14);     // 콘솔에서의 글자색을 노란색(14)으로 변경한다. 
    while (1) {
        int keyDown = getKeyDown();
        if (keyDown == 's' || keyDown == 'S') { // s나 S가 입력되면 콘솔에서의 글자색을 연한 흰색(7)으로
                                                // 변경 후 TRUE를 리턴.
            SetConsoleTextAttribute(hand, 7);
            return TRUE;
        }
        if (keyDown == 't' || keyDown == 'T') { // t나 T가 입력되면 콘솔에서의 글자색을 연한 흰색(7)으로
                                                // 변경 후 FALSE를 리턴.
            SetConsoleTextAttribute(hand, 7);
            return FALSE;
        }
        gotoxy(DEFAULT_X + 5, DEFAULT_Y + 9);   // 커서를 (5, 9) 좌표로 이동.
        printf("-- press 's' to start --");
        Sleep(1000 / 3);    // 0.3초마다 대기해서 깜빡이게 보이게 한다.
        gotoxy(DEFAULT_X + 5, DEFAULT_Y + 9);   // 커서를 (5, 9) 좌표로 이동.
        printf("                         ");
        Sleep(1000 / 3);    // 0.3초마다 대기해서 깜빡이게 보이게 한다.
    }
}