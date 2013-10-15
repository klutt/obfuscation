#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "insertionsort.h"



void fill_random(int *list, int length)
{
  for(int i=0; i<length; i++)
    list[i]=rand()-RAND_MAX/2;
}

void list_copy(int *a, int *b, int length)
{
  for(int i=0; i<length; i++)
    b[i]=a[i];
}

void insertionSortSafe(int *list, int length)
{
  for(int i=0; i<length-1; i++)
    {
      int max=i+1;
      for(int j=i; j<length; j++)
	{
	  if(list[j]>list[max])
	    max=j;
	}
      int tmp = list[i];
      list[i]=list[max];
      list[max]=tmp;
    }
}

int list_equal(int *a, int *b, int size)
{
  for(int i=0; i<size; i++)
    if(a[i]!=b[i])
      return 0;
  return 1;
}

void testrandomlists(int n, int size)
{
  for(int i=0; i<n; i++)
    {
      int list[size];
      int check[size];
      fill_random(list, size);
      list_copy(list, check, size);
      insertionSort(list, size);
      insertionSortSafe(check, size);
      if(!list_equal(list, check, size))
	 printf("FAIL!\n");
    }
}
      
int main()
{
  srand(time(NULL));
  testrandomlists(1000, 1000);
  return 0;
}
