#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str[10];
	vector<string> str1;
	int N;
	cin>>N;
	cin.ignore(1000,'\n');
	for(int i=0;i<N;i++)
	{
		getline(cin,str[i]);
		str1.push_back(str[i]);
	}
	
	for(int i=0;i<str1.size();i++)
	{
		cout<<str1.at(i)<<endl;
	}
	return 0;
}
