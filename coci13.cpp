#include<bits/stdc++.h>
using namespace std;

bool comparator(pair<long long,long long> a,pair<long long,long long> b)
{
	if(a.second!=b.second)
	return a.second > b.second;
	
	return a.first < b.first;
}
int main()
{
	long long N,K;
	cin>>N>>K;
	pair<long long,long long> *arr = new pair<long long,long long>[N];
	for(int i=0;i<N;i++)
	{
		cin>>arr[i].first>>arr[i].second;
	}
	multiset<long long> bags;
	for(int i=0;i<K;i++)
	{
		long long a;
		cin>>a;
		bags.insert(a);
	}
	sort(arr,arr+N,comparator);
	long long ans=0;
	for(int i=0;i<N;i++)
	{
		if(bags.empty())
		{
			break;
		}
		if(bags.lower_bound(arr[i].first)!=bags.end())
		{
			ans += arr[i].second;
			bags.erase(bags.lower_bound(arr[i].first));
		}
	}
	cout<<ans;
	return 0;
}
