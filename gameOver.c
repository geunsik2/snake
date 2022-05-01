#include "a.h"

void GameOver(int score, int best, Queue* pq, int stage, int* scoreArr) {   // GameOver ����. �ְ� ������ �����ϰ� ������ �ۼ��ϸ�,
                                                                            // ���� ������ ����Ѵ�.
    FILE* wfp;
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);  // ǥ���ܼ������ �ڵ��� ��ȯ.
    if (score >= best) {    // ���� ������ �ְ� �������� ũ�ų� ���� ���
        scoreArr[stage - 1] = score;    // scoreArr[stage - 1]�� ���� ������ �����Ѵ�.
    }
    else {  // ���� ������ �ְ� �������� ���� ���
        scoreArr[stage - 1] = best; // scoreArr[stage - 1]�� �ְ� ������ �����Ѵ�.
    }
    wfp = fopen("score.txt", "w");  // score.txt ������ ���� �������� ����.
    fprintf(wfp, "%d %d %d %d", scoreArr[0], scoreArr[1], scoreArr[2], scoreArr[3]);
    // scoreArr[0]���� scoreArr[3]���� ���� ����� ���� score.txt ���Ͽ� �ۼ��Ѵ�.
    fclose(wfp);    // ���� ���� score.txt ������ �ݴ´�.
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