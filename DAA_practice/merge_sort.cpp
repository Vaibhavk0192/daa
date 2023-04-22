#include <bits/stdc++.h>
using namespace std;
void display(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void Rmerge(int arr[], int l, int mid, int h)
{
    int n1 = mid - l + 1;
    int n2 = h - mid;
    int a[n1];
    int b[n2];
    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
            k++;
            j++;
        }
    }
    while (i < n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }

    while (j < n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
}

void iterativeMergeSort(int arr[], int n)
{
    int p;
    int l;

    for (p = 1; p <= n - 1; p = p * 2)
    {
        for (int l = 0; l < n - 1; l += 2 * p)
        {
            int mid = min(l + p - 1, n - 1);
            int h = min(l + 2 * p - 1, n - 1);  
            Rmerge(arr, l, mid, h);
        }
    }
}

void mergeSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, h);
        Rmerge(arr, l, mid, h);
    }
}

int main()
{
    int d[6] = {2, 5, 4, 1, 3, 6};
    display(d, 6);
    cout << "the sorted merge list is" << endl;
    iterativeMergeSort(d, 5);
    display(d, 6);
    // int arr[] = {1, 6, 3, 7, 9, 2};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // // cout<<n;
    // mergeSort(arr, 0, n-1);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // return 0;
}
