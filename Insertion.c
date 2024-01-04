/*
This C program generates an array of random integers, 
sorts the array using the INSERTION sort algorithm, 
and then prints the sorted array along with the elapsed time it took to perform the sorting.
*/

#include <stdio.h>
#include <stdlib.h>                     
#include <time.h>             
#include <unistd.h>    


int main()
{


    double time_spent = 0.0;
 
    clock_t begin = clock();


    int array[1000001];
    int i, j, n, temp;

   
    printf("Enter number of elements in the array \n");
    scanf("%d", &n);
    if(n < 1 || n > 10000000)                     
        exit(1);

    
    srand((unsigned)(time(NULL)));          
    for (i = 0; i < n; i++)                 
        array[i] = rand() %1000001;                

    
    for (i = 1; i < n; i++) {
        j = i;
        while ((j > 0) && (array[j - 1] > array[j])) {
            temp = array[j - 1];
            array[j - 1] = array[j];
            array[j] = temp;
            j--;
        }
    }

    
    printf("Sorted Array\n");
    for (i = 0; i < n; i++)
        printf("%d \n", array[i]);

    
 
    clock_t end = clock();
 
    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("The elapsed time is %f seconds", time_spent);



    return 0;
}