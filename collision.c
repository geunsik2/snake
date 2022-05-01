#include "a.h"

int isCollision(int state) {    // 충돌 여부 검사.
    if (state == COLLISION) return TRUE;    // state가 10인 경우 1을 리턴한다.
    return FALSE;
}

int colWithFruit(SnakePos* sp, FruitPos* fp) {  // snake가 Fruit와 충돌한 상황 설정.
    if ((sp->x == fp->x && sp->y == fp->y)) {   // snake의 (x,y) 좌표와 fruit의 (x,y) 좌표가 같은 경우
        return TRUE;    // 1을 리턴한다.
    }
    return FALSE;   // 0을 리턴한다.
}

int colWithWall(MData map[MAP_SIZE][MAP_SIZE], SnakePos* sp, int way) { // snake가 Wall과 충돌한 상황 설정.
    if (way == UP) {    // way가 72인 경우
        if (map[sp->x][rotate(sp->y, way)] == WALL) // map[snake_x][rotate(sp->y, way)]의 값이 1인 경우
            return TRUE;    // 1을 리턴한다.
    }
    if (way == DOWN) {  // way가 80인 경우
        if (map[sp->x][rotate(sp->y, way)] == WALL) // map[snake_x][rotate(sp->y, way)]의 값이 1인 경우
            return TRUE;    // 1을 리턴한다.
    }
    if (way == LEFT) {  // way가 75인 경우
        if (map[rotate(sp->x, way)][sp->y] == WALL) // map[rotate(sp->x, way)][snake_y]의 값이 1인 경우
            return TRUE;    // 1을 리턴한다.
    }
    if (way == RIGHT) { // way가 77인 경우
        if (map[rotate(sp->x, way)][sp->y] == WALL) // map[rotate(sp->x, way)][snake_y]의 값이 1인 경우
            return TRUE;    // 1을 리턴한다.
    }
    return FALSE;   // 0을 리턴한다.
}

int colWithTail(MData map[MAP_SIZE][MAP_SIZE], SnakePos* sp, int way) { // snake가 Tail과 충돌한 상황 설정.
    if (way == UP) {    // way가 72인 경우
        if (map[sp->x][rotate(sp->y, way)] == TAIL) // map[snake_x][rotate(sp->y, way)]의 값이 3인 경우
            return TRUE;    // 1을 리턴한다.
    }
    if (way == DOWN) {  // way가 80인 경우
        if (map[sp->x][rotate(sp->y, way)] == TAIL)  // map[snake_x][rotate(sp->y, way)]의 값이 3인 경우
            return TRUE;    // 1을 리턴한다.
    }
    if (way == LEFT) {  // way가 75인 경우
        if (map[rotate(sp->x, way)][sp->y] == TAIL)  // map[rotate(sp->x, way)][snake_y]의 값이 3인 경우
            return TRUE;    // 1을 리턴한다.
    }
    if (way == RIGHT) { // way가 77인 경우
        if (map[rotate(sp->x, way)][sp->y] == TAIL)  // map[rotate(sp->x, way)][snake_y]의 값이 3인 경우
            return TRUE;    // 1을 리턴한다.
    }
    return FALSE;   // 0을 리턴한다.
}