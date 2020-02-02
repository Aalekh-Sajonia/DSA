#include<bits/stdc++.h>
using namespace std;
int cube[1000001];
int num[1000001];
typedef long long ll;
void calCube()
{
	for(ll i=2;i<=100;i++)
	{
		if(cube[i]==0)
		{
			for(ll j=1;i*i*i*j<1000001;j++)
			{
				cube[i*i*i*j] = -1;
			}
		}
	}
	
	ll k=1;
	for(ll i=1;i<1000001;i++)
	{
		if(cube[i]!=-1)
		{
			num[i] = k;
			k++;
		}
	}
}

int main()
{
	calCube();
	
//	for(int i=0;i<50;i++)
//	{
//		cout<<i<<" "<<cube[i]<<endl;
//	}
	
	int t;
	cin>>t;
	int k=1;
	while(t--)
	{
		int a;
		cin>>a;
		cout<<"Case "<<k<<": ";
		if(num[a]!=0)
		{
			cout<<num[a];
		}
		else
		{
			cout<<"Not Cube Free";
		}
		cout<<endl;
		k++;
	}
	return 0;
}
