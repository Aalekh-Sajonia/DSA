#include<bits/stdc++.h>
using namespace std;

bool find(int arr[],int n,int ele,int k)
{
	int temp;
	int count=0;
	for(int i=0;i<n;i++)
	{
		temp = arr[i]/ele;
		if(temp>0)
		{
			count += temp;
		}
		if(count >= k)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int *arr = new int[n];
		int *arr1 = new int[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			arr1[i] = arr[i];
		}
		sort(arr,arr+n,greater<int>());
		int largest = arr[0];
		int smallest = 0;
		int max_mid = INT_MIN;
		while(smallest<largest)
		{
			int mid = (smallest+largest)/2;
			cout<<mid<<endl;
			if(find(arr1,n,mid,k))
			{
				smallest = mid+1;
				if(max_mid<mid)
				max_mid = mid;
			}
			else
			{
				largest = mid;
			}
		}
		cout<<max_mid<<endl;
	}
}
