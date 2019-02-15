#include<iostream>
#include<cstring>
using namespace std;

class emp
{
	char ename[20];
	int rollno;
	float sal;

public:
	emp()
	{
		char *s;
		s = " ";
		strcpy_s(ename, 2, s);
			rollno = 0;
			sal = 0;
		cout << "i am default constructor";
	}
	emp(char *s, int r,float s1)
	{
	strcpy_s(ename, 10, s);
	rollno=r;
	sal = s1;
	cout << "i am parametrized constructor";
	}
	void display()
	{
		cout << "student details" << endl << "student name :" << ename << endl << "rollno"<<rollno<<"sal"<<sal;
		

	}
	~emp()
	{
		cout << "destructor";
		system("pause");
	}
	void set_rollno(int i)
	{
		cout << "call by value";
		rollno = i;
	}
	void set_sal(float &sal)
	{
		cout << "call by reference";
		sal = 111;
	}
};
int main()
{
	emp e;
	float salqa = 2200;
	e.display();
	e.set_rollno(255);
	e.set_sal(salqa);
	system("pause");
	
	return 0;
}