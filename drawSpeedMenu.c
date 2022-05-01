#include "a.h"

int drawSpeedMenu(int* scoreArr) {  //show stage Menu and score;
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);  // 표준콘솔출력의 핸들을 반환.

    int i;
    FILE* rfp, * wfp;
    rfp = fopen("score.txt", "r");  // score.txt 파일을 읽기 전용으로 연다.
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
        wfp = fopen("score.txt", "w"); // score.txt 파일을 쓰기 전용으로 연다.
        fprintf(wfp, "%d %d %d %d", scoreArr[0], scoreArr[1], scoreArr[2], scoreArr[3]);
        // scoreArr[0]부터 scoreArr[3]까지 각각 저장된 값을 score.txt 파일에 작성한다.
        for (i = 0; i < 4; i++) {
            gotoxy(DEFAULT_X, DEFAULT_Y + (i + 4)); // 커서를 (0, 4)부터 (0, 7)까지 이동한다.
            printf(" Stage [%d] : %d", i + 1, scoreArr[i]); // stage 별 점수를 콘솔에 출력한다.
        }
        fclose(wfp);    // 쓰기 전용 score.txt 파일을 닫는다.
    }
    fscanf(rfp, "%d %d %d %d", &scoreArr[0], &scoreArr[1], &scoreArr[2], &scoreArr[3]);
    // score.txt 파일을 읽어서 scoreArr[0]부터 scoreArr[3]까지 값을 입력한다.
    for (i = 0; i < 4; i++) {
        gotoxy(DEFAULT_X, DEFAULT_Y + (i + 4)); // 커서를 (0, 4)부터 (0, 7)까지 이동한다.
        printf(" Stage [%d] : %d", i + 1, scoreArr[i]); // stage 별 점수를 콘솔에 출력한다.
    }

    fclose(rfp);    // score.txt 파일을 닫는다.

    while (1) {
        int keyDown = getKeyDown();
        if (keyDown == '1') {   // 사용자로부터 1을 입력받으면 1을 리턴한다.
            SetConsoleTextAttribute(hand, 7);   // 콘솔에서의 글자색을 연한 흰색(7)으로 변경한다.
            return 1;
        }
        if (keyDown == '2') {   // 사용자로부터 2을 입력받으면 2를 리턴한다.
            SetConsoleTextAttribute(hand, 7);
            return 2;
        }
        if (keyDown == '3') {   // 사용자로부터 3을 입력받으면 3을 리턴한다.
            SetConsoleTextAttribute(hand, 7);
            return 3;
        }
        if (keyDown == '4') {   // 사용자로부터 4을 입력받으면 4를 리턴한다.
            SetConsoleTextAttribute(hand, 7);
            return 4;
        }
        SetConsoleTextAttribute(hand, 14);  // 콘솔에서의 글자색을 노란색(14)으로 변경한다.
        gotoxy(DEFAULT_X, DEFAULT_Y + 9);   // 커서를 (0, 9) 좌표로 이동.
        printf(">> Choose Stage : 1, 2, 3, 4");
        Sleep(1000 / 3);    // 0.3초마다 대기해서 깜빡이게 보이게 한다.
        gotoxy(DEFAULT_X, DEFAULT_Y + 9);
        printf(">>                          ");
        Sleep(1000 / 3);    // 0.3초마다 대기해서 깜빡이게 보이게 한다.
    }
}
