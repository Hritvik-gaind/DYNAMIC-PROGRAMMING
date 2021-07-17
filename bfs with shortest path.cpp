#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
class Graph{
	unordered_map<int,list<int> >h;
	public:
	void addedge(int u,int v,bool bidir =true)
	{
		h[u].push_back(v);
		if(bidir)
		{
			h[v].push_back(u);
		}
	}
	void sssp(int src,int n)
	{
		unordered_map<int,bool> visited;
		unordered_map<int,int> distance;
		queue<int> q;
		visited[src] = true;
		distance[src] =0;
		q.push(src);
		while(!q.empty())
		{
			int node  = q.front();
			q.pop();
			for(auto children:h[node])
			{
				if(!visited[children])
				{
					q.push(children);
					visited[children] = true;
					distance[children] = distance[node] + 1;
				}
			}
		}
        for(int i=1;i<=n;i++)
        {
            if(i!=src)
            {
            if(!visited[i])
            {
                cout<<-1<<" ";
            }
            else
            {
                cout<<distance[i]*6<<" ";
            }
            }
        }
        // for(auto x:visited)
        // {
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
		// for(int i=1;i<=n;i++)
		// {
		// 	cout<<i<<"--> ";
		// 	 for(auto x:distance)
		// 	 {
		// 		 cout<<x.second<<" ";
		// 	 }
        //      cout<<endl;
		// }
	}



};
int main() {
	int q;
	cin>>q;
	while(q--)
	{
		Graph  g;
		int n,m;
		cin>>n>>m;
		for(int i=0;i<m;i++)
		{
			int u,v;
			cin>>u>>v;
			g.addedge(u,v);
		}
		int src;
		cin>>src;
		g.sssp(src,n);
        cout<<endl;
	}
	return 0;
}
