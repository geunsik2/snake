#include "a.h"

void GameStart(MData map[MAP_SIZE][MAP_SIZE], int stage, int* scoreArr) {   // ���� ���� �Լ�.
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

        if (_kbhit()) { // Ű���� �Է��� ���� �� ���ǹ��� �����Ѵ�.
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
                savedKey = moveSnakeHead(map, &snake, key); // snake�� Wall �Ǵ� Tail�� �浹 �� savedKey�� 10�� �����ϰ�
                                                            // �浹���� �ʾ��� �� key���� savedKey�� �����Ѵ�.
                Enqueue(&queue, snakeSecond);
                setSnakeTail(map, snakeSecond.x, snakeSecond.y);    // Ŀ���� snakeSecond�� ��ġ�� (x, y) ��ǥ�� �̵��ϰ�
                                                                    // �� ����Ѵ�.
                                                                    // map[snakeSecond.x][snakeSecond.y]�� 3�� �����Ѵ�.
                if (time == TRUE) { // time�� TRUE�� ���
                    snakeTail = Dequeue(&queue);
                    removeSnake(map, snakeTail.x, snakeTail.y); // snakeTail�� ��ġ�� ��ǥ�� ������ ����Ѵ�.
                }
                else {  // snake�� fruit�� �浹�� ��� time�� TRUE�� �ʱ�ȭ�Ѵ�.
                    time = TRUE;
                }
                if (isCollision(savedKey)) {    // savedKey�� Collision(10)�� ���
                                                // �ְ� ������ �����ϰ� ������ �ۼ��ϸ�, ���� ������ ����Ѵ�.
                    GameOver(score, best, &queue, stage, scoreArr);
                    return;
                }
            }
        }
        else {  // Ű���� �Է��� ���� �� ���ǹ� ����.
            snakeSecond = snake;    // snakeSecond�� snake�� ��ǥ�� �����Ѵ�.
            savedKey = moveSnakeHead(map, &snake, savedKey);    // snake�� Wall �Ǵ� Tail�� �浹 �� savedKey�� 10�� �����ϰ�
                                                                // �浹���� �ʾ��� �� key���� savedKey�� �����Ѵ�.
            Enqueue(&queue, snakeSecond);
            setSnakeTail(map, snakeSecond.x, snakeSecond.y);    // Ŀ���� snakeSecond�� ��ġ�� (x, y) ��ǥ�� �̵��ϰ�
                                                                // �� ����Ѵ�.
                                                                // map[snakeSecond.x][snakeSecond.y]�� 3�� �����Ѵ�.
            if (time == TRUE) { // time�� TRUE�� ���
                snakeTail = Dequeue(&queue);
                removeSnake(map, snakeTail.x, snakeTail.y); // snakeTail�� ��ġ�� ��ǥ�� ������ ����Ѵ�.
            }
            else {
                time = TRUE;    // snake�� fruit�� �浹�� ��� time�� TRUE�� �ʱ�ȭ�Ѵ�.
            }
            if (isCollision(savedKey)) {    // savedKey�� Collision(10)�� ���
                                            // �ְ� ������ �����ϰ� ������ �ۼ��ϸ�, ���� ������ ����Ѵ�.
                GameOver(score, best, &queue, stage, scoreArr);
                return;
            }
        }
    }
}