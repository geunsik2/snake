#include "a.h"

void setSnake(MData map[MAP_SIZE][MAP_SIZE], int snake_x, int snake_y) {    // �� �Ӹ� ���.
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);  // ǥ���ܼ������ �ڵ��� ��ȯ.
    gotoxy(snake_x, snake_y);   // Ŀ���� snake�� ��ġ�� (x, y) ��ǥ�� �̵�.
    SetConsoleTextAttribute(hand, 14);  // �ֿܼ����� ���ڻ��� ���� �����(14)���� �����Ѵ�.
    printf("��");
    SetConsoleTextAttribute(hand, 7);   // �ֿܼ����� ���ڻ��� ���� ���(7)���� �����Ѵ�.
    map[snake_x][snake_y] = HEAD;   // map[snake_x][snake_y]�� 2�� ����.
}

void setSnakeTail(MData map[MAP_SIZE][MAP_SIZE], int snake_x, int snake_y) {    // �� ���� ���.
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);  // ǥ���ܼ������ �ڵ��� ��ȯ.
    SetConsoleTextAttribute(hand, 14);  // �ֿܼ����� ���ڻ��� ���� �����(14)���� �����Ѵ�.
    gotoxy(snake_x, snake_y);   // Ŀ���� snake�� ��ġ�� (x, y) ��ǥ�� �̵�.
    printf("��");
    map[snake_x][snake_y] = TAIL;   // map[snake_x][snake_y]�� 3�� ����.
    SetConsoleTextAttribute(hand, 7);   // �ֿܼ����� ���ڻ��� ���� ���(7)���� �����Ѵ�.
}