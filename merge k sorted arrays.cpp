#include<iostream>
#include <bits/stdc++.h>
//#include<priority_queue>
#include<vector>
#define ppi pair<int,pair<int,int>>
using namespace std;

vector<int> mergeksortedarrays(vector<vector<int> >v)
{
    int k = v.size();
    int n = v[0].size();
    vector<int> res;
    priority_queue<ppi,vector<ppi>,greater<ppi>> pq;
    for(int i=0;i<k;i++)
    {
        pq.push({v[i][0],{i,0}});
    }
    while(!pq.empty())
    {
        auto x = pq.top();
        pq.pop();
        res.push_back(x.first);
        int colNo = x.second.second;
        int rowNo = x.second.first;
        if(colNo<n-1)
        {
            pq.push({v[rowNo][colNo+1],{rowNo,colNo+1}});
        }
    }
    return res;

}
int main()
{
    int k,n;
    cin>>k>>n;
    vector<vector<int> > v(k, vector<int>(n));

    for(int i=0;i<k;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>v[i][j];
        }
    }
    vector<int> ans = mergeksortedarrays(v);
    for(auto x:ans)
    {
        cout<<x<<" ";
    }
}
