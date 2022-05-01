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

typedef struct _fruitxy {       // typedef�� ����ü�� ����
    int x;                      // _fruitxy�� �������
    int y;
    int numOfFruit;
} FruitPos;                     // _fruitxy�� ��Ī.

typedef struct _snakexy {       // typedef�� ����ü�� ����
    int x;                      // _snakexy�� �������
    int y;
} SnakePos;                     // _snakexy�� ��Ī.


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


//����ü ������ �����ϱ�
//struct Person* p1 = malloc(sizeof(struct Person)); // ����ü ������ ����, �޸� �Ҵ�
//struct Ű����� ����ü �̸��� ����Ͽ� ����ü �����͸� �����մϴ�.
//�̶� �Ϲ� ������ �ƴ� ������ �����̹Ƿ� �ݵ��* �� ���Դϴ�.
//�׸��� malloc �Լ��� �޸𸮸� �Ҵ��� �� ũ�⸦ �˾ƾ� �ϹǷ� sizeof(struct Person)�� ���� ����ü ũ�⸦ ���Ͽ� �־��ݴϴ�.


//ȭ��ǥ ���
//������ ���� ����ü �������� ����� ������ ���� -> (ȭ��ǥ ������)�� ����ؾ� �Ѵٴ� ���Դϴ�.
//����ü �����Ϳ���.���� ����� �����ϰ��� �Ѵٸ�
//p1->age;      // ȭ��ǥ �����ڷ� ����� ����
//(*p1).age;    // ����ü �����͸� �������� �� .���� ����� ����
//�� �ڵ�ó�� ��ȣ�� �������� ����ϸ� . (��)���� ����� ������ �� �ֽ��ϴ�.