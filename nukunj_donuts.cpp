#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    long long int *arr = new long long int[n];
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
	}
	sort(arr,arr+n,greater<int>());
	long long ans=0;
	int k=0;
	for(int i=0;i<n;i++)
	{
		ans += arr[i]*(1<<i);	
	}
	cout<<ans<<endl;
    return 0;
}
