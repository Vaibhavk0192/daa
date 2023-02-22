#include <bits/stdc++.h>
using namespace std;

class job
{
public:
    char id;
    int profit;
    int deadline;
    job(){};
    job(int id,int deadline,int profit)
    {
        this->id=id;
        this->deadline=deadline;
        this->profit=profit;
    }
};

bool compare(job a,job b){
    return a.profit>b.profit;
}

void jobScheduling(job arr[],int n)
{
    sort(arr,arr+n,compare);
    int result[n];
    bool slot[n]={false};
    for (int i=0;i<n;i++){
        for (int j=min(n,arr[i].deadline)-1;j>=0;j--){
            if(!slot[j]){
                slot[j]=true;
                result[j]=i;
                break;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[result[i]].id<<" ";
    }

}

int main()
{
    job arr[] = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};

    int n = sizeof(arr) / sizeof(arr[0]);
    jobScheduling(arr, n);
    return 0;
}