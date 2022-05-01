#include "a.h"

int setFruit(MData map[MAP_SIZE][MAP_SIZE], FruitPos* fp) { // Fruit ���� ��ġ �� ��� ����
    HANDLE  hand = GetStdHandle(STD_OUTPUT_HANDLE); // ǥ���ܼ������ �ڵ��� ��ȯ.
    int i, j;
    srand((unsigned int)time(NULL));    // ���� �߻� �ʱ�ȭ.
    while (1) {
        i = rand() % (MAP_SIZE - 2) + 1;    // i�� 0 ~ 20 ������ � ���� �����Ѵ�.
        j = rand() % (MAP_SIZE - 2) + 1;    // j�� 0 ~ 20 ������ � ���� �����Ѵ�.
        if (map[i][j] == EMPTY) {   // ���� (i,j) ��ǥ�� 0�� ���
            map[i][j] = FRUIT;  // �ش� ��ǥ�� FRUIT(5)�� �ʱ�ȭ�Ѵ�.
            fp->x = i;  // ����ü ������ FruitPos�� ������� x�� ����. ��, x�� i���� ����.
            fp->y = j;  // ����ü ������ FruitPos�� ������� y�� ����. ��, y�� j���� ����.
            (fp->numOfFruit)++; // numOfFruit�� 1�� ������Ų��.
            SetConsoleTextAttribute(hand, 10);  // �ֿܼ����� ���ڻ��� ���� ���λ�(10)���� �����Ѵ�.
            gotoxy(i, j);   // �ش� ��ǥ�� Ŀ���� �̵��Ѵ�.
            printf("��");
            SetConsoleTextAttribute(hand, 7);   // �ֿܼ����� ���ڻ��� ���� ���(7)���� �����Ѵ�.

            return 1;
        }
    }
}

int setBonusFruit(MData map[MAP_SIZE][MAP_SIZE], FruitPos* fp) {    // Fruit �߰� ���� �Լ� (���� �ϰ� ȣ���� ���� ����.)
    int i, j, numOfFruit = 0;
    for (i = 0; i < MAP_SIZE - 1; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            if (map[i][j] == EMPTY) {
                map[i][j] = FRUIT;
                numOfFruit++;
            }
        }
    }
    return numOfFruit;
}