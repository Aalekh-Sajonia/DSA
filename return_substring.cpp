#include<bits/stdc++.h>
using namespace std;

int subseq(string str,string output[])
{
	if(str.empty())
	{
		output[0] = "";
		return 1;
	}
	
	string smallstr = str.substr(1);
	int smalloutputsize = subseq(smallstr, output);
	
	for(int i=0;i<smalloutputsize;i++)
	{
		output[i+smalloutputsize] = str[0] + output[i]; 
	}
	return 2*smalloutputsize;
}
int main()
{
	string str;
	cin>>str;
	string output[100];
	int count = subseq(str,output);
	for(int i=0;i<count;i++)
	{
		cout<<output[i]<<endl;
	}
	return 0;
}
