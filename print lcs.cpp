#include<iostream>
#include<vector>
using namespace std;
string s1,s2;
int n,m;
int lcs(int i,int j)
{
    //base case
    if(s1[i]==NULL||s2[j]==NULL)
    {
        return 0;
    }
    //recursive case
    if(s1[i]==s2[j])
    {
        return 1+ lcs(i+1,j+1);
    }
    else
    {
        int  op1,op2;
        op1=op2=INT_MIN;
        op1 = lcs(i,j+1);
        op2 = lcs(i+1,j);
        return max(op1,op2);
    }
}
int bottomup()
{
    int dp[100][100] ;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            dp[i][j] = 0;
        }
    }
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
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    vector<int> v;
    int i=n,j=m;
    while(i>0&&j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            v.push_back(s1[i-1]);
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    for(int i=v.size()-1;i>=0;i--)
    {
        cout<<char(v[i]);
    }
    cout<<endl;
    return dp[n][m];
}
//int bottomup()
//{
//    int dp[100][100]={0};
////    memset(dp,0,sizeof(dp));
//    int len1 = s1.length();
//    int len2 = s2.length();
//    for(int i=1;i<=len1;i++)
//    {
//        for(int j=1;j<=len2;j++)
//        {
//            if(s1[i-1]==s2[j-1])
//            {
//                dp[i][j] = 1+dp[i-1][j-1];
//            }
//            else
//            {
//                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
//            }
//        }
//
//    }
//    return dp[len1][len2];
//}
int main()
{
    cin>>s1>>s2;
//    cout<<lcs(0,0);
     n = s1.length();
     m = s2.length();
     cout<<bottomup();

}
