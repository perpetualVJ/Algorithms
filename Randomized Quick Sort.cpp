//Program for Randomized Quick Sort
#include <iostream>
#include <cstdlib>
using namespace std;

int PARTITION(int A[], int p, int r)
{
	int temp;
	int x = A[r];
	int i = p - 1;
	for (int j = p; j <= r-1; j++)
	{
		if (A[j] <= x)
		{
			i++;
			
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	temp = A[i+1];
	A[i+1] = A[r];
	A[r] = temp;
	
	return i+1;
}
int RANDOMIZED_PARTITION(int A[], int p, int r)
{
	int i = (rand() % (r - p + 1)) + p;
	int temp;
	
	temp = A[r];
	A[r] = A[i];
	A[i] = temp;
	
	return PARTITION(A, p, r);
}
void RANDOMIZED_QUICK_SORT(int A[], int p, int r)
{
	int q;
	if (p < r)
	{
		q = RANDOMIZED_PARTITION(A, p, r);
		RANDOMIZED_QUICK_SORT(A, p, q-1);
		RANDOMIZED_QUICK_SORT(A, q+1, r);
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
	
	RANDOMIZED_QUICK_SORT(A,1,100);
	
	cout<<"Sorted Sequence:-"<<endl;
	for (int i = 1; i < 101; i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
}
