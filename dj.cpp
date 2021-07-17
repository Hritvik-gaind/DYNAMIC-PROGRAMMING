#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
class Graph{
//	unordered_map<int,list<int,int> >h;
	unordered_map<int,list<int> >h;
	public:
	void addedge(int u,int v,bool bidir = true)
	{
		h[u].push_back(v);
		if(bidir)
		{
			h[v].push_back(u);
		}
	}
	int bfs(int src,int n)
	{
		unordered_map<int,bool> visited;
		visited[src] = true;
		queue<int> q;
		q.push(src);
		while(!q.empty())
		{
			int t = q.front();
			q.pop();
			for(auto children:h[t])
			{
				if(!visited[children])
				{
					visited[children] = true;
				}
			}

		}
		int cnt=0;
		int c=0;
		for(int i=0;i<=n;i++)
		{
			if(!visited[i])
			{
				cnt++;
			}
			else
			{
				c++;
			}
		}
		return c*cnt;
	}

};
int main() {
	int n,m;
	cin>>n>>m;
	Graph g;
	for(int i=0;i<m;i++)
	{

		int u,v;
		cin>>u>>v;
		g.addedge(u,v);
	}
	cout<<g.bfs(0,n-1);
	return 0;
}
