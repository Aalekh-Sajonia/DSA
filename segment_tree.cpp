#include<bits/stdc++.h>
using namespace std;

void buildTree(int *arr,int *tree,int start,int end,int pos)
{
	if(start==end)
	{
		tree[pos] = arr[start];
		return ;
	}
	int mid = (start+end)/2;
	
	buildTree(arr,tree,start,mid,2*pos);
	buildTree(arr,tree,mid+1,end,2*pos+1);
	
	tree[pos] = tree[2*pos] + tree[2*pos+1];	
} 

void update(int *arr,int *tree,int start,int end,int treeNode,int idx,int value)
{
	
	if(start==end)
	{
		arr[idx] = value;
		tree[treeNode] = value;
		return;
	}
	int mid = (start+end)/2;
	
	if(idx > mid)
	{
		update(arr,tree,mid+1,end,2*treeNode+1,idx,value);
	}
	else
	{
		update(arr,tree,start,mid,2*treeNode,idx,value);
	}
	
	tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

int query(int *tree,int start,int end,int treeNode,int left,int right)
{
	
	if(start>right || end<left)
	{
		return 0;
	}
	
	if(start>=left && end<=right)
	{
		return tree[treeNode];
	}
	
	int mid = (start+end)/2;
	int ans1 = query(tree,start,mid,2*treeNode,left,right);
	int ans2 = query(tree,mid+1,end,2*treeNode+1,left,right);
	
	return ans1+ans2;
}

int main()
{
	int arr[] = {1,2,3,4,5};
	int *tree = new int[10];
	
	buildTree(arr,tree,0,4,1);
	
	update(arr,tree,0,4,1,2,10);
	
	for(int i=1;i<10;i++)
	{
		cout<<tree[i]<<endl;
	}
	
	cout<<query(tree,0,4,1,2,4);
	return 0;
}
