#include<bits/stdc++.h>
using namespace std;

bool comp(int *arr,int *q,int size,unordered_set<int>* component)
{
	for(int i=0;i<size;i++)
	{
		unordered_set<int> :: iterator itr = component->begin();
		int flag=0;
		while(itr!=component->end())
		{
		//	cout<<arr[i]<<" "<<q[*itr]<<endl;
			if(arr[i]==q[*itr])
				flag=1;
			itr++;
		}
		if(flag==0)
			return false;
	}
	return true;
}


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
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		int m;
		cin>>m;
		int* p = new int[n];
		int* q = new int[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i];
		}
		for(int i=0;i<n;i++)
		{
			cin>>q[i];
		}
		vector<int>* edges = new vector<int>[n];
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
		int flag= 0;
		while(itr!=components->end())
		{
			flag=0;
			unordered_set<int>* component = *itr;
			unordered_set<int> :: iterator it = component->begin();
			int* arr = new int[component->size()];
			int* arrcomp = new int[component->size()];
			int i=0;
			while(it != component->end())
			{
				arr[i] = p[*it];
			//	cout<< *it + 1<<" ";
				it++;
				i++;
			}
			bool ans = comp(arr,q,component->size(),component);
			if(ans==false)
			{
				flag=1;
				cout<<"NO"<<endl;
				break;
			}
			itr++;
		}
		if(flag==0)
		{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}
