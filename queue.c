#include "a.h"

void QueueInit(Queue* pq) { // snakePos�� ������� x, y�� NULL�� �ʱ�ȭ.
    pq->rear = NULL;    // pq->rear�� NULL�� �ʱ�ȭ.
    pq->front = NULL;   // pq->front�� NULL�� �ʱ�ȭ.
}
int isEmpty(Queue* pq) {    // �������� ������ ����ü�� NULL�� ��� 1�� �����ϰ� �ƴ� ��� 0�� �����Ѵ�. ?
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