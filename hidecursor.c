#include "a.h"

void hidecursor(void) {     // 콘솔창의 커서를 숨기는 함수.
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // 표준콘솔출력의 핸들을 반환.
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;          // 커서의 크기 --> 100
    info.bVisible = FALSE;      // 커서를 표시 안 하겠다는 의미.
    SetConsoleCursorInfo(consoleHandle, &info);
}

// GetStdHandle(STD_OUTPUT_HANDLE) -> 표준콘솔출력의 핸들을 반환.