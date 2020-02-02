#include<bits/stdc++.h>
using namespace std;
bool visited[100010];
stack<int> st;
vector<int> adjList[100010];


// stack me wo sab se neeche hoga jisse aage kai aur jane ka rasta ni hoga 
// aisa karne se jisse maximum nodes coevr ho jaege wo uppar rahega stack me
// jaha se traverse karne se minimum number mil jaega.


void dfs2(int index)
{
	visited[index] = true;
	for(unsigned int j=0;j<adjList[index].size();j++)
	{
		if(!visited[adjList[index][j]])
		{
			dfs2(adjList[index][j]);
		}
	}
}

void dfs(int index)
{
	visited[index]=true;
	for(unsigned int j=0;j<adjList[index].size();j++)
	{
		if(!visited[adjList[index][j]])
		{
			dfs(adjList[index][j]);
		}
	}
	st.push(index);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(visited,false,sizeof(visited));
		int n,m;
		cin>>n>>m;
		for(int i=0;i<m;i++)
		{
			int a,b;
			cin>>a>>b;
			adjList[a].push_back(b);
		}
		int count=0;
		for(int i=1;i<=n;i++)
		{
			if(!visited[i])
			{
				dfs(i);
			}
		}
		
		memset(visited,false,sizeof(visited));
		count=0;
		while(!st.empty())
		{
			int index = st.top();
			cout<<index<<endl;
			st.pop();
			if(!visited[index])
			{
				count++;
				dfs2(index);
			}
		}
		cout<<count<<endl;
		for(int i=0;i<n;i++)
		{
			adjList[i].clear();
		}
	}
	return 0;
}
