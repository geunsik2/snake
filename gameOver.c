#include "a.h"

void GameOver(int score, int best, Queue* pq, int stage, int* scoreArr) {   // GameOver 설정. 최고 점수를 갱신하고 파일을 작성하며,
                                                                            // 현재 점수를 출력한다.

    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);  // 표준콘솔출력의 핸들을 반환.
    if (score >= best) {    // 현재 점수가 최고 점수보다 크거나 같은 경우
        scoreArr[stage - 1] = score;    // scoreArr[stage - 1]에 현재 점수를 대입한다.
    }
    else {  // 현재 점수가 최고 점수보다 낮을 경우
        scoreArr[stage - 1] = best; // scoreArr[stage - 1]에 최고 점수를 대입한다.
    }
    ranking_db(score, best, stage, scoreArr);   // 게임오버 시 해당 유저의 스테이지 별 점수를 DB에 입력한다.
    SetConsoleTextAttribute(hand, 14);  // 콘솔에서의 글자색을 진한 노란색(14)으로 변경한다.
    gotoxy(MAP_SIZE / 2 - 4, MAP_SIZE / 2 - 5); // 커서를 (7,6) 좌표로 이동.
    printf("===<GAME OVER>===\n");
    gotoxy(MAP_SIZE / 2 - 3, MAP_SIZE / 2 - 3); // 커서를 (8,8) 좌표로 이동.
    printf("Your Score : %d\n", score); // 현재 점수 출력.
    gotoxy(DEFAULT_X + 8, MAP_SIZE + 5);    // 커서를 (8,27) 좌표로 이동.
    printf("\n");
    SetConsoleTextAttribute(hand, 7);   // 콘솔에서의 글자색을 연한 흰색(7)으로 변경한다.

    while (!isEmpty(pq)) {  // isEmpty(pq)의 리턴값이 0이면 무한루프
                            // 1이면 반복문을 실행하지 않는다.
        Dequeue(pq);
    }
}