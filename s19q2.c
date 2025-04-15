#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5 // Maximum size of each queue
#define QUEUE_COUNT 4 // Number of queues// Structure to represent a queue
typedef struct Queue {
int items[MAX_SIZE];
int front;
int rear;
} Queue;
// Function to initialize a queue
void initQueue(Queue* q) {
q->front = -1;
q->rear = -1;
}
// Function to check if the queue is full
int isFull(Queue* q) {
return (q->rear == MAX_SIZE - 1);
}
// Function to check if the queue is empty
int isEmpty(Queue* q) {
return (q->front == -1 || q->front > q->rear);
}
// Function to enqueue an element
void enqueue(Queue* q, int value) {
if (isFull(q)) {
printf("Queue is full!\n");
return;}
if (isEmpty(q)) {
q->front = 0;
}
q->rear++;
q->items[q->rear] = value;
}
// Function to dequeue an element
int dequeue(Queue* q) {
if (isEmpty(q)) {
printf("Queue is empty!\n");
return -1; // Return -1 if the queue is empty
}
int item = q->items[q->front];
q->front++;
return item;
}
// Function to display the current state of the queues
void displayQueues(Queue queues[]) {
for (int i = 0; i < QUEUE_COUNT; i++) {
printf("Queue %d: ", i + 1);
if (isEmpty(&queues[i])) {
printf("Empty\n");
} else {
for (int j = queues[i].front; j <= queues[i].rear; j++) {
printf("%d ", queues[i].items[j]);}
printf("\n");
}
}
}
int main() {
Queue queues[QUEUE_COUNT];
for (int i = 0; i < QUEUE_COUNT; i++) {
initQueue(&queues[i]);
}
int choice, queueNumber, value;
while (1) {
printf("\nMenu:\n");
printf("1. Enqueue\n");
printf("2. Dequeue\n");
printf("3. Display Queues\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter queue number (1-4): ");
scanf("%d", &queueNumber);
if (queueNumber < 1 || queueNumber > 4) {printf("Invalid queue number!\n");
break;
}
printf("Enter value to enqueue: ");
scanf("%d", &value);
enqueue(&queues[queueNumber - 1], value);
break;
case 2:
printf("Enter queue number (1-4): ");
scanf("%d", &queueNumber);
if (queueNumber < 1 || queueNumber > 4) {
printf("Invalid queue number!\n");
break;
}
value = dequeue(&queues[queueNumber - 1]);
if (value != -1) {
printf("Dequeued from Queue %d: %d\n", queueNumber, value);
}
break;
case 3:
displayQueues(queues);
break;
case 4:
exit(0);default:
printf("Invalid choice! Please try again.\n");
}
}
return 0;
}