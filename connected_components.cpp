#include <bits/stdc++.h>
using namespace std;
vector<int> v;
void dfs(int **edge,int n,int start,int *visited)
{
	visited[start]=1;
	v.push_back(start);
//	cout<<start<<" ";
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

int main()
{
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
  
  int *visited = new int[n]();
  
  for(int i=0;i<e;i++)
  {
  	int a,b;
  	cin>>a>>b;
  	edge[a][b]=1;
  	edge[b][a]=1;
  }
  
  for(int i=0;i<n;i++)
  {
  	if(visited[i]==0)
  	{
  		dfs(edge,n,i,visited);
	//	cout<<v.size()<<endl;	
  		sort(v.begin(),v.end());
  		for(int i = 0;i<v.size();i++)
  		{
  			cout<<v[i]<<" ";	
		}
		v.clear();
		cout<<endl;
	}

  }

  return 0;
}

