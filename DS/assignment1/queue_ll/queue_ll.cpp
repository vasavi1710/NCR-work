#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
class queue
{
	struct node *start;
public:
	queue()
	{
		start = NULL;
	}
	void enqueue(int ele)
	{
		struct node *temp;
		temp = new node;
		temp->data = ele;
		temp->next = NULL;
		if (start == NULL)
		{
			start = temp;
		}
		else
		{
			struct node *curr;
			curr = new node;
			curr = start;
			while (curr->next != NULL)
				curr = curr->next;
				curr->next = temp;
			
		}

	}
	int dequeue()
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
			cout << "\n" << temp->data;
		}
		else
			cout << "\n no elements to display";
	}
	~queue()
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
	queue q1;
	q1.enqueue(40);
	q1.enqueue(50);
	q1.enqueue(60);
	q1.enqueue(70);
	q1.display();
	q1.dequeue();
	q1.dequeue();
	q1.display();
	system("pause");
	return 0;
}