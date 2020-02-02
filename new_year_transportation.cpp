#include<bits/stdc++.h>
using namespace std;
int flag;
void dfs(vector<int> *edges,int t,int start,int *visited)
{
	if(start==t)
		flag = 1;
	visited[start]=1;
	for(int i=0;i<edges[start].size();i++)
	{
		if(visited[edges[start][i]])
		{
			continue;
		}
		if(edges[start][i])
		{
			dfs(edges,t,edges[start][i],visited);
		}
	}
}

int main()
{
	int n,t;
	cin>>n>>t;
	vector<int> *edges = new vector<int>[n+1];
	for(int i=0;i<n-1;i++)
	{
		int a;
		cin>>a;
		edges[i+1].push_back((i+1)+a);
		//cout<<i+1<<" "<<(i+1)+a<<endl;
	}
	
	int *visited = new int[n+1]();
	dfs(edges,t,1,visited);
	if(flag)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}
