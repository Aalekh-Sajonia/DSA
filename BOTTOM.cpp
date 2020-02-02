#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>* edges,int start,unordered_set<int> &visited, stack<int> &finishStack)
{
	visited.insert(start);
	for(int i=0;i<edges[start].size();i++)
	{
		int adjacent = edges[start][i];
		if(visited.count(adjacent) == 0)
		{
			dfs(edges,adjacent,visited,finishStack);
		}
	}
	finishStack.push(start);	
}

void dfs2(vector<int>* edges,int start,unordered_set<int>* component,unordered_set<int> &visited)
{
	visited.insert(start);
	component->insert(start);
	for(int i=0;i<edges[start].size();i++)
	{
		int adjacent = edges[start][i];
		if(visited.count(adjacent) == 0)
		{
			dfs2(edges,adjacent,component,visited);
		}
	}
}

unordered_set<unordered_set<int>*>* getSCC(vector<int>* edges,vector<int>* edgesT,int n)
{
	unordered_set<int> visited;
	stack<int> finishedVertices;
	for(int i=0;i<n;i++)
	{
		if(visited.count(i)==0)
		{
			dfs(edges,i,visited,finishedVertices);
		}
	}
	unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
	visited.clear();
	while(finishedVertices.size() != 0)
	{
		int element = finishedVertices.top();
		finishedVertices.pop();
		if(visited.count(element)!=0)
		{
			continue;
		}
		unordered_set<int>* component = new unordered_set<int>();
		dfs2(edgesT, element, component,visited);
		output->insert(component);
	}
	return output;
}

int main()
{
	while(true)
	{
		int n;
		cin>>n;
		if(n==0)
			break;
		vector<int>* edges = new vector<int>[n];
		vector<int>* edgesT = new vector<int>[n];
		int m;
		cin>>m;
	
		for(int i=0;i<m;i++)
		{
			int a,b;
			cin>>a>>b;
			edges[a-1].push_back(b-1);
			edgesT[b-1].push_back(a-1);
		}
		
		unordered_set<unordered_set<int>*>* components = getSCC(edges,edgesT,n);
		
		unordered_set<unordered_set<int>*> :: iterator itr = components->begin();
		vector<int> store;
		while(itr!= components->end())
		{
			unordered_set<int> *component = *itr;
			unordered_set<int> :: iterator it = component->begin();
			int flag=0;
			while(it!=component->end())
			{
				for(int i=0;i<edges[*it].size();i++)
				{
					if(component->count(edges[*it][i])==0)
					{
						flag=1;
						break;
					}
				}	
				if(flag==1)
					break;		
				it++;
			}
			if(flag==0)
			{
				it = component->begin();		
				while(it!=component->end())
				{
					store.push_back(*it);
					it++;
				}	
			}
		//	delete component;
			itr++;
		}
		
		sort(store.begin(),store.end());
		vector<int> :: iterator it1;
		it1 = store.begin();
		while(it1!=store.end())
		{
			cout<<*it1+1<<" ";
			it1++;
		}
		cout<<endl;
		delete components;
		delete [] edges;
		delete [] edgesT;
	}
	return 0;
}
