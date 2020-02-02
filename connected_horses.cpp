#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

long long fact(int a)
{
	long long ans=1;
	for(int i=1;i<=a;i++)
	{
		ans = ans * i;
		ans = ans%mod;
	}
	return ans;
}

void fill(int **arr,unordered_set<int> *edges,int q,int n,int m)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr[i][j]!=0)
			{
				if(i+2<n and j-1>=0)
				{
					if(arr[i+2][j-1]!=0)
					{
						edges[arr[i][j]-1].insert(arr[i+2][j-1]-1);
						edges[arr[i+2][j-1]-1].insert(arr[i][j]-1);
					}
				}
				if(i+2<n and j+1<m)
				{
					if(arr[i+2][j+1]!=0)
					{
						edges[arr[i][j]-1].insert(arr[i+2][j+1]-1);
						edges[arr[i+2][j+1]-1].insert(arr[i][j]-1);
					}
				}
				if(i-2>=0 and j-1>=0)
				{
					if(arr[i-2][j-1]!=0)
					{
						edges[arr[i][j]-1].insert(arr[i-2][j-1]-1);
						edges[arr[i-2][j-1]-1].insert(arr[i][j]-1);
					}
				}
				if(i-2>=0 and j+1<m)
				{
					if(arr[i-2][j+1]!=0)
					{
						edges[arr[i][j]-1].insert(arr[i-2][j+1]-1);
						edges[arr[i-2][j+1]-1].insert(arr[i][j]-1);
					}
				}
				if(i+1<n and j-2>=0)
				{
					if(arr[i+1][j-2]!=0)
					{
						edges[arr[i][j]-1].insert(arr[i+1][j-2]-1);
						edges[arr[i+1][j-2]-1].insert(arr[i][j]-1);
					}
				}
				if(i-1>=0 and j-2>=0)
				{
					if(arr[i-1][j-2]!=0)
					{
						edges[arr[i][j]-1].insert(arr[i-1][j-2]-1);
						edges[arr[i-1][j-2]-1].insert(arr[i][j]-1);
					}
				}
				if(i+1<n and j+2<m)
				{
					if(arr[i+1][j+2]!=0)
					{
						edges[arr[i][j]-1].insert(arr[i+1][j+2]-1);
						edges[arr[i+1][j+2]-1].insert(arr[i][j]-1);
					}
				}
				if(i-1>=0 and j+2<m)
				{
					if(arr[i-1][j+2]!=0)
					{
						edges[arr[i][j]-1].insert(arr[i-1][j+2]-1);
						edges[arr[i-1][j+2]-1].insert(arr[i][j]-1);
					}
				}
			}
		}
	}
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
		int n,m,q;
		cin>>n>>m>>q;
		int **arr = new int*[n];
		for(int i=0;i<n;i++)
		{
			arr[i] = new int[m];
			for(int j=0;j<m;j++)
				arr[i][j]=0;
		}
		vector<int>* ed = new vector<int>[q];
		for(int i=0;i<q;i++)
		{
			int a,b;
			cin>>a>>b;
			arr[a-1][b-1]=i+1;
			
		}
			
		unordered_set<int>* edges = new unordered_set<int>[q];	
		
		fill(arr,edges,q,n,m);
		
		
		
		for(int i=0;i<q;i++)
		{
			unordered_set<int> :: iterator itr = edges[i].begin();
			for(itr ; itr!=edges[i].end();itr++)
			{
				ed[i].push_back(*itr);
			}
		}	
		
		/*for(int i=0;i<q;i++)
		{
			cout<<i+1<<" ";
			for(int j=0;j<ed[i].size();j++)
			{
				cout<<ed[i][j]<<" ";
			}
			cout<<endl;			
		}*/
		
		unordered_set<unordered_set<int>*>* components = getComponents(ed,q);	
		
		unordered_set<unordered_set<int>*> :: iterator itr;
		itr = components->begin();
		long long ans=1;
		while(itr!=components->end())
		{
			unordered_set<int>* component = *itr;
			ans *= fact(component->size());
			ans = ans%mod;
			itr++;
		}
	cout<<ans<<endl;
	}
	return 0;
}
