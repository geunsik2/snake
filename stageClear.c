#include "a.h"

void stageClear(MData map[MAP_SIZE][MAP_SIZE]) {    // 22�� 22�� ũ�⸦ ������ 2���� �迭(map)�� 0���� �ʱ�ȭ.
    int i, j;
    for (i = 0; i <= MAP_SIZE; i++) {
        for (j = 0; i <= MAP_SIZE; j++) {
            map[i][j] = EMPTY;  // �迭�� ��� ���� 0���� �ʱ�ȭ�Ѵ�.
        }
    }
}