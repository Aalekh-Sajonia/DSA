#include <iostream>
using namespace std;

void dfs(int **edge,int n,int start,int *visited)
{
	visited[start] = 1;
	for(int i=0;i<n;i++)
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
				dfs(edge,n,i,visited);
			}
		}
	}
}

int main() {
    int n,e;
    cin>>n>>e;
    int **edge = new int*[n];
    for(int i=0;i<n;i++)
    {
    	edge[i] = new int[n];
    	for(int j=0;j<n;j++)
    	{
    		edge[i][j]=0;
		}
	}
	
	for(int i=0;i<e;i++)
	{
		int a,b;
		cin>>a>>b;
		edge[a][b]=1;
		edge[b][a]=1;
	}
	int *visited = new int[n]();
	
	dfs(edge,n,0,visited);
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			cout<<"false";
			return 0;
		}
	}
	cout<<"true";
  return 0;
}

