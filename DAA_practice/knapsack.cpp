#include <bits/stdc++.h>
using namespace std;

class sack
{
public:
    double weight, value;
    sack(){};
    sack(int value, int weight)
    {
        this->value = value;
        this->weight = weight;
    }
};

bool compare(sack a, sack b)
{
    double a1 = a.value / a.weight;
    double b1 = b.value / b.weight;
    return a1 >b1;
}

void knapSack(sack a[], int n, double cap)
{
    sort(a, a + n, compare);
    double final_value = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].weight <= cap)
        {
            final_value = final_value + a[i].value;
            cap = cap - a[i].weight;
        }
        else
        {
            final_value = final_value + a[i].value * (cap / a[i].weight);
            break;
        }
    }
    cout << final_value;
}

int main()
{
    // Weight of knapsack
    int N = 60;

    // Given weights and values as a pairs
    sack arr[] = {{100, 10},
                  {280, 40},
                  {120, 20},
                  {120, 24}};

    int size = sizeof(arr) / sizeof(arr[0]);

  
    knapSack(arr, size,N);
    return 0;
}