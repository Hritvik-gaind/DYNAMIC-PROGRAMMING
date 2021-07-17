#include<iostream>
#include<set>
#include<unordered_map>
#include<list>
using namespace std;
class Graph{

    unordered_map<int,list<pair<int,int> > >h;
    public:
        void addedge(int src,int dest,int dist,bool bidir =true)
        {
            h[src].push_back(make_pair(dest,dist));
            if(bidir==true)
            {
                h[dest].push_back(make_pair(src,dist));
            }
        }
        void dijsktra(int src,int n)
        {
            unordered_map<int,int> distance;
            for(auto node:h)
            {
                distance[node.first] = INT_MAX;
            }
            distance[src] = 0;
            set<pair<int,int> > s;
            s.insert(make_pair(0,src));
            while(!s.empty())
            {
                auto node = *(s.begin());
                s.erase(s.begin());
                int parentdist = node.first;
                int parent = node.second;
                for(auto children:h[parent])
                {
                    int edgedistance = children.second;
                    if(distance[children.first]>edgedistance+parentdist)
                    {
                        auto f = s.find(make_pair(distance[children.first],children.first));
                        if(f!=s.end())
                        {
                            s.erase(f);
                        }
                        distance[children.first] = edgedistance+parentdist;
                        s.insert(make_pair(distance[children.first],children.first));
                    }

                }
            }
           for(int i=1;i<=n;i++)
           {
            if(i!=src)
           {


            if(distance[i]!=INT_MAX)
            {
                cout<<distance[i]<<" ";
            }
            else
            {
                cout<<-1<<" ";
            }
        }


  }

        }
//        void dfs(int src,unordered_map <int,bool> &visited)
//        {
//            visited[src] = true;
//            cout<<src<<" ";
//            for(auto x:h[src])
//            {
//                if(!visited[x])
//                {
//                    dfs(x,visited);
//                }
//            }
//
//        }
};
int main()
{
    Graph g;
//    g.addedge(0,1);
//    g.addedge(0,4);
//    g.addedge(2,1);
//    g.addedge(2,4);
//    g.addedge(2,3);
//    g.addedge(3,4);
//    g.addedge(3,5);
//    unordered_map<int,bool> visited;
//    g.dfs(0,visited);
      int t;
      cin>>t;
      while(t--)
      {
          Graph g;
          int n,m,x,y,r;
          cin>>n>>m;
          for(int i=0;i<m;i++)
          {
              cin>>x>>y>>r;
              g.addedge(x,y,r);
          }
          int src;
          cin>>src;
          g.dijsktra(src,n);
      }

}
