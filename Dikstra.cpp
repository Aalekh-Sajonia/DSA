#include<bits/stdc++.h>
using namespace std;

int getMinVertex(int *dist,bool *visited,int n)
{
	int minVertex = -1;
	for(int i=0;i<n;i++)
	{
		if(!visited[i] && (minVertex==-1 || dist[i]<dist[minVertex]))
		{
			minVertex = i;
		}
	}
	return minVertex;
}

void dijkstra(int **edges,int n)
{
	bool * visited = new bool[n]();
	int *distance = new int[n];
	for(int i=0;i<n;i++)
	{
		distance[i] = INT_MAX;
	}
	
	distance[0] = 0;
	
	for(int i=0;i<n-1;i++)
	{
		int minVertex = getMinVertex(distance,visited,n);
		visited[minVertex] = true;
		
		for(int j=0;j<n;j++)
		{
			if(edges[minVertex][j] && !visited[j])
			{
				int currD = distance[minVertex] + edges[minVertex][j];
				if(distance[j]>currD)
				{
					distance[j] = currD;
				}
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<i<<" "<<distance[i]<<endl;
	}
}

int main()
{
	int n,e;
	cin>>n>>e;
	int **edges = new int*[n];
	for(int i=0;i<n;i++)
	{
		edges[i] = new int[n];
		for(int j=0;j<n;j++)
			edges[i][j]=0;
	}
	
	for(int i=0;i<e;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		edges[a][b] = c;
		edges[b][a] = c;
	}
	
	cout<<endl;
	dijkstra(edges,n);
	
	return 0;
}
