#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f 
struct node
{
	int maxPrefixSum;
	int maxSuffixSum;
	int maxSubarraySum;
	int totalSum;
	
	node()
	{
		maxPrefixSum = maxSuffixSum = maxSubarraySum = totalSum = -inf;
	}
};

node merge(node leftChild,node rightChild)
{
	node parentNode;
	
	parentNode.totalSum = leftChild.totalSum + rightChild.totalSum;
	
	parentNode.maxPrefixSum = max(leftChild.maxPrefixSum,
								leftChild.totalSum + 
								rightChild.maxPrefixSum);
								
	parentNode.maxSuffixSum = max(rightChild.maxSuffixSum,
								rightChild.totalSum+
								leftChild.maxSuffixSum);
								
	parentNode.maxSubarraySum = max({leftChild.maxSubarraySum,
									rightChild.maxSubarraySum,
									leftChild.maxSuffixSum+
									rightChild.maxPrefixSum });
	
	return parentNode;
}

void constructTree(node* tree,int *arr,int start,int end,int treeIndex)
{
	if(start==end)
	{
		tree[treeIndex].maxPrefixSum = arr[start];
		tree[treeIndex].maxSubarraySum = arr[start];
		tree[treeIndex].maxSuffixSum = arr[start];
		tree[treeIndex].totalSum = arr[start];
		return ;
	}
	
	int mid = (start+end)/2;
	constructTree(tree,arr,start,mid,2*treeIndex);
	constructTree(tree,arr,mid+1,end,2*treeIndex+1);
	
	tree[treeIndex] = merge(tree[2*treeIndex] , tree[2*treeIndex+1]);
	
}

node query(node *tree,int ss,int se,int qs,int qe,int treeIndex)
{
	if(ss>qe || se<qs)
	{
		node nullNode;
		return nullNode;
	}
	
	if(ss >= qs && se<= qe)
	{
		return tree[treeIndex];
	}
	
	int mid=(ss+se)/2;
	
	node left = query(tree,ss,mid,qs,qe,2*treeIndex);
	node right = query(tree,mid+1,se,qs,qe,2*treeIndex+1);
	
	node res = merge(left,right);
	return res;
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	node *tree = new node[4*n];
	
	constructTree(tree,arr,0,n-1,1);
	
/*	for(int i=1;i<20;i++)
	{
		cout<<tree[i].maxPrefixSum<<" "<<tree[i].maxSubarraySum<<" "
		<<tree[i].maxSuffixSum<<" "<<tree[i].totalSum<<endl;
	}*/
	
	
	int que;
	cin>>que;
	while(que--)
	{	
		int a,b;
		cin>>a>>b;
		node ans = query(tree,0,n-1,a-1,b-1,1);
		cout<<ans.maxSubarraySum<<endl;
	}
	return 0;
}
