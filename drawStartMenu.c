#include "a.h"


int drawStartMenu(void) {   // show start menu. ����ȭ��. 
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);  // ǥ���ܼ������ �ڵ��� ��ȯ.
    SetConsoleTextAttribute(hand, 13);  // �ֿܼ����� ���ڻ��� ��ȫ��(13)���� �����Ѵ�.
    gotoxy(DEFAULT_X, DEFAULT_Y);       // Ŀ���� (0, 0) ��ǥ�� �̵�.
    printf("============================================");
    SetConsoleTextAttribute(hand, 14);  // �ֿܼ����� ���ڻ��� �����(14)���� �����Ѵ�.
    printf("================ Snake Game ================");
    SetConsoleTextAttribute(hand, 11);  // �ֿܼ����� ���ڻ��� �ϴû�(11)���� �����Ѵ�.
    printf("============================================");
    SetConsoleTextAttribute(hand, 15);  // �ֿܼ����� ���ڻ��� £�� �Ͼ��(15)���� �����Ѵ�.
    gotoxy(DEFAULT_X, DEFAULT_Y + 4);   // Ŀ���� (0, 4) ��ǥ�� �̵�.
    printf("> Key  : up, down, left, right,");
    gotoxy(DEFAULT_X, DEFAULT_Y + 5);   // Ŀ���� (0, 5) ��ǥ�� �̵�.
    printf("> Exit : 't'");

    gotoxy(DEFAULT_X + 11, DEFAULT_Y + 14);     // Ŀ���� (11, 14) ��ǥ�� �̵�.
    printf("<Made by BlockDMask.>");
    gotoxy(DEFAULT_X + 11, DEFAULT_Y + 15);     // Ŀ���� (11, 15) ��ǥ�� �̵�.
    printf("<BlockDMask@gmail.com>");


    SetConsoleTextAttribute(hand, 14);     // �ֿܼ����� ���ڻ��� �����(14)���� �����Ѵ�. 
    while (1) {
        int keyDown = getKeyDown();
        if (keyDown == 's' || keyDown == 'S') { // s�� S�� �ԷµǸ� �ֿܼ����� ���ڻ��� ���� ���(7)����
                                                // ���� �� TRUE�� ����.
            SetConsoleTextAttribute(hand, 7);
            return TRUE;
        }
        if (keyDown == 't' || keyDown == 'T') { // t�� T�� �ԷµǸ� �ֿܼ����� ���ڻ��� ���� ���(7)����
                                                // ���� �� FALSE�� ����.
            SetConsoleTextAttribute(hand, 7);
            return FALSE;
        }
        gotoxy(DEFAULT_X + 5, DEFAULT_Y + 9);   // Ŀ���� (5, 9) ��ǥ�� �̵�.
        printf("-- press 's' to start --");
        Sleep(1000 / 3);    // 0.3�ʸ��� ����ؼ� �����̰� ���̰� �Ѵ�.
        gotoxy(DEFAULT_X + 5, DEFAULT_Y + 9);   // Ŀ���� (5, 9) ��ǥ�� �̵�.
        printf("                         ");
        Sleep(1000 / 3);    // 0.3�ʸ��� ����ؼ� �����̰� ���̰� �Ѵ�.
    }
}