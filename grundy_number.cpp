#include<bits/stdc++.h>
using namespace std;

int calMex(unordered_set<int> s)
{
	int mex = 0;
	while(s.find(mex)!= s.end())
	{
		mex++;
	}
	return mex;
}

int grundy(int n)
{
	if(n==0)
	{
		return 0;
	}
	
	unordered_set<int> s;
	
	s.insert(grundy(n/2));
	s.insert(grundy(n/3));
	s.insert(grundy(n/6));	
	
	return calMex(s);	
}

int main()
{
	int n;
	cin>>n;
	cout<<grundy(n);	
	return 0;
}
