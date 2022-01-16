#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  #define MAXJOBS 100

  struct job {
        char name[100];
        int G, Marks, order;
  };

  struct pQueue {
        struct job node[MAXJOBS];
        int front, rear;
  };

  int jobCount = 0;

  /* enqeue operation */
  void enqueue(struct pQueue *pq, struct job myJob) {
        struct job temp;
        int i, j;

        if (pq->front == MAXJOBS - 1) {
                printf("Enqueue operation failed - PQ is full\n");
                return;
        } else if (pq->front == -1) {
                pq->front = 0;
        }
        pq->rear++;
        pq->node[pq->rear] = myJob;
        for (i = pq->front; i < pq->rear; i++) {
                for (j = i + 1; j <= pq->rear; j++) {
                        /* place the node with high Marks at the front */
                        if (pq->node[i].Marks < pq->node[j].Marks) {
                                temp = pq->node[i];
                                pq->node[i] = pq->node[j];
                                pq->node[j] = temp;
                        } else  if (pq->node[i].Marks ==
                                        pq->node[j].Marks) {
                                /*
                                 * if both elements have same Marks, then the
                                 * element with lesser order is processed first
                                 */
                                if (pq->node[i].order > pq->node[j].order) {
                                        temp = pq->node[i];
                                        pq->node[i] = pq->node[j];
                                        pq->node[j] = temp;
                                }
                        }
                }
        }
        return;
  }

  /* dequeue operation */
  void dequeue(struct pQueue *pq) {
        if (pq->front == -1) {
                printf("Priority Queue underflow\n");
                return;
        }

        if (pq->front == pq->rear) {
                pq->front = pq->rear = -1;
        } else {
                printf("Dequeued Data:\n");
                printf("Job Name : %s\n", pq->node[pq->front].name);
                printf("Job ID   : %d\n", pq->node[pq->front].G);
                printf("Marks : %d\n", pq->node[pq->front].Marks);
                printf("Order    : %d\n", pq->node[pq->front].order);
                pq->front++;
        }
        return;
  }

  /* dump the contents of the queue */
  void dumpQueue(struct pQueue *pq) {
        int i;
        if (pq->front == -1) {
                printf("Priority Queue Underflow\n");
                return;
        }

        printf("Job Name    G  Priority  Order\n");
        printf("-------------------------------------\n");
        for (i = pq->front; i <= pq->rear; i++) {
                printf("%8s%5d%9d%5d\n", pq->node[i].name, pq->node[i].G,
                        pq->node[i].Marks, pq->node[i].order);
        }
        return;
  }

  int main() {
        struct pQueue pq;
        struct job myJob;
        int i, ch, order = 0;

        memset(&pq, 0, sizeof (struct pQueue));
        pq.front = pq.rear = -1;
        while (1) {
                printf("1. Add new Name(Enqueue)\n");
                printf("2. Dequeue\n3. Dump Queue\n");
                printf("4. Exit\nEnter your choice:");
                scanf("%d", &ch);
                switch (ch) {
                        case 1:
                                getchar();
                                printf("Enter the name:");
                                fgets(myJob.name, 100, stdin);
                                myJob.name[strlen(myJob.name) - 1] = '\0';
                                printf("Job ID: ");
                                scanf("%d", &myJob.G);
                                printf("Marks: ");
                                scanf("%d", &myJob.Marks);
                                myJob.order = order++;
                                enqueue(&pq, myJob);
                                break;

                        case 2:
                                dequeue(&pq);
                                break;

                        case 3:
                                dumpQueue(&pq);
                                break;

                        case 4:
                                exit(0);
                        default:

                                printf("U have entered wrong option!!\n");

                                break;
                }
        }
        return 0;
  }
