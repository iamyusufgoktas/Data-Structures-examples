/*
This C program generates an array of random integers, 
sorts the array using the MERGE sort algorithm, 
and then prints the sorted array along with the elapsed time it took to perform the sorting.
*/

#include <stdio.h>
#include <stdlib.h>                    
#include <time.h>                       

 
// function to sort the subsection a[i .. j] of the array a[]
void merge_sort(int z, int j, int a[], int aux[]) {
    if (j <= z) {
        return;     // the subsection is empty or a single element
    }
    int mid = (z + j) / 2;

    // left sub-array is a[i .. mid]
    // right sub-array is a[mid + 1 .. j]
    
    merge_sort(z, mid, a, aux);     // sort the left sub-array recursively
    merge_sort(mid + 1, j, a, aux);     // sort the right sub-array recursively

    int pointer_left = z;       // pointer_left points to the beginning of the left sub-array
    int pointer_right = mid + 1;        // pointer_right points to the beginning of the right sub-array
    int k;      // k is the loop counter

    // we loop from i to j to fill each element of the final merged array
    for (k = z; k <= j; k++) {
        if (pointer_left == mid + 1) {      // left pointer has reached the limit
            aux[k] = a[pointer_right];
            pointer_right++;
        } else if (pointer_right == j + 1) {        // right pointer has reached the limit
            aux[k] = a[pointer_left];
            pointer_left++;
        } else if (a[pointer_left] < a[pointer_right]) {        // pointer left points to smaller element
            aux[k] = a[pointer_left];
            pointer_left++;
        } else {        // pointer right points to smaller element
            aux[k] = a[pointer_right];
            pointer_right++;
        }
    }

    for (k = z; k <= j; k++) {      // copy the elements from aux[] to a[]
        a[k] = aux[k];
    }
}


int main() {

double time_spent = 0.0;
 
clock_t begin = clock();

  int a[1000001], aux[1000001], h, z, u, swap2;
 
    printf("Enter number of elements in the array \n");
    scanf("%d", &h);
    if(h < 1 || h > 1000001)                     
        exit(1);

    srand((unsigned)(time(NULL)));          
    for (z = 0; z < h; z++)                 
        a[z] = rand() %1000001;  
 
  merge_sort(0, h - 1, a, aux);
 
  printf("Printing the sorted array:\n");
 
  for (z = 0; z < h; z++)
     printf("%d\n", a[z]);
 
clock_t end = clock();
 
    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
printf("The elapsed time is %f seconds", time_spent);
 
  return 0;
}