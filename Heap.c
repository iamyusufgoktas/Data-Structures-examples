/*
This C program generates an array of random integers, 
sorts the array using the HEAP sort algorithm, 
and then prints the sorted array along with the elapsed time it took to perform the sorting.
*/


#include <stdio.h>
#include <stdlib.h>                    
#include <time.h>                       

  int main()
  {

double time_spent = 0.0;
 
clock_t begin = clock();


  int arr[1000001], no,  i, j, c, heap_root, temp;
  printf("Enter number of elements in the array \n");
    scanf("%d", &no);
    if(no < 1 || no > 1000001)                     
        exit(1);

    srand((unsigned)(time(NULL)));          
    for (i = 0; i < no; i++)                 
        arr[i] = rand() %1000001;    {
  c = i;
  do
  {
  heap_root  = (c - 1) / 2;
  if  (arr[heap_root] < arr[c])
  {
  temp =  arr[heap_root];
  arr[heap_root] = arr[c];
  arr[c]  = temp;
  }
  c =  heap_root;
  } while (c !=  0);
  }
  
  printf("Heap  array : ");
  for (i = 0; i <  no; i++)
  printf("%d\t ", arr[i]);
  for (j = no - 1; j  >= 0; j--)
  {
  temp = arr[0];
  arr[0] = arr[j];
  arr[j] = temp;
  heap_root = 0;
  do
  {
  c = 2 *  heap_root + 1;
  if  ((arr[c] < arr[c + 1]) && c < j-1)
  c++;
  if  (arr[heap_root]<arr[c] && c<j)
  {
  temp =  arr[heap_root];
  arr[heap_root] = arr[c];
  arr[c]  = temp;
  }
  heap_root  = c;
  } while (c  < j);
  } 
  printf("\nSorted  array : ");
  for (i = 0; i <  no; i++)
  printf("\t%d", arr[i]);
  printf("\n");
  
 
    clock_t end = clock();
 
    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("The elapsed time is %f seconds", time_spent);

  return 0;
  }

