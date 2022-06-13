#pragma once
#define _CRT_SECURE_NO_WARNINGS //scanf, fopen 등을 사용할 때 Warning C4996 Error로 부터 방지
#include <stdio.h>      // 표준 입출력 함수.
#include <stdlib.h>     // rand, srand... 등 다양한 함수가 들어있는 라이브러리.
#include <conio.h>      // kbhit, getch, putch... 등 콘솔 입출력 함수. 윈도우즈에서만 쓸 수 있는 비표준 함수이다.
#include <Windows.h>    // system, sleep... 등 콘솔창을 이용하여 무엇인가를 하고 싶을 때 사용하는 함수.
#include <time.h>       // 시간 관련 함수를 모아놓은 라이브러리.    
#include <string.h>     // 문자열 관련 함수를 모아놓은 라이브러리.
#include <mysql.h>      // mysql 관련 함수를 모아놓은 라이브러리.

#define DB_HOST "127.0.0.1"		// loopback address -> 본인 컴퓨터 IP를 가리킴.
#define DB_USER "root"			// mysql 이름
#define DB_PASS "abc123"		// mysql 비밀번호
#define DB_NAME "snake_db"		// DB 이름
#define CHOP(x) x[strlen(x) - 1] = ' '		// strlen(x) - 1 -> 엔터키 위치 즉, 엔터키를 공백으로 바꾼다.

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

extern char id[50];     // id가 프로그램 전체에서 유효하도록 extern 키워드 사용.

typedef int MData;		// 자료형 int를 MData로 정의.

typedef struct _fruitxy {   // typedef로 구조체를 정의
    int x;                  // _fruitxy의 멤버변수
    int y;
    int numOfFruit;
} FruitPos;                 // _fruitxy의 별칭.

typedef struct _snakexy {   // typedef로 구조체를 정의
    int x;                  // _snakexy의 멤버변수
    int y;
} SnakePos;                 // _snakexy의 별칭.


///////////////////////////QUEUE//////////////////////////////////////////
typedef struct _mynode {    // typedef로 구조체 _mynode를 정의
    SnakePos data;  // snake의 멤버변수 x와 y를 가리킴.
    struct _mynode* next;   // snake의 다음 x와 y를 가리킴.
} Node;      // _mynode의 별칭.

typedef struct _myqueue {   // typedef로 구조체 _myqueue를 정의 
    Node* rear;     // Node->data, next
    Node* front;    // Node->next->data, next
} MyQueue;  // _myqueue의 별칭.
typedef MyQueue Queue;  // MyQueue의 별칭.

void QueueInit(Queue* pq);
int isEmpty(Queue* pq);
void Enqueue(Queue* pq, SnakePos data);
SnakePos Dequeue(Queue* pq);
SnakePos Peek(Queue* pq);
///////////////////////////////////////////////////////////////////////////


// 함수 원형
int getKeyDown();           // 키보드가 눌려있을 경우에만 _getch()를 통해 키보드 입력을 받는 함수.
void gotoxy(int, int);      // 콘솔에서의 커서를 이동하는 함수.
void hidecursor(void);      // 콘솔창의 커서를 숨기는 함수.
int drawStartMenu(void);    // 메인화면을 그리는 함수.
int drawSpeedMenu(int*);    // 맵 선택 메뉴와 점수를 보여주는 함수.
void stageClear(MData map[MAP_SIZE][MAP_SIZE]);     // map[22][22]을 0으로 초기화하는 함수.
void stageOneInit(MData map[MAP_SIZE][MAP_SIZE]);   // 첫 번째 맵 -> 맵의 모서리를 1로 초기화하는 함수.
void stageTwoInit(MData map[MAP_SIZE][MAP_SIZE]);   // 두 번째 맵 -> 맵의 첫 번째 행, 마지막 행, 12번째 열을 1로 초기화하는 함수.
void stageThreeInit(MData map[MAP_SIZE][MAP_SIZE]); // 세 번째 맵 -> 맵 중앙에 十 모양으로 1을 대입하는 함수.
void stageFourinit(MData map[MAP_SIZE][MAP_SIZE]);  // 네 번째 맵 -> 중앙이 뚫린 X 모양으로 1을 대입하는 함수.
void drawMainMap(MData map[MAP_SIZE][MAP_SIZE]);    // 1로 초기화된 좌표에 □를 출력하고 0으로 초기화된 좌표에 공백을 출력하는 함수.
void drawSubMap(int, int, int);     // 맵을 선택하면 콘솔창 하단에 해당 맵의 점수 및 도움말을 출력하는 함수.                             
int setFruit(MData map[MAP_SIZE][MAP_SIZE], FruitPos*);         // Fruit 생성 위치 및 모양 설정 함수.
int setBonusFruit(MData map[MAP_SIZE][MAP_SIZE], FruitPos*);    // Fruit 추가 생성 함수.
void setSnake(MData map[MAP_SIZE][MAP_SIZE], int, int);         // 뱀 머리 출력하는 함수.
void setSnakeTail(MData map[MAP_SIZE][MAP_SIZE], int, int);     // 뱀 꼬리 출력하는 함수.
void removeSnake(MData map[MAP_SIZE][MAP_SIZE], int, int);      // 뱀이 위치한 좌표에 공백을 출력하는 함수.
int rotate(int, int);
int isCollision(int);       // 충돌 여부 검사 함수.
int colWithFruit(SnakePos*, FruitPos*);     // 뱀이 Fruit와 충돌한 상황 설정 함수.
int colWithWall(MData map[MAP_SIZE][MAP_SIZE], SnakePos* sp, int);  // 뱀이 Wall과 충돌한 상황 설정 함수.
int colWithTail(MData map[MAP_SIZE][MAP_SIZE], SnakePos* sp, int);  // 뱀이 Tail과 충돌한 상황 설정 함수.
int moveSnakeHead(MData map[MAP_SIZE][MAP_SIZE], SnakePos*, int);   // 뱀을 움직이고 충돌 여부를 검사하는 함수.
int overlap(int, int);      // snake의 방향을 좌->우, 우->좌, 상->하, 하->상 으로 전환하지 못하게 하는 함수.
void GameOver(int, int, Queue*, int, int*); // GameOver 설정. 최고 점수를 갱신하고 파일을 작성하며 현재 점수를 출력하는 함수.
void GameStart(MData map[MAP_SIZE][MAP_SIZE], int, int*);   // 게임 시작 함수.
int login_db(void);     // 회원가입과 로그인 처리를 하는 함수.
int ranking_db(int, int, int, int[]);   // 유저의 점수 정보를 ranking 테이블에 입력하는 함수.


// 구조체 포인터 선언하기
// struct Person* p1 = malloc(sizeof(struct Person)); // 구조체 포인터 선언, 메모리 할당
// struct 키워드와 구조체 이름을 사용하여 구조체 포인터를 선언한다.
// 이때 일반 변수가 아닌 포인터 변수이므로 반드시* 을 붙인다.
// 그리고 malloc 함수로 메모리를 할당할 때 크기를 알아야 하므로 sizeof(struct Person)과 같이 구조체 크기를 구하여 넣어준다.

// 구조체 포인터의 멤버에 접근하기
// 구조체 포인터의 멤버에 접근할 때는 -> (화살표 연산자)를 사용해야 한다.
// 구조체 포인터에서.으로 멤버에 접근하고자 한다면
// p1->age;      // 화살표 연산자로 멤버에 접근
// (*p1).age;    // 구조체 포인터를 역참조한 뒤 .으로 멤버에 접근
// 위 코드처럼 괄호와 역참조를 사용하면 . (점)으로 멤버에 접근할 수 있다.