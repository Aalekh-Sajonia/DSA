#include<bits/stdc++.h>
using namespace std;
const int N =510;
int m[N][N];
int d[N][N];
int r,c;
void dp()
{
    d[r][c]=1;
    for(int i=r-1;i>=1;i--)
        d[i][c] = max(1,d[i+1][c]-m[i][c]);
        
        
    for(int i=c-1;i>=1;i--)
        d[r][i]= max(1,d[r][i+1]-m[r][i]);
        
        
    for(int i=r-1;i>=1;i--)
    for(int j=c-1;j>=1;j--)
        d[i][j]= max(1,min(d[i+1][j]-m[i][j],d[i][j+1]-m[i][j]));
}
int main()
{
	cin>>n;
	while(n--)
	{
	cin>>r>>c;
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			cin>>m[i][j];
		}
	}
	dp();
	cout<<d[1][1];
	cout<<endl;
	}
	return 0;
}
