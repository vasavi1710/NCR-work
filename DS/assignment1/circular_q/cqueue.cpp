#include<iostream>
#include<stdlib.h>
using namespace std;
class cqueue
{
	int rear, front;
	int *s;
	int size;
public:
	cqueue()
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
			{
				rear = (rear + 1) % size;
				s[rear] = n;
			}
		}
	
	}
	bool isOverflow()
	{
		return(front==(rear+1)%size|| (front==0&&rear == (size - 1) ));
	}
	int dequeue()
	{
		int l;
		l = -1;
		if (!(isUnderflow()))
		{
				l = s[front];
			if (front == rear)
				front = rear = -1;
			else
			front = (front + 1) % size;
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
			for (i = front; i < rear; i=((i+1)%size))
			{
				cout << "\n" << s[i];
			}
			cout << endl << s[rear];
		}
		else
			cout << "no elements to display" << endl;
	}
	void get_size(int n)
	{
		size = n;
		s = new int[size];
	}
};
int main()
{
	cqueue Q;
	int k;
	cout << "enter the size of the queue";
	cin >> k;
	Q.get_size(k);
	Q.display();
	Q.enqueue(40);
	Q.enqueue(50);
	Q.enqueue(6);
	Q.enqueue(70);
	Q.enqueue(80);
	Q.display();
	k = Q.dequeue();
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