#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int* bubsort(int *arr,int n)
{
	int temp=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
	return arr;
}

int main()
{
	int arr[10]={10,2,3,1,21,26,123,12,32,23};
	int *arr1 = bubsort(arr,10);
	for(int i=0;i<10;i++)
	{
		cout<<arr1[i]<<endl;
	}
	
}
