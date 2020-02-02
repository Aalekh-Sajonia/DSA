#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

struct treeNode
{ 
	ll sqSum;
	ll tSum;
};

struct lazyNode
{
	ll set;
	ll update;
};

void makeTree(int start,int end,int node,treeNode *tree,ll *arr)
{
	if(start==end)
	{
		tree[node].sqSum = arr[start-1] * arr[start-1];
		tree[node].tSum = arr[start-1];
		return ;
	}
	
	int mid = (start+end)/2;
	
	makeTree(start,mid,2*node,tree,arr);
	makeTree(mid+1,end,2*node+1,tree,arr);
	
	tree[node].sqSum = tree[2*node].sqSum + tree[2*node+1].sqSum;
	tree[node].tSum = tree[2*node].tSum + tree[2*node+1].tSum;
}


void update(int start,int end,int l,int r,ll v,int qtype,int node,
			treeNode *tree, lazyNode *lazyTree)
{
	if(start>end)
	return;
	
	if(lazyTree[node].set != 0)
	{
		ll x = lazyTree[node].set;
		tree[node].tSum = x * (end-start+1); //isse neeche ke sari values 'set' ho jaegi
		tree[node].sqSum = x*x*(end-start+1); //to tension lene ki bat ni he.
		
		if(start!=end)
		{
			lazyTree[2*node].set = x;
			lazyTree[2*node].update = 0;
			lazyTree[2*node+1].set = x;
			lazyTree[2*node+1].update = 0; // this will make sure ki set phele hi aaya he
		}				//aur update bad me;
		lazyTree[node].set = 0;
	}
	
	if(lazyTree[node].update != 0)
	{
		ll x = lazyTree[node].update;
		tree[node].sqSum += x*x*(end-start+1) + 2*x*(tree[node].tSum);
		tree[node].tSum += x*(end-start+1);
		
		if(start!=end)
		{
			lazyTree[2*node].update += x;
			lazyTree[2*node+1].update +=x;
		}
		lazyTree[node].update = 0;
	}
	
	if(end<l || start>r)
	return;
	
	if(start>=l && end<=r)
	{
		if(qtype==0)
		{
			tree[node].tSum = v*(end-start+1);
			tree[node].sqSum = v*v*(end-start+1);
			if(start!=end)
			{
				lazyTree[2*node].update=0; //wo hi value set karna he i.e change to update 
				lazyTree[2*node].set = v;  //ko 0 karna padega nito set ke sath update bhi 
				lazyTree[2*node+1].update = 0; //ho jaega
				lazyTree[2*node+1].set = v;
			}
		}
		else
		{
			tree[node].sqSum += v*v*(end-start+1) + 2*v*(tree[node].tSum);
			tree[node].tSum += v*(end-start+1);
			if(start!=end)
			{
				lazyTree[2*node].update += v;
				lazyTree[2*node+1].update +=v;
			}
		}
		return;
	}
	int mid = (start+end)/2;
	update(start,mid,l,r,v,qtype,2*node,tree,lazyTree);
	update(mid+1,end,l,r,v,qtype,2*node+1,tree,lazyTree);
	
	tree[node].sqSum = tree[2*node].sqSum + tree[2*node+1].sqSum;
	tree[node].tSum = tree[2*node].tSum + tree[2*node+1].tSum;
}

ll query(int start,int end,int l,int r,int node,treeNode *tree,lazyNode *lazyTree)
{
	if(start>end)
	return 0;
	
	if(lazyTree[node].set!=0)
	{
		ll x = lazyTree[node].set;
		tree[node].tSum = x*(end-start+1);
		tree[node].sqSum = x*x*(end-start+1);
		
		if(start!=end)
		{
			lazyTree[2*node].set = x;
			lazyTree[2*node].update = 0;
			lazyTree[2*node+1].set = x;
			lazyTree[2*node+1].update = 0;
		}
		lazyTree[node].set = 0; //purana update baki he isliye 0 ni kiya jo uppar se aara he
	}//wo set hone ke bad bhi rahega valid isliye us update ko 0 ni kiya
	if(lazyTree[node].update != 0)
	{
		ll x = lazyTree[node].update;
		tree[node].sqSum += x*x*(end-start+1) + 2*x*(tree[node].tSum);
		tree[node].tSum += x*(end-start+1);
		if(start!=end)
		{
			lazyTree[2*node].update += x;
			lazyTree[2*node+1].update += x;
		}
		lazyTree[node].update = 0;
	}
	
	if(end<l || start>r)
	return 0;
	
	if(start>=l && end<=r)
	{
		return tree[node].sqSum;
	}
	
	int mid = (end+start)/2;
	
	ll a1 = query(start,mid,l,r,2*node,tree,lazyTree);
	ll a2 = query(mid+1,end,l,r,2*node+1,tree,lazyTree);
	
	return a1+a2;
}

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cout<<"Case "<<i+1<<":"<<endl;
		int n,q;
		cin>>n>>q;
		ll arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		treeNode *tree = new treeNode[4*n]();
		makeTree(1,n,1,tree,arr);
		/*for(int i=1;i<12;i++)
		{
			cout<<tree[i].sqSum <<" "<<tree[i].tSum<<endl;
		}*/
		lazyNode lazyTree[4*n];
		
		for(int j=0;j<4*n;j++)
		{
			lazyTree[j].set = 0;
			lazyTree[j].update = 0;
		}
		
		for(int j=0;j<q;j++)
		{
			int qtype;
			cin>>qtype;
			if(qtype == 0 || qtype == 1)
			{
				int l,r;
				ll v;
				cin>>l>>r>>v;
				update(1,n,l,r,v,qtype,1,tree,lazyTree);
			}
			else if(qtype==2)
			{
				int l,r;
				cin>>l>>r;
				cout<<query(1,n,l,r,1,tree,lazyTree)<<endl;
			}
		}
	}
	
	/*for(int i=1;i<12;i++)
	{
		cout<<tree[i].sqSum <<" "<<tree[i].tSum<<endl;
	}*/
	return 0;
}
