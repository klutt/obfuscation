/* Test file to see if the obfuscated version works correctly. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

void matrix_multiply_safe(int *A, int *B, int *C, int N)
{
  for(int i=0; i<N*N; i++)
    C[i]=0;

  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      for(int k=0; k<N; k++)
	C[i*N + j] += A[i*N + k] * B[k*N + j];
}

int matrix_equal(int *A, int *B, int N)
{
  for(int i=0; i<N*N; i++)
    if(A[i]!=B[i])
      return 0;
  return 1;
}

void identity(int *A, int N)
{
  for(int i=0; i<N*N; i++)
    if(i%(N+1)==0)
      A[i]=1;
    else
      A[i]=0;
}

void zero(int *A, int N)
{
  for(int i=0; i<N*N; i++)
    A[i]=0;
}

void random_matrix(int *A, int N)
{
  for(int i=0; i<N*N; i++)
    A[i]=rand() - RAND_MAX/2;
}

void test_matrix_multiply(int noTests, int size)
{
  srand(time(NULL));
  int A[size*size];
  int B[size*size];
  int S[size*size];
  int T[size*size];
  int I[size*size];
  int Z[size*size];

  identity(I,size);
  zero(Z, size);

  printf("Random multiplications with zero matrix\n\n");

  for(int i=0; i<noTests; i++)
    {
      random_matrix(A,size);
      matrix_multiply(A,Z,T,size);
      if(!matrix_equal(T,Z,size))
	 printf("FAIL\n");
      matrix_multiply(Z,A,T,size);
      if(!matrix_equal(T,Z,size))
	 printf("FAIL\n");
    }

  printf("Random multiplications with identity matrix\n\n");

  for(int i=0; i<noTests; i++)
    {
      random_matrix(A,size);
      matrix_multiply(A,I,T,size);
      if(!matrix_equal(T,A,size))
	 printf("FAIL\n");
      matrix_multiply(I,A,T,size);
      if(!matrix_equal(T,A,size))
	 printf("FAIL\n");
    }

  printf("Random multiplications\n\n");

  for(int i=0; i<noTests; i++)
    {
      random_matrix(A,size);
      random_matrix(B,size);
      matrix_multiply(A,B,T,size);
      matrix_multiply_safe(A,B,S,size);
      if(!matrix_equal(S,T,size))
	 printf("FAIL\n");
    }


}

void print_matrix(int *A, int N)
{
  for(int i=0; i<N; i++)
    {
    for(int j=0; j<N; j++)
      printf("%d\t",A[i*N + j]);
    printf("\n");
    }
}

void main()
{
  int I[]={1,0,0,0,1,0,0,0,1};
  int O[]={0,0,0,0,0,0,0,0,0};
  int A[]={2,3,4,2,6,4,6,7,8};
  int T[]={4,6,8,6,8,9,7,6,8};

  int Q[10*10];
  identity(Q,10);

  test_matrix_multiply(1000,30);
}

