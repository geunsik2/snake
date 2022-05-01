#include "a.h"

///////////////////////////QUEUE//////////////////////////////////////////

typedef struct _mynode {    // typedef로 구조체를 정의
    SnakePos data;  // snake의 멤버변수 x와 y를 가리킴.
    struct _mynode* next;   // snake의 다음 x와 y를 가리킴.
} Node;      // _mynode의 별칭.

typedef struct _myqueue {   // typedef로 구조체를 정의 
    Node* rear;     // Node->data, next ?
    Node* front;    // Node->next->data, next ?
} MyQueue;  // _myqueue의 별칭.
typedef MyQueue Queue;  // MyQueue의 별칭.

void QueueInit(Queue* pq) { // snakePos의 멤버변수 x, y를 NULL로 초기화.
    pq->rear = NULL;    // pq->rear를 NULL로 초기화.
    pq->front = NULL;   // pq->front를 NULL로 초기화.
}
int isEmpty(Queue* pq) {    // 다음으로 생성할 구조체가 NULL인 경우 1을 리턴하고 아닌 경우 0을 리턴한다.
    if (pq->front == NULL)
        return TRUE;
    else
        return FALSE;
}
void Enqueue(Queue* pq, SnakePos data) {    // ?
    Node* newNode = (Node*)malloc(sizeof(Node));    // ?
    newNode->data = data;   // newNode->data에 snake의 멤버변수 x와 y를 대입한다.
    newNode->next = NULL;   // snake의 다음 x와 y를 NULL로 초기화. 
    if (pq->front == NULL) {    // pq->front가 NULL인 경우 다음 구조체 생성.?
        pq->rear = newNode;  
        pq->front = newNode;
    }
    else {
        pq->rear->next = newNode;
        pq->rear = newNode;
    }
}
SnakePos Dequeue(Queue* pq) {
    Node* delNode;
    SnakePos delData = { 0,0 }; // 구조체 생성 후 0으로 초기화 ?
    if (isEmpty(pq)) {  // pq->front == NULL이면 delData를 리턴한다.
        return delData;
    }
    delNode = pq->front;    
    delData = delNode->data;
    pq->front = pq->front->next;
    free(delNode);
    return delData;
}
SnakePos Peek(Queue* pq) {
    return pq->front->data;
}
///////////////////////////////////////////////////////////////////////////


void setSnakeTail(MData map[MAP_SIZE][MAP_SIZE], int snake_x, int snake_y) {    // 뱀 꼬리 부분 설정.
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);  // 표준콘솔출력의 핸들을 반환.
    SetConsoleTextAttribute(hand, 14);  // 콘솔에서의 글자색을 진한 노란색(14)으로 변경한다.
    gotoxy(snake_x, snake_y);   // 커서를 snake가 위치한 (x, y) 좌표로 이동.
    printf("ㆁ");
    map[snake_x][snake_y] = TAIL;   // map[snake_x][snake_y]에 3을 대입.
    SetConsoleTextAttribute(hand, 7);   // 콘솔에서의 글자색을 연한 흰색(7)으로 변경한다.

}

void setSnake(MData map[MAP_SIZE][MAP_SIZE], int snake_x, int snake_y) {    // 뱀 머리 부분 설정.
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);  // 표준콘솔출력의 핸들을 반환.
    gotoxy(snake_x, snake_y);   // 커서를 snake가 위치한 (x, y) 좌표로 이동.
    SetConsoleTextAttribute(hand, 14);  // 콘솔에서의 글자색을 진한 노란색(14)으로 변경한다.
    printf("●");
    SetConsoleTextAttribute(hand, 7);   // 콘솔에서의 글자색을 연한 흰색(7)으로 변경한다.
    map[snake_x][snake_y] = HEAD;   // map[snake_x][snake_y]에 2를 대입.
}

