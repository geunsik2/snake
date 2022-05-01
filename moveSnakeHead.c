#include "a.h"

//get snake x, y and move snake
int moveSnakeHead(MData map[MAP_SIZE][MAP_SIZE], SnakePos* snake, int way) {    // snake를 움직이고 충돌 여부를 검사한다.
    removeSnake(map, snake->x, snake->y); // 커서를 (snake->x, snake->y) 좌표로 이동해서 공백을 출력하고 
                                          // map[snake_x][snake_y]에 0을 대입한다.
    if (colWithWall(map, snake, way) == TRUE) { // colWithWall의 리턴값이 1인 경우
        gotoxy(1, 1);   // 커서를 (1, 1) 좌표로 이동한다.
        printf("> Hit : wall");
        return COLLISION;   // 10을 리턴한다.
    }
    if (colWithTail(map, snake, way) == TRUE) { // colWithTail의 리턴값이 1인 경우
        gotoxy(1, 1);   // 커서를 (1, 1) 좌표로 이동한다.
        printf("> Hit : tail");
        return COLLISION;   // 10을 리턴한다.
    }

    if (way == UP) {    // way가 72(↑)인 경우
        if (snake->y - 1 == -1) {       // snake의 y좌표가 0인 경우
            snake->y = MAP_SIZE - 1;    // snake의 y좌표에 21을 대입한다.
        }
        else {
            --(snake->y);   // snake의 y좌표를 1 감소한다.
        }
        setSnake(map, snake->x, (snake->y)); // 커서를 snake가 위치한 (x, y) 좌표로 이동해서 ●를 출력하고
                                             // map[snake_x][snake_y]에 2를 대입.
        return UP;  // 72를 리턴한다.
    }
    if (way == DOWN) {  // way가 80(↓)인 경우
        if (snake->y + 1 == MAP_SIZE) { // snake의 y좌표가 21인 경우
            snake->y = 0;   // snake의 y좌표에 0을 대입한다.
        }
        else {
            ++(snake->y);   // snake의 y좌표를 1 증가한다.
        }
        setSnake(map, snake->x, (snake->y));    // 커서를 snake가 위치한 (x, y) 좌표로 이동해서 ●를 출력하고
                                                // map[snake_x][snake_y]에 2를 대입.
        return DOWN;    // 80을 리턴한다.
    }
    if (way == LEFT) {  // way가 75(←)인 경우
        if (snake->x - 1 == -1) {       // snake의 x좌표가 0인 경우
            snake->x = MAP_SIZE - 1;    // snake의 x좌표에 21을 대입한다.
        }
        else {
            --(snake->x);   // snake의 x좌표를 1 감소한다. 
        }
        setSnake(map, (snake->x), snake->y);    // 커서를 snake가 위치한 (x, y) 좌표로 이동해서 ●를 출력하고
                                                // map[snake_x][snake_y]에 2를 대입.
        return LEFT;    // 75를 리턴한다.
    }
    if (way == RIGHT) { // way가 77(→)인 경우
        if (snake->x + 1 == MAP_SIZE) { // snake의 x좌표가 21인 경우
            snake->x = 0;   // snake의 x좌표에 0을 대입한다.
        }
        else {
            ++(snake->x);   // snake의 x좌표를 1 증가한다.
        }
        setSnake(map, snake->x, snake->y);  // 커서를 snake가 위치한 (x, y) 좌표로 이동해서 ●를 출력하고
                                            // map[snake_x][snake_y]에 2를 대입.
        return RIGHT;   // 77을 리턴한다.
    }
    return way; // way를 리턴한다.
}