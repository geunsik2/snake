#include "a.h"

void GameStart(MData map[MAP_SIZE][MAP_SIZE], int stage, int* scoreArr) {   // 게임 시작 함수.
    int best = scoreArr[stage - 1]; // best에 현재 선택한 맵의 점수를 대입한다.
    int score = 0;  // score 0으로 초기화.
    int key, savedKey = 0;  // key, savedKey 0으로 초기화.
    Queue queue;    // 구조체 생성.
    QueueInit(&queue);  // rear, front NULL로 초기화.
    SnakePos snake = { MAP_SIZE / 4 - 2, MAP_SIZE / 4 + 1 };    // snake를 (3,6) 좌표에 생성.
    SnakePos snakeSecond;   // 구조체 생성.
    SnakePos snakeTail; // 구조체 생성.
    int time = FALSE;   // time을 0으로 초기화.
    FruitPos fruit; // 구조체 생성.
    fruit.numOfFruit = 0;   // FruitPos의 멤버변수 numOfFruit를 0으로 초기화.

    if (stage == 1) {   // 첫 번째 맵 생성.
        stageOneInit(map);
    }
    else if (stage == 2) {  // 두 번째 맵 생성.
        stageTwoInit(map);
    }
    else if (stage == 3) {  // 세 번째 맵 생성.
        stageThreeInit(map);
    }
    else {  // 네 번째 맵 생성.
        stageFourinit(map);
    }

    drawMainMap(map);   // 1로 초기화된 좌표에 □를 출력하고 0으로 초기화된 좌표에 공백을 출력한다.
    setSnake(map, snake.x, snake.y);    // 커서를 (3,6) 좌표로 이동해서 ●를 출력하고
                                        // map[3][6]에 2를 대입한다.

    while (1) {
        Sleep(1000 / (DWORD)NORMAL);    // snake speed
        if (fruit.numOfFruit == 0) {    // draw fruit
            setFruit(map, &fruit);  // 난수를 발생시켜 맵의 좌표를 무작위로 선택하고 map[?][?]에 들어있는 값이 0이라면
                                    // 해당 좌표를 FRUIT(5)로 초기화한다.
                                    // numOfFruit를 1 증가시키고 ★을 출력한다.
        }
        drawSubMap(score, best, stage); // 서브화면. 맵을 선택하면 해당 맵의 점수 및 도움말을 출력한다.

        if (colWithFruit(&snake, &fruit) == TRUE) { // snake의 (x,y) 좌표와 fruit의 (x,y) 좌표가 같은 경우
                                                    // 현재 점수에 5점 누적 합산한다.
            (fruit.numOfFruit)--;   // numOfFruit를 1 감소시킨다.
            time = FALSE;   // time을 0으로 초기화.
            score += 5; // score에 5점 누적 합산.
        }

        if (_kbhit()) { // 키보드 입력이 있을 시 조건문을 실행한다.
            key = _getch(); // key에 사용자의 키보드 입력을 저장한다.
            if (key == 't' || key == 'T') {     // t 또는 T 입력 시 메인화면으로 이동한다.
                return;
            }
            if (key == 'p' || key == 'P') {     // p 또는 P 입력 시 일시정지한다.
                system("pause");
                gotoxy(DEFAULT_X, MAP_SIZE + 6);
                printf("                                            ");
                gotoxy(DEFAULT_X, DEFAULT_Y);
            }

            if (key == 224) {   // 방향키(↑, ↓, ←, →) 입력을 받은 경우.
                key = _getch(); // key에 사용자의 키보드 입력을 대입한다. 
                if (overlap(savedKey, key) == TRUE) {   // 좌->우, 우->좌, 상->하, 하->상 으로 방향 전환 시도 시
                    key = savedKey; // key에 savedKey를 대입한다.
                }
                snakeSecond = snake; // snakeSecond에 snake의 좌표를 대입한다. 
                savedKey = moveSnakeHead(map, &snake, key); // snake가 Wall 또는 Tail과 충돌 시 savedKey에 10을 대입하고
                                                            // 충돌하지 않았을 시 key값을 savedKey에 대입한다.
                Enqueue(&queue, snakeSecond);
                setSnakeTail(map, snakeSecond.x, snakeSecond.y);    // 커서를 snakeSecond가 위치한 (x, y) 좌표로 이동하고
                                                                    // ㆁ를 출력한다.
                                                                    // map[snakeSecond.x][snakeSecond.y]에 3을 대입한다.
                if (time == TRUE) { // time이 TRUE인 경우
                    snakeTail = Dequeue(&queue);
                    removeSnake(map, snakeTail.x, snakeTail.y); // snakeTail이 위치한 좌표에 공백을 출력한다.
                }
                else {  // snake가 fruit와 충돌한 경우 time을 TRUE로 초기화한다.
                    time = TRUE;
                }
                if (isCollision(savedKey)) {    // savedKey가 Collision(10)인 경우
                                                // 최고 점수를 갱신하고 파일을 작성하며, 현재 점수를 출력한다.
                    GameOver(score, best, &queue, stage, scoreArr);
                    return;
                }
            }
        }
        else {  // 키보드 입력이 없을 시 조건문 실행.
            snakeSecond = snake;    // snakeSecond에 snake의 좌표를 대입한다.
            savedKey = moveSnakeHead(map, &snake, savedKey);    // snake가 Wall 또는 Tail과 충돌 시 savedKey에 10을 대입하고
                                                                // 충돌하지 않았을 시 key값을 savedKey에 대입한다.
            Enqueue(&queue, snakeSecond);
            setSnakeTail(map, snakeSecond.x, snakeSecond.y);    // 커서를 snakeSecond가 위치한 (x, y) 좌표로 이동하고
                                                                // ㆁ를 출력한다.
                                                                // map[snakeSecond.x][snakeSecond.y]에 3을 대입한다.
            if (time == TRUE) { // time이 TRUE인 경우
                snakeTail = Dequeue(&queue);
                removeSnake(map, snakeTail.x, snakeTail.y); // snakeTail이 위치한 좌표에 공백을 출력한다.
            }
            else {
                time = TRUE;    // snake가 fruit와 충돌한 경우 time을 TRUE로 초기화한다.
            }
            if (isCollision(savedKey)) {    // savedKey가 Collision(10)인 경우
                                            // 최고 점수를 갱신하고 파일을 작성하며, 현재 점수를 출력한다.
                GameOver(score, best, &queue, stage, scoreArr);
                return;
            }
        }
    }
}