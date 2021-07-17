#include<iostream>
using namespace std;
#define int long long int
string s1,s2,s3;
int n,m;
int lcs(string s1,string s2,int i,int j)
{
    //base case
    if(s1[i]==NULL||s2[j]==NULL)
    {
        return 0;
    }
    //recursive case
    if(s1[i]==s2[j])
    {
        return 1+ lcs(s1,s2,i+1,j+1);
    }
    else
    {
        int op1,op2;
        op1 = op2 = INT_MIN;
        op1 = lcs(s1,s2,i,j+1);
        op2 = lcs(s1,s2,i+1,j);
        return max(op1,op2);
    }

}
int bottomup(string s1,string s2,int i,int j)
{
    int dp[200][200]={0};
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int32_t main()
{
    cin>>s1>>s2;
    n = s1.length();
    m = s2.length();
    //int op1 = lcs(s1,s2,0,0);
    //int op2 = lcs(s2,s3,0,0);
    //cout<<min(op1,op2);

    cout<<bottomup(s1,s2,0,0);
}
