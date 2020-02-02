#include<bits/stdc++.h>
using namespace std;
#define INT_SIZE 32
class trieNode
{
	public:
	int data;
	trieNode *left;
	trieNode *right;
	trieNode()
	{
		data = 0;
		left = NULL;
		right = NULL;
	}
};

void insert(trieNode *root,int pre_XOR)
{
	trieNode *temp = root;
	for(int i= INT_SIZE-1;i>=0;i--)
	{
		bool val = pre_XOR & (1<<i);
		
		if(val==0)
		{
			if(temp->left==NULL)
			{
				temp->left = new trieNode;
			}
			temp = temp->left;
		}
		else
		{
			if(temp->right==NULL)
			{
				temp->right = new trieNode;
			}
			temp = temp->right;
		}
	}
	temp->data = pre_XOR;	
}

int query(trieNode *root,int pre_XOR)
{
	trieNode *temp = root;
	for(int i=INT_SIZE-1;i>=0;i--)
	{
		bool val = pre_XOR & (1<<i);
		
		if(val==0)
		{
			if(temp->right != NULL)
			{
				temp = temp->right;
			}
			else
			{
				temp = temp->left;
			}
		}
		else
		{
			if(temp->left != NULL)
			{
				temp = temp->left;
			}
			else
			{
				temp = temp->right;
			}
		}
	}
	return temp->data ^ pre_XOR;
}

int maxSub(int *arr,int n)
{
	trieNode *root = new trieNode;
	insert(root,0);
	
	int ans = INT_MIN ;
	int pre_XOR = 0;
	for(int i=0;i<n;i++)
	{
		pre_XOR = pre_XOR ^ arr[i];
		insert(root,pre_XOR);
		
		ans = max(ans,query(root,pre_XOR));
	}
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
	cout<<maxSub(arr,n);
	return 0;
	
}
