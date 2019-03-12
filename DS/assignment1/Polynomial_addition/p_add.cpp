#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	int coeff;
	struct node *next;
};
class poly_add
{
	struct node *start;
public:
	poly_add()
	{
		start = NULL;

	}
	void insert_last(int ele,int coeff)
	{
		struct node *temp;
		temp = new node;
		temp->data = ele;
		temp->coeff = coeff;
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
			cout << "\n";
			while (temp->next != NULL)
			{
				cout  << temp->data;
				cout <<"x"<<temp->coeff<<"+";
				temp = temp->next;
			}
			cout << temp->data<<"x"<<temp->coeff;
		}
		else
			cout << "\n no elements to display";
	}
	void add(poly_add p1, poly_add p2)
	{
		struct node *f;
		struct node *s;
		poly_add res;
		for (f = p1.start,s=p2.start;(f!=NULL ) &&(s!=NULL);)
		{
			if (f->coeff == s->coeff)
			{
				res.insert_last(f->data + s->data, f->coeff);
				f = f->next;
				s = s->next;
			}
			else if (f->coeff > s->coeff)
			{
				res.insert_last(f->data, f->coeff);
				f = f->next;
			}
			else 
			{
				res.insert_last(s->data, s->coeff);
				s = s->next;
			}
		}
		if (f != NULL )
		{
			while (f != NULL)
			{
				res.insert_last(f->data, f->coeff);
				f = f->next;
			}
		}
		else	
		{
			while (s != NULL)
			{
				res.insert_last(s->data, s->coeff);
				s = s->next;
			}
		}
		res.display();
	 }
};
int main()
{
	poly_add p1, p2, p3;
	p1.insert_last(20,2);
	p1.insert_last(10, 0);
	p2.insert_last(25, 2);
	p2.insert_last(30, 1);
	p1.display();
	p2.display();
	 p3.add(p1, p2);
	system("pause");
	return 0;
}