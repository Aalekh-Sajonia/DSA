#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int *start = new int[n+1]();
	int *end = new int[n+1]();
	int *tcoins = new int[n+1]();
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		start[a]++;
		end[b]++;
	}
	tcoins[1] = start[1];
	for(int i=2;i<=n;i++)
	{
		tcoins[i] = (start[i] - end[i-1]) + tcoins[i-1]; 
	}
	
	int *noBoxes = new int[n+1]();
	for(int i=1;i<=n;i++)
	{
		noBoxes[tcoins[i]]++;
	}
	
	for(int i=n-1;i>=1;i--)
	{
		noBoxes[i] = noBoxes[i] + noBoxes[i+1];
	}
	int t;
	cin>>t;
	while(t--)
	{
		int q;
		cin>>q;
		cout<<noBoxes[q]<<endl;			
	}	
    return 0;
}

