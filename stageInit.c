#include "a.h"

//////////////////////////////////////STAGE MAP SETTING////////////////////////////////
void stageClear(MData map[MAP_SIZE][MAP_SIZE]) {    // 22�� 22�� ũ�⸦ ������ 2���� �迭(map)�� 0���� �ʱ�ȭ.
    int i, j;
    for (i = 0; i <= MAP_SIZE; i++) {
        for (j = 0; i <= MAP_SIZE; j++) {
            map[i][j] = EMPTY;  // �迭�� ��� ���� 0���� �ʱ�ȭ�Ѵ�.
        }
    }
}

void stageOneInit(MData map[MAP_SIZE][MAP_SIZE]) {  // ù ��° �� -> ���� �𼭸��� 1�� �ʱ�ȭ.
    int i, j;
    for (i = 0; i < MAP_SIZE; i++) {
        if (i == 0 || i == MAP_SIZE - 1) {  // i�� 0 �Ǵ� 21�� ���. ��, ù ��° ���� ������ ���� 1�� �ʱ�ȭ�Ѵ�.
            for (j = 0; j < MAP_SIZE; j++) {
                map[i][j] = WALL;
            }
        }
        else {  // i�� 1 ~ 20�� ���
            for (j = 0; j < MAP_SIZE; j++) {
                if (j == 0 || j == MAP_SIZE - 1)    // j�� 0 �Ǵ� 21�� ���. ��, ù ��° ��� ������ ���� 1�� �ʱ�ȭ�Ѵ�.
                    map[i][j] = WALL;
                else    // j�� 1 ~ 20�� ���. ��, �� ��° ����� 21 ����� 0���� �ʱ�ȭ�Ѵ�.
                    map[i][j] = EMPTY;
            }
        }

    }
}

void stageTwoInit(MData map[MAP_SIZE][MAP_SIZE]) {  // �� ��° �� -> ù ��° ��, ������ ��, 12��° ���� 1�� �ʱ�ȭ.
    int i, j;
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            if (i == (int)MAP_SIZE / 2 || j == 0 || j == MAP_SIZE - 1) { // i�� 11�̰ų� j�� 0 �Ǵ� 21�� ���.
                                                                         // ��, ù ��° ��, ��������, 12��° ���� 1�� �ʱ�ȭ�Ѵ�.
                map[i][j] = WALL;
            }
            else {  // ������ ��� 0���� �ʱ�ȭ�Ѵ�.
                map[i][j] = EMPTY;
            }
        }

    }
}

void stageThreeInit(MData map[MAP_SIZE][MAP_SIZE]) {    // �� ��° �� -> �� �߾ӿ� � ������� 1�� �����Ѵ�.
    int i, j;
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            if (i == MAP_SIZE / 2 || j == MAP_SIZE / 2) {   // i�� 11�̰ų� j�� 11�� ���.
                                                            // ��, 12��° ��� 12��° ���� 1�� �ʱ�ȭ�Ѵ�.
                map[i][j] = WALL;
            }
            else {  // ������ ��� 0���� �ʱ�ȭ�Ѵ�.
                map[i][j] = EMPTY;
            }
        }
    }
}

void stageFourinit(MData map[MAP_SIZE][MAP_SIZE]) { // �� ��° �������� -> �߾��� �ո� X ������� 1�� �����Ѵ�.
    int i, j;
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            if (i == j || i + j == MAP_SIZE - 1) {  // i�� j�� ���ų� i�� j�� ���� ���� 21�� ���
                                                    // (0,0), (0,21), (1,1), (1,20), ... (21,21), (21,0)
                if (i == MAP_SIZE / 2 - 1 || i == MAP_SIZE / 2) // i�� 10�̰ų� 11�� ��� 0���� �ʱ�ȭ�Ѵ�.
                                                                // (10,10), (10,11), (11,11), (11,10)
                    map[i][j] = EMPTY;
                else    // (10,10), (10,11), (11,11), (11,10)�� ������ ������ ��� 1�� �ʱ�ȭ. 
                    map[i][j] = WALL;

            }
            else {  // ������ ��� 0���� �ʱ�ȭ�Ѵ�.
                map[i][j] = EMPTY;
            }
        }
    }
}