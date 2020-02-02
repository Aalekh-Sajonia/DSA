#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main()
{

	string str;
	int n,i,x;
	long long int A[50001];
	while(1)
	{
		cin>>str;
		if(str[0]=='0')
		break;
		n=str.size();
		for(int i=0;i<5000;i++)
		{
			A[i] = 0;
		}
		A[0]=1;
		for(int i=1;i<n;i++)
		{
			x = (str[i-1]-'0')*10+(str[i]-'0');
			if(str[i]!='0')
				A[i] =  A[i-1];
			if(x>=10&&x<=26 && i>1)
				A[i] += A[i-2];
			else if(x>=10&&x<=26)
				A[i]++;
			A[i] = A[i]%mod;
		}
		cout<<A[n-1]<<endl;
	}
	return 0;
}
