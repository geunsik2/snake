#include "a.h"

void QueueInit(Queue* pq) { // snakePos의 멤버변수 x, y를 NULL로 초기화.
    pq->rear = NULL;    // pq->rear를 NULL로 초기화.
    pq->front = NULL;   // pq->front를 NULL로 초기화.
}
int isEmpty(Queue* pq) {    // 다음으로 생성할 구조체가 NULL인 경우 1을 리턴하고 아닌 경우 0을 리턴한다. ?
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