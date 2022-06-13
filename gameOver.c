#include "a.h"

void GameOver(int score, int best, Queue* pq, int stage, int* scoreArr) {   // GameOver ����. �ְ� ������ �����ϰ� ������ �ۼ��ϸ�,
                                                                            // ���� ������ ����Ѵ�.

    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);  // ǥ���ܼ������ �ڵ��� ��ȯ.
    if (score >= best) {    // ���� ������ �ְ� �������� ũ�ų� ���� ���
        scoreArr[stage - 1] = score;    // scoreArr[stage - 1]�� ���� ������ �����Ѵ�.
    }
    else {  // ���� ������ �ְ� �������� ���� ���
        scoreArr[stage - 1] = best; // scoreArr[stage - 1]�� �ְ� ������ �����Ѵ�.
    }
    ranking_db(score, best, stage, scoreArr);   // ���ӿ��� �� �ش� ������ �������� �� ������ DB�� �Է��Ѵ�.
    SetConsoleTextAttribute(hand, 14);  // �ֿܼ����� ���ڻ��� ���� �����(14)���� �����Ѵ�.
    gotoxy(MAP_SIZE / 2 - 4, MAP_SIZE / 2 - 5); // Ŀ���� (7,6) ��ǥ�� �̵�.
    printf("===<GAME OVER>===\n");
    gotoxy(MAP_SIZE / 2 - 3, MAP_SIZE / 2 - 3); // Ŀ���� (8,8) ��ǥ�� �̵�.
    printf("Your Score : %d\n", score); // ���� ���� ���.
    gotoxy(DEFAULT_X + 8, MAP_SIZE + 5);    // Ŀ���� (8,27) ��ǥ�� �̵�.
    printf("\n");
    SetConsoleTextAttribute(hand, 7);   // �ֿܼ����� ���ڻ��� ���� ���(7)���� �����Ѵ�.

    while (!isEmpty(pq)) {  // isEmpty(pq)�� ���ϰ��� 0�̸� ���ѷ���
                            // 1�̸� �ݺ����� �������� �ʴ´�.
        Dequeue(pq);
    }
}