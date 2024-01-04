#include <stdio.h>
#define SIZE 5

int Q[SIZE];
int qp = 0;

void printQueue(){
    for(int i = 0; i < SIZE; i++)
        printf("%d ", Q[i]);
    printf("\n");
}

int enqueue(int item){
    if(qp>=SIZE){
        printf("Queue is full.\n");
        return -1;
    }
    else{
        Q[qp] = item;
        qp++;
        return 0;
    }
}

void dequeue(){
    if(qp<0){
        printf("Queue is empty.\n");
    }
    else{
        int temp;
        temp = Q[0];
        for(int i = 0; i < SIZE-1; i++)
            Q[i] = Q[i+1];
        qp--;
		printf("%d Dequeued", temp);
    }
}

void reset(){
    qp = 0;
    for(int i = 0; i <= SIZE ; i++)
        Q[i] = 0;
}


int main()
{
    int x, item;
    
    do{
        printQueue();
        printf("1-Enqueue\n2-Dequeue\n3-Reset\n0-Exit\n");
        scanf("%d", &x);
        
        if(x==1){
            printf("Enter number for enqueue :\n");
            scanf("%d", &item);
            enqueue(item);
        }
        if(x==2){
            dequeue();
        }
        if(x==3){
            reset();
        }
        if(x==0)
            return 0;
    }while(x!=0);
    
    return 0;
}
