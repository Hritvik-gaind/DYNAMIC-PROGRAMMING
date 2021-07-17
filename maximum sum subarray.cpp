#include<iostream>
#include<vector>
using namespace std;
int kadane(vector <int> ans,int n)
{
    int csum=0;
    int msum=INT_MIN;
    for(int i=0;i<n;i++)
    {
        csum +=ans[i];
        msum = max(csum,msum);
        if(csum<0)
        {
            csum=0;
        }

    }
    return msum;
}
int main()
{
  int r,c;
  cin>>r>>c;
  int arr[r][c];
  for(int i=0;i<r;i++)
  {
     for(int j=0;j<c;j++)
     {
       cin>>arr[i][j];
     }
  }
  int ma = INT_MIN;
  for(int i=0;i<r;i++)
  {
    vector<int> ans(c);
    for(int j=i;j<r;j++)
    {
      for(int col=0;col<c;col++)
      {
        ans[col] +=arr[j][col];
      }
      ma = max(ma,kadane(ans,c));
    }
  }
  cout<<ma;
}
