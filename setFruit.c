#include "a.h"

int setFruit(MData map[MAP_SIZE][MAP_SIZE], FruitPos* fp) { // Fruit 생성 위치 및 모양 설정
    HANDLE  hand = GetStdHandle(STD_OUTPUT_HANDLE); // 표준콘솔출력의 핸들을 반환.
    int i, j;
    srand((unsigned int)time(NULL));    // 난수 발생 초기화.
    while (1) {
        i = rand() % (MAP_SIZE - 2) + 1;    // i에 0 ~ 20 사이의 어떤 수를 대입한다.
        j = rand() % (MAP_SIZE - 2) + 1;    // j에 0 ~ 20 사이의 어떤 수를 대입한다.
        if (map[i][j] == EMPTY) {   // 맵의 (i,j) 좌표가 0인 경우
            map[i][j] = FRUIT;  // 해당 좌표를 FRUIT(5)로 초기화한다.
            fp->x = i;  // 구조체 포인터 FruitPos의 멤버변수 x에 접근. 즉, x에 i값을 대입.
            fp->y = j;  // 구조체 포인터 FruitPos의 멤버변수 y에 접근. 즉, y에 j값을 대입.
            (fp->numOfFruit)++; // numOfFruit를 1씩 증가시킨다.
            SetConsoleTextAttribute(hand, 10);  // 콘솔에서의 글자색을 진한 연두색(10)으로 변경한다.
            gotoxy(i, j);   // 해당 좌표로 커서를 이동한다.
            printf("★");
            SetConsoleTextAttribute(hand, 7);   // 콘솔에서의 글자색을 연한 흰색(7)으로 변경한다.

            return 1;
        }
    }
}

int setBonusFruit(MData map[MAP_SIZE][MAP_SIZE], FruitPos* fp) {    // Fruit 추가 생성 함수 (선언만 하고 호출은 하지 않음.)
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