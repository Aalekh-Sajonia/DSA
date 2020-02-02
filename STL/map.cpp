#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	map<int,string> customer;
	customer[100]="Aalekh";
	customer[110]="Sajonia";
	customer[150]="Rakshita";
	customer[200]="Rajat";
	customer.insert(pair<int,string>(250,"Tzuyu")); //pairs can only be inserted
	map<int,string>::iterator itr=customer.begin();
	
	for(itr=customer.begin();itr!=customer.end();itr++)
	{
		cout<<itr->second<<endl;
	}
	cout<<customer.size();
	 
	return 0;
}
