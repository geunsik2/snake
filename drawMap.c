#include "a.h"

//draw game map
void drawMainMap(MData map[MAP_SIZE][MAP_SIZE]) {   // 1로 초기화된 좌표에 □를 출력하고 0으로 초기화된 좌표에 공백을 출력한다.
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);  // 표준콘솔출력의 핸들을 반환.
    SetConsoleTextAttribute(hand, 15);  // 콘솔에서의 글자색을 진한 흰색(15)으로 변경한다.

    int i, j;
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            if (map[i][j] == WALL) {    // i와 j의 값이 1인 경우, 커서를 해당 좌표로 이동한 후 □ 출력.
                gotoxy(i, j);
                printf("□");
            }
            else if (map[i][j] == EMPTY) {  // i와 j의 값이 0인 경우, 커서를 해당 좌표로 이동한 후 공백 출력.
                gotoxy(i, j);
                printf(" ");
            }
        }
    }
    SetConsoleTextAttribute(hand, 7);   // 콘솔에서의 글자색을 연한 흰색(7)으로 변경한다.
}

void drawSubMap(int score, int best, int stage) {   // 맵을 선택하면 해당 맵의 점수 및 도움말을 출력한다.
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);  // 표준콘솔출력의 핸들을 반환.
    SetConsoleTextAttribute(hand, 15);  // 콘솔에서의 글자색을 진한 흰색(15)으로 변경한다.

    gotoxy(DEFAULT_X, MAP_SIZE + 1);    // 커서를 (0, 23) 좌표로 이동.
    printf(" Stage[%d] Best Score : %4d", stage, best); // 선택한 맵의 최고 점수 출력.
    gotoxy(DEFAULT_X, MAP_SIZE + 2);    // 커서를 (0, 24) 좌표로 이동.
    printf(" Stage[%d] Your Score : %4d", stage, score);    // 선택한 맵의 현재 점수 출력.
    gotoxy(DEFAULT_X + 8, MAP_SIZE + 5);    // 커서를 (8, 27) 좌표로 이동.
    printf("[Exit - 't' / Pause - 'p']\n"); // 맵 나가기 및 일시정지 도움말 출력.
    SetConsoleTextAttribute(hand, 7);   // 콘솔에서의 글자색을 연한 흰색(7)으로 변경한다.
}