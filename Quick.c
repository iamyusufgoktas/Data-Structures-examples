/*
This C program generates an array of random integers, 
sorts the array using the QUICK sort algorithm, 
and then prints the sorted array along with the elapsed time it took to perform the sorting.
*/

#include<stdio.h>
#include <stdlib.h>                    
#include <time.h>                       


void quicksort(int number[25],int first,int last){

int i, j, pivot, temp;

if(first<last){

pivot=first;

i=first;

j=last;

while(i<j){

while(number[i]<=number[pivot]&&i<last)

i++;

while(number[j]>number[pivot])

j--;

if(i<j){

temp=number[i];

number[i]=number[j];

number[j]=temp;

}

}

temp=number[pivot];

number[pivot]=number[j];

number[j]=temp;

quicksort(number,first,j-1);

quicksort(number,j+1,last);

}

}

int main(){

double time_spent = 0.0;
 
clock_t begin = clock();

int i, count, number[1000001];

printf("Enter number of elements in the array \n");
    scanf("%d", &count);
    if(count < 1 || count > 1000001)                     
        exit(1);

    srand((unsigned)(time(NULL)));          
    for (i = 0; i < count; i++)                 
        number[i] = rand() %1000001;  

quicksort(number,0,count-1);

printf("The Sorted Order is: ");

for(i=0;i<count;i++)

printf(" %d\n",number[i]);
 
    clock_t end = clock();
 
    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("The elapsed time is %f seconds", time_spent);

return 0;

}
