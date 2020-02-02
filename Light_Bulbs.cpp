#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x,y;
	cin>>n>>x>>y;
	string str;
	cin>>str;
	long long int zero_groups=0;
	if(str[0]=='0')
	zero_groups++;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='1'&&str[i+1]=='0')
		{
			zero_groups++;
		}
	}
	if(zero_groups==0)
	{
		cout<<"0";
		return 0;
	}
	cout<<(zero_groups-1)*min(x,y) + y;
	return 0;
}
