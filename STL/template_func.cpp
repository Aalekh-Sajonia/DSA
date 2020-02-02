#include<iostream>
#include<bits/stdc++.h>
using namespace std;
template <class X>
X fun(X a,X b)
{
	if(a>b)
	return a;
	else
	return b;
}
template <class X, class Y>
Y fun1(X a,Y b)
{
	if(a>b)
	return a;
	else 
	return b;
}

int main()
{
	//cout<<fun(6,7);
	cout<<fun1(6,8.2);
	return 0;
}
