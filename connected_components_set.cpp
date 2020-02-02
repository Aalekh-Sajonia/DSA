#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>* edges,int start,unordered_set<int>* component,bool* visited)
{
	visited[start] = true;
	component->insert(start);
	for(int i=0;i<edges[start].size();i++)
	{
		int next = edges[start][i];
		if(!visited[next])
		{
			dfs(edges,next,component,visited);
		}
	}
}

unordered_set<unordered_set<int>*>* getComponents(vector<int>* edges,int n)
{
	bool *visited = new bool[n]();
	
	unordered_set<unordered_set<int>*>* output = new  unordered_set<unordered_set<int>*>();
	
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			unordered_set<int>* component = new unordered_set<int>();
			dfs(edges,i,component,visited);
			output->insert(component);
		}
	}
	
	delete[] visited;
	return output;
}

int main()
{
	int n;
	cin>>n;
	vector<int>* edges = new vector<int>[n];
	int m;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		edges[a-1].push_back(b-1);
		edges[b-1].push_back(a-1);
	}
	unordered_set<unordered_set<int>*>* components = getComponents(edges,n);
	
	unordered_set<unordered_set<int>*> :: iterator itr;
	itr = components->begin();
	while(itr!=components->end())
	{
		unordered_set<int>* component = *itr;
		unordered_set<int> :: iterator it = component->begin();
		while(it != component->end())
		{
			cout<< *it + 1<<" ";
			it++;
		}
		cout<<endl;
		itr++;
	}
	
	return 0;
}
