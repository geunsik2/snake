#pragma once
#define _CRT_SECURE_NO_WARNINGS //scanf, fopen 등을 사용할 때 Warning C4996 Error로 부터 방지
#include <stdio.h>      // 표준 입출력 함수.
#include <stdlib.h>     // rand, srand... 등 다양한 함수가 들어있는 라이브러리.
#include <conio.h>      // kbhit, getch, putch... 등 콘솔 입출력 함수. 윈도우즈에서만 쓸 수 있는 비표준 함수이다.
#include <Windows.h>    // system, sleep... 등 콘솔창을 이용하여 무엇인가를 하고 싶을 때 사용하는 함수.
#include <time.h>       // 시간 관련 함수를 모아놓은 라이브러리.    

#define DEFAULT_X 0     // x 좌표 기본값 --> 0
#define DEFAULT_Y 0     // y 좌표 기본값 --> 0

#define UP 72           // 방향키 ↑의 ASCII Code --> 72
#define LEFT 75         // 방향키 ←의 ASCII Code --> 75
#define RIGHT 77        // 방향키 →의 ASCII Code --> 77
#define DOWN 80         // 방향키 ↓의 ASCII Code --> 80
#define MAP_SIZE 22     // 22를 MAP_SIZE로 정의.

#define WALL 1          // WALL 값 1로 정의.
#define EMPTY 0         // EMPTY를 값 0으로 정의.
#define HEAD 2          // HEAD를 값 2로 정의.     
#define TAIL 3          // TAIL을 값 3으로 정의.
#define FRUIT 5         // FRUIT를 값 5 정의.
#define COLLISION 10    // COLLISION을 값 10으로 정의.

#define TRUE 1          // TRUE를 값 1로 정의.
#define FALSE 0         // FALSE를 값 0으로 정의.

#define NORMAL 10       // NORMAL을 값 10으로 정의.

typedef int MData;		// 자료형 int를 MData로 정의.

typedef struct _fruitxy {       // typedef로 구조체를 정의
    int x;                      // _fruitxy의 멤버변수
    int y;
    int numOfFruit;
} FruitPos;                     // _fruitxy의 별칭.

typedef struct _snakexy {       // typedef로 구조체를 정의
    int x;                      // _snakexy의 멤버변수
    int y;
} SnakePos;                     // _snakexy의 별칭.


// 함수 원형
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
int setBonusFruit(MData map[MAP_SIZE][MAP_SIZE], FruitPos*);    // 선언만 하고 호출은 하지 않음.


//구조체 포인터 선언하기
//struct Person* p1 = malloc(sizeof(struct Person)); // 구조체 포인터 선언, 메모리 할당
//struct 키워드와 구조체 이름을 사용하여 구조체 포인터를 선언합니다.
//이때 일반 변수가 아닌 포인터 변수이므로 반드시* 을 붙입니다.
//그리고 malloc 함수로 메모리를 할당할 때 크기를 알아야 하므로 sizeof(struct Person)과 같이 구조체 크기를 구하여 넣어줍니다.


//화살표 사용
//주의할 점은 구조체 포인터의 멤버에 접근할 때는 -> (화살표 연산자)를 사용해야 한다는 것입니다.
//구조체 포인터에서.으로 멤버에 접근하고자 한다면
//p1->age;      // 화살표 연산자로 멤버에 접근
//(*p1).age;    // 구조체 포인터를 역참조한 뒤 .으로 멤버에 접근
//위 코드처럼 괄호와 역참조를 사용하면 . (점)으로 멤버에 접근할 수 있습니다.