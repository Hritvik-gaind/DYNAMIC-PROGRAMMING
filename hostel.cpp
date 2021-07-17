#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long
int arr[100000];
int32_t main()
{
    int n,k,q,i,j;
    cin>>n>>k;
    j=0;
    for(int i=0;i<n;i++)
    {
        cin>>q;
        if(q==1)
        {
            int x1,x2;
            cin>>x1>>x2;
            int dist = pow(x1,2) + pow(x2,2);
            arr[j] = dist;
            j++;
        }
        else if(q==2)
        {
            sort(arr,arr+j);
//            for(int i=0;i<j;i++)
//            {
//                cout<<arr[i]<<" ";
//            }
            cout<<arr[k-1]<<" ";

        }
    }
}
