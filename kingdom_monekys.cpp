#include<bits/stdc++.h>
using namespace std;
long long sum=0;
void dfs(vector<int> *edges,int n,int *visited,int start,int *weight)
{
	//cout<<weight[start]<<" ";
	visited[start] = 1;
	sum += weight[start];
	for(int i=0;i<edges[start].size();i++)
	{
		if(visited[edges[start][i]])
		{
			continue;
		}
		else
		{
			dfs(edges,n,visited,edges[start][i],weight);
		}
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{	
		int n,m;
		cin>>n>>m;
		int* weight = new int[n];
		vector<int>* edges = new vector<int>[n];
		
		for(int i=0;i<m;i++)
		{
			int a,b;
			cin>>a>>b;
			edges[a-1].push_back(b-1);
			edges[b-1].push_back(a-1);	
	 	} 
		
		for(int i=0;i<n;i++)
		{
			cin>>weight[i];
		}
		
		int *visited = new int[n]();
		
		long long ans = INT_MIN;
		for(int i = 0;i<n;i++)
		{
			sum=0;
			if(!visited[i])
			{
				dfs(edges,n,visited,i,weight);
				if(sum>ans)
				{
					ans = sum;
				}
			//	cout<<endl;
			}
		}
		cout<<ans<<endl;
		delete [] visited;
		delete [] weight;
		delete [] edges;
	}
	return 0;
}
