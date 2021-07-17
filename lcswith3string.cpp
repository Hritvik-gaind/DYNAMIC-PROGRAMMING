#include<iostream>
using namespace std;
string s1,s2,s3;
int n,m,o;
int bottomup(int n,int m,int o)
{
  int dp[n+1][m+1][o+1];
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=m;j++)
    {
        for(int k=0;k<=o;k++)
        {
            if(i==0||j==0||k==0)
            {
                dp[i][j][k] = 0;
            }
            else if(s1[i-1]==s2[j-1]&&s1[i-1]==s3[k-1])
            {
                dp[i][j][k] = 1+ dp[i-1][j-1][k-1];
            }
            else
            {
                dp[i][j][k] = max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
            }
        }
    }
  }
  return dp[n][m][o];
}

int main()
{
  cin>>s1>>s2>>s3;
  n = s1.length();
  m = s2.length();
  o = s3.length();
  cout<<bottomup(n,m,o);
}
