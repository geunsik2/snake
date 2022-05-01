#pragma once
#define _CRT_SECURE_NO_WARNINGS //scanf, fopen ���� ����� �� Warning C4996 Error�� ���� ����
#include <stdio.h>      // ǥ�� ����� �Լ�.
#include <stdlib.h>     // rand, srand... �� �پ��� �Լ��� ����ִ� ���̺귯��.
#include <conio.h>      // kbhit, getch, putch... �� �ܼ� ����� �Լ�. ����������� �� �� �ִ� ��ǥ�� �Լ��̴�.
#include <Windows.h>    // system, sleep... �� �ܼ�â�� �̿��Ͽ� �����ΰ��� �ϰ� ���� �� ����ϴ� �Լ�.
#include <time.h>       // �ð� ���� �Լ��� ��Ƴ��� ���̺귯��.    

#define DEFAULT_X 0     // x ��ǥ �⺻�� --> 0
#define DEFAULT_Y 0     // y ��ǥ �⺻�� --> 0

#define UP 72           // ����Ű ���� ASCII Code --> 72
#define LEFT 75         // ����Ű ���� ASCII Code --> 75
#define RIGHT 77        // ����Ű ���� ASCII Code --> 77
#define DOWN 80         // ����Ű ���� ASCII Code --> 80
#define MAP_SIZE 22     // 22�� MAP_SIZE�� ����.

#define WALL 1          // WALL �� 1�� ����.
#define EMPTY 0         // EMPTY�� �� 0���� ����.
#define HEAD 2          // HEAD�� �� 2�� ����.     
#define TAIL 3          // TAIL�� �� 3���� ����.
#define FRUIT 5         // FRUIT�� �� 5 ����.
#define COLLISION 10    // COLLISION�� �� 10���� ����.

#define TRUE 1          // TRUE�� �� 1�� ����.
#define FALSE 0         // FALSE�� �� 0���� ����.

#define NORMAL 10       // NORMAL�� �� 10���� ����.

typedef int MData;		// �ڷ��� int�� MData�� ����.

typedef struct _fruitxy {   // typedef�� ����ü�� ����
    int x;                  // _fruitxy�� �������
    int y;
    int numOfFruit;
} FruitPos;                 // _fruitxy�� ��Ī.

typedef struct _snakexy {   // typedef�� ����ü�� ����
    int x;                  // _snakexy�� �������
    int y;
} SnakePos;                 // _snakexy�� ��Ī.


///////////////////////////QUEUE//////////////////////////////////////////
typedef struct _mynode {    // typedef�� ����ü _mynode�� ����
    SnakePos data;  // snake�� ������� x�� y�� ����Ŵ.
    struct _mynode* next;   // snake�� ���� x�� y�� ����Ŵ.
} Node;      // _mynode�� ��Ī.

typedef struct _myqueue {   // typedef�� ����ü _myqueue�� ���� 
    Node* rear;     // Node->data, next ?
    Node* front;    // Node->next->data, next ?
} MyQueue;  // _myqueue�� ��Ī.
typedef MyQueue Queue;  // MyQueue�� ��Ī.

void QueueInit(Queue* pq);
int isEmpty(Queue* pq);
void Enqueue(Queue* pq, SnakePos data);
SnakePos Dequeue(Queue* pq);
SnakePos Peek(Queue* pq);
///////////////////////////////////////////////////////////////////////////


// �Լ� ����
int getKeyDown();
void gotoxy(int, int);
void hidecursor(void);
int drawStartMenu(void);
int drawSpeedMenu(int*);
void stageClear(MData map[MAP_SIZE][MAP_SIZE]);
void stageOneInit(MData map[MAP_SIZE][MAP_SIZE]);
void stageTwoInit(MData map[MAP_SIZE][MAP_SIZE]);
void stageThreeInit(MData map[MAP_SIZE][MAP_SIZE]);
void stageFourinit(MData map[MAP_SIZE][MAP_SIZE]);
void drawMainMap(MData map[MAP_SIZE][MAP_SIZE]);
void drawSubMap(int, int, int);
int setFruit(MData map[MAP_SIZE][MAP_SIZE], FruitPos*);
int setBonusFruit(MData map[MAP_SIZE][MAP_SIZE], FruitPos*);    // ���� �ϰ� ȣ���� ���� ����.
void setSnake(MData map[MAP_SIZE][MAP_SIZE], int, int);
void setSnakeTail(MData map[MAP_SIZE][MAP_SIZE], int, int);
void removeSnake(MData map[MAP_SIZE][MAP_SIZE], int, int);
int rotate(int, int);
int isCollision(int);
int colWithFruit(SnakePos*, FruitPos*);
int colWithWall(MData map[MAP_SIZE][MAP_SIZE], SnakePos* sp, int);
int colWithTail(MData map[MAP_SIZE][MAP_SIZE], SnakePos* sp, int);
int moveSnakeHead(MData map[MAP_SIZE][MAP_SIZE], SnakePos*, int);
int overlap(int, int);
void GameOver(int, int, Queue*, int, int*);
void GameStart(MData map[MAP_SIZE][MAP_SIZE], int, int*);


// ����ü ������ �����ϱ�
// struct Person* p1 = malloc(sizeof(struct Person)); // ����ü ������ ����, �޸� �Ҵ�
// struct Ű����� ����ü �̸��� ����Ͽ� ����ü �����͸� �����Ѵ�.
// �̶� �Ϲ� ������ �ƴ� ������ �����̹Ƿ� �ݵ��* �� ���δ�.
// �׸��� malloc �Լ��� �޸𸮸� �Ҵ��� �� ũ�⸦ �˾ƾ� �ϹǷ� sizeof(struct Person)�� ���� ����ü ũ�⸦ ���Ͽ� �־��ش�.

// ����ü �������� ����� �����ϱ�
// ����ü �������� ����� ������ ���� -> (ȭ��ǥ ������)�� ����ؾ� �Ѵ�.
// ����ü �����Ϳ���.���� ����� �����ϰ��� �Ѵٸ�
// p1->age;      // ȭ��ǥ �����ڷ� ����� ����
// (*p1).age;    // ����ü �����͸� �������� �� .���� ����� ����
// �� �ڵ�ó�� ��ȣ�� �������� ����ϸ� . (��)���� ����� ������ �� �ִ�.