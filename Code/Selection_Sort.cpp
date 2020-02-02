#include<iostream>
using namespace std;

void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int *selsort(int *arr,int n)
{
	int min,loc;
	for(int i=0;i<n-1;i++)
	{
		min = arr[i];
		loc = i;
		for(int j=i+1;j<n;j++)
		{
			if(min>arr[j])
			{
				min = arr[j];
				loc =  j;
			}
		}
		swap(&arr[i],&arr[loc]);
		
	}
	return arr;
}

int main()
{
	int arr[10] = {32,13,23,12,45,5,4,34,56,39};
	int *arr1 = selsort(arr,10);
	
	for(int i=0;i<10;i++)
	{
		cout<<arr1[i]<<endl;
	}

}
