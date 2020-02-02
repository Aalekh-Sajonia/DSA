#include<bits/stdc++.h>
using namespace std;

void buildTree(int *arr,int *tree,int start,int end,int treeIndex)
{
	
	if(start==end)
	{
		tree[treeIndex] = arr[start];
		return ;
	}
	
	int mid = (start+end)/2;
	
	buildTree(arr,tree,start,mid,2*treeIndex);
	buildTree(arr,tree,mid+1,end,2*treeIndex+1);
	
	tree[treeIndex] = min(tree[2*treeIndex],tree[2*treeIndex+1]);
}

void updateSegmentTreeLazy(int *tree,int *lazy,int low,int high,
int startR,int endR,int currPos,int inc)
{
	if(low>high)
	{
		return ;
	}
	//before doing anything update lazy tree
	if(lazy[currPos] != 0)
	{
		tree[currPos] += lazy[currPos];
		
		if(low!=high)
		{
			lazy[2*currPos] += lazy[currPos];
			lazy[2*currPos+1] += lazy[currPos];
		}
		lazy[currPos] = 0;
	}
	
	//no overlap;
	if(startR > high || endR<low)
	{
		return;
	}
	//complete overlap
	if(startR <=  low && endR >= high)
	{
		tree[currPos] += inc;
		if(low!=high)
		{
			lazy[2*currPos] += inc;
			lazy[2*currPos+1] += inc;
		}
		return; 
	}
	
	//partial overlap
	int mid = (low+high)/2;
	updateSegmentTreeLazy(tree,lazy,low,mid,startR,endR,2*currPos,inc);
	updateSegmentTreeLazy(tree,lazy,mid+1,high,startR,endR,2*currPos+1,inc);
	
	tree[currPos] = min(tree[2*currPos] , tree[2*currPos+1]);
	
}

int query(int *tree,int *lazy,int low,int high,
int startR,int endR,int currPos)
{	
	if(low>high)
	{
		return INT_MAX;		
	}
	
	//before doing anything update lazy tree
	if(lazy[currPos] != 0)
	{
		tree[currPos] += lazy[currPos];
		
		if(low!=high)
		{
			lazy[2*currPos] += lazy[currPos];
			lazy[2*currPos+1] += lazy[currPos];
		}
		lazy[currPos] = 0;
	}
	
	if(startR > high || endR < low)
	{
		return INT_MAX;
	}
		
	if(startR <=  low && endR >= high)
	{
	/*	tree[currPos] += lazy[currPos];
		if(low!=high)
		{
			lazy[2*currPos] += lazy[currPos];
			lazy[2*currPos+1] += lazy[currPos];
		}*/
		return tree[currPos];		
	}
	
	int mid = (low+high)/2;
	
	int ans1 = query(tree,lazy,low,mid,startR,endR,2*currPos);
	int ans2 = query(tree,lazy,mid+1,high,startR,endR,2*currPos+1);
	
	return min(ans1,ans2);
	
}


int main()
{
	int arr[] = {1,3,-2,4};
	int *tree = new int[12]();
	int *lazy = new int[12]();
	buildTree(arr,tree,0,3,1);
	
//	updateSegmentTreeLazy(tree,lazy,0,3,0,3,1,3);
	updateSegmentTreeLazy(tree,lazy,0,3,0,1,1,2);
/*
	cout<<"Segment Tree"<<endl;
	for(int i=1;i<12;i++)
	{
		cout<<tree[i]<<endl;	
	}	
	
	cout<<"Lazy Tree"<<endl;
	for(int i=1;i<12;i++)
	{
		cout<<lazy[i]<<endl;
	}*/
	
	cout<<query(tree,lazy,0,3,0,1,1);
 	return 0;
}
