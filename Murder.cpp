#include<bits/stdc++.h>
using namespace std;

long long merge(int arr[],int left,int mid,int right)
{
	int i = left;
	int j = mid;
	int k = 0;
	long long sum = 0;
	
	int temp[right-left+1];
	
	while(i<mid && j<=right)
	{
		if(arr[i]<arr[j])
		{			
			sum += arr[i]*(right-j+1);
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];	
		}
	}
	while(i<mid)
	{
		temp[k++]=arr[i++];
	}
	while(j<=right)
	{
		temp[k++] = arr[j++];
	}

	for(int i=left,k=0;i<=right;i++,k++)
	{
		arr[i] = temp[k];
	}
	return sum;
}

long long merge_sort(int arr[],int left,int right)
{
	long long sum = 0;
	if(right>left)
	{
		int mid = (left+right)/2;
		
		long long lsum = merge_sort(arr,left,mid); 
		long long rsum = merge_sort(arr,mid+1,right);
		long long tsum = merge(arr,left,mid+1,right);
		
		return lsum + rsum + tsum;
		
	}
	return sum;
}

long long solve(int arr[],int n)
{
	long long ans = merge_sort(arr,0,n-1);
	return ans;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		int* arr = new int[N];
		for(int i=0;i<N;i++)
		{
			cin>>arr[i];
		}
		
		cout<<solve(arr,N)<<endl;
		
		
	}
	return 0;
}
