#include<bits/stdc++.h>
using namespace std;
#define ll long long

void change(int arr[])
{
    for(int i=0;i<5;i++)
    {
        arr[i]+=1;
        cout<<arr[i];
    }
    
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
        {
            int arr[5]={1,2,3,4,5};
            change(arr);
            for(int i=0;i<5;i++)
            {
                cout<<arr[i]<<" ";
            }
        }
    return 0;
}