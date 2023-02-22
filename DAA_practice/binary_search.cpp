// #include <bits/stdc++.h>
// using namespace std;

// int binarySearch(int arr[], int n, int key)
// {
//     sort(arr, arr + n);
//     int low = 0;
//     int high = n - 1;
//     while (low <= high)
//     {
//         int mid = floor((high + low) / 2);
//         if (arr[mid] == key)
//         {
//             return mid;
//         }
//         else if (arr[mid] > key)
//         {
//             high = mid - 1;
//         }
//         else
//         {
//             low = mid + 1;
//         }
//     }
//     return -1;
// }

// int rBinarySearch(int arr[], int low, int high, int key)
// {
//     if (low <= high)
//     {
//         int mid = floor((low + high) / 2);
//         if (arr[mid] == key)
//             return mid;
//         else if (arr[mid] > key)
//             rBinarySearch(arr, mid + 1, high, key);
//         else
//             rBinarySearch(arr, low, mid - 1, key);
//     }
//     else
//     {
//         return -1;
//     }
// }

// int main()
// {
//     int arr[] = {1, 3, 83, 69, 2};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     if (rBinarySearch(arr,0,n,89) >= 0)
//     {
//         cout << "Element Found!";
//     }
//     else
//     {
//         cout << "Element not Found!";
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int rBinarySearch(int arr[], int n, int key, int low, int high)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            rBinarySearch(arr, n, key, low, mid - 1);
        }
        else
        {
            rBinarySearch(arr, n, key, mid + 1, high);
        }
    }
        return -1;
}

int binarySearch(int arr[], int n, int key)
{
    sort(arr, arr + n);
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 6, 3, 7, 9, 2};
    sort(arr, arr + 6);
    if (rBinarySearch(arr, 6, 10, 0, 6) > 0)
    {
        cout << "Element Found!";
    }
    else
    {
        cout << "Element not Found!";
    }
    return 0;
}