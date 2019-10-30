//Program for Quick Sort using Hoare's partition
#include <iostream>
#include <cstdlib>
using namespace std;

int PARTITION(int A[], int p, int r)
{
	int temp;
	int x = A[p];
	int i = p - 1;
	int j = r + 1;
	
	while(1)
	{
		do{
			j = j - 1;
		}while (A[j] <= x);
		
		do{
			i = i + 1;
		}while (A[i] >= x);
		
		if (i < j)
		{
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
		else
			return j;
		
	}
}

void QUICK_SORT(int A[], int p, int r)
{
	int q;
	if (p < r)
	{
		q = PARTITION(A, p, r);
		QUICK_SORT(A, p, q-1);
		QUICK_SORT(A, q+1, r);
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
	
	QUICK_SORT(A,1,100);
	
	cout<<"Sorted Sequence:-"<<endl;
	for (int i = 1; i < 101; i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
}
