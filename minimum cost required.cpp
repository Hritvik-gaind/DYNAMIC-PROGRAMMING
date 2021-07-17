#include<iostream>
using namespace std;
int n,capacity;
int price[1000],weight[1000];
int minimumcost(int n,int capacity)
{
    //base case
    if(n==0)
    {
        return INT_MAX;
    }
    if(capacity==0)
    {
        return 0;
    }
    //recursive case
    int op1=INT_MAX,op2=INT_MAX,op3=INT_MAX;
    //exclude
    op1 = 0 + minimumcost(n-1,capacity);
    if(capacity>=weight[n-1])
    {

        op3 = price[n-1] + minimumcost(n,capacity-weight[n-1]);
    }
    return min(op1,op3);
}
int main()
{
    cin>>n>>capacity;
    for(int i=0;i<n;i++)
    {
        cin>>price[i];

    }
    int k=0;
    for(int i=1;i<=n;i++)
    {
        weight[k++] = i;
    }
//    for(int i=0;i<n;i++)
//    {
//        cout<<price[i]<<" ";
//    }
//    cout<<endl;
//    for(int i=0;i<n;i++)
//    {
//
//        cout<<weight[i]<<" ";
//    }
    cout<<minimumcost(n,capacity);
}
