#include "a.h"

//draw game map
void drawMainMap(MData map[MAP_SIZE][MAP_SIZE]) {   // 1�� �ʱ�ȭ�� ��ǥ�� �ฦ ����ϰ� 0���� �ʱ�ȭ�� ��ǥ�� ������ ����Ѵ�.
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);  // ǥ���ܼ������ �ڵ��� ��ȯ.
    SetConsoleTextAttribute(hand, 15);  // �ֿܼ����� ���ڻ��� ���� ���(15)���� �����Ѵ�.

    int i, j;
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            if (map[i][j] == WALL) {    // i�� j�� ���� 1�� ���, Ŀ���� �ش� ��ǥ�� �̵��� �� �� ���.
                gotoxy(i, j);
                printf("��");
            }
            else if (map[i][j] == EMPTY) {  // i�� j�� ���� 0�� ���, Ŀ���� �ش� ��ǥ�� �̵��� �� ���� ���.
                gotoxy(i, j);
                printf(" ");
            }
        }
    }
    SetConsoleTextAttribute(hand, 7);   // �ֿܼ����� ���ڻ��� ���� ���(7)���� �����Ѵ�.
}

void drawSubMap(int score, int best, int stage) {   // ���� �����ϸ� �ش� ���� ���� �� ������ ����Ѵ�.
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);  // ǥ���ܼ������ �ڵ��� ��ȯ.
    SetConsoleTextAttribute(hand, 15);  // �ֿܼ����� ���ڻ��� ���� ���(15)���� �����Ѵ�.

    gotoxy(DEFAULT_X, MAP_SIZE + 1);    // Ŀ���� (0, 23) ��ǥ�� �̵�.
    printf(" Stage[%d] Best Score : %4d", stage, best); // ������ ���� �ְ� ���� ���.
    gotoxy(DEFAULT_X, MAP_SIZE + 2);    // Ŀ���� (0, 24) ��ǥ�� �̵�.
    printf(" Stage[%d] Your Score : %4d", stage, score);    // ������ ���� ���� ���� ���.
    gotoxy(DEFAULT_X + 8, MAP_SIZE + 5);    // Ŀ���� (8, 27) ��ǥ�� �̵�.
    printf("[Exit - 't' / Pause - 'p']\n"); // �� ������ �� �Ͻ����� ���� ���.
    SetConsoleTextAttribute(hand, 7);   // �ֿܼ����� ���ڻ��� ���� ���(7)���� �����Ѵ�.
}