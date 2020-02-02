/*#include<iostream>
using namespace std;
int *inssort(int *arr,int n)
{
	for(int i=1;i<n;i++)
	{
		int temp = arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>temp)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
	return arr;
}
int main()
{
	int arr[10]={32,3,5,21,232,13,13,23,123,23};
	int *arr1 = inssort(arr,10);
	for(int i=0;i<10;i++)
	{
		cout<<arr1[i]<<endl;
	}
}*/

#include<iostream>
using namespace std;

int *inssort(int *arr,int n)
{
	for(int i=1;i<n;i++)
	{
		int temp=arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>temp)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
	return arr;
}


int main()
{
	int arr[10] = {12,32,1,23,123,123,24,34,23,443};
	int *arr1 = inssort(arr,10);
	for(int i=0;i<10;i++)
	{
		cout<<arr1[i]<<endl;
	}
	return 0;
}


































