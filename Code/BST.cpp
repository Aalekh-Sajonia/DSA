#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node* right;
	struct node* left;
};
struct node* root;

void insert()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	cin>>temp->data;
	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node* itr, *p;
		itr=root;
		while(itr)
		{
			p=itr;
			if(temp->data>itr->data)
			{
				itr=itr->right;
			}
			else
			{
				itr=itr->left;
			}
		}
		if(temp->data>p->data)
		{
			p->right=temp;
		}
		else
		{
			p->left=temp;
		}
		}
}

void inorder(struct node* t)
{
	if(t->left)
	{
		inorder(t->left);
	}
	cout<<t->data<<" ";
	if(t->right)
	{
		inorder(t->right);
	}
}

void preorder(struct node* t)
{
	cout<<t->data<<" ";
	if(t->left)
	{
		preorder(t->left);	
	}		
	if(t->right)
	{
		preorder(t->right);
	}
}

void postorder(struct node *t)
{
	if(t->left)
	{
		postorder(t->left);
	}
	if(t->right)
	{
		postorder(t->right);
	}
	cout<<t->data<<" ";
}
int main()
{
	for(int i=0;i<5;i++)
	{
		insert();
	}
	postorder(root);
	return 0;
}

