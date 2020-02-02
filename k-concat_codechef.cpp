#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll kadane(int arr[],int n){
	ll current_sum=0;
	ll max_sum=INT_MIN;
	for(int i=0;i<n;i++){
		current_sum+=arr[i];
		if(max_sum>current_sum){
			max_sum=current_sum;
		}
		if(current_sum<0){
			current_sum=0;
		}
	}
	return max_sum;
}

ll maxSubArraySym(int arr[],int n,int k){
	ll kadanes_sum=kadane(arr,n);
	if(k==1){
		return kadanes_sum;
	}
	
	ll curr_prefix_sum=0,curr_suffix_sum=0;
	ll max_prefix_sum = INT_MIN, max_suffix_sum=INT_MIN;
	
	for(int i=0;i<n;i++){
		curr_prefix_sum += arr[i];
		max_prefix_sum = max(curr_prefix_sum,max_prefix_sum);
	}
	ll total_sum = curr_prefix_sum;
	for(int i=n-1;i>=0;i--){
		curr_suffix_sum += arr[i];
		max_suffix_sum = max(max_suffix_sum,curr_suffix_sum);	
	}
	ll ans;
	if(total_sum<0){
		
		ans=max(max_prefix_sum+max_suffix_sum,kadanes_sum);
		
	}else{
		
		ans=max(max_prefix_sum+max_suffix_sum+(total_sum*(k-2)),kadanes_sum);
	}
	
	return ans;
	
}


int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		cout<< maxSubArraySym(arr,n,k)<<endl;
	}
	return 0;
}
