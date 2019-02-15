#include<iostream>
using namespace std;
class distance2;
class distance1
{
	int meter;
	int centimeter;

public:
	distance1() {
		int meter = 0;
		int centimeter = 0;
	}
	friend void add(distance1,distance2);
};
class distance2
{
	int feet;
	int inches;
public:
	distance2()
	{
		int feet=0;
		int inches=0;
	}
	friend void add(distance1,distance2);
};
void add(distance1 d1, distance2 d2)
{
	cout << "enter meter and centimeter distance";
	cin >> d1.meter >> d1.centimeter;
	cout << "enter feet and inches distance";
	cin >> d2.feet >> d2.inches;
	cout << "u want the result in 1.meter centimeter 2.feet inches";
	int k,res,res1;
	cin >> k;
	switch (k)
	{
	case 1: d1.meter+= (0.3048 * d2.feet);
			 d1.centimeter+=(2.54 * d2.inches);
			 cout << "distance in meter centimeter after addition is" << d1.meter << "meters" << d1.centimeter << "centimeter";
			 getchar();
			 break;
	case 2: d2.feet += (3.28084* d1.meter);
		d2.inches += (0.3937007874 * d1.centimeter);
		cout << "distance in meter centimeter after addition is" << d2.feet << "meters" << d2.inches << "centimeter";
		getchar();
		break;
	default:cout << "entered option dont exist"; break;
	}
}
int main()
{
	distance1 D1;
	distance2 D2;
	add(D1,D2);
	getchar();
}