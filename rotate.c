#include "a.h"

int rotate(int xy, int way) {   // rotate �Լ��� ���� ����� �ϴ��� �Ѹ���� �����ϱ�?
    if (way == UP || way == LEFT) { // way�� 72(��)�̰ų� 75(��)�� ���
        if (xy - 1 == -1) { // xy -1�� -1�� ���
            xy = MAP_SIZE - 1; // xy�� 21�� �����Ѵ�.
        }
        else {
            --(xy); // xy�� 1 �����Ѵ�.
        }
        return xy;
    }
    if (way == DOWN || way == RIGHT) {  // way�� 80(��)�̰ų� 77(��)�� ���
        if (xy + 1 == MAP_SIZE) {   // xy + 1�� 22�� ���
            xy = 0; // xy�� 0�� �����Ѵ�.
        }
        else {
            ++xy;   // xy�� 1 �����Ѵ�.
        }
        return xy;
    }
    return FALSE;   // 0�� �����Ѵ�.
}