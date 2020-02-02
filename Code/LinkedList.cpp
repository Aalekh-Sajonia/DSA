#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node* link;
};
struct node* root;
void append()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	cin>>temp->data;
	temp->link=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node* p;
		p=root;
		while(p->link!=NULL)
		{
			p=p->link;	
		}
		p->link=temp;
	}
}
void display()
{
	struct node* temp;
	temp=root;
	while(temp!=NULL)
	{
		cout<<temp->data<<endl;
		temp=temp->link;
	}
}
int length()
{
	int count=0;
	struct node* temp;
	temp=root;
	while(temp!=NULL)
	{
		count++;
		temp=temp->link;
	}
	return count;
}
void addatbegin()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	cin>>temp->data;
	temp->link=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		temp->link=root;
		root=temp;
	}
}

void del(int n)
{
	struct node* temp;
	temp=root;
	if(n>length())
	{
		return;
	}
	else if(n==1)
	{
		root=temp->link;
		temp->link=NULL;
		free(temp);
	}
	else
	{
		struct node* q;
		int i=1;
		while(i<n-1)
		{
			temp=temp->link;
			i++;
		}
		q=temp->link;
		temp->link=q->link;
		q->link=NULL;
		free(q);
	}
}

void reverse()
{
	int i,j,len,k,temp;
	i=0;
	len=length();
	j=len-1;
	struct node* p,*q;
	p=q=root;
	while(i<j)
	{
		k=0;
		while(k<j)
		{
			q=q->link;
			k++;
		}
		temp=p->data;
		p->data=q->data;
		q->data=temp;
		i++;
		j--;
		p=p->link;
		q=root;
	}
}
int main()
{
	for(int i=0;i<6;i++)
	{
		append();
	}
	cout<<endl;
	reverse();
	display();
	return 0;
}
