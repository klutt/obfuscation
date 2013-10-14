#include "matrix.h"

void matrix_multiply(int *A, int *B, int *C, int N)
{
  for(    int i=0,j=0,k=0;
	  k++<N ? 1 : ++j<N ? k=1 : ++i<N ? k=1+(j=0) : 0;
	  C[i*N + j] = A[i*N + k -1] * B[(k-1)*N + j] + (k==1 ? 0 : C[i*N + j])
	  ) {}
}
