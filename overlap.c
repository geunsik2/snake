#include "a.h"

int overlap(int savedKey, int key) {    // snake�� ������ ��->��, ��->��, ��->��, ��->�� ���� ��ȯ �� 1�� �����Ѵ�.
    if (savedKey == UP && key == DOWN)  // savedKey�� ���� 72(��)�̰� key�� ���� 80(��)�� ���
        return TRUE;
    if (savedKey == DOWN && key == UP)  // savedKey�� ���� 80(��)�̰� key�� ���� 72(��)�� ���
        return TRUE;
    if (savedKey == LEFT && key == RIGHT)   // savedKey�� ���� 75(��)�̰� key�� ���� 77(��)�� ���
        return TRUE;
    if (savedKey == RIGHT && key == LEFT)   // savedKey�� ���� 77(��)�̰� key�� ���� 75(��)�� ���
        return TRUE;

    return FALSE;
}