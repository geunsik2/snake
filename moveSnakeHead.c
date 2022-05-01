#include "a.h"

//get snake x, y and move snake
int moveSnakeHead(MData map[MAP_SIZE][MAP_SIZE], SnakePos* snake, int way) {    // snake�� �����̰� �浹 ���θ� �˻��Ѵ�.
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