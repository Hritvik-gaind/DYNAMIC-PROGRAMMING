#include<iostream>
using namespace std;
#define int long long int
int arr[1000005];
int dp[10005][10005];
bool subsetsumtarget(int i,int n,int sum,int curr_sum)
{
    if(i==n)
    {

        return dp[n][curr_sum] = false;
    }
    if(sum == curr_sum)
    {

        return dp[i][curr_sum] = true;
    }
    if(curr_sum>sum)
    {
        return dp[i][curr_sum] = false;
    }

	if(dp[i][curr_sum]!=false)
	{
		return dp[i][curr_sum];
	}

    //what should i return here
	return dp[i][curr_sum] = subsetsumtarget(i+1,n,sum,curr_sum)||subsetsumtarget(i+1,n,sum,curr_sum+arr[i]);

}
int32_t main()
{
    int n,sum;
    cin>>n>>sum;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
        {
            dp[i][j] = false;
        }
	}
    if(subsetsumtarget(0,n,sum,0))
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }

}
