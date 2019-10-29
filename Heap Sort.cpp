//Program for  Heap Sort

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int PARENT(int i)                                //Calculating parent's index
{
	return i / 2;
}

int LEFT(int i)                                  //Calculating Left child's index
{
	return 2 * i;
}

int RIGHT(int i)                                  //Calculating Right child's index
{
	return 2 * i + 1;
}
void MAX_HEAPIFY(int A[], int heap_size, int i)                 //function to maintain the Max Heap Property
{
	int temp;
	int largest;
	int l = LEFT(i);
	int r = RIGHT(i);
	
	if (l <= heap_size && A[l] > A[i])
		largest = l;
	else
		largest = i;
	
	if (r <= heap_size && A[r] > A[largest])
		largest = r;
		
	if (largest != i)
	{
		temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		
		MAX_HEAPIFY(A,heap_size,largest);
	}
}

BUILD_MAX_HEAP(int A[], int n)
{
	int heap_size = n;
	for (int i = n / 2; i >= 1; i--)
	{
		MAX_HEAPIFY(A,heap_size,i);
	}
}
void HEAP_SORT(int A[], int n, int heap_size)
{
	int temp;
	BUILD_MAX_HEAP(A,n);
	
	for (int i = n; i >= 2; i--)
	{
		temp = A[1];
		A[1] = A[i];
		A[i] = temp;
		
		heap_size = heap_size - 1;
		MAX_HEAPIFY(A,heap_size,1);
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
	
	HEAP_SORT(A,100,100);
	
	cout<<"Sorted Sequence:-"<<endl;
	for (int i = 1; i < 101; i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

