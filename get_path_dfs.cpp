#include <bits/stdc++.h>
using namespace std;
vector<int> vect;
bool getPath(int **edge,int n,int tempX,int tempY,int *visited)
{
	if(tempX==tempY)
	{
	//	vect.push_back(tempX);
		return true;
	}
	
	visited[tempX] = 1;
	for(int i=0;i<n;i++)
	{
		if(i==tempX)
		continue;
		if(edge[tempX][i]==1)
		{
			if(visited[i]==1)
			continue;
			else
			{
				if(getPath(edge,n,i,tempY,visited))
				{
					vect.push_back(i);
					return true;
				}
				else
				{
					continue;
				}
			}
		}
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
		edge[i][j]=0;
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
  
  getPath(edge,n,tempX,tempY,visited);
  for(int i=0;i<vect.size();i++)
  {
  	cout<<vect[i]<<" ";
  }
  if(vect.size()>0)
  {
  	cout<<tempX;
  }
  
  return 0;
}

