#include "a.h"

//keyboard input
int getKeyDown() {  // Ű���尡 �������� ��쿡�� _getch()�� ���� �Է��� �ް� �׷��� ���� ��� -1�� ����
    if (_kbhit()) return _getch();  // _kbhit() --> ���� Ű���尡 �Էµ� �������� ����.
                                    // _getch() --> Ű������ �Է��� ������, �Է��� ������ ȭ�鿡 ������ �ʴ´�.
    return -1;
}