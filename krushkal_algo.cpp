#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int src;
	int dest;
	int weight;
};

bool compare(edge e1,edge e2)
{
	return e1.weight<e2.weight;
}

int getParent(int v,int *parent)
{
	if(parent[v]==v)
		return v;
	
	return getParent(parent[v],parent);
}

edge* kruskal(edge *e,int n,int E)
{
	sort(e,e+E,compare);
	edge* output = new edge[n-1];
	int *parent = new int[n];
	for(int i=0;i<n;i++)
	{
		parent[i] = i;
	}
	int count=0;
	int i=0;
	while(count<(n-1))
	{
		edge currentEdge = e[i];
		int srcParent = getParent(currentEdge.src,parent);
		int destParent = getParent(currentEdge.dest,parent);
		
		if(srcParent!=destParent)
		{
			output[count] = currentEdge;
			count++;
			parent[srcParent] = destParent;
		}
		i++;		
	}
	return output;
}

int main()
{
	int n,E;
	cin>>n>>E;
	edge *e = new edge[E];
	for(int i=0;i<E;i++)
	{
		cin>>e[i].src;
		cin>>e[i].dest;
		cin>>e[i].weight;
	}
	
	edge *output = kruskal(e,n,E);
	for(int i=0;i<n-1;i++)
	{
		if(output[i].dest>output[i].src)
		{
			cout<<output[i].src<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
		}
		else
		{
			cout<<output[i].dest<<" "<<output[i].src<<" "<<output[i].weight<<endl;
		}
	}
	return 0;
}
