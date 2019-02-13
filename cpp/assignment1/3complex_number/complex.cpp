#include<iostream>
using namespace std;
class complex
{
	float real, img;
public:
	complex()
	{
		real = img = 0;
	}
	complex(float r)
	{
		real = img = r;
	}
	complex(float r, float i)
	{
		real = r;
		img = i;
	}
	friend void add(complex &b,complex &c, complex &d);
	friend void multiply(complex &b,complex &c, complex &d);
	void display()
	{
		cout << real << "+" << img<<"i";
	}
};

void add(complex &b,complex &c, complex &d) {
b.real = c.real + d.real;
	b.img = c.img + d.img;
}
void multiply(complex &b, complex &c, complex &d)
{
	
	b.real = ((c.real)*(d.real)) - ((c.img)*(d.img));
	b.img= ((c.real)*(d.img)) + ((c.real)*(d.img));
}
int main()
{
	complex A,D;
	complex B(2);
	complex C(3, 4);
	add(A,B, C);
	cout << "after addition";
	A.display();
	multiply(D,B, C);
	cout << "after multiplication";
	D.display();
	getchar();
}