#include<bits/stdc++.h>
using namespace std;

int stalls(int *arr,int size,int k,int current_stall)
{
	if(current_stall>=size)
	{
		return 0;
	}
	
	int select_stall = arr[current_stall] + stalls(arr,size,k,current_stall+k+1);
	
	int not_select_stalls = stalls(arr,size,k,current_stall+1);
	
	return max(select_stall,not_select_stalls);
}

int main()
{
	int n;
	cin>>n;
	int k;
	cin>>k;
	int *arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<stalls(arr,n,k,0);
	
	return 0;
}
