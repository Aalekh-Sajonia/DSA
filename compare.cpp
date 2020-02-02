#include<bits/stdc++.h>
using namespace std;

void remove_dup(vector<int> a)
{
	set<int> st;
	for(int i=0;i<a.size();i++)
	{
		st.insert(a.at(i));
	}
	set<int>::iterator itr;
	for(itr=st.begin();itr!=st.end();itr++)
	{
		cout<<*itr<<" ";
	}
}

int main()
{
	vector<int> a;
	a.push_back(1);
	a.push_back(4);
	a.push_back(4);
	a.push_back(2);
	a.push_back(3);
	a.push_back(2);
	a.push_back(3);
	a.push_back(5);
	a.push_back(7);
	
	remove_dup(a);
}
