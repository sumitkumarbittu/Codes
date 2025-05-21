#include <stdio.h>
#define MAX 100

void enqueue(int *queue, int *rear, int value)
{
    if (*rear == MAX - 1)
    printf("Queue is Full!\n");
    else
    queue[++(*rear)] = value;
}

int dequeue(int *queue, int *front, int *rear)
{
    if (*front > *rear)
    {
        printf("Queue is Empty!\n");
        return -1;
    }
    else
    return queue[(*front)++];
}

void push(int *queue, int *front, int *rear, int value)
{
    enqueue(queue, rear, value);
    int size = *rear - *front + 1;

    for (int i = 0; i < size - 1; i++)
    {
        int temp = dequeue(queue, front, rear);
        enqueue(queue, rear, temp);
    }
}

int pop(int *queue, int *front, int *rear)
{
    return dequeue(queue, front, rear);
}

int isStackEmpty(int *front, int *rear)
{
    return *front > *rear;
}

int top(int *queue, int *front)
{
    if (isStackEmpty(front, queue + MAX - 1))
    {
        printf("Stack is Empty!\n");
        return -1;
    }
    return queue[*front];
}

int main()
{
    int queue[MAX];
    int front = 0, rear = -1;

    push(queue, &front, &rear, 10);
    push(queue, &front, &rear, 20);
    push(queue, &front, &rear, 30);

    printf("Top element is %d\n", top(queue, &front));
    printf("Popped element is %d\n", pop(queue, &front, &rear));
    printf("Top element is %d\n", top(queue, &front));

    push(queue, &front, &rear, 40);
    printf("Top element is %d\n", top(queue, &front));
    printf("Popped element is %d\n", pop(queue, &front, &rear));

    return 0;
}