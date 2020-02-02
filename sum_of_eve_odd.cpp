#include<bits/stdc++.h>
using namespace std;

struct treeNode
{
	int even;
	int odd;
};

void buildTree(treeNode *tree,int *arr,int start,int end,int treeIndex)
{
	if(start==end)
	{
		if(arr[start]%2 == 0)
			tree[treeIndex].even = 1;
		else
			tree[treeIndex].odd = 1;
			
		return;
	}
	
	int mid = (start+end)/2;
	buildTree(tree,arr,start,mid,2*treeIndex);
	buildTree(tree,arr,mid+1,end,2*treeIndex+1);
	
	tree[treeIndex].even = tree[2*treeIndex].even + tree[2*treeIndex+1].even;
	tree[treeIndex].odd = tree[2*treeIndex].odd + tree[2*treeIndex+1].odd;
}

void update(treeNode *tree,int *arr,int start,int end,int treeIndex,int pos,int val)
{
	if(start == end)
	{
		arr[pos] = val;
		tree[treeIndex].even = tree[treeIndex].odd = 0;
		if(val%2==0)
			tree[treeIndex].even = 1;
		else
			tree[treeIndex].odd = 1;
		return;
	}
	
	int mid = (start+end)/2;
	
	if(pos>mid)
	{
		update(tree,arr,mid+1,end,2*treeIndex+1,pos,val);
	}
	else
	{
		update(tree,arr,start,mid,2*treeIndex,pos,val);
	}
	
	tree[treeIndex].even = tree[2*treeIndex].even + tree[2*treeIndex+1].even;
	tree[treeIndex].odd = tree[2*treeIndex].odd + tree[2*treeIndex+1].odd;
}

treeNode query(treeNode *tree,int start,int end,int treeIndex,int left, int right)
{
	if(start>right || end<left)
	{
		treeNode null; 
		null.even = 0;
		null.odd = 0;
		return null;
	}
	
	if(start>=left && end<=right )
	{
		return tree[treeIndex];	
	}	
	
	int mid = (start+end)/2;
	
	treeNode n1 = query(tree,start,mid,2*treeIndex,left,right);
	treeNode n2 = query(tree,mid+1,end,2*treeIndex+1,left,right);
	
	treeNode ans; 
	ans.even = n1.even + n2.even;
	ans.odd = n1.odd + n2.odd;
	return ans;
}
int main()
{
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	treeNode *tree = new treeNode[3*n]();
	buildTree(tree,arr,0,n-1,1);
	
/*	for(int i=1;i<20;i++)
		cout<<tree[i].even<<" "<<tree[i].odd<<endl;*/
		
/*	treeNode temp = query(tree,0,n-1,1,1,4);
	cout<<temp.even<<" "<<temp.odd;*/
	
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(a==0)
		{
			update(tree,arr,0,n-1,1,b-1,c);
		}
		else
		{
			treeNode ans = query(tree,0,n-1,1,b-1,c-1);
			if(a==1)
			{
				cout<<ans.even<<endl;
			}
			else
			{
				cout<<ans.odd<<endl;
			}
		}
	}
//	update(tree,arr,0,n-1,1,b,c);
	
/*	for(int i=1;i<20;i++)
		cout<<tree[i].even<<" "<<tree[i].odd<<endl;*/
	return 0;
}