void removeSnake(MData map[MAP_SIZE][MAP_SIZE], int snake_x, int snake_y) { // 뱀을 콘솔창에서 지우는 함수.
    gotoxy(snake_x, snake_y);   // 커서를 snake가 위치한 (x, y) 좌표로 이동.
    printf("  ");
    map[snake_x][snake_y] = EMPTY;  // map[snake_x][snake_y]에 0을 대입.
}

int rotate(int xy, int way) {   // rotate 함수가 무슨 기능을 하는지 한마디로 정의하기....
    if (way == UP || way == LEFT) { // way가 72(↑)이거나 75(←)인 경우
        if (xy - 1 == -1) { // xy -1이 -1인 경우
            xy = MAP_SIZE - 1; // xy에 21을 대입한다.
        }
        else {
            --(xy); // xy를 1 감소한다.
        }
        return xy;
    }
    if (way == DOWN || way == RIGHT) {  // way가 80(↓)이거나 77(→)인 경우
        if (xy + 1 == MAP_SIZE) {   // xy + 1이 22인 경우
            xy = 0; // xy에 0을 대입한다.
        }
        else {
            ++xy;   // xy를 1 증가한다.
        }
        return xy;
    }
    return FALSE;   // 0을 리턴한다.
}

int colWithTail(MData map[MAP_SIZE][MAP_SIZE], SnakePos* sp, int way) { // snake가 Tail과 충돌한 상황 설정.
                                                                        // rotate(sp->y, way)를 제대로 이해했는지
                                                                        // 물어보기..
    if (way == UP) {    // way가 72인 경우
        if (map[sp->x][rotate(sp->y, way)] == TAIL) // map[snake_x][rotate(sp->y, way)]의 값이 3인 경우
            return TRUE;    // 1을 리턴한다.
    }
    if (way == DOWN) {  // way가 80인 경우
        if (map[sp->x][rotate(sp->y, way)] == TAIL)  // map[snake_x][rotate(sp->y, way)]의 값이 3인 경우
            return TRUE;    // 1을 리턴한다.
    }
    if (way == LEFT) {  // way가 75인 경우
        if (map[rotate(sp->x, way)][sp->y] == TAIL)  // map[rotate(sp->x, way)][snake_y]의 값이 3인 경우
            return TRUE;    // 1을 리턴한다.
    }
    if (way == RIGHT) { // way가 77인 경우
        if (map[rotate(sp->x, way)][sp->y] == TAIL)  // map[rotate(sp->x, way)][snake_y]의 값이 3인 경우
            return TRUE;    // 1을 리턴한다.
    }
    return FALSE;   // 0을 리턴한다.
}

int colWithWall(MData map[MAP_SIZE][MAP_SIZE], SnakePos* sp, int way) { // snake가 Wall과 충돌한 상황 설정.
    if (way == UP) {    // way가 72인 경우
        if (map[sp->x][rotate(sp->y, way)] == WALL) // map[snake_x][rotate(sp->y, way)]의 값이 1인 경우
            return TRUE;    // 1을 리턴한다.
    }
    if (way == DOWN) {  // way가 80인 경우
        if (map[sp->x][rotate(sp->y, way)] == WALL) // map[snake_x][rotate(sp->y, way)]의 값이 1인 경우
            return TRUE;    // 1을 리턴한다.
    }
    if (way == LEFT) {  // way가 75인 경우
        if (map[rotate(sp->x, way)][sp->y] == WALL) // map[rotate(sp->x, way)][snake_y]의 값이 1인 경우
            return TRUE;    // 1을 리턴한다.
    }
    if (way == RIGHT) { // way가 77인 경우
        if (map[rotate(sp->x, way)][sp->y] == WALL) // map[rotate(sp->x, way)][snake_y]의 값이 1인 경우
            return TRUE;    // 1을 리턴한다.
    }
    return FALSE;   // 0을 리턴한다.
}


//get snake x, y and move snake
int moveSnakeHead(MData map[MAP_SIZE][MAP_SIZE], SnakePos* snake, int way) {    // snake의 (x,y) 좌표를 구하고 움직인다.
    removeSnake(map, snake->x, snake->y); // 커서를 (snake->x, snake->y) 좌표로 이동해서 공백을 출력하고 
                                          // map[snake_x][snake_y]에 0을 대입한다.
    if (colWithWall(map, snake, way) == TRUE) { // colWithWall의 리턴값이 1인 경우
        gotoxy(1, 1);   // 커서를 (1, 1) 좌표로 이동한다.
        printf("> Hit : wall");
        return COLLISION;   // 10을 리턴한다.
    }
    if (colWithTail(map, snake, way) == TRUE) { // colWithTail의 리턴값이 1인 경우
        gotoxy(1, 1);   // 커서를 (1, 1) 좌표로 이동한다.
        printf("> Hit : tail");
        return COLLISION;   // 10을 리턴한다.
    }

    if (way == UP) {    // way가 72(↑)인 경우
        if (snake->y - 1 == -1) {       // snake의 y좌표가 0인 경우
            snake->y = MAP_SIZE - 1;    // snake의 y좌표에 21을 대입한다.
        }
        else {
            --(snake->y);   // snake의 y좌표를 1 감소한다.
        }
        setSnake(map, snake->x, (snake->y)); // 커서를 snake가 위치한 (x, y) 좌표로 이동해서 ●를 출력하고
                                             // map[snake_x][snake_y]에 2를 대입.
        return UP;  // 72를 리턴한다.
    }
    if (way == DOWN) {  // way가 80(↓)인 경우
        if (snake->y + 1 == MAP_SIZE) { // snake의 y좌표가 21인 경우
            snake->y = 0;   // snake의 y좌표에 0을 대입한다.
        }
        else {
            ++(snake->y);   // snake의 y좌표를 1 증가한다.
        }
        setSnake(map, snake->x, (snake->y));    // 커서를 snake가 위치한 (x, y) 좌표로 이동해서 ●를 출력하고
                                                // map[snake_x][snake_y]에 2를 대입.
        return DOWN;    // 80을 리턴한다.
    }
    if (way == LEFT) {  // way가 75(←)인 경우
        if (snake->x - 1 == -1) {       // snake의 x좌표가 0인 경우
            snake->x = MAP_SIZE - 1;    // snake의 x좌표에 21을 대입한다.
        }
        else {
            --(snake->x);   // snake의 x좌표를 1 감소한다. 
        }
        setSnake(map, (snake->x), snake->y);    // 커서를 snake가 위치한 (x, y) 좌표로 이동해서 ●를 출력하고
                                                // map[snake_x][snake_y]에 2를 대입.
        return LEFT;    // 75를 리턴한다.
    }
    if (way == RIGHT) { // way가 77(→)인 경우
        if (snake->x + 1 == MAP_SIZE) { // snake의 x좌표가 21인 경우
            snake->x = 0;   // snake의 x좌표에 0을 대입한다.
        }
        else {
            ++(snake->x);   // snake의 x좌표를 1 증가한다.
        }
        setSnake(map, snake->x, snake->y);  // 커서를 snake가 위치한 (x, y) 좌표로 이동해서 ●를 출력하고
                                            // map[snake_x][snake_y]에 2를 대입.
        return RIGHT;   // 77을 리턴한다.
    }
    return way; // way를 리턴한다.
}

int overlap(int savedKey, int key) {    // snake의 방향을 좌->우, 우->좌, 상->하, 하->상 으로
                                        // 전환할 시 1을 리턴한다.
    if (savedKey == UP && key == DOWN)  // savedKey의 값이 72(↑)이고 key의 값이 80(↓)인 경우
        return TRUE;
    if (savedKey == DOWN && key == UP)  // savedKey의 값이 80(↓)이고 key의 값이 72(↑)인 경우
        return TRUE;
    if (savedKey == LEFT && key == RIGHT)   // savedKey의 값이 75(←)이고 key의 값이 77(→)인 경우
        return TRUE;
    if (savedKey == RIGHT && key == LEFT)   // savedKey의 값이 77(→)이고 key의 값이 75(←)인 경우
        return TRUE;

    return FALSE;
}

int colWithFruit(SnakePos* sp, FruitPos* fp) {  // snake가 Fruit와 충돌한 상황 설정.
    if ((sp->x == fp->x && sp->y == fp->y)) {   // snake의 (x,y) 좌표와 fruit의 (x,y) 좌표가 같은 경우
        return TRUE;    // 1을 리턴한다.
    }
    return FALSE;   // 0을 리턴한다.
}

int isCollision(int state) {    // 충돌
    if (state == COLLISION) return TRUE;    // state가 10인 경우 1을 리턴한다.
    return FALSE;
}
void GameOver(int score, int best, Queue* pq, int stage, int* scoreArr) {   // GameOver 설정.
    FILE* wfp;
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);  // 표준콘솔출력의 핸들을 반환.
    if (score >= best) {    // 현재 점수가 최고 점수보다 크거나 같은 경우
        scoreArr[stage - 1] = score;    // scoreArr[stage - 1]에 현재 점수를 대입한다.
    }
    else {  // 현재 점수가 최고 점수보다 낮을 경우
        scoreArr[stage - 1] = best; // scoreArr[stage - 1]에 최고 점수를 대입한다.
    }
    wfp = fopen("score.txt", "w");  // score.txt 파일을 쓰기 전용으로 연다.
    fprintf(wfp, "%d %d %d %d", scoreArr[0], scoreArr[1], scoreArr[2], scoreArr[3]);    
    // scoreArr[0]부터 scoreArr[3]까지 각각 저장된 값을 score.txt 파일에 작성한다.
    fclose(wfp);    // 쓰기 전용 score.txt 파일을 닫는다.
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

void GameStart(MData map[MAP_SIZE][MAP_SIZE], int stage, int* scoreArr) {
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
        // DWORD -> unsigned long 	4 byte --> (DWORD)NORMAL --> (4byte)10 ?
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

        if (_kbhit()) { // 현재 키보드가 입력된 상태라면
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
                savedKey = moveSnakeHead(map, &snake, key); 
                Enqueue(&queue, snakeSecond);
                setSnakeTail(map, snakeSecond.x, snakeSecond.y);
                if (time == TRUE) {
                    snakeTail = Dequeue(&queue);
                    removeSnake(map, snakeTail.x, snakeTail.y);
                }
                else {
                    time = TRUE;
                }
                if (isCollision(savedKey)) { GameOver(score, best, &queue, stage, scoreArr); return; }
            }
        }
        else {
            snakeSecond = snake;
            savedKey = moveSnakeHead(map, &snake, savedKey);
            Enqueue(&queue, snakeSecond);
            setSnakeTail(map, snakeSecond.x, snakeSecond.y);
            if (time == TRUE) {
                snakeTail = Dequeue(&queue);
                removeSnake(map, snakeTail.x, snakeTail.y);
            }
            else {
                time = TRUE;
            }
            if (isCollision(savedKey)) { GameOver(score, best, &queue, stage, scoreArr); return; }

        }
    }
}

int main() {
    MData map[MAP_SIZE][MAP_SIZE];
    system("color 7");
    hidecursor();
    int stage;
    int scoreArr[4] = { 0 };
    while (1) {
        system("mode con: cols=44 lines=30");   //console size
        if (drawStartMenu() == FALSE) break; // 메인화면에서 t 또는 T 입력 시 프로그램을 종료한다.
        system("cls");
        stage = drawSpeedMenu(scoreArr);
        system("cls");
        GameStart(map, stage, scoreArr);
        system("pause");
    }
    return 0;
}