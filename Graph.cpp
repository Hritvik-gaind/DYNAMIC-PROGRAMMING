#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class Graph{
    unordered_map<int,list<int> >h;
    public:
        void addedge(int u,int v,bool bidir=true)
        {
            h[u].push_back(v);
            if(bidir)
            {
                h[v].push_back(u);
            }
        }
        void dfs(int src,unordered_map <int,bool> &visited)
        {
            visited[src] = true;
            cout<<src<<" ";
            for(auto x:h[src])
            {
                if(!visited[x])
                {
                    dfs(x,visited);
                }
            }

        }
};
int main()
{
    Graph g;
    g.addedge(0,1);
    g.addedge(0,4);
    g.addedge(2,1);
    g.addedge(2,4);
    g.addedge(2,3);
    g.addedge(3,4);
    g.addedge(3,5);
    unordered_map<int,bool> visited;
    g.dfs(0,visited);

}
