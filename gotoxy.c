#include "a.h"

//move cursor
void gotoxy(int x, int y) {     // �ֿܼ����� Ŀ���� �̵��ϴ� �Լ�.
    COORD Pos;
    Pos.X = 2 * x;      // ��� ���ĺ��� ũ�Ⱑ 0.5 * 1�̹Ƿ� x�� 2�� �����ش�.
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); // �ܼ��� ��� �ڵ��� �ְ�, 
                                                                    // ��ġ�� �����ָ� Ŀ�� �̵�.
}

// GetStdHandle(STD_OUTPUT_HANDLE) -> ǥ���ܼ������ �ڵ��� ��ȯ.