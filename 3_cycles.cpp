#include<iostream>
#include<vector>
using namespace std;

int solve(int n,int m,vector<int>u,vector<int>v)
{
	int adj_matrix[10000][10000];
	for(int i=0;i<m;i++)
	{
		adj_matrix[u[i]][v[i]]=1;
		adj_matrix[v[i]][u[i]]=1;
	}
	
	int count=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(adj_matrix[i][j]==1)
			{
				for(int k=1;k<=n;k++)
				{
					if(i==k)
						continue;
					if(adj_matrix[j][k]==1)
					{
						if(adj_matrix[k][i]==1)
							count++;
					}
				}
			}
		}
	}
	return count/6;
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
