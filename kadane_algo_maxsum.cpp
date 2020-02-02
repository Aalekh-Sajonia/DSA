#include<bits/stdc++.h>
using namespace std;
int kadane(int arr[],int n){
	int current_sum=0;
	int best_sum=0;
	for(int i=0;i<n;i++){
		current_sum+=arr[i];
		if(current_sum>best_sum){
			best_sum=current_sum;
		}
		if(current_sum<0){
			current_sum=0;
		}
	}
	return best_sum;
}
int main()
{
	int arr[]={2,3,-6,-4,7,9,1};
	cout<<kadane(arr,7);
	return 0;
}
