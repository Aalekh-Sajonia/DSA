#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n,greater<int>());
	int max = -1;
	int arr1[3];
	for(int i=0;i<n;i++)
	{
		if(arr[i]<arr[i+1]+arr[i+2])
		{
			arr1[0] = arr[i];
			arr1[1] = arr[i+1];
			arr1[2] = arr[i+2];
			max = arr1[0]+arr1[1]+arr1[2];
			break;
		}
	}
	sort(arr1,arr1+3);
	if(max==-1)
	{
		cout<<"-1";
	}
	else
	{
		cout<<arr1[0]<<" "<<arr1[1]<<" "<<arr1[2]<<endl;
	}
	return 0;
}
