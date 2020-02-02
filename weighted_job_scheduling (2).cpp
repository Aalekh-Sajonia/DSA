#include<bits/stdc++.h>
using namespace std;
struct Job
{
	int start,finish,profit;
};
bool compare(Job a,Job b)
{
	return a.finish < b.finish;
}

int fMProfit(Job arr[],int n)
{
	sort(arr,arr+n,compare);
	int *dp = new int[n];
	dp[0] = arr[0].profit;
	
	for(int i=1;i<n;i++)
	{
		int inc = arr[i].profit;
		int lNConflict = -1;
		
		int right = i;
		int left = 0;
		int mid = left + ((right-left)/2);
		while(left<=right)
		{
			mid = left + ((right-left)/2);
			if(arr[mid].finish <= arr[i].start)
			{
				lNConflict = mid;
				left = mid+1;
			}
			else
			{
				right = mid-1;
			}
		}
		if(lNConflict != -1)
		{
			inc += dp[lNConflict];
		}
		dp[i] = max(inc,dp[i-1]);
	}
	return dp[n-1];
}

int main()
{
	int n;
	cin>>n;
	Job *arr = new Job[n];
	int a,b,c;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i].start>>arr[i].finish>>arr[i].profit;
	}
	cout<<fMProfit(arr,n);
	return 0;
}
