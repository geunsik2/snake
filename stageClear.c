#include "a.h"

void stageClear(MData map[MAP_SIZE][MAP_SIZE]) {    // 22행 22열 크기를 가지는 2차원 배열(map)을 0으로 초기화.
    int i, j;
    for (i = 0; i <= MAP_SIZE; i++) {
        for (j = 0; i <= MAP_SIZE; j++) {
            map[i][j] = EMPTY;  // 배열의 모든 값을 0으로 초기화한다.
        }
    }
}