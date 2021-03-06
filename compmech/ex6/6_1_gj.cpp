
//
// 6_1_gj.cpp 
//
// 3�N6�g32�Ԕ����V��
// �X�V����
// 2017.05.22 ... ver 1.0 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 4
#define EPS 1e-6

typedef double Matrix [N][N+1];

void print_matrix(Matrix a)
{
  for (int i=0;i<N;i++)
  {
    for (int j=0;j<N;j++)
    {
      printf("%8.3f",a[i][j]);
    }
    printf("|%8.3f\n",a[i][N]);
  }
  printf("\n");
}

void change_row(Matrix origin,const int a)
{
	int change=a;
    double array;
    double max_value=origin[a][a];
   	for(int k = a; k<N; k++){
    		if(fabs(max_value)<fabs(origin[k][a])){
    			max_value = origin[k][a];
    			change=k;
    		}
    }
	printf("Max value: %7.3f\n",fabs(max_value));
	printf("Max row: %d\n",change);
	if(change==a)return;
  for (int i = 0; i < N+1 ; ++i)
  {
    array= origin[a][i]; 
    origin[a][i] = origin[change][i];
    origin[change][i] = array;
  }
   printf("Row %d changed with row %d \n\n",a,change);
}

void gauss_jordan(Matrix a)
{
  for (int i=0;i<N;i++)
  {
    
    	change_row(a,i);
    	double pivot=a[i][i];

	 for (int j=i;j<N+1;j++)
    {
      a[i][j]/=pivot;
    }
    for (int k=0;k<N; k++)
    {
      if(k!=i)
      {
        double d=a[k][i];
        for (int j = 0; j < N+1; j++)
        {
          a[k][j]-=d*a[i][j];
        }
      }
    }
    print_matrix(a);
  }
}

void print_result(Matrix a)
{
  printf("========results=======\n");
  for (int i = 0; i < N; i++)
  {
    printf("x%d = %9.3lf\n", i+1, a[i][N]);
  }
}

 int main(void)
{
Matrix A = {{-2,-6,5,-2,-7},{1,3,-2,-1,-3},{-1,3,-1,1,6},{-3,-2,1,2,4}};
  print_matrix(A);
  gauss_jordan(A);
  print_result(A);
  return 0;
}