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
	complex(complex &c)
	{
		real = c.real;
		img = c.img;
	}
	void display()
	{
		cout << real << "+" << img << "i" << endl;
		
	}
	
	complex operator+(complex c)
	{
		complex res;
		res.real = real + c.real;
		res.img = img + c.img;
		return res;
	}
	complex operator-(complex c)
	{
		complex res;
		res.real = real-c.real;
		res.img = img-c.img;
		return res;
	}
	complex operator-()
	{
		complex res;
		res.real = -real;
		res.img = -img;
		return res;
	}
	complex operator++()
	{
		complex res;
		res.real = ++real;
		res.img = ++img;
		return res;
	}
	complex operator++(int x)
	{
		complex res;
		res.real = real++;
		res.img = img++;
		return res;
	}
	/*complex operator->(complex c)
	{
		complex res;
		res.real = c.real;
		res.img = c.img;
		return res;
	}*/
	/*complex operator,(complex &c)
	{
	}
	complex operator->(complex &c)
	{
		this-
	}*/
	friend ostream& operator<<(ostream &cout, complex c);
	friend  istream& operator>> (istream &cin, complex &c);
};
ostream& operator<<(ostream &cout, complex c)
{
	cout << "real is" << c.real << endl;
	cout << "img is" << c.img << endl;
	return (cout);
}
istream& operator>>(istream &cin, complex &c)
{
	cin >> c.real;
	cin >> c.img;
	return (cin);
}
int main()
{
	complex c1(2, 3), c2(2), c3(c1), c4, c5, c6,c7;
	c4 = c1+c2;
	c4.display();
	c5 = c1-c2;
	c5.display(); 
	c6 = -c5;
	c6.display(); 
	c4 = ++c1;
	c4.display();
	c5 = c1++;
	c5.display();
	c6 = c4;
	c6.display();
	cout << c1;
	c1.display();
	cin>>c7;
	c7.display();
	system("pause");
	getchar();
	return 0;
}