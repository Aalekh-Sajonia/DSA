#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	map<int,int> m;
	int temp;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		m[temp]++;
	}
	
	map<int,int>::iterator itr;
	for(itr=m.begin();itr!=m.end();itr++)
	{
		if(itr->second>=2)
		{
			cout<<itr->first<<endl;
		}
	}
	return 0;
}
