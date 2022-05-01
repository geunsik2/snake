#include "a.h"

int overlap(int savedKey, int key) {    // snake의 방향을 좌->우, 우->좌, 상->하, 하->상 으로 전환 시 1을 리턴한다.
    if (savedKey == UP && key == DOWN)  // savedKey의 값이 72(↑)이고 key의 값이 80(↓)인 경우
        return TRUE;
    if (savedKey == DOWN && key == UP)  // savedKey의 값이 80(↓)이고 key의 값이 72(↑)인 경우
        return TRUE;
    if (savedKey == LEFT && key == RIGHT)   // savedKey의 값이 75(←)이고 key의 값이 77(→)인 경우
        return TRUE;
    if (savedKey == RIGHT && key == LEFT)   // savedKey의 값이 77(→)이고 key의 값이 75(←)인 경우
        return TRUE;

    return FALSE;
}