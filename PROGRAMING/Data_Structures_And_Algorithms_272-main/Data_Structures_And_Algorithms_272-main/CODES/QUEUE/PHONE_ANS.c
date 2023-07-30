//Call answering system in mobile
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the structure for the queue
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Function to initialize an empty queue
void initializeQueue(Queue* queue) {
    queue->front = queue->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

// Function to enqueue an element into the queue
void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue an element from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }

    Node* temp = queue->front;
    int data = temp->data;

    queue->front = queue->front->next;
    free(temp);

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return data;
}

int main() {
    Queue queue;
    initializeQueue(&queue);

    // Enqueue phone calls
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);

    // Process phone calls in FIFO order
    while (!isEmpty(&queue)) {
        int callNumber = dequeue(&queue);
        printf("Processing phone call number: %d\n", callNumber);
    }

    return 0;
}

