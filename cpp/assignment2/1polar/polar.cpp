#include<iostream>
using namespace std;
class polar
{
	int angle;
	int radius;
public:
	static int x;
	polar()
	{
		angle = radius = 0;
		x++;
	}
	polar(int a, int b)
	{
		angle = a; radius = b;
		x++;
	}
};
int polar::x;
int main()
{
	polar p;
	cout << polar::x<<endl;
	//getchar();
	polar p1(20, 3);
	cout << polar::x<<endl;
	//getchar();
	polar p3;
	cout << p3.x;
	getchar();
	return 0;
}