#include "a.h"

///////////////////////////QUEUE//////////////////////////////////////////

typedef struct _mynode {    // typedef�� ����ü�� ����
    SnakePos data;  // snake�� ������� x�� y�� ����Ŵ.
    struct _mynode* next;   // snake�� ���� x�� y�� ����Ŵ.
} Node;      // _mynode�� ��Ī.

typedef struct _myqueue {   // typedef�� ����ü�� ���� 
    Node* rear;     // Node->data, next ?
    Node* front;    // Node->next->data, next ?
} MyQueue;  // _myqueue�� ��Ī.
typedef MyQueue Queue;  // MyQueue�� ��Ī.

void QueueInit(Queue* pq) { // snakePos�� ������� x, y�� NULL�� �ʱ�ȭ.
    pq->rear = NULL;    // pq->rear�� NULL�� �ʱ�ȭ.
    pq->front = NULL;   // pq->front�� NULL�� �ʱ�ȭ.
}
int isEmpty(Queue* pq) {    // �������� ������ ����ü�� NULL�� ��� 1�� �����ϰ� �ƴ� ��� 0�� �����Ѵ�.
    if (pq->front == NULL)
        return TRUE;
    else
        return FALSE;
}
void Enqueue(Queue* pq, SnakePos data) {    // ?
    Node* newNode = (Node*)malloc(sizeof(Node));    // ?
    newNode->data = data;   // newNode->data�� snake�� ������� x�� y�� �����Ѵ�.
    newNode->next = NULL;   // snake�� ���� x�� y�� NULL�� �ʱ�ȭ. 
    if (pq->front == NULL) {    // pq->front�� NULL�� ��� ���� ����ü ����.?
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
    SnakePos delData = { 0,0 }; // ����ü ���� �� 0���� �ʱ�ȭ ?
    if (isEmpty(pq)) {  // pq->front == NULL�̸� delData�� �����Ѵ�.
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


void setSnakeTail(MData map[MAP_SIZE][MAP_SIZE], int snake_x, int snake_y) {    // �� ���� �κ� ����.
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);  // ǥ���ܼ������ �ڵ��� ��ȯ.
    SetConsoleTextAttribute(hand, 14);  // �ֿܼ����� ���ڻ��� ���� �����(14)���� �����Ѵ�.
    gotoxy(snake_x, snake_y);   // Ŀ���� snake�� ��ġ�� (x, y) ��ǥ�� �̵�.
    printf("��");
    map[snake_x][snake_y] = TAIL;   // map[snake_x][snake_y]�� 3�� ����.
    SetConsoleTextAttribute(hand, 7);   // �ֿܼ����� ���ڻ��� ���� ���(7)���� �����Ѵ�.

}

void setSnake(MData map[MAP_SIZE][MAP_SIZE], int snake_x, int snake_y) {    // �� �Ӹ� �κ� ����.
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);  // ǥ���ܼ������ �ڵ��� ��ȯ.
    gotoxy(snake_x, snake_y);   // Ŀ���� snake�� ��ġ�� (x, y) ��ǥ�� �̵�.
    SetConsoleTextAttribute(hand, 14);  // �ֿܼ����� ���ڻ��� ���� �����(14)���� �����Ѵ�.
    printf("��");
    SetConsoleTextAttribute(hand, 7);   // �ֿܼ����� ���ڻ��� ���� ���(7)���� �����Ѵ�.
    map[snake_x][snake_y] = HEAD;   // map[snake_x][snake_y]�� 2�� ����.
}

void removeSnake(MData map[MAP_SIZE][MAP_SIZE], int snake_x, int snake_y) { // ���� �ܼ�â���� ����� �Լ�.
    gotoxy(snake_x, snake_y);   // Ŀ���� snake�� ��ġ�� (x, y) ��ǥ�� �̵�.
    printf("  ");
    map[snake_x][snake_y] = EMPTY;  // map[snake_x][snake_y]�� 0�� ����.
}

int rotate(int xy, int way) {   // rotate �Լ��� ���� ����� �ϴ��� �Ѹ���� �����ϱ�....
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

int colWithTail(MData map[MAP_SIZE][MAP_SIZE], SnakePos* sp, int way) { // snake�� Tail�� �浹�� ��Ȳ ����.
                                                                        // rotate(sp->y, way)�� ����� �����ߴ���
                                                                        // �����..
    if (way == UP) {    // way�� 72�� ���
        if (map[sp->x][rotate(sp->y, way)] == TAIL) // map[snake_x][rotate(sp->y, way)]�� ���� 3�� ���
            return TRUE;    // 1�� �����Ѵ�.
    }
    if (way == DOWN) {  // way�� 80�� ���
        if (map[sp->x][rotate(sp->y, way)] == TAIL)  // map[snake_x][rotate(sp->y, way)]�� ���� 3�� ���
            return TRUE;    // 1�� �����Ѵ�.
    }
    if (way == LEFT) {  // way�� 75�� ���
        if (map[rotate(sp->x, way)][sp->y] == TAIL)  // map[rotate(sp->x, way)][snake_y]�� ���� 3�� ���
            return TRUE;    // 1�� �����Ѵ�.
    }
    if (way == RIGHT) { // way�� 77�� ���
        if (map[rotate(sp->x, way)][sp->y] == TAIL)  // map[rotate(sp->x, way)][snake_y]�� ���� 3�� ���
            return TRUE;    // 1�� �����Ѵ�.
    }
    return FALSE;   // 0�� �����Ѵ�.
}

int colWithWall(MData map[MAP_SIZE][MAP_SIZE], SnakePos* sp, int way) { // snake�� Wall�� �浹�� ��Ȳ ����.
    if (way == UP) {    // way�� 72�� ���
        if (map[sp->x][rotate(sp->y, way)] == WALL) // map[snake_x][rotate(sp->y, way)]�� ���� 1�� ���
            return TRUE;    // 1�� �����Ѵ�.
    }
    if (way == DOWN) {  // way�� 80�� ���
        if (map[sp->x][rotate(sp->y, way)] == WALL) // map[snake_x][rotate(sp->y, way)]�� ���� 1�� ���
            return TRUE;    // 1�� �����Ѵ�.
    }
    if (way == LEFT) {  // way�� 75�� ���
        if (map[rotate(sp->x, way)][sp->y] == WALL) // map[rotate(sp->x, way)][snake_y]�� ���� 1�� ���
            return TRUE;    // 1�� �����Ѵ�.
    }
    if (way == RIGHT) { // way�� 77�� ���
        if (map[rotate(sp->x, way)][sp->y] == WALL) // map[rotate(sp->x, way)][snake_y]�� ���� 1�� ���
            return TRUE;    // 1�� �����Ѵ�.
    }
    return FALSE;   // 0�� �����Ѵ�.
}


//get snake x, y and move snake
int moveSnakeHead(MData map[MAP_SIZE][MAP_SIZE], SnakePos* snake, int way) {    // snake�� (x,y) ��ǥ�� ���ϰ� �����δ�.
    removeSnake(map, snake->x, snake->y); // Ŀ���� (snake->x, snake->y) ��ǥ�� �̵��ؼ� ������ ����ϰ� 
                                          // map[snake_x][snake_y]�� 0�� �����Ѵ�.
    if (colWithWall(map, snake, way) == TRUE) { // colWithWall�� ���ϰ��� 1�� ���
        gotoxy(1, 1);   // Ŀ���� (1, 1) ��ǥ�� �̵��Ѵ�.
        printf("> Hit : wall");
        return COLLISION;   // 10�� �����Ѵ�.
    }
    if (colWithTail(map, snake, way) == TRUE) { // colWithTail�� ���ϰ��� 1�� ���
        gotoxy(1, 1);   // Ŀ���� (1, 1) ��ǥ�� �̵��Ѵ�.
        printf("> Hit : tail");
        return COLLISION;   // 10�� �����Ѵ�.
    }

    if (way == UP) {    // way�� 72(��)�� ���
        if (snake->y - 1 == -1) {       // snake�� y��ǥ�� 0�� ���
            snake->y = MAP_SIZE - 1;    // snake�� y��ǥ�� 21�� �����Ѵ�.
        }
        else {
            --(snake->y);   // snake�� y��ǥ�� 1 �����Ѵ�.
        }
        setSnake(map, snake->x, (snake->y)); // Ŀ���� snake�� ��ġ�� (x, y) ��ǥ�� �̵��ؼ� �ܸ� ����ϰ�
                                             // map[snake_x][snake_y]�� 2�� ����.
        return UP;  // 72�� �����Ѵ�.
    }
    if (way == DOWN) {  // way�� 80(��)�� ���
        if (snake->y + 1 == MAP_SIZE) { // snake�� y��ǥ�� 21�� ���
            snake->y = 0;   // snake�� y��ǥ�� 0�� �����Ѵ�.
        }
        else {
            ++(snake->y);   // snake�� y��ǥ�� 1 �����Ѵ�.
        }
        setSnake(map, snake->x, (snake->y));    // Ŀ���� snake�� ��ġ�� (x, y) ��ǥ�� �̵��ؼ� �ܸ� ����ϰ�
                                                // map[snake_x][snake_y]�� 2�� ����.
        return DOWN;    // 80�� �����Ѵ�.
    }
    if (way == LEFT) {  // way�� 75(��)�� ���
        if (snake->x - 1 == -1) {       // snake�� x��ǥ�� 0�� ���
            snake->x = MAP_SIZE - 1;    // snake�� x��ǥ�� 21�� �����Ѵ�.
        }
        else {
            --(snake->x);   // snake�� x��ǥ�� 1 �����Ѵ�. 
        }
        setSnake(map, (snake->x), snake->y);    // Ŀ���� snake�� ��ġ�� (x, y) ��ǥ�� �̵��ؼ� �ܸ� ����ϰ�
                                                // map[snake_x][snake_y]�� 2�� ����.
        return LEFT;    // 75�� �����Ѵ�.
    }
    if (way == RIGHT) { // way�� 77(��)�� ���
        if (snake->x + 1 == MAP_SIZE) { // snake�� x��ǥ�� 21�� ���
            snake->x = 0;   // snake�� x��ǥ�� 0�� �����Ѵ�.
        }
        else {
            ++(snake->x);   // snake�� x��ǥ�� 1 �����Ѵ�.
        }
        setSnake(map, snake->x, snake->y);  // Ŀ���� snake�� ��ġ�� (x, y) ��ǥ�� �̵��ؼ� �ܸ� ����ϰ�
                                            // map[snake_x][snake_y]�� 2�� ����.
        return RIGHT;   // 77�� �����Ѵ�.
    }
    return way; // way�� �����Ѵ�.
}

int overlap(int savedKey, int key) {    // snake�� ������ ��->��, ��->��, ��->��, ��->�� ����
                                        // ��ȯ�� �� 1�� �����Ѵ�.
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

int colWithFruit(SnakePos* sp, FruitPos* fp) {  // snake�� Fruit�� �浹�� ��Ȳ ����.
    if ((sp->x == fp->x && sp->y == fp->y)) {   // snake�� (x,y) ��ǥ�� fruit�� (x,y) ��ǥ�� ���� ���
        return TRUE;    // 1�� �����Ѵ�.
    }
    return FALSE;   // 0�� �����Ѵ�.
}

int isCollision(int state) {    // �浹
    if (state == COLLISION) return TRUE;    // state�� 10�� ��� 1�� �����Ѵ�.
    return FALSE;
}
void GameOver(int score, int best, Queue* pq, int stage, int* scoreArr) {   // GameOver ����.
    FILE* wfp;
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);  // ǥ���ܼ������ �ڵ��� ��ȯ.
    if (score >= best) {    // ���� ������ �ְ� �������� ũ�ų� ���� ���
        scoreArr[stage - 1] = score;    // scoreArr[stage - 1]�� ���� ������ �����Ѵ�.
    }
    else {  // ���� ������ �ְ� �������� ���� ���
        scoreArr[stage - 1] = best; // scoreArr[stage - 1]�� �ְ� ������ �����Ѵ�.
    }
    wfp = fopen("score.txt", "w");  // score.txt ������ ���� �������� ����.
    fprintf(wfp, "%d %d %d %d", scoreArr[0], scoreArr[1], scoreArr[2], scoreArr[3]);    
    // scoreArr[0]���� scoreArr[3]���� ���� ����� ���� score.txt ���Ͽ� �ۼ��Ѵ�.
    fclose(wfp);    // ���� ���� score.txt ������ �ݴ´�.
    SetConsoleTextAttribute(hand, 14);  // �ֿܼ����� ���ڻ��� ���� �����(14)���� �����Ѵ�.
    gotoxy(MAP_SIZE / 2 - 4, MAP_SIZE / 2 - 5); // Ŀ���� (7,6) ��ǥ�� �̵�.
    printf("===<GAME OVER>===\n");
    gotoxy(MAP_SIZE / 2 - 3, MAP_SIZE / 2 - 3); // Ŀ���� (8,8) ��ǥ�� �̵�.
    printf("Your Score : %d\n", score); // ���� ���� ���.
    gotoxy(DEFAULT_X + 8, MAP_SIZE + 5);    // Ŀ���� (8,27) ��ǥ�� �̵�.
    printf("\n");
    SetConsoleTextAttribute(hand, 7);   // �ֿܼ����� ���ڻ��� ���� ���(7)���� �����Ѵ�.

    while (!isEmpty(pq)) {  // isEmpty(pq)�� ���ϰ��� 0�̸� ���ѷ���
                            // 1�̸� �ݺ����� �������� �ʴ´�.
        Dequeue(pq);    
    }
}

void GameStart(MData map[MAP_SIZE][MAP_SIZE], int stage, int* scoreArr) {
    int best = scoreArr[stage - 1]; // best�� ���� ������ ���� ������ �����Ѵ�.
    int score = 0;  // score 0���� �ʱ�ȭ.
    int key, savedKey = 0;  // key, savedKey 0���� �ʱ�ȭ.
    Queue queue;    // ����ü ����.
    QueueInit(&queue);  // rear, front NULL�� �ʱ�ȭ.
    SnakePos snake = { MAP_SIZE / 4 - 2, MAP_SIZE / 4 + 1 };    // snake�� (3,6) ��ǥ�� ����.
    SnakePos snakeSecond;   // ����ü ����.
    SnakePos snakeTail; // ����ü ����.
    int time = FALSE;   // time�� 0���� �ʱ�ȭ.
    FruitPos fruit; // ����ü ����.
    fruit.numOfFruit = 0;   // FruitPos�� ������� numOfFruit�� 0���� �ʱ�ȭ.

    if (stage == 1) {   // ù ��° �� ����.
        stageOneInit(map);
    }
    else if (stage == 2) {  // �� ��° �� ����.
        stageTwoInit(map);
    }
    else if (stage == 3) {  // �� ��° �� ����.
        stageThreeInit(map);
    }
    else {  // �� ��° �� ����.
        stageFourinit(map);
    }

    drawMainMap(map);   // 1�� �ʱ�ȭ�� ��ǥ�� �ฦ ����ϰ� 0���� �ʱ�ȭ�� ��ǥ�� ������ ����Ѵ�.
    setSnake(map, snake.x, snake.y);    // Ŀ���� (3,6) ��ǥ�� �̵��ؼ� �ܸ� ����ϰ�
                                        // map[3][6]�� 2�� �����Ѵ�.

    while (1) {
        // DWORD -> unsigned long 	4 byte --> (DWORD)NORMAL --> (4byte)10 ?
        Sleep(1000 / (DWORD)NORMAL);    // snake speed
        if (fruit.numOfFruit == 0) {    // draw fruit
            setFruit(map, &fruit);  // ������ �߻����� ���� ��ǥ�� �������� �����ϰ� map[?][?]�� ����ִ� ���� 0�̶��
                                    // �ش� ��ǥ�� FRUIT(5)�� �ʱ�ȭ�Ѵ�.
                                    // numOfFruit�� 1 ������Ű�� ���� ����Ѵ�.
        }
        drawSubMap(score, best, stage); // ����ȭ��. ���� �����ϸ� �ش� ���� ���� �� ������ ����Ѵ�.

        if (colWithFruit(&snake, &fruit) == TRUE) { // snake�� (x,y) ��ǥ�� fruit�� (x,y) ��ǥ�� ���� ���
                                                    // ���� ������ 5�� ���� �ջ��Ѵ�.
            (fruit.numOfFruit)--;   // numOfFruit�� 1 ���ҽ�Ų��.
            time = FALSE;   // time�� 0���� �ʱ�ȭ.
            score += 5; // score�� 5�� ���� �ջ�.
        }

        if (_kbhit()) { // ���� Ű���尡 �Էµ� ���¶��
            key = _getch(); // key�� ������� Ű���� �Է��� �����Ѵ�.
            if (key == 't' || key == 'T') {     // t �Ǵ� T �Է� �� ����ȭ������ �̵��Ѵ�.
                return;
            }
            if (key == 'p' || key == 'P') {     // p �Ǵ� P �Է� �� �Ͻ������Ѵ�.
                system("pause");
                gotoxy(DEFAULT_X, MAP_SIZE + 6);
                printf("                                            ");
                gotoxy(DEFAULT_X, DEFAULT_Y);
            }

            if (key == 224) {   // ����Ű(��, ��, ��, ��) �Է��� ���� ���.
                key = _getch(); // key�� ������� Ű���� �Է��� �����Ѵ�. 
                if (overlap(savedKey, key) == TRUE) {   // ��->��, ��->��, ��->��, ��->�� ���� ���� ��ȯ �õ� ��
                    key = savedKey; // key�� savedKey�� �����Ѵ�.
                }
                snakeSecond = snake; // snakeSecond�� snake�� ��ǥ�� �����Ѵ�. 
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
        if (drawStartMenu() == FALSE) break; // ����ȭ�鿡�� t �Ǵ� T �Է� �� ���α׷��� �����Ѵ�.
        system("cls");
        stage = drawSpeedMenu(scoreArr);
        system("cls");
        GameStart(map, stage, scoreArr);
        system("pause");
    }
    return 0;
}