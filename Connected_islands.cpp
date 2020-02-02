#include<iostream>
#include<vector>
using namespace std;
int const MAXN = 120;
int visited[MAXN];
void DFS(int edge[][MAXN],int n,int start)
{
	visited[start]=1;
//	v.push_back(start);
//	cout<<start<<" ";
	for(int i=1;i<=n;i++)
	{
		if(i==start)
		{
			continue;
		}
		if(edge[start][i]==1)
		{
			if(visited[i]==1)
			{
				continue;
			}
			else
			{
				DFS(edge,n,i);
			}
		}
	}
}
int solve(int n,int m,vector<int>u,vector<int>v)
{
	int adj[MAXN][MAXN];
	for(int i=0;i<u.size();i++)
	{
		adj[u[i]][v[i]] = 1;
		adj[v[i]][u[i]] = 1;
	}
	
	
	int count = 0;
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==0)
		{
			count++;
			DFS(adj,n,i);	
		}
	}
	if(count>0)
	return count;
	else
	return 1;
}

int main()
{
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
}
