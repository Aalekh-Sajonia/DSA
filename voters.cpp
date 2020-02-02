#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N,M,K;
	cin>>N>>M>>K;
	int arr1[N];
	int arr2[M];
	int arr3[K];
	map<int,int> m;
	for(int i=0;i<N;i++)
	{
		cin>>arr1[i];
		m[arr1[i]]++;
	}
	for(int i=0;i<M;i++)
	{
		cin>>arr2[i];
		m[arr2[i]]++;
	}
	for(int i=0;i<K;i++)
	{
		cin>>arr3[i];
		m[arr3[i]]++;
	}
	map<int,int>::iterator itr;
	vector<int> myvect;
	int counter=0;
	for(itr=m.begin();itr!=m.end();itr++)
	{
		if(itr->second>=2)
		{
			myvect.push_back(itr->first);
			counter++;
		}
	}
	cout<<counter++<<endl;
	for(int i=0;i<myvect.size();i++)
	{
		cout<<myvect.at(i)<<endl;
	}
	return 0;
}
