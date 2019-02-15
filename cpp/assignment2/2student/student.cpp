#include<iostream>
using namespace std;
#include<cstring>
class student
{
	char rollno[10];
	char name[30];
	int m1, m2, m3;
	int totalm;
	char grade[20];
public:
	friend ostream& operator<<(ostream &cout, student c);
	friend  istream& operator >> (istream &cin, student &c);
	friend void calc(student *s, int n);
};
istream& operator>>(istream &cin, student &c)
{
	cout << "enter rollno";
	cin >> c.rollno;
	cout << "enter name";
	cin >> c.name;
	cout << "enter three subjects marks";
	cin >> c.m1 >> c.m2 >> c.m3;
	return cin;
}
ostream& operator<< (ostream &cout, student c)
{
	cout << "\n details of the student are"<<endl;
	cout << c.rollno << endl << c.name << endl << c.m1 << endl << c.m2 << endl << c.m3 << endl<<c.totalm<<endl<<c.grade;
	return cout;
}
void calc(student *s, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		float avg = 0;

		s[i].totalm = s[i].m1 + s[i].m2 + s[i].m3;
		avg = s[i].totalm / 3;
		if (avg > 60)

			strcpy_s(s[i].grade, "First Class");
		else if (50 < avg < 60)
			strcpy_s(s[i].grade, "Second Class");

		else if (40 < avg < 50)
			strcpy_s(s[i].grade, "Third Class");
		else
			strcpy_s(s[i].grade, "Fail");
	}
}

int main()
{
	int i;
	cout << "enter the number of students ";
	int n1;
	cin >> n1;
	student s[5];
	for (i = 0; i < n1; i++)
	{
		cin >> s[i];
	}
	calc(s, n1);
	for (i = 0; i < n1; i++)
	{
		cout << s[i];
	}
	
	system("pause");
	return 0;
}