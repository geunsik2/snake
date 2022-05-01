#include "a.h"

//////////////////////////////////////STAGE MAP SETTING////////////////////////////////
void stageClear(MData map[MAP_SIZE][MAP_SIZE]) {    // 22행 22열 크기를 가지는 2차원 배열(map)을 0으로 초기화.
    int i, j;
    for (i = 0; i <= MAP_SIZE; i++) {
        for (j = 0; i <= MAP_SIZE; j++) {
            map[i][j] = EMPTY;  // 배열의 모든 값을 0으로 초기화한다.
        }
    }
}

void stageOneInit(MData map[MAP_SIZE][MAP_SIZE]) {  // 첫 번째 맵 -> 맵의 모서리를 1로 초기화.
    int i, j;
    for (i = 0; i < MAP_SIZE; i++) {
        if (i == 0 || i == MAP_SIZE - 1) {  // i가 0 또는 21인 경우. 즉, 첫 번째 열과 마지막 열을 1로 초기화한다.
            for (j = 0; j < MAP_SIZE; j++) {
                map[i][j] = WALL;
            }
        }
        else {  // i가 1 ~ 20인 경우
            for (j = 0; j < MAP_SIZE; j++) {
                if (j == 0 || j == MAP_SIZE - 1)    // j가 0 또는 21인 경우. 즉, 첫 번째 행과 마지막 행을 1로 초기화한다.
                    map[i][j] = WALL;
                else    // j가 1 ~ 20인 경우. 즉, 두 번째 행부터 21 행까지 0으로 초기화한다.
                    map[i][j] = EMPTY;
            }
        }

    }
}

void stageTwoInit(MData map[MAP_SIZE][MAP_SIZE]) {  // 두 번째 맵 -> 첫 번째 행, 마지막 행, 12번째 열을 1로 초기화.
    int i, j;
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            if (i == (int)MAP_SIZE / 2 || j == 0 || j == MAP_SIZE - 1) { // i가 11이거나 j가 0 또는 21인 경우.
                                                                         // 즉, 첫 번째 행, 마지막행, 12번째 열을 1로 초기화한다.
                map[i][j] = WALL;
            }
            else {  // 나머지 경우 0으로 초기화한다.
                map[i][j] = EMPTY;
            }
        }

    }
}

void stageThreeInit(MData map[MAP_SIZE][MAP_SIZE]) {    // 세 번째 맵 -> 맵 중앙에 十 모양으로 1을 대입한다.
    int i, j;
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            if (i == MAP_SIZE / 2 || j == MAP_SIZE / 2) {   // i가 11이거나 j가 11인 경우.
                                                            // 즉, 12번째 행과 12번째 열을 1로 초기화한다.
                map[i][j] = WALL;
            }
            else {  // 나머지 경우 0으로 초기화한다.
                map[i][j] = EMPTY;
            }
        }
    }
}

void stageFourinit(MData map[MAP_SIZE][MAP_SIZE]) { // 네 번째 스테이지 -> 중앙이 뚫린 X 모양으로 1을 대입한다.
    int i, j;
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            if (i == j || i + j == MAP_SIZE - 1) {  // i와 j가 같거나 i와 j를 더한 값이 21인 경우
                                                    // (0,0), (0,21), (1,1), (1,20), ... (21,21), (21,0)
                if (i == MAP_SIZE / 2 - 1 || i == MAP_SIZE / 2) // i가 10이거나 11인 경우 0으로 초기화한다.
                                                                // (10,10), (10,11), (11,11), (11,10)
                    map[i][j] = EMPTY;
                else    // (10,10), (10,11), (11,11), (11,10)을 제외한 나머지 경우 1로 초기화. 
                    map[i][j] = WALL;

            }
            else {  // 나머지 경우 0으로 초기화한다.
                map[i][j] = EMPTY;
            }
        }
    }
}