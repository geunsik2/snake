#include "a.h"

//move cursor
void gotoxy(int x, int y) {     // 콘솔에서의 커서를 이동하는 함수.
    COORD Pos;
    Pos.X = 2 * x;      // 모든 알파벳의 크기가 0.5 * 1이므로 x에 2를 곱해준다.
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); // 콘솔의 출력 핸들을 주고, 
                                                                    // 위치를 정해주면 커서 이동.
}

// GetStdHandle(STD_OUTPUT_HANDLE) -> 표준콘솔출력의 핸들을 반환.