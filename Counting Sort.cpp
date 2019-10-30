//Program for Counting Sort

#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

void COUNTING_SORT(int A[], int B[], int n, int k)
{
	int C[k + 1];
	
	for (int i = 0; i <= k; i++)
	{
		C[i] = 0;
	}
	
	for (int i = 1; i <= n; i++)
	{
		C[A[i]] = C[A[i]] + 1;
	}
	
	for (int i = 1; i <= k; i++)
	{
		C[i] = C[i] + C[i-1];
	}
	
	for (int i = n; i >= 1; i--)
	{
		B[C[A[i]]] = A[i];
		C[A[i]] = C[A[i]] - 1;
	}
}

int main()
{
	int A[101];
	int B[101];
	int k = -1;
	
	//Using random function to store random values in array A
	for (int i = 1; i < 101; i++)
	{
		A[i] = rand() % 101;
		if (k < A[i])
			k = A[i];
	}
	//cout<<k<<endl;
	cout<<"Unsorted Sequence:-"<<endl;
	for (int i = 1; i < 101; i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
	
	COUNTING_SORT(A,B,100,k);
	
	cout<<"Sorted Sequence:-"<<endl;
	for (int i = 1; i < 101; i++)
	{
		cout<<B[i]<<" ";
	}
	cout<<endl;
}
