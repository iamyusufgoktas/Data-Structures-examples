#include <stdio.h>
#include <stdlib.h>                     
#include <time.h>                      

int insertion();
int selection();
int bubble();
void merge_sort();
void quicksort();
int heap();


int main()
{
    int algorithm;

    printf("\n 1-Insertion sort");
    printf("\n 2-Selection sort");
    printf("\n 3-Bubble sort");
    printf("\n 4-Mergesort");
    printf("\n 5-Quicksort");
    printf("\n 6-Heap sort");

    printf("\nChoose the algorithm you want:");
    scanf("%d",&algorithm);

    switch (algorithm)
    {
    case 1:
        insertion();
        break;
    case 2:
       selection();
       break;
    case 3:
       bubble();   
       break;   
    case 6:
       heap();  
    default: printf("Please select a defined algorithm");
        break;
    }

    return 0;
}









int insertion() {
                   
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
}












int selection() {
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

}










int bubble() {
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
}











int heap() {
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
  }