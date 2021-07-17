#include<iostream>
using namespace std;
#define int long long int
int isugly(int n)
{
    int ugly[n];
    ugly[0] =1;
    int countt=1;
    int index2=0;
    int index3=0;
    int index5=0;
    while(countt<n)
    {
        int next2 = ugly[index2]*2;
        int next3 = ugly[index3]*3;
        int next5 = ugly[index5]*5;
        int next = min(next2,min(next3,next5));
        if(next==next2)
        {
            index2++;
        }
        if(next==next3)
        {
            index3++;
        }
        if(next==next5)
        {
            index5++;
        }
        ugly[countt++] = next;
    }
    return ugly[n-1];
}
int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
//        int ugly[n];
        cout<<isugly(n)<<endl;
    }


}
