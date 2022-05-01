#include "a.h"

void removeSnake(MData map[MAP_SIZE][MAP_SIZE], int snake_x, int snake_y) { // snake가 위치한 좌표에 공백을 출력한다.
    gotoxy(snake_x, snake_y);   // 커서를 snake의 (x, y) 좌표로 이동.
    printf("  ");
    map[snake_x][snake_y] = EMPTY;  // map[snake_x][snake_y]에 0을 대입.
}