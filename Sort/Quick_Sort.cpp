#include<bits/stdc++.h>
using namespace std;

int partition(int *arr,int lb,int ub)
{
	int pivot = arr[lb];
	int start = lb;
	int end = ub;
	
	while(start<end)
	{
		while(arr[start] <= pivot)
		{
			start++;	
		}	
		while(arr[end] > pivot)
		{
			end--;
		}
		if(start<end)  // do this for security as the above statements might cross start with end;
		{
			swap(arr[start],arr[end]);
		}
	}	
	
	swap(arr[lb],arr[end]);
	return end;	
}

void quickSort(int *arr,int start,int end)
{
	if(start<end)
	{
		int mid = partition(arr,start,end);
		
		quickSort(arr,start,mid-1);
		quickSort(arr,mid+1,end);		
	}
}

void printArr(int *arr,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	quickSort(arr,0,n-1);
	printArr(arr,n);	
	return 0;
}
