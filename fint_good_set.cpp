#include<bits/stdc++.h>
using namespace std;
#define N 750003
#define MOD 1000000007
typedef long long ll;
ll calFactors(ll factors[],ll *arr,ll n)
{
	for(ll i=1;i<N;i++)
	{
		if(factors[i]!=0)
		{
			for(ll j=i+i;j<N;j+=i)
			{
				if(factors[j]!=0)
				{
					factors[j] = (factors[j]%MOD + factors[i]%MOD)%MOD;
				}
			}
		}
	}
	
	ll sum=0;
	for(ll i=1;i<N;i++)
	{
		if(factors[i]>0)
			sum = (sum%MOD + factors[i]%MOD)%MOD;
	}
	if(factors[0]==1)
	{
	    return sum*2+1;
	}
	return sum;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll factors[N] = {0};
		ll n;
		cin>>n;
		ll *arr = new ll[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			factors[arr[i]] = 1;
		}
		sort(arr,arr+n);
		cout<<calFactors(factors,arr,n)<<endl;
	} 
	return 0;
}
