//Implementation of kruskal's Minimum Spanning Tree

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void initialize(int arr[], int n)
{
	for (int i = 0; i <= n; i++)
	{
		arr[i] = i;
	}
}

int root(int arr[], int i)
{
	while (arr[i] != i)
	{
		i = arr[i];
	}
	return i;
}

void unionn(int arr[], int a, int b)
{
	int root_a = root(arr, a);
	int root_b = root(arr, b);
	arr[root_a] = arr[root_b];
}

int Kruskal_MST(pair <int, pair <int,int> > p[], int edges, int arr[])
{
	int cost = 0;
	int mincost = 0;
	int x, y;
	for (int i = 0; i < edges; i++)
	{
		x = p[i].second.first;
		y = p[i].second.second;
		cost = p[i].first;
		
		int root_x = root(arr, x);
		int root_y = root(arr, y);
		
		if (root_x != root_y)
		{
			mincost = mincost + cost;
			unionn(arr,x,y);
		}
	}
	return mincost;
}

int main()
{
	int x, y;
	int nodes, edges, weight;
	int minimumCost;
	cout<<"Enter the number of nodes and edges"<<endl;
	cin>>nodes>>edges;
	
	pair<int, pair<int, int> > p[edges];
	int arr[nodes + 1];
	
	initialize(arr, nodes);
	
	for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
    // Sort the edges in the ascending order
    sort(p, p + edges);
    
    minimumCost = Kruskal_MST(p, edges, arr);
    cout << minimumCost << endl;
    return 0;
}
