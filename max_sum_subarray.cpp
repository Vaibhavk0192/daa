#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int max(int a, int b, int c)
{
    return max(max(a, b), c);
}

int maxCrossingSum(int arr[], int l, int m, int h)
{
    int sum = 0;
    int leftSum = INT_MIN;
    for (int i = m; i >= l; i--)
    {
        sum = sum + arr[i];
        if (sum > leftSum)
        {
            leftSum = sum;
        }
    }
    sum=0;
    int rightSum =INT_MIN;
    for (int i = m+1; i <= h; i++)
    {
        sum = sum + arr[i];
        if (sum > rightSum)
        {
            rightSum = sum;
        }
    }

    return max(leftSum + rightSum , leftSum, rightSum);
}

int maxSubArraySum(int arr[], int l, int h)
{
    if (l > h)
    {
        return 0;
    }
    if (l == h)
    {
        return arr[l];
    }
    int m = (l + h) / 2;

    return max(maxSubArraySum(arr, l, m - 1), maxSubArraySum(arr, m + 1, h),
               maxCrossingSum(arr, l, m, h));
}

int main()
{
    int arr[] = {2, 3, 4, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubArraySum(arr, 0, n - 1);
    cout << maxSum;
    return 0;
}
