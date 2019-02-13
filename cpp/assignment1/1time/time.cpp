#include<iostream>
using namespace std;
class Time
{
	int hours, minute, seconds;
public:
	Time()
	{
		hours,minute,seconds = 0;
	}
	Time(int h, int m, int s)
	{
		hours = h;
		minute = m;
		seconds = s;
	}
	void display()
	{
		cout << hours << ":" << minute << ":" << seconds;
	}
	void add(Time &C1, Time &C2)
	{
		hours = C1.hours + C2.hours;
		if (hours >=24)
		{
			hours = hours-24;
		}
		minute = C1.minute + C2.minute;
		if (minute >=60)
		{
			minute = minute - 60;
			hours = hours + 1;
			if (hours >= 24)
			{
				hours = hours-24;
			}
		}
		seconds = C1.seconds + C2.seconds;
		{
			if (seconds >= 60)
			{
				seconds = seconds - 60;
				minute = minute + 1;
				if (minute >= 60)
				{
					minute = minute - 60;
					hours = hours + 1;
				}

			}
		}
	}
};

int main()
{
	Time T1(23,2,12);
	Time T2(4, 58, 40);
	Time T3;
	T3.add(T1, T2);
	T3.display();
	getchar();
	return 0;
}