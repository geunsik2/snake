#include "a.h"

void hidecursor(void) {     // �ܼ�â�� Ŀ���� ����� �Լ�.
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // ǥ���ܼ������ �ڵ��� ��ȯ.
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;          // Ŀ���� ũ�� --> 100
    info.bVisible = FALSE;      // Ŀ���� ǥ�� �� �ϰڴٴ� �ǹ�.
    SetConsoleCursorInfo(consoleHandle, &info);
}

// GetStdHandle(STD_OUTPUT_HANDLE) -> ǥ���ܼ������ �ڵ��� ��ȯ.