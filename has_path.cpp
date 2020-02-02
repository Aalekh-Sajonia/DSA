#include <iostream>
using namespace std;
int flag;
void dfs(int **edge,int n,int v1,int v2,bool *visited)
{	
//	cout<<v1<<endl;
	visited[v1]=true;
	/*if(visited[v2]==1)
	return true;*/
	for(int i=0;i<n;i++)
	{
		if(i==v1)
		{
			continue;
		}

		if(edge[v1][i]==true)
		{
			if(visited[i])
			{
				continue;
			}
			if(i==v2)
			{
				flag = 1;
				return ;
			}
			dfs(edge,n,i,v2,visited);		
		}		
	}
	return ;
}
int main() {
    int n,e;
    cin >> n >> e;
    
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
	
	bool visited[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
		
	int v1,v2;
	cin>>v1>>v2;
	dfs(edge,n,v1,v2,visited);
	if(flag==1)
	{
		cout<<"true";
	}
	else
	{
		cout<<"false";
	}
  return 0;
}

