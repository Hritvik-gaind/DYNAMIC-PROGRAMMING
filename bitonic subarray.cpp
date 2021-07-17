#include<iostream>
using namespace std;
#define int long long int
int maxlengthbiotonic(int *arr,int *inc,int *dec,int n)
{
    inc[0] =1;
    dec[n-1] = 1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>=arr[i-1])
        {
            inc[i] = inc[i-1] +1;
        }
        else
        {
            inc[i] = 1;
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>=arr[i+1])
        {
            dec[i] = dec[i+1] +1;
        }
        else
        {
            dec[i] =1;
        }
    }
//    for(int i=0;i<n;i++)
//    {
//        cout<<inc[i]<<" ";
//    }
   int ans = INT_MIN;
   for(int i=0;i<n;i++)
   {
       ans=max(ans,dec[i]+inc[i]-1);
   }
   return ans;
}
int32_t main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int arr[n];
    int inc[n];
    int dec[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

     cout<<maxlengthbiotonic(arr,inc,dec,n);
    }
}
