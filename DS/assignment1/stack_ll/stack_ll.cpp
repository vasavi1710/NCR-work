#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
class stack
{
	struct node *start;
public:
	stack()
	{
		start = NULL;
	}
	void push(int ele)
	{
		struct node *temp;
		temp = new node;
		temp->data = ele;
		temp->next = start;
		start = temp;
	}
	int pop()
	{
		int X = -1;
		if (start != NULL)
		{
			struct node *cur;
			cur = start;
			X = cur->data;
			start = cur->next;
			delete cur;

		}
		else
			cout << "list is empty";
		return X;
	}
	void display()
	{
		if (start != NULL)
		{
			struct node *temp;
			temp = new node;
			temp = start;
			while (temp->next != NULL)
			{
				cout << "\n" << temp->data;
				temp = temp->next;
			}
			cout << "\n"<<temp->data;
		}
		else
			cout << "\n no elements to display";
	}
	~stack()
	{
		struct node *temp;
		temp = new node;
		temp = start;
		while (temp != NULL)
		{
			start = temp->next;
			delete temp;
			temp = start;
		}
	}
};
int main()
{
	stack s1;
	s1.push(40);
	s1.push(50);
	s1.push(60);
	s1.push(70);
	s1.display();
	s1.pop();
	s1.pop();
	s1.display();
		system("pause");
	return 0;
}