#include<bits/stdc++.h>
using namespace std;

struct Edge
{	
	int src;
	int dest;
	int weight;
};

bool compare(Edge e1,Edge e2)
{
	return e1.weight < e2.weight;
}

int getParent(int v,int *parent)
{
	if(v == parent[v])
	{
		return v;
	}
	return getParent(parent[v],parent);
}

void kruskals(Edge *edges,int n,int e,int cost,int x)
{
	sort(edges,edges+e,compare);
	int * parent = new int[n];
	for(int i=0;i<n;i++)
	{
		parent[i] = i;
	}
	int count=0;
	int i=0;
	int sum=0;
	while(count<(n-1) && i<e) // i should be less than e otherwise it will go in segmentation fault.
	{
		Edge currentEdge = edges[i];
		if(currentEdge.weight >= cost)
		{
			break;
		}
		int srcParent = getParent(currentEdge.src,parent);
		int destParent = getParent(currentEdge.dest,parent);
		
		if(srcParent != destParent)
		{
			count++;
			parent[srcParent] = destParent;
			sum += currentEdge.weight;
 		}
		i++;
	}
	
	int numOfAirport = 0;
	for(int i=0;i<n;i++)
	{
		if(parent[i]==i)
			numOfAirport++;
	}
	
	int final_ans = sum + (numOfAirport*cost);
	cout<<"Case #"<<x<<":"<<" "<<final_ans<<" "<<numOfAirport<<endl;
	delete [] parent;
	
}

int main()
{
	int t;
	cin>>t;
	int x = 1;
	while(t--)
	{
		int n,e;
		int cost;
		cin>>n>>e>>cost;
		Edge *edges = new Edge[e];
		for(int i=0;i<e;i++)
		{
			cin>>edges[i].src;
            edges[i].src--;
			cin>>edges[i].dest;
            edges[i].dest--;
			cin>>edges[i].weight;	
		}	
		kruskals(edges,n,e,cost,x);
		x++;
		delete [] edges;
	}
	return 0;
} 
