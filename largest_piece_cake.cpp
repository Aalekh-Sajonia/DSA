#include<iostream>
#include<vector>
using namespace std;
#define NMAX 55
int visited[NMAX][NMAX];
int c=0;
int DFS(int i,int j,int n,char cake[][NMAX])
{
	//cout<<i<<" "<<j<<endl;
	visited[i][j]=1;
	if(i+1>=0 && i+1<n && visited[i+1][j]==0 && cake[i+1][j]=='1')
	{
		c+= DFS(i+1,j,n,cake);
	}
	if(j+1>=0 && j+1<n && visited[i][j+1]==0 && cake[i][j+1]=='1')
	{
		c+= DFS(i,j+1,n,cake);
	}
	if(i-1>=0 && i-1<n && visited[i-1][j]==0 && cake[i-1][j]=='1')
	{
		c+= DFS(i-1,j,n,cake);
	}
	if( j-1>=0 && j-1<n && visited[i][j-1]==0 && cake[i][j-1]=='1')
	{
		c+= DFS(i,j-1,n,cake);
	}
	return 1;
}

int solve(int n,char cake[NMAX][NMAX])
{
	int max = INT_MIN;
	for(int i=0;i<n;i++)
	{
	
		for(int j=0;j<n;j++)
		{
			c=0;
			if(visited[i][j]==0 && cake[i][j]=='1')		
			{
				int a = DFS(i,j,n,cake);		
			}
			cout<<endl;
			if(c+1>max)
			max = c+1;
		}	
		
	}	
	return max;
	
}
char cake[NMAX][NMAX];

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%s",cake[i]);
	}
	cout<<solve(n,cake)<<endl;
}
