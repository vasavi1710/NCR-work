#include<iostream>
using namespace std;
class point
{
	int x, y;
public:
	point()
	{
		cout << "enter x and y values";
		cin >> x >> y;
	}
	point(int a, int b)
	{
		x = a;
		y = b;
	}
	friend void distance(point &p1,point &p2);
};
void distance(point &p1,point &p2)
{
	float d;
	d = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
	cout << "distance between two points is" << d;
	getchar();
}
int main()
{
	point q;
	point l(14, 15);
	distance(q, l);
	getchar();
}