#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct queue{
    int front;
    int rear;
    int * arr;
    int size;
    int count;
} queue;

queue * createIntegerQueue(int queueSize){
    queue * q;
    q = (queue*)malloc(sizeof(queue));
    q->arr = (int *)malloc(sizeof(int) * (queueSize));
    if(q->arr == NULL){
        printf("Queue creation fails\n");
        return NULL;
    }
    q->front = 0;
    q->rear = 0;
    q->size = queueSize;
    q->count = 0;
    return q;
}

int enqueueInteger(queue * q, int d){
    if( q->count == q->size || (q->rear + 1) % q->size == q->front){
        return 0;
    }
    q->arr[q->rear] = d;
    q->rear = (q->rear+1)%q->size;
    q->count++;
    return 1;
}

int dequeueInteger(queue * q, int *dp){
    if( q->count == 0 || q->front == q->rear){
        return 0;
    }
    *dp = q->arr[q->front];
    q->front = (q->front+1)%q->size;
    q->count--;
    return 1;
}

int freeIntegerQueue(queue ** q){
    if (q == NULL || *q == NULL) return 0;
    free((*q)->arr);
    free(*q);
    *q = NULL;
    return 1;
}

int isIntegerQueueFull(queue * q){
    if(q->count == q->size || (q->rear + 1) % q->size == q->front){
        return 1;
    }
    else return 0;
}

int isIntegerQueueEmpty(queue * q){
    if(q->count == 0 ||q->front == q->rear){
        return 1;
    }
    else return 0;
}

void displayIntegerQueue(queue * q){
    if(isIntegerQueueEmpty(q)){
        printf("Queue is empty\n");
        return;
    }
    int i = q->front;
    printf("Queue elements: ");
    while(i != q->rear){
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->size;
    }
}

int main()
{   printf("which question you want to run ? \n");
    printf("1. Question 1 : Integer Queue \n2. Question 2 : rvalue \n");
    int ques;
    scanf("%d",&ques);
    if(ques == 1){
        printf("Question 1 : Integer Queue \n");    
    queue * q;
    int s;
    printf("Enter queue size: ");
    scanf("%d",&s);
    q = createIntegerQueue(s+1);
    
    int ch ;
    while(1){
         printf("what you want to do ? \n");
    printf("0. Enque all the elements \n1. Enqueue\n2. Dequeue\n3. isEmpty\n4. isFull\n5. Free Queue\n6. display queue\n7. Exit\n");
        scanf("%d",&ch);
        int d;
        switch(ch){
            case 0 : printf("enter all the elements of queue : \n");
                     while(!isIntegerQueueFull(q)){
                        int temp;
                        scanf("%d",&temp);
                        enqueueInteger(q , temp);
                     }
                     break;
            case 1 : printf("Enter the element to be enqueue : \n");
                     scanf("%d", &d);
                     if(enqueueInteger(q , d)){
                        printf("enqueued successfully\n");
                     }else{
                        printf("unsuccessfull\n");
                     }
                     break;

            case 2 : if(isIntegerQueueEmpty(q)){
                        printf("queue is empty\n");
                        break;
                     }
                     if(dequeueInteger(q , &d)){
                        printf("element dequeue successfully\n");
                        printf("element dequeue is : %d\n" ,d);
                     }
                     else{
                        printf("operation unsuccessfull\n");
                     }
                     break;

            case 3 : if(isIntegerQueueEmpty(q)){
                        printf("queue is empty\n");
                     }else{
                        printf("queue is not empty\n");
                     }
                     break;

            case 4 : if(isIntegerQueueFull(q)){
                        printf("queue is full\n");
                     }else{
                        printf("queue is not full\n");
                     }
                     break;

            case 5 : if(freeIntegerQueue(&q)){
                        printf("Queue is Emptied\n");
                        printf("Exiting...\n");
                        return 0;
                     }

            case 6 : displayIntegerQueue(q);
                        break;
            case 7 : printf("program ended successfully\n");
                     return 0;
            default : 
            printf("invalid choice\n");
        }     
    }
}

//Question 2: random value
else if(ques == 2){
    printf("Question 2 : random value \n");  
    queue * q2;
    printf("Enter queue size: ");
    int size;
    scanf("%d",&size);
    q2 = createIntegerQueue(size+1);
    while(!isIntegerQueueFull(q2)){
        
        int temp;
        scanf("%d",&temp);
        enqueueInteger(q2,temp);
    }
    int rval = rand()%10;
    printf("Random Value Generated: %d\n",rval);

    int i=1;
    while(!isIntegerQueueEmpty(q2)){
        int qElement;
        dequeueInteger(q2,&qElement);
        if((qElement - rval) > 0){
            qElement -= rval;
            enqueueInteger(q2,qElement);
        }
        else{
            printf("Popped Element no. %d : %d\n",i,qElement);
            i++;
        }
    }
}

else{
    printf("Invalid Question Number\n");
}
return 0;
}