//
// Created by l1460 on 24-4-11.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// ����˳��ջ�ṹ
typedef struct {
    int data[MAX_SIZE];
    int top;
} SeqStack;

// ��ʼ��ջ
void initStack(SeqStack *stack) {
    stack->top = -1;
}

// �ж�ջ�Ƿ�Ϊ��
int isEmpty(SeqStack *stack) {
    return stack->top == -1;
}

// �ж�ջ�Ƿ�����
int isFull(SeqStack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// ��ջ
void push(SeqStack *stack, int item) {
    if (isFull(stack)) {
        printf("ջ�������޷���ջ\n");
        return;
    }
    stack->data[++stack->top] = item;
}

// ��ջ
int pop(SeqStack *stack) {
    if (isEmpty(stack)) {
        printf("ջΪ�գ��޷���ջ\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--];
}

// ��ȡջ��Ԫ��
int peek(SeqStack *stack) {
    if (isEmpty(stack)) {
        printf("ջΪ��\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top];
}

// ģ����Ϸ����
void simulateGame(int N, int m, int n) {
    SeqStack stack;
    initStack(&stack);

    // ��ʼ��������Ϸ����Ա���
    for (int i = N; i >= 1; --i) {
        push(&stack, i);
    }

    srand((unsigned int)time(NULL)); // �������

    int start = rand() % N + 1; // ������ɿ�ʼ���������
    int count = 1; // ������
    int eliminated = 0; // ��¼�Ѿ���Ȧ������

    printf("��ʼ��Ϸ��\n");
    while (eliminated < n) {
        int person = pop(&stack); // ��ջ

        // ����ǿ�ʼ�������˻����Ѿ�������m�����Ȧ
        if (count == m || person == start) {
            printf("��%d����Ȧ�����ǣ�%d\n", eliminated + 1, person);
            eliminated++;
            count = 1; // ���ü�����
        } else {
            push(&stack, person); // ��ջ
            count++;
        }
    }
}

int main() {
    int N, m, n;

    printf("������������ N: ");
    scanf("%d", &N);

    printf("�����뱨�������� m: ");
    scanf("%d", &m);

    printf("������Ҫ��Ȧ������ n (n <= N): ");
    scanf("%d", &n);

    simulateGame(N, m, n);

    return 0;
}