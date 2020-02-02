#include<bits/stdc++.h>
using namespace std;
bool dec(pair<int,int> a,pair<int,int> b)
{
	return (a.second<b.second);
}

  
int main()
{
	vector<pair<int,int>>arr ;
	int n;
	cin>>n;
	int a,b;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		arr.push_back(make_pair(a,b));
	}
	sort(arr.begin(),arr.end(),dec);
	
	
	int count = 0;
	int min = arr[0].second;;
	for(int i=0;i<n;i++)
	{
		if(min<=arr[i].first)
		{
			min = arr[i].second;
			count++;
		}
	}
	cout<<count+1;
	return 0;
}
