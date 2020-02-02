#include <bits/stdc++.h>
using namespace std;

void print(vector<int> *edge,int n,int start,int *visited,queue<int> q)
{
  //  cout<<start<<" ";
  	int *lvl = new int[n]();
    q.push(start);
    visited[start] = 1;
    int level=0;
    int ans=0;
    lvl[0] = level;
    while(!q.empty())
    {
    	int currentVertex = q.front();
    //	cout<<edge[currentVertex].size()<<endl;
    	q.pop();
        for(int i=0;i<edge[currentVertex].size();i++)
        {
            if(visited[edge[currentVertex][i]])
                continue;
            if(edge[currentVertex][i])
            {
                visited[edge[currentVertex][i]] = 1;
                q.push(edge[currentVertex][i]);
                lvl[edge[currentVertex][i]] = lvl[currentVertex]+1;
               // cout<<edge[currentVertex][i]<<" ";
            }
            if(edge[currentVertex][i]==n-1)
            {
            	cout<<lvl[currentVertex]+1<<endl;
            	return ;
			}
        }
        level++;
    }
//	cout<<ans<<endl; 
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
    int n, e;
    cin >> n >> e;
    vector<int>* edges = new vector<int>[n];
    
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }
    
    int *visited = new int[n];
    for(int i=0;i<n;i++)
    {
        visited[i] = 0;
    }
    queue<int> q;
       
    print(edges,n,0,visited,q);
}	
  return 0;
}

