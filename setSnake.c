#include "a.h"

void setSnake(MData map[MAP_SIZE][MAP_SIZE], int snake_x, int snake_y) {    // 뱀 머리 출력.
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);  // 표준콘솔출력의 핸들을 반환.
    gotoxy(snake_x, snake_y);   // 커서를 snake가 위치한 (x, y) 좌표로 이동.
    SetConsoleTextAttribute(hand, 14);  // 콘솔에서의 글자색을 진한 노란색(14)으로 변경한다.
    printf("●");
    SetConsoleTextAttribute(hand, 7);   // 콘솔에서의 글자색을 연한 흰색(7)으로 변경한다.
    map[snake_x][snake_y] = HEAD;   // map[snake_x][snake_y]에 2를 대입.
}

void setSnakeTail(MData map[MAP_SIZE][MAP_SIZE], int snake_x, int snake_y) {    // 뱀 꼬리 출력.
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);  // 표준콘솔출력의 핸들을 반환.
    SetConsoleTextAttribute(hand, 14);  // 콘솔에서의 글자색을 진한 노란색(14)으로 변경한다.
    gotoxy(snake_x, snake_y);   // 커서를 snake가 위치한 (x, y) 좌표로 이동.
    printf("ㆁ");
    map[snake_x][snake_y] = TAIL;   // map[snake_x][snake_y]에 3을 대입.
    SetConsoleTextAttribute(hand, 7);   // 콘솔에서의 글자색을 연한 흰색(7)으로 변경한다.
}