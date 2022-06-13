#pragma once
#define _CRT_SECURE_NO_WARNINGS //scanf, fopen ���� ����� �� Warning C4996 Error�� ���� ����
#include <stdio.h>      // ǥ�� ����� �Լ�.
#include <stdlib.h>     // rand, srand... �� �پ��� �Լ��� ����ִ� ���̺귯��.
#include <conio.h>      // kbhit, getch, putch... �� �ܼ� ����� �Լ�. ����������� �� �� �ִ� ��ǥ�� �Լ��̴�.
#include <Windows.h>    // system, sleep... �� �ܼ�â�� �̿��Ͽ� �����ΰ��� �ϰ� ���� �� ����ϴ� �Լ�.
#include <time.h>       // �ð� ���� �Լ��� ��Ƴ��� ���̺귯��.    
#include <string.h>     // ���ڿ� ���� �Լ��� ��Ƴ��� ���̺귯��.
#include <mysql.h>      // mysql ���� �Լ��� ��Ƴ��� ���̺귯��.

#define DB_HOST "127.0.0.1"		// loopback address -> ���� ��ǻ�� IP�� ����Ŵ.
#define DB_USER "root"			// mysql �̸�
#define DB_PASS "abc123"		// mysql ��й�ȣ
#define DB_NAME "snake_db"		// DB �̸�
#define CHOP(x) x[strlen(x) - 1] = ' '		// strlen(x) - 1 -> ����Ű ��ġ ��, ����Ű�� �������� �ٲ۴�.

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

extern char id[50];     // id�� ���α׷� ��ü���� ��ȿ�ϵ��� extern Ű���� ���.

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
    Node* rear;     // Node->data, next
    Node* front;    // Node->next->data, next
} MyQueue;  // _myqueue�� ��Ī.
typedef MyQueue Queue;  // MyQueue�� ��Ī.

void QueueInit(Queue* pq);
int isEmpty(Queue* pq);
void Enqueue(Queue* pq, SnakePos data);
SnakePos Dequeue(Queue* pq);
SnakePos Peek(Queue* pq);
///////////////////////////////////////////////////////////////////////////


// �Լ� ����
int getKeyDown();           // Ű���尡 �������� ��쿡�� _getch()�� ���� Ű���� �Է��� �޴� �Լ�.
void gotoxy(int, int);      // �ֿܼ����� Ŀ���� �̵��ϴ� �Լ�.
void hidecursor(void);      // �ܼ�â�� Ŀ���� ����� �Լ�.
int drawStartMenu(void);    // ����ȭ���� �׸��� �Լ�.
int drawSpeedMenu(int*);    // �� ���� �޴��� ������ �����ִ� �Լ�.
void stageClear(MData map[MAP_SIZE][MAP_SIZE]);     // map[22][22]�� 0���� �ʱ�ȭ�ϴ� �Լ�.
void stageOneInit(MData map[MAP_SIZE][MAP_SIZE]);   // ù ��° �� -> ���� �𼭸��� 1�� �ʱ�ȭ�ϴ� �Լ�.
void stageTwoInit(MData map[MAP_SIZE][MAP_SIZE]);   // �� ��° �� -> ���� ù ��° ��, ������ ��, 12��° ���� 1�� �ʱ�ȭ�ϴ� �Լ�.
void stageThreeInit(MData map[MAP_SIZE][MAP_SIZE]); // �� ��° �� -> �� �߾ӿ� � ������� 1�� �����ϴ� �Լ�.
void stageFourinit(MData map[MAP_SIZE][MAP_SIZE]);  // �� ��° �� -> �߾��� �ո� X ������� 1�� �����ϴ� �Լ�.
void drawMainMap(MData map[MAP_SIZE][MAP_SIZE]);    // 1�� �ʱ�ȭ�� ��ǥ�� �ฦ ����ϰ� 0���� �ʱ�ȭ�� ��ǥ�� ������ ����ϴ� �Լ�.
void drawSubMap(int, int, int);     // ���� �����ϸ� �ܼ�â �ϴܿ� �ش� ���� ���� �� ������ ����ϴ� �Լ�.                             
int setFruit(MData map[MAP_SIZE][MAP_SIZE], FruitPos*);         // Fruit ���� ��ġ �� ��� ���� �Լ�.
int setBonusFruit(MData map[MAP_SIZE][MAP_SIZE], FruitPos*);    // Fruit �߰� ���� �Լ�.
void setSnake(MData map[MAP_SIZE][MAP_SIZE], int, int);         // �� �Ӹ� ����ϴ� �Լ�.
void setSnakeTail(MData map[MAP_SIZE][MAP_SIZE], int, int);     // �� ���� ����ϴ� �Լ�.
void removeSnake(MData map[MAP_SIZE][MAP_SIZE], int, int);      // ���� ��ġ�� ��ǥ�� ������ ����ϴ� �Լ�.
int rotate(int, int);
int isCollision(int);       // �浹 ���� �˻� �Լ�.
int colWithFruit(SnakePos*, FruitPos*);     // ���� Fruit�� �浹�� ��Ȳ ���� �Լ�.
int colWithWall(MData map[MAP_SIZE][MAP_SIZE], SnakePos* sp, int);  // ���� Wall�� �浹�� ��Ȳ ���� �Լ�.
int colWithTail(MData map[MAP_SIZE][MAP_SIZE], SnakePos* sp, int);  // ���� Tail�� �浹�� ��Ȳ ���� �Լ�.
int moveSnakeHead(MData map[MAP_SIZE][MAP_SIZE], SnakePos*, int);   // ���� �����̰� �浹 ���θ� �˻��ϴ� �Լ�.
int overlap(int, int);      // snake�� ������ ��->��, ��->��, ��->��, ��->�� ���� ��ȯ���� ���ϰ� �ϴ� �Լ�.
void GameOver(int, int, Queue*, int, int*); // GameOver ����. �ְ� ������ �����ϰ� ������ �ۼ��ϸ� ���� ������ ����ϴ� �Լ�.
void GameStart(MData map[MAP_SIZE][MAP_SIZE], int, int*);   // ���� ���� �Լ�.
int login_db(void);     // ȸ�����԰� �α��� ó���� �ϴ� �Լ�.
int ranking_db(int, int, int, int[]);   // ������ ���� ������ ranking ���̺� �Է��ϴ� �Լ�.


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