#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int knapsack(int sack, int weight[], int profit[], int n)
{
    int i, w;
    int k[n+1][sack+1];
    // vector<vector<int>> k(n + 1, vector<int>(sack + 1));
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= sack; w++)
        {
            if (i == 0 || w == 0)
            {
                k[i][w] = 0;
            }
            else if (weight[i - 1] <= w)
            {
                k[i][w] = max(profit[i - 1] + k[i - 1][w - weight[i - 1]], k[i - 1][w]);
            }
            else
            {
                k[i][w] = k[i - 1][w];
            }
        }
    }
    return k[n][sack];
}

int main()
{
    int profit[] = {5,6,12,9,15};
    int weight[] = {2,3,5,6,7};
    int sack = 15;
    int n = sizeof(profit) / sizeof(profit[0]);
    cout << knapsack(sack, weight, profit, n);
    return 0;
}