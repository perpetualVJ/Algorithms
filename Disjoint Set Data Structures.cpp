//Implementation of Disjoint set Data Structures

#include <iostream>
using namespace std;

void initialize(int arr[], int size[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = i;
		//initially the size of each set is 1
		size[i] = 1;
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

void disjoint_union(int arr[], int size[], int a, int b)
{
	int root_a = root(arr,a);
	int root_b = root(arr,b);
	
	if (size[root_a] < size[root_b])
	{
		arr[root_a] = arr[root_b];
		size[root_b] += size[root_a];	
	}	
	else
	{
		arr[root_b] = arr[root_a];
		size[root_a] += size[root_b];
	}
}

bool find(int arr[], int a, int b)
{
	int root_a = root(arr,a);
	int root_b = root(arr,b);
	
	if (root_a == root_b)
		return true;
	else
		return false;
}

int main()
{
	//Creating Disjoint set Data Structure for 100 elements
	int arr[101], size[101];
	
	//Initializing the roots of each initial subset
	initialize(arr, size, 101);
	
	//Connecting several components
	disjoint_union(arr, size, 5, 19);
	disjoint_union(arr, size, 2, 5);
	disjoint_union(arr, size, 3, 19);
	disjoint_union(arr, size, 5, 1);
	disjoint_union(arr, size, 78, 7);
	disjoint_union(arr, size, 78, 8);
	disjoint_union(arr, size, 76, 9);
	disjoint_union(arr, size, 56, 19);
	
	//finding if 5 and 1 is connected
	if (find(arr, 5, 1))
		cout<<"Connected"<<endl;
	else
		cout<<"Unconnected"<<endl;
		
	//finding if 9 and 78 is connected
	if (find(arr, 9, 78))
		cout<<"Connected"<<endl;
	else
		cout<<"Unconnected"<<endl;
	
}
