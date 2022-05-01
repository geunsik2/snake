#include "a.h"

int isCollision(int state) {    // �浹 ���� �˻�.
    if (state == COLLISION) return TRUE;    // state�� 10�� ��� 1�� �����Ѵ�.
    return FALSE;
}

int colWithFruit(SnakePos* sp, FruitPos* fp) {  // snake�� Fruit�� �浹�� ��Ȳ ����.
    if ((sp->x == fp->x && sp->y == fp->y)) {   // snake�� (x,y) ��ǥ�� fruit�� (x,y) ��ǥ�� ���� ���
        return TRUE;    // 1�� �����Ѵ�.
    }
    return FALSE;   // 0�� �����Ѵ�.
}

int colWithWall(MData map[MAP_SIZE][MAP_SIZE], SnakePos* sp, int way) { // snake�� Wall�� �浹�� ��Ȳ ����.
    if (way == UP) {    // way�� 72�� ���
        if (map[sp->x][rotate(sp->y, way)] == WALL) // map[snake_x][rotate(sp->y, way)]�� ���� 1�� ���
            return TRUE;    // 1�� �����Ѵ�.
    }
    if (way == DOWN) {  // way�� 80�� ���
        if (map[sp->x][rotate(sp->y, way)] == WALL) // map[snake_x][rotate(sp->y, way)]�� ���� 1�� ���
            return TRUE;    // 1�� �����Ѵ�.
    }
    if (way == LEFT) {  // way�� 75�� ���
        if (map[rotate(sp->x, way)][sp->y] == WALL) // map[rotate(sp->x, way)][snake_y]�� ���� 1�� ���
            return TRUE;    // 1�� �����Ѵ�.
    }
    if (way == RIGHT) { // way�� 77�� ���
        if (map[rotate(sp->x, way)][sp->y] == WALL) // map[rotate(sp->x, way)][snake_y]�� ���� 1�� ���
            return TRUE;    // 1�� �����Ѵ�.
    }
    return FALSE;   // 0�� �����Ѵ�.
}

int colWithTail(MData map[MAP_SIZE][MAP_SIZE], SnakePos* sp, int way) { // snake�� Tail�� �浹�� ��Ȳ ����.
    if (way == UP) {    // way�� 72�� ���
        if (map[sp->x][rotate(sp->y, way)] == TAIL) // map[snake_x][rotate(sp->y, way)]�� ���� 3�� ���
            return TRUE;    // 1�� �����Ѵ�.
    }
    if (way == DOWN) {  // way�� 80�� ���
        if (map[sp->x][rotate(sp->y, way)] == TAIL)  // map[snake_x][rotate(sp->y, way)]�� ���� 3�� ���
            return TRUE;    // 1�� �����Ѵ�.
    }
    if (way == LEFT) {  // way�� 75�� ���
        if (map[rotate(sp->x, way)][sp->y] == TAIL)  // map[rotate(sp->x, way)][snake_y]�� ���� 3�� ���
            return TRUE;    // 1�� �����Ѵ�.
    }
    if (way == RIGHT) { // way�� 77�� ���
        if (map[rotate(sp->x, way)][sp->y] == TAIL)  // map[rotate(sp->x, way)][snake_y]�� ���� 3�� ���
            return TRUE;    // 1�� �����Ѵ�.
    }
    return FALSE;   // 0�� �����Ѵ�.
}