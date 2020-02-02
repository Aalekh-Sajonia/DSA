#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	cin>>a;
	tuple<string,int,int> t1[a];
	/*t1=make_tuple("Aalekh",1,10);
	cout<<get<0>(t1)<<" ";
	cout<<get<1>(t1)<<" ";
	cout<<get<2>(t1);*/
	
	for(int i=0;i<a;i++)
	{
		string str;
		int b,c;
		cin>>str;
		cin>>b;
		cin>>c;
		t1[i]=make_tuple(str,b,c);
	}
	for(int i=0;i<a;i++)
	{
		cout<<get<0>(t1[i])<<" ";
		cout<<get<1>(t1[i])<<" ";
		cout<<get<2>(t1[i]);
		cout<<endl;
	}
	return 0;
}
