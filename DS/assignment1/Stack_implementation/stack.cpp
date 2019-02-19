#include<iostream>
#include<stdlib.h>
using namespace std;
class stack
{
	int top;
	int *s;
	int size;
public:
	stack()
	{
		top = -1;
		s = NULL;
		size = 0;
	}
	bool isFull()
	{
		return(top == size - 1);
	}
	bool isEmpty()
	{
		return(top == -1);
	}
	void push(int n)
	{
		if (!isFull())
		 (s[++top] = n);
		else
			cout << "stack overflow";
	}
	int pop()
	{
		int x=-999;
		if (!isEmpty())
			 (x = s[top--]);
		else
			cout << "stack underflow";
		return x;
	}
	int peek()
	{
		int x=-999;
		if (!isEmpty())
			 (x = s[top]);
		else
			cout << "stack underflow";
		return x;
	}
	void display()
	{
		int i;
		for ( i = 0; i <=top; i++)
		{
			cout << "\n" << s[i];
		}
		if (top == -1)
			cout << "no elements to display";
	}
	void getsize(int n)
	{
		size = n;
		 s = new int[n];
	}
	~stack()
	{
		delete s;
	}
};
int main()
{
	stack sk;
	int k;
	int a;
	cout<<"enter thes size of the stack";
	cin >> a;
	sk.getsize(a);
	sk.push(20);
	sk.push(30);
	sk.display();
	sk.push(40);
	k=sk.pop();
	cout << "popped element is:" << k;
	sk.peek();
	sk.push(70);
	sk.display();
	k=sk.pop();
	k=sk.pop();
	k=sk.pop();
	sk.display();
	k=sk.pop();
	system("pause");
	
	return 0;

}