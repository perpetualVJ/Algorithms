//Implementing Prim's Minimum Spanning Tree

#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> P;

int Prim_MST(vector<P> adj[], int edges ,int nodes, int x)
{
	priority_queue<P , vector<P>, greater<P> > Q;
	bool marked[nodes + 1];
	
	for (int i = 0; i <= nodes; i++)
	{
		marked[i] = false;
	}
	int mincost = 0;
	int y;
	P p;
	Q.push(make_pair(0,x));
	while(Q.empty() != true)
	{
		p = Q.top();
		Q.pop();
		y = p.second;
		
		if(marked[y] == true)
			continue;
		mincost += p.first;
		
		marked[y] = true;
		for (int i = 0; i < adj[y].size(); i++)
		{
			cout<<adj[y][i].second<<endl;
			if (marked[adj[y][i].second] == false)
			{
				Q.push(adj[y][i]);
			}
		}
	}
	return mincost;
}
int main()
{
	int nodes, edges;
	cout<<"Enter the number of nodes and edges"<<endl;
	cin>>nodes>>edges;
	
	vector<P> adj[nodes + 1];
	int x, y, weight;
	
	for (int i = 0; i < edges; i++)
	{
		cin>>x>>y>>weight;
		adj[x].push_back(make_pair(weight, y));
		adj[y].push_back(make_pair(weight, x));
	}
	
	int minimumCost = Prim_MST(adj, edges, nodes, 1);                      //taking 1 as the source vertex
	
	cout<<"Minimum Cost is: "<<minimumCost<<endl; 
	
}
