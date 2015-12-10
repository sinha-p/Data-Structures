#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<list>
using namespace std;
class Graph{
int V;
list<int> *adjlist;
void dfsutil(int s,bool visited[]);
public:
Graph(int V);
void addedge(int s,int d);
void bfs(int s);
void dfs(int s);

};
Graph::Graph(int V)
{
    this->V=V;
    adjlist=new list<int>[V];
}
void Graph::addedge(int s,int d)
{
    adjlist[s].push_back(d);
}
void Graph::bfs(int s)
{
    list<int> que;
    int t;
    bool visited[V];
    for(int j=0;j<V;j++)
        visited[j]=false;
    list<int>::iterator i;
    visited[s]=true;
    que.push_back(s);
    while(!que.empty())
    {
        t=que.front();
        que.pop_front();
        cout<<t<<" ";
        for(i=adjlist[t].begin();i!=adjlist[t].end();i++)
        {
            if(visited[*i]==false)
            {que.push_back(*i);
                visited[*i]=true;
            }
        }

    }
}
void Graph::dfsutil(int v,bool visited[])
{
    visited[v]=true;
    cout<<v<<" ";
    list<int>::iterator i;

    for(i=adjlist[v].begin();i!=adjlist[v].end();i++)
        if(visited[*i]==false)
        dfsutil(*i,visited);
}
void Graph::dfs(int s)
{
    bool *visited=new bool[V];
    for(int j=0;j<V;j++)
        visited[j]=false;
   dfsutil(s,visited);
}
int main(){
Graph G(4);
G.addedge(2,0);
G.addedge(0,2);
G.addedge(0,1);
G.addedge(1,2);
G.addedge(2,3);
G.addedge(3,3);
cout<<"\nBFS=";
G.bfs(2);
cout<<"\nDFS=";
G.dfs(2);

}
