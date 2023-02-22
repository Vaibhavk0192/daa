#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int l, int h)
{
    int pivot = a[h];
    int i = l - 1;
    for (int j = l; j < h; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[h]);
    return i + 1;
}

void QuickSort(int a[], int l, int h)
{
    if (l < h)
    {
        int p = partition(a, l, h);
        QuickSort(a, l, p - 1);
        QuickSort(a, p + 1, h);
    }
}

void iterativeQuickSort(int arr[],int l,int h)
{
    int stack[h-l+1];
    int top=-1;
    stack[++top]=l;
    stack[++top]=h;
    while (top>=0)
    {
        h=stack[top--];
        l=stack[top--];
        int p=partition(arr,l,h);
        if(p-1>l){
            stack[++top]=l;
            stack[++top]=p-1;
        }
        if(p+1<h)
        {
            stack[++top]=p+1;
            stack[++top]=h;
        }
    }
    
}

int main()
{
    int a[] = {23, 43, 56, 2, 13, 40};
    iterativeQuickSort(a, 0, 5);
    for (int i = 0; i < 6; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}