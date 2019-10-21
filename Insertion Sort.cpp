//Program for INSERTION SORT

#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

void INSERTION_SORT(int A[],int n)
{
	int key;
	int i;
	for (int j = 2; j < n; j++)
	{
		key = A[j];
		//Insert A[j] into the sorted sequence A[1..j-1]
		i = j - 1;
		while (i > 0 && A[i] > key)
		{
			A[i+1] = A[i];
			i = i - 1;
		}
		A[i+1] = key;
	}
}

int main()
{
	int A[100000];
	
	//Using random function to store random values in array A
	for (int i = 1; i < 100000; i++)
	{
		A[i] = rand();
	}
	INSERTION_SORT(A,100000);
	
	cout<<"Sorted Sequence:-"<<endl;
	for (int i = 1; i < 100000; i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
	
}


