#include <stdio.h>

#define N 10

int S[N];
int sp = 0;

int push(int item){
    if(sp >= N){
        printf("Stack is full.\n");
        return -1;
    }
    else {
        S[sp] = item;
        sp++;
        return 0;
    }
}

int pop(){
    if(sp <= 0){
        printf("Stack is empty.\n");
        return -1;
    }
    else{
        sp--;
        return S[sp];
    }
}

void reset(){
    sp = 0;
}

int top(){
    return (sp - 1);
}

int size(){
    return sp;
}

int isEmpty(){
    if (sp == 0)
        return 1;
    else
        return 0;
}

void printArray(){
    for(int i = 0; i < N; i++){
        printf("%d, ", S[i]);
    }
    printf("\n");
}

int main(){
    int x, item;
    
    do{
        printf("1 - Push\n2 - Pop\n3 - Reset\n4 - Top\n5 - Size\n6 - isEmpty\n\n0 - Exit\n");
        scanf("%d", &x);
        if(x == 1){
            printf("Enter number for push :");
            scanf("%d", &item);
            push(item);
        }
        else if(x == 2){
            if(pop() != -1)
                printf("Removed item : %d\n", pop());
        }
        else if(x == 3){
            reset();
            printf("Stack reseted.");
        }
        else if(x == 4)
            printf("Last item's index is : %d\n", top());
        else if(x == 5)
            printf("Stack's size is : %d\n", size());
        else if(x == 6)
            if(isEmpty() == 1)
                printf("Stack is empty!\n");
            else
                printf("Stack is not empty!\n");
        printArray();
    }while(x != 0);
    

    return 0;
}