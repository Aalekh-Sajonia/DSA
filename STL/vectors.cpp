#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> a {1,2,3,4};
/*	vector<int> b(5,20);
	cout<<a.capacity()<<endl;
	a.push_back(10);
	a.pop_back();
	cout<<a.size();*/
	vector<int> :: iterator it=a.begin();
	a.insert(it+2,6);
	for(int i=0;i<a.size();i++)
	{
		cout<<a.at(i)<<" ";
	}
	return 0;
}
