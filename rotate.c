#include "a.h"

int rotate(int xy, int way) {   // rotate 함수가 무슨 기능을 하는지 한마디로 정의하기?
    if (way == UP || way == LEFT) { // way가 72(↑)이거나 75(←)인 경우
        if (xy - 1 == -1) { // xy -1이 -1인 경우
            xy = MAP_SIZE - 1; // xy에 21을 대입한다.
        }
        else {
            --(xy); // xy를 1 감소한다.
        }
        return xy;
    }
    if (way == DOWN || way == RIGHT) {  // way가 80(↓)이거나 77(→)인 경우
        if (xy + 1 == MAP_SIZE) {   // xy + 1이 22인 경우
            xy = 0; // xy에 0을 대입한다.
        }
        else {
            ++xy;   // xy를 1 증가한다.
        }
        return xy;
    }
    return FALSE;   // 0을 리턴한다.
}