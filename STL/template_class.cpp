#include<iostream>
#include<bits/stdc++.h>
using namespace std;
template<class X>
class myclass
{
	private:
	struct list
	{
		int capacity;
		X *a;
	};
	list *p;
	public:
	myclass(int capacity)
	{
		p=new list;
		p->capacity=capacity;
		p->a=new X[capacity];
	}
	void insert()
	{
		for(int i=0;i<p->capacity;i++)
		{
			cin>>p->a[i];
		}
	}
	void disp()
	{
		for(int i=0;i<p->capacity;i++)
		{
			cout<<p->a[i]<<" ";
		}
	}
};
int main()
{
	myclass<string> myobj(5);
	myobj.insert();
	myobj.disp();
	
	return 0;
}
