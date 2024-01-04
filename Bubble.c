/*
This C program generates an array of random integers, 
sorts the array using the BUBBLE sort algorithm, 
and then prints the sorted array along with the elapsed time it took to perform the sorting.
*/

#include <stdio.h>
#include <stdlib.h>                    
#include <time.h>                       

int main()
{

  double time_spent = 0.0;
 
  clock_t begin = clock();

  int array3[1000001], b, x, f, swap;

    printf("Enter number of elements in the array \n");
    scanf("%d", &b);
    if(b< 1 || b> 1000001)                     
        exit(1);

    srand((unsigned)(time(NULL)));          
    for (x = 0; x < b; x++)                 
        array3[x] = rand() %1000001;  
  for (x = 0 ; x < b- 1; x++)
  {
    for (f = 0 ; f < b- x - 1; f++)
    {
      if (array3[f] > array3[f+1]) 
      {
        swap       = array3[f];
        array3[f]   = array3[f+1];
        array3[f+1] = swap;
      }
    }
  }

  printf("Sorted list in ascending order:\n");

  for (x = 0; x < b; x++)
     printf("%d\n", array3[x]);
 
    clock_t end = clock();
 
    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("The elapsed time is %f seconds", time_spent);   

  return 0;
}