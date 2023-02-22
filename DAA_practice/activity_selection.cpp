#include <bits/stdc++.h>
using namespace std;

class activity
{
public:
    int start, finish;
    activity() {}
    activity(int start, int finish)
    {
        this->finish = finish;
        this->start = start;
    }
};

bool compare(activity a, activity b)
{
    return a.finish < b.finish;
}
void printActivity(activity arr[], int n)
{
    sort(arr, arr + n, compare);
    int i = 0;
    cout << "(" << arr[i].start << "," << arr[i].finish << ")";
    for (int j = 1; j < n; j++)
    {
        if (arr[j].start >= arr[i].finish)
        {
            cout << "(" << arr[j].start << "," << arr[j].finish << ")";
            i=j;
        }
    }
}

int main()
{
    activity arr[] = {{5, 9},
                      {1, 2},
                      {3, 4},
                      {0, 6},
                      {5, 7},
                      {8, 9}};
    int n = sizeof(arr) / sizeof(arr[0]);
    printActivity(arr,n);
    return 0;
}