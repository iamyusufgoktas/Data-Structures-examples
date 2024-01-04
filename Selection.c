/*
This C program generates an array of random integers, 
sorts the array using the SELECTION sort algorithm, 
and then prints the sorted array along with the elapsed time it took to perform the sorting.
*/


#include <stdio.h>
#include <stdlib.h>                    
#include <time.h>                       

int main()
{
    double time_spent = 0.0;
 
    clock_t begin = clock();

  int array2[1000001], a, c, d, position, t;

    printf("Enter number of elements in the array \n");
    scanf("%d", &a);
    if(a < 1 || a > 1000001)                     
        exit(1);

    srand((unsigned)(time(NULL)));          
    for (c = 0; c < a; c++)                 
        array2[c] = rand() %1000001;                

  for (c = 0; c < (a - 1); c++) 
  {
    position = c;

    for (d = c + 1; d < a; d++)
    {
      if (array2[position] > array2[d])
        position = d;
    }
    if (position != c)
    {
      t = array2[c];
      array2[c] = array2[position];
      array2[position] = t;
    }
  }

  printf("Sorted list in ascending order:\n");

  for (c = 0; c < a; c++)
    printf("%d\n", array2[c]);

 
  clock_t end = clock();
 
  // calculate elapsed time by finding difference (end - begin) and
  // dividing the difference by CLOCKS_PER_SEC to convert to seconds
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
  printf("The elapsed time is %f seconds", time_spent);

  return 0;
}

