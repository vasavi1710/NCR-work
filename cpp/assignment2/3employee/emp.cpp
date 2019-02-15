#include<iostream>
using namespace std;
#include<cstring>
class employee
{
	int eno;
	char ename[20];
	int sal;
public:
	employee() 
	{
		char str[2]=" ";
	
		eno = 0;
		strcpy_s(ename,2,str);
		sal = 0;
	}
	employee(int a, char *s, int b)
	{
		eno = a;
		strcpy_s(ename, strlen(s),s);
		sal = b;
	}
	void read_data()
	{
		cout << "enter eno";
		cin >> eno;
		cout << "enter name";
		cin >> ename;
		cout << "enter salary";
		cin >> sal;
	}
	friend ostream& operator<<(ostream &cout, employee *e1);
};
ostream& operator<<(ostream &cout, employee *e1) 
{
	int i;
	for (i = 0; i < 5; i++)
	{
		cout << "\nstudent" << i+1 << "details";
		cout << e1[i].eno << endl;
		cout << e1[i].ename << endl;
		cout << e1[i].sal << endl;

	}
	return cout;
}
int main()
{
	int i;
	employee *e;
	e = new employee[5];
	for (i = 0; i < 5; i++)
	{
		e[i].read_data();
	}
	cout << e;
	system("pause");
	return 0;
}