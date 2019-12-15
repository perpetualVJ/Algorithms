//To implement BREADTH FIRST SEARCH

#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int main()
{
	int v;                                                      // no of vertices
		
	cout<<"Enter the number of vertices"<<endl;
	cin>>v;
	
	list <int> adj[v + 1];                                      // adjacency lists
	bool visit[v + 1];                                          // to record the marked nodes
	int d[v+1];                                                 // to record shortest path
	int x;                                                      // destination vertex must lies between 0 and v
	list <int>:: iterator it;
	queue <int> q;                                              
	int a, b;
	int e;                                                      // no of edges
	
	for (int i = 1; i <= v; i++)
	{
		visit[i] = false;
		d[i] = INT_MAX;
	}

	
	cout<<"Enter the number of edges"<<endl;
	cin>>e;
	
	for (int i = 0; i < e; i++)
	{
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);	
	}
	
	d[1] = 0;
	visit[1] = true;
	q.push(1);	
	
	while (q.empty() != true)
	{
		int u = q.front();
		q.pop();
		
		for (it = adj[u].begin(); it != adj[u].end(); it++)
		{
			if (visit[*it] == false)
			{
				visit[*it] = true;
				d[*it] = d[u] + 1;
				q.push(*it);
			}
		}
	}
	
	cout<<"Enter the destination vertex"<<endl;
	cin>>x;
	
	cout<<"Shortest Path through BFS is: "<<d[x]<<endl;
	
}


