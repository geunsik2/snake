#include "a.h"

int drawSpeedMenu(int* scoreArr) {  //show stage Menu and score;
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);  // ǥ���ܼ������ �ڵ��� ��ȯ.

    int i;
    FILE* rfp, * wfp;
    rfp = fopen("score.txt", "r");  // score.txt ������ �б� �������� ����.
    SetConsoleTextAttribute(hand, 11);
    gotoxy(DEFAULT_X, DEFAULT_Y);
    printf("============================================");
    SetConsoleTextAttribute(hand, 14);
    gotoxy(DEFAULT_X, DEFAULT_Y + 1);
    printf("================ BEST SCORE ================");
    SetConsoleTextAttribute(hand, 13);
    gotoxy(DEFAULT_X, DEFAULT_Y + 2);
    printf("============================================");
    SetConsoleTextAttribute(hand, 15);
    if (rfp == NULL) {
        wfp = fopen("score.txt", "w"); // score.txt ������ ���� �������� ����.
        fprintf(wfp, "%d %d %d %d", scoreArr[0], scoreArr[1], scoreArr[2], scoreArr[3]);
        // scoreArr[0]���� scoreArr[3]���� ���� ����� ���� score.txt ���Ͽ� �ۼ��Ѵ�.
        for (i = 0; i < 4; i++) {
            gotoxy(DEFAULT_X, DEFAULT_Y + (i + 4)); // Ŀ���� (0, 4)���� (0, 7)���� �̵��Ѵ�.
            printf(" Stage [%d] : %d", i + 1, scoreArr[i]); // stage �� ������ �ֿܼ� ����Ѵ�.
        }
        fclose(wfp);    // ���� ���� score.txt ������ �ݴ´�.
    }
    fscanf(rfp, "%d %d %d %d", &scoreArr[0], &scoreArr[1], &scoreArr[2], &scoreArr[3]);
    // score.txt ������ �о scoreArr[0]���� scoreArr[3]���� ���� �Է��Ѵ�.
    for (i = 0; i < 4; i++) {
        gotoxy(DEFAULT_X, DEFAULT_Y + (i + 4)); // Ŀ���� (0, 4)���� (0, 7)���� �̵��Ѵ�.
        printf(" Stage [%d] : %d", i + 1, scoreArr[i]); // stage �� ������ �ֿܼ� ����Ѵ�.
    }

    fclose(rfp);    // score.txt ������ �ݴ´�.

    while (1) {
        int keyDown = getKeyDown();
        if (keyDown == '1') {   // ����ڷκ��� 1�� �Է¹����� 1�� �����Ѵ�.
            SetConsoleTextAttribute(hand, 7);   // �ֿܼ����� ���ڻ��� ���� ���(7)���� �����Ѵ�.
            return 1;
        }
        if (keyDown == '2') {   // ����ڷκ��� 2�� �Է¹����� 2�� �����Ѵ�.
            SetConsoleTextAttribute(hand, 7);
            return 2;
        }
        if (keyDown == '3') {   // ����ڷκ��� 3�� �Է¹����� 3�� �����Ѵ�.
            SetConsoleTextAttribute(hand, 7);
            return 3;
        }
        if (keyDown == '4') {   // ����ڷκ��� 4�� �Է¹����� 4�� �����Ѵ�.
            SetConsoleTextAttribute(hand, 7);
            return 4;
        }
        SetConsoleTextAttribute(hand, 14);  // �ֿܼ����� ���ڻ��� �����(14)���� �����Ѵ�.
        gotoxy(DEFAULT_X, DEFAULT_Y + 9);   // Ŀ���� (0, 9) ��ǥ�� �̵�.
        printf(">> Choose Stage : 1, 2, 3, 4");
        Sleep(1000 / 3);    // 0.3�ʸ��� ����ؼ� �����̰� ���̰� �Ѵ�.
        gotoxy(DEFAULT_X, DEFAULT_Y + 9);
        printf(">>                          ");
        Sleep(1000 / 3);    // 0.3�ʸ��� ����ؼ� �����̰� ���̰� �Ѵ�.
    }
}
