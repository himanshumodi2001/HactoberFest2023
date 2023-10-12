//Himanshu Kumar Modi 21BCI0011
#include <stdio.h>
int max(int a, int b) 
{
  return (a > b) ? a : b;
}
int knapsack(int n, int w, int weight[], int value[]) 
{
  int i, j;
  int k[n + 1][w + 1];

  for (i = 0; i <= n; i++) 
  {
    for (j = 0; j <= w; j++) 
    {
      if (i == 0 || j == 0)
        k[i][j] = 0;
      else if (weight[i - 1] <= j)
        k[i][j] = max(value[i - 1] + k[i - 1][j - weight[i - 1]], k[i - 1][j]);
      else
        k[i][j] = k[i - 1][j];
    }
  }
  return k[n][w];
}
int main() 
{
  int n,w,i,max_profit;
  printf("Enter number of items: ");
  scanf("%d", &n);
  printf("Enter maximum weight allowed: ");
  scanf("%d", &w);
  int weight[n], profit[n];
  printf("Enter weights and profits of each items:\n");
  for(i=0;i<n;i++)
  {
      printf("\tItem %d:\n", i+1);
      printf("\t\tWeight: ");
      scanf("%d", &weight[i]);
      printf("\t\tProfit: ");
      scanf("%d", &profit[i]);
  }
  max_profit = knapsack(n, w, weight, profit);
  printf("Maximum profit: %d", max_profit);

  return 0;
}