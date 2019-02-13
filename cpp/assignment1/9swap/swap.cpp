#include<iostream>
using namespace std;
class swapping
{
public:
	int a, b;

	void get()
	{
		cin >> a >> b;
	
		getchar();
	}
	void swap_by_value(int c, int d)
	{
		c = c + d;
		d = c - d;
		c = c - d;
	}
	void swap_by_reference(int &l, int &m)
	{
		l = l + m;
		m = l - m;
		l = l - m;
	}

};
int main()
{
	swapping s1;
	int ch;
	s1.get();
	printf("enter ur choice 1.call by value 2.call by reference");
	scanf_s("%d", &ch);
	switch (ch)
	{
	case 1: s1.swap_by_value(s1.a,s1.b);
		cout << "a" << s1.a << "b" << s1.b;
		break;
	case 2: s1.swap_by_reference(s1.a, s1.b);
		cout << "a" << s1.a << "b" << s1.b;
		break;
	default:cout << "entered option is unavailable"; break;
	}
	getchar();
	return 0;
}