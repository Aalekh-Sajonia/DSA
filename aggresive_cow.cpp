#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(int cow,ll positions[],int n,ll distance)
{
	int count = 1;
	long long last_position = positions[0];

	for(int i=0;i<n;i++)
	{
		if(positions[i] - last_position >= distance)
		{
			count++;
			last_position = positions[i];
		}
		
		if(count == cow)
		{
			return true;
		}
	}
	return false;
	
	
}

int main() {
	
	int t;
	cin>>t;
	int N,C;
	while(t--)
	{
		cin>>N;
		cin>>C;
		long long *arr = new long long[N];
		for(int i=0;i<N;i++)
		{
			cin>>arr[i];
		}
		sort(arr,arr+N);
		long long end = arr[N-1] - arr[0];
		long long start = 0;
		long long ans = -1;
		while(start<=end)
		{
			ll mid = start + (end-start)/2;
			if(check(C,arr,N,mid))
			{
				ans = mid;
				start = mid+1;
			}
			else
			{
				end = mid-1;
			}
		}
		cout<<ans<<endl;
		delete []arr;
	}

	return 0;
}
