#include "a.h"

void removeSnake(MData map[MAP_SIZE][MAP_SIZE], int snake_x, int snake_y) { // snake�� ��ġ�� ��ǥ�� ������ ����Ѵ�.
    gotoxy(snake_x, snake_y);   // Ŀ���� snake�� (x, y) ��ǥ�� �̵�.
    printf("  ");
    map[snake_x][snake_y] = EMPTY;  // map[snake_x][snake_y]�� 0�� ����.
}