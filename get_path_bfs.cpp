#include <bits/stdc++.h>
using namespace std;
map<int,int> m;

bool BFS(int **edge,int n,int v1,int v2,int *visited)
{
	queue<int> q;
	q.push(v1);
	while(!q.empty())
	{
		for(int i=0;i<n;i++)
		{
			if(i==v1)
			continue;
			if(edge[q.front()][i]==1)
			{
				if(visited[i]==1)
				continue;
				else
				{
					visited[i]=1;
					m.insert(pair<int,int>(i,q.front()));
					q.push(i);
					if(i==v2)
					{
						return true;
					}
				}
			}
		}
		q.pop();
	}
	return false;
}

int main()
{
  int n, e, tempX, tempY;
  cin >> n >> e;
  int **edge = new int*[n];
  for(int i=0;i<n;i++)
  {
  	edge[i] = new int[n];
  	for(int j=0;j<n;j++)
  	{
  		edge[i][j] = 0;
	}
  }
  
  int *visited = new int[n]();

  
  for(int i=0;i<e;i++)
  {
  	int a,b;
  	cin>>a>>b;
  	edge[a][b]=1;
  	edge[b][a]=1;
  }
  
  cin>>tempX>>tempY;
  bool ans = BFS(edge,n,tempX,tempY,visited);
  //cout<<ans<<endl;
  int c=tempY;
  if(ans==true)
  {
  	while(c!=tempX)
  	{
  		cout<<c<<" ";
		c=m[c];	
	}
	cout<<tempX;
  }
  
  /*map<int, int>::iterator itr;
  for(itr = m.begin();itr!=m.end();itr++)
  {
  	cout<<itr->first<<" "<<itr->second<<endl;
  }*/

  
  return 0;
}

