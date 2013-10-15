#include <stdio.h>

#include "insertionsort.h"

int main()
{
  int test[]={6,8,4,3,9,2,5};
  for(int i=0; i<6; i++)
    printf("%d, ", test[i]);
  printf("%d\n", test[6]);
  insertionSort(test, 7);
  for(int i=0; i<6; i++)
    printf("%d, ", test[i]);
  printf("%d\n", test[6]);
  return 0;
}
