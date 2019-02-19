#include<iostream>
#include<stdlib.h>
using namespace std;
class queue
{
	int rear, front;
	int *s;
	int size;
public:
	queue()
	{
		rear = -1;
		front = -1;
		s = NULL;
		size = 0;
	}
	void enqueue(int n)
	{
		if (!isOverflow())
		{
			if (rear == -1 && front == -1)
			{
				rear = 0;
				front = 0;
				s[rear] = n;
			}
			else
				s[++rear] = n;
		}
	}
	bool isOverflow()
	{
		return(rear == size - 1);
	}
	int dequeue()
	{
		int l;
		l=-999;
		if (!(isUnderflow()))
		{
			l = s[front++];
		}
		return l;
	}
	bool isUnderflow()
	{
		return(rear == -1 && front == -1);
	}
	void display()
	{
		int i;
		if (!isUnderflow()) {
			for (i = front; i <= rear; i++)
			{
				cout << "\n" << s[i];
			}
		}
		else
			cout << "no elements to display"<<endl;
	}
	void get_size(int n)
	{
		size = n;
		s = new int[size];
	}
};
int main()
{
	queue Q;
	int k;
	cout << "enter the size of the queue";
	cin >> k;
	Q.get_size(k);
	Q.display();
	Q.enqueue(40);
	Q.enqueue(50);
	Q.enqueue(60);
	Q.display();
	k=Q.dequeue();
	cout << "\n dequeued element is" << k;
	k = Q.dequeue();
	cout << "\n dequeued element is" << k;
	k = Q.dequeue();
	cout << "\n dequeued element is" << k;
	k = Q.dequeue();
	cout << "\n dequeued element is" << k;
	Q.display();
	system("pause");
	return 0;
}