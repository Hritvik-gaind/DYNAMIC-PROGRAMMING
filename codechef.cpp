#include<iostream>
#include<vector>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin>>n;
    vector<string> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        bool ans = 1;
        if(arr[i][0]>='a' && arr[i][0]<='m')
        {
            for(auto x:arr[i])
            {
                if(x>= 'a' && x <='m');
                else
                {
                    ans = 0;
                    break;

                }

            }
        }
        else if(arr[i][0]>= 'N' && arr[i][0]<='Z')
        {
            for(auto x: arr[i])
            {
                if(x>= 'N'&& x<= 'Z');
                else{
                    ans =0;
                    break;
                }
            }
        }
        else ans=0;
        if(!ans)
        {
            cout<<"NO"<<endl;
            return ;
        }
    }
    cout<<"YES"<<endl;
}
int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }

}
