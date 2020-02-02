#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void updateTree(ll *tree,ll *lazy,ll start,ll end,ll l,ll r,ll treeIndex,ll val)
{
	if(start>end)
	{
		return ;
	}
	
	if(lazy[treeIndex]!=0)
	{
		tree[treeIndex] += (end-start+1)*lazy[treeIndex];
		
		if(start!=end)
		{
			lazy[2*treeIndex] += lazy[treeIndex];
			lazy[2*treeIndex+1] += lazy[treeIndex];
		}
		lazy[treeIndex] = 0;
	}
	
	if(l>end || r<start)
	{
		return ;
	}
	//update
	if(l<=start && end<=r)
	{
		tree[treeIndex] += (end-start+1)*val;
		if(start!=end)
		{
			lazy[2*treeIndex] += val;
			lazy[2*treeIndex+1] += val;
		}
		return ;
	}
	
	ll mid = (start+end)/2;
	updateTree(tree,lazy,start,mid,l,r,2*treeIndex,val);
	updateTree(tree,lazy,mid+1,end,l,r,2*treeIndex+1,val);
	
	tree[treeIndex] = tree[2*treeIndex] + tree[2*treeIndex+1];
}

ll query(ll *tree,ll *lazy,ll start,ll end,ll l,ll r,ll treeIndex)
{
	if(start>end)
	{
		return 0;
	}
	
	if(lazy[treeIndex]!=0)
	{
		tree[treeIndex] += (end-start+1)*lazy[treeIndex];
		if(start!=end)
		{
			lazy[2*treeIndex] += lazy[treeIndex];
			lazy[2*treeIndex+1] += lazy[treeIndex]; 
		}
		lazy[treeIndex] = 0;
	}
	
	if(l>end || r<start)
	{
		return 0;
	}
	
	if(l<=start && end<=r)
	{
	/*	tree[currPos] += lazy[currPos];
		if(low!=high)
		{
			lazy[2*currPos] += lazy[currPos];
			lazy[2*currPos+1] += lazy[currPos];
		}*/
		return tree[treeIndex];		
	}
	ll mid = (start+end)/2;
	ll ans1 = query(tree,lazy,start,mid,l,r,2*treeIndex);
	ll ans2 = query(tree,lazy,mid+1,end,l,r,2*treeIndex+1);
	
	return ans1+ans2;
}

int main()
{
	ll t;
	cin>>t;
	while(t--)	
	{	
		ll n;
		cin>>n;
		ll *tree = new ll[4*n]();
		ll *lazy = new ll[4*n]();
		for(int i=0;i<4*n;i++)
		{
			tree[i] = 0;
			lazy[i] = 0;
		}
		ll q;
		cin>>q;
		while(q--)
		{
			ll a;
			cin>>a;
			if(a==0)
			{
				ll b,c,d;
				cin>>b>>c>>d;
				updateTree(tree,lazy,0,n-1,b-1,c-1,1,d);
			}
			else
			{
				ll b,c;
				cin>>b>>c;
				cout<<query(tree,lazy,0,n-1,b-1,c-1,1)<<endl;
				
			}
			
		}
	/*	updateTree(tree,lazy,0,n-1,2-1,4-1,1,26);
		updateTree(tree,lazy,0,n-1,4-1,8-1,1,80);
		updateTree(tree,lazy,0,n-1,4-1,5-1,1,20);
		updateTree(tree,lazy,0,n-1,5-1,7-1,1,14);
		cout<<query(tree,lazy,0,n-1,3,7,1);*/
	}
	return 0;
}
