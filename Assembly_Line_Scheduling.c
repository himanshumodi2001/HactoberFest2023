//Himanshu Kumar Modi 21BCI0011
#include <stdio.h>
#include <limits.h>

#define N 5
int min(int a, int b) 
{
  return (a < b) ? a : b;
}
int assemblyLineScheduling(int a[][N], int t[][N], int e[], int x[], int n) 
{
  int f[2][N];
  int i, j;
  f[0][0] = e[0] + a[0][0];
  f[1][0] = e[1] + a[1][0];
  for (i = 1; i < n; i++) 
  {
    for (j = 0; j < 2; j++) 
    {
      f[j][i] = INT_MAX;
      if (f[j][i - 1] != INT_MAX) 
      {
        f[j][i] = min(f[j][i], f[j][i - 1] + a[j][i]);
        if (j == 0)
          f[j][i] = min(f[j][i], f[j ^ 1][i - 1] + t[j ^ 1][i - 1] + a[j][i]);
        if (j == 1)
          f[j][i] = min(f[j][i], f[j ^ 1][i - 1] + t[j ^ 1][i] + a[j][i]);
      }
    }
  }
  return min(f[0][n - 1] + x[0], f[1][n - 1] + x[1]);
}
int main() 
{
  int a[2][N] = {{8,10,4,5,9}, {9,6,7,5,6}};
  int t[2][N] = {{0,2,3,1,3}, {0,2,1,2,2}};
  int e[] = {3,5};
  int x[] = {2,1};
  printf("The minimum time taken is: %d\n", assemblyLineScheduling(a, t, e, x, N));
  return 0;
}