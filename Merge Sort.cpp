//Program to sort numbers in ascending order using MERGE SORT

#include <iostream>
#include<climits>
#include<cstdlib>

using namespace std;

MERGE(int A[], int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int L[n1 + 2];
	int R[n2 + 2];
	
	for (int i = 1; i <= n1; i++)
	{
		L[i] = A[p + i - 1];
	}
	
	for (int i = 1; i <= n2; i++)
	{
		R[i] = A[q + i];
	}
	L[n1 + 1] = INT_MAX;
	R[n2 + 1] = INT_MAX;
	
	int i = 1;
	int j = 1;
	for(int k = p; k <= r; k++)
	{
		if (L[i] <= R[j])
		{
			A[k] = L[i];
			i = i + 1;
		}
		else
		{
			A[k] = R[j];
			j = j + 1;
		}
	}
}
MERGE_SORT(int A[], int p, int r)
{
	int q;
	if (p < r)
	{
		q = (p + r) / 2;
		MERGE_SORT(A, p, q);
		MERGE_SORT(A, q + 1, r);
		MERGE(A, p, q, r);
	}
	
}
int main()
{
	int A[101];
	
	//Using random function to store random values in array A
	for (int i = 1; i < 101; i++)
	{
		A[i] = rand() % 101;
		
	}
	
	cout<<"Unsorted Sequence:-"<<endl;
	for (int i = 1; i < 101; i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
	
	MERGE_SORT(A,1,100);
	
	cout<<"Sorted Sequence:-"<<endl;
	for (int i = 1; i < 101; i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
	
}

