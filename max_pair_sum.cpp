#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

struct t
{
	ll val=0;
	ll idx=0;
}tree[300005],x,y,p,q,z,w;
ll n,a[100005],i,l,d,r,sum;

char c;

void build(ll node,ll lo,ll hi)
{
	if(lo==hi)
	{
		tree[node].val = a[lo];
		tree[node].idx = lo;
		return ;
	}
	else
	{
		ll mid = (lo+hi)/2;
		build(2*node,lo,mid);
		build(2*node+1,mid+1,hi);
		t x = tree[2*node];
		t y = tree[2*node+1];
		if(x.val>y.val)
		{
			tree[node].val = x.val;
			tree[node].idx = x.idx;
		}
		else
		{
			tree[node].val = y.val;
			tree[node].idx = y.idx;
		}
	}
}

t query(ll node,ll lo,ll hi,ll l,ll r)
{
	if(l>hi || r<lo || lo>hi || l>r)
	return z;
	if(l<=lo && hi<=r)
	return tree[node];
	
	ll mid=(lo+hi)/2;
	t x = query(2*node,lo,mid,l,r);
	t y = query(2*node+1,mid+1,hi,l,r);
	if(x.val>y.val)
	return x;
	else
	return y;
}

void update(ll node,ll lo, ll hi,ll id, ll amt)
{
	if(lo==hi)
	{
		//cout<<id<<endl;
		a[id] = amt;
		tree[node].val = amt; 
	}
	else
	{
		ll mid = (lo+hi)/2;
		if(id > mid)
		update(2*node+1,mid+1,hi,id,amt);
		else
		update(2*node,lo,mid,id,amt);
		
		if(tree[2*node].val > tree[2*node+1].val)
		{
			tree[node].val = tree[2*node].val;
			tree[node].idx = tree[2*node].idx;
		}
		else
		{
			tree[node].val = tree[2*node+1].val;
			tree[node].idx = tree[2*node+1].idx;
		}
		
	}
}

int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>a[i];
	build(1,1,n);
	int que;
	cin>>que;
	while(que--)
	{
	cin>>c;
	cin>>l>>r;
	
	if(c=='U')
	update(1,1,n,l,r);
	
	/*for(int i = 1;i<=10;i++)
	{
		cout<<tree[i].val<<" "<<tree[i].idx<<endl;
	}*/
	else{
	p = query(1,1,n,l,r);
	q = query(1,1,n,l,p.idx-1);
	w = query(1,1,n,p.idx+1,r);
	sum = p.val + max(q.val,w.val);
	cout<<sum<<endl;
	}
	}
	return 0;
}
