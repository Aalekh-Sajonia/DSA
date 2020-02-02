#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	list<int> l1{3,2,1};
	list<int>::iterator itr=l1.begin();
/*	while(itr!=l1.end())
	{
		cout<<*itr<<" ";
		itr++;
	}*/
	l1.push_back(4);
	l1.push_front(0);
	
	//l1.pop_back();
	//l1.pop_front();
	l1.sort();
	l1.reverse();
	l1.remove(2);
	//l1.clear();
	for(itr=l1.begin();itr!=l1.end();itr++)
	{
		cout<<*itr<<" ";
	}
	cout<<endl;
	cout<<l1.size();
	return 0;
}
