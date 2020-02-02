#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node* llink;
	struct node* rlink;
};
struct node* root=NULL;

void append()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	cout<<"enter the data to be inserted:";
	cin>>temp->data;
	temp->llink=NULL;
	temp->rlink=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node* p;
		p=root;
		while(p->rlink!=NULL)
		{
			p=p->rlink;
		}
		p->rlink=temp;
		temp->llink=p;
	}
}

void display()
{
	struct node* temp;
	temp=root;
	while(temp!=NULL)
	{
		cout<<temp->data;
		temp=temp->rlink;
		cout<<endl;
	}
}

int length()
{
	struct node* temp;
	temp=root;
	int count=0;
	while(temp!=NULL)
	{
		temp=temp->rlink;
		count++;
	}
	return count;
}

void addatbegin()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	cout<<"Enter data to be inserted at the begin:";
	cin>>temp->data;
	temp->rlink=root;
	temp->llink=NULL;
	root=temp;
}

void insertele(int n)
{
	int i=1;
	if(n>length())
	{
		return;
	}
	else 
	{
		struct node* temp,*p;
		temp=(struct node*)malloc(sizeof(struct node*));
		cout<<"Enter data to be inserted at pos "<<n<<" :";
		cin>>temp->data;
		temp->llink=NULL;
		temp->rlink=NULL;
		p=root;
		while(i<n-1)
		{
			p=p->rlink;
			i++;
		}
		temp->rlink=p->rlink;
		p->rlink->llink=temp;
		temp->llink=p;
		p->rlink=temp;
	}
}
int main()
{
	for(int i=0;i<5;i++)
	{
		append();
	}
	display();
	cout<<"The length of the LL is:"<<length()<<endl;
	insertele(3);
	cout<<endl;
	display();
	return 0;
}
