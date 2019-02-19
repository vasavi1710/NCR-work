#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
class self
{
	struct node *start;
public:
	void insert_last(int ele)
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
	void self_adjust(int ele)
	{
		if (start != NULL)
		{
			if (start->next == NULL)
			{
				if (start->data == ele)
					cout << "already self adjusted";
				else
					cout << "element not found";
			}
			else
			{
				struct node *cur, *temp;
				cur = new node;
				cur = start;
				while (cur->next != NULL &&cur->next->data != ele)
					cur = cur->next;
				if (cur->next != NULL)//ELEMENT FOUND
				{
					temp = cur->next;
					cur->next = temp->next;
					temp->next = start;
					start = temp;
				}
				else
					cout << "element not found";
			}

		}
		else
			cout << "list is empty";
	}
	~self()
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
	self s;
	s.insert_last(40);
	s.insert_last(50);
	s.insert_last(60);
	s.insert_last(70);
	s.display();
	cout << "after self adjusting";
	s.self_adjust(60);
	s.display();
	system("pause");
	return 0;
}