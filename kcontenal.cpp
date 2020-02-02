#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll kadane(int arr[],int n)
{
	ll curr_sum=0;
	ll max_so_far=0;
	for(int i=0;i<n;i++)
	{
		curr_sum=curr_sum + arr[i];
 		if(max_so_far<curr_sum)
 		{
 			max_so_far = curr_sum;	
		}
		if(curr_sum<0)
		{
			curr_sum=0;
		}
	}
	return max_so_far;
}

ll maxSum(int arr[],int n,int k)
{
		ll kadane_sum = kadane(arr,n);
		if(k==1)
		{
			return kadane_sum;
		}
		
		ll curr_prefix_sum = 0;
		ll curr_suffix_sum = 0;
		ll max_prefix_sum = INT_MIN;
		ll max_suffix_sum = INT_MIN;
		
		for(int i=0;i<n;i++)
		{
			curr_prefix_sum = curr_prefix_sum + arr[i];
			max_prefix_sum = max(curr_prefix_sum,max_prefix_sum);
		}
		ll totalsum = curr_prefix_sum;
		for(int i=n-1;i>=0;i--)
		{
			curr_suffix_sum = curr_suffix_sum + arr[i];
			max_suffix_sum = max(max_suffix_sum,curr_suffix_sum);
		}
		ll ans;
		if(totalsum<0)
		{
			ans=max(max_suffix_sum + max_prefix_sum,kadane_sum);
		}
		else
		{
			ans = max(max_suffix_sum+max_prefix_sum+(totalsum*(k-2)),kadane_sum);
		}
		return ans;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int *arr;
		arr = new int[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		cout<<maxSum(arr,n,k)<<endl;
		delete[] arr;
	}
	return 0;
}
