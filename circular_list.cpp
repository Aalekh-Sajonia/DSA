#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int i,p;
	while(t--)
	{
		cin>>i>>p;
		int mod = p%12;
		int ans = i+mod;
		if(ans<12)
		{
			cout<<ans;
		}
		else
		{
			mod = ans-11;
			cout<<mod-1;
		}
	}
	
	return 0;
}
