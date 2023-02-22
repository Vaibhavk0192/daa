#include <bits/stdc++.h>
using namespace std;

class job
{
public:
    char id;
    int dead;
    int profit;
    job()
    {
    }
    job(char id, int dead, int profit)
    {
        this->id = id;
        this->dead = dead;
        this->profit = profit;
    }
};

bool comparison(job a, job b)
{
    return a.profit > b.profit;
}

void jobScheduling(job arr[], int n)
{
    sort(arr, arr + n, comparison);

    int result[n];
    bool slot[n] = {false};

    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--)
        {
            if (!slot[j])
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[result[i]].id << " ";
    }
}

int main()
{
	job arr[] ={{'a', 4, 100}, {'b', 4, 98}, {'c', 4, 54}, {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(arr) / sizeof(arr[0]);
    jobScheduling(arr, n);
    return 0;
}
