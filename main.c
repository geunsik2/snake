#include "a.h"

int main() {
    MData map[MAP_SIZE][MAP_SIZE];  // ũ�Ⱑ [22][22]�� 2���� �迭 map ����.
    system("color 7");  // �ܼ� ���� ����.
    hidecursor();   // �ܼ�â�� Ŀ���� ����.
    int stage;
    int scoreArr[4] = { 0 };    // 4���� �� ���� ������ �����ϱ� ���� ũ�Ⱑ 4�� scoreArr ����.
    while (1) { 
        system("mode con: cols=44 lines=30");   // �ܼ� ������ ����.
        if (drawStartMenu() == FALSE) break;    // ����ȭ�鿡�� t �Ǵ� T �Է� �� ���α׷��� �����Ѵ�.
        system("cls");      // �ֿܼ��� ����� ���� ��� �����.
        stage = drawSpeedMenu(scoreArr);    // �� ���� �޴��� ������ �����ָ�, ����ڰ� �Է��� �� ��ȣ(1 ~ 4)�� stage�� �����Ѵ�.
        system("cls");      // �ֿܼ��� ����� ���� ��� �����.
        GameStart(map, stage, scoreArr);    // ���� ����.
        system("pause");    // ���α׷� �Ͻ�����.
    }
    return 0;
}