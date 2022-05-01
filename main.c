#include "a.h"

int main() {
    MData map[MAP_SIZE][MAP_SIZE];  // 크기가 [22][22]인 2차원 배열 map 생성.
    system("color 7");  // 콘솔 색상 지정.
    hidecursor();   // 콘솔창의 커서를 숨김.
    int stage;
    int scoreArr[4] = { 0 };    // 4개의 맵 별로 점수를 저장하기 위해 크기가 4인 scoreArr 생성.
    while (1) { 
        system("mode con: cols=44 lines=30");   // 콘솔 사이즈 지정.
        if (drawStartMenu() == FALSE) break;    // 메인화면에서 t 또는 T 입력 시 프로그램을 종료한다.
        system("cls");      // 콘솔에서 출력한 것을 모두 지운다.
        stage = drawSpeedMenu(scoreArr);    // 맵 선택 메뉴와 점수를 보여주며, 사용자가 입력한 맵 번호(1 ~ 4)를 stage에 대입한다.
        system("cls");      // 콘솔에서 출력한 것을 모두 지운다.
        GameStart(map, stage, scoreArr);    // 게임 시작.
        system("pause");    // 프로그램 일시정지.
    }
    return 0;
}