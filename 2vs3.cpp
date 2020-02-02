#include<bits/stdc++.h>
using namespace std;

int power[100006],arr[100006],tree[300006];
void fastpower()
{
	power[0] = 1;
	for(int i=1;i<100006;i++)
	{
		power[i] = (power[i-1]*2)%3;
	}
}

void build(int index,int start,int end)
{
	if(start==end)
	{
		tree[index] = arr[start];
		return;
	}
	
	int mid = (start+end)/2;
	
	build(2*index,start,mid);
	build(2*index+1,mid+1,end);
	
	tree[index] = (tree[2*index+1] + (tree[2*index]*power[end-mid])%3)%3; //using modulo property
}

void update(int index,int start,int end,int idx)
{
	if(start==end)
	{
		tree[index] = 1;
		arr[idx] = 1;
		return ;
	}
	
	int mid = (start+end)/2;
	if(start<=idx and mid>=idx)
	{
		update(2*index,start,mid,idx);
	}
	else
	{
		update(2*index+1,mid+1,end,idx);
	}
	tree[index] = (tree[2*index+1] + tree[2*index]*power[end-mid])%3;
}

int query(int index,int start,int end,int left,int right)
{
	if(start>right || end<left)
	return 0;
	if(left<=start && right>=end)
	return (tree[index]*power[right-end])%3;
	
	int mid = (start+end)/2;
	int ans1 = query(2*index,start,mid,left,right);
	int ans2 = query(2*index+1,mid+1,end,left,right);
	return (ans1+ans2)%3;
}

int main()
{
	fastpower();
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		arr[i+1] = s[i]-48;
	}
	build(1,1,n);
	
	int q;
	cin>>q;
	while(q--)
	{
		int t;
		cin>>t;
		if(t==0)
		{
			int l,r;
			cin>>l>>r;
			cout<<query(1,1,n,l+1,r+1)<<endl;
		}
		else
		{
			int x;
			cin>>x;
			if(s[x]=='0')
			{
				s[x] = '1';
				arr[x+1] = 1;
				update(1,1,n,x+1);
			}
		}
	}
	return 0;
}
