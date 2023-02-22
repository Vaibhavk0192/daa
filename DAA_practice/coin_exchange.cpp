#include <bits/stdc++.h>
using namespace std;

bool compare(int a,int b)
{
    return a>b;
}

void coinExchange(int arr[],int n,int value)
{
    sort(arr,arr+n,compare);
    vector <int> ans;
    for(int i=0;i<n;i++)
    {
        while (arr[i]<=value)
        {
            value=value-arr[i];
            ans.push_back(arr[i]);
        }
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}
int main(){
    int value;
    cout<<"enter the total value"<<endl;
    cin>>value;
    int arr[]={2,5,10,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    coinExchange(arr,n,value);
}