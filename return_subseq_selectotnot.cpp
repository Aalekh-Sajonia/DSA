#include<bits/stdc++.h>
using namespace std;

void fun(string str,string output)
{
	if(str.empty())
	{
		cout<<output<<endl;
		return;
	}
	
	fun(str.substr(1),output);
	fun(str.substr(1),output + str[0]);
}
int main()
{
	string str;
	cin>>str;
	string output;
	fun(str,output);
	return 0;
}
