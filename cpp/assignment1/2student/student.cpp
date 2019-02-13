#include<iostream>
#include<cstring>
using namespace std;

class student
{
	char *sname;
	char grade[20];
	int s1marks, s2marks, s3marks;
	float avg;
public:
	void set_data(char *s, int m1, int m2, int m3)
	{

		sname = (char *)malloc(sizeof(char) * 12);
		strcpy_s(sname,12,s);
		s1marks = m1;
		s2marks = m2;
		s3marks = m3;
	}
	void calavg(student &a)
	{
		avg = (a.s1marks+a.s2marks+a.s3marks) / 3;
	}
	void compute_grade()
	{
		if (avg > 60)
		
			strcpy_s(grade, "First Class");
		else if (50 < avg < 60)
			strcpy_s(grade, "Second Class");
		
		else if (40 < avg < 50)
			strcpy_s(grade, "Third Class");
		else
			strcpy_s(grade, "Fail");
	}
	void display()
	{
		cout << "student details" << endl << "student name :" << sname << endl << "grade :" << grade;
		getchar();

	}
};
int main()
{
	student s;
	s.set_data("vasavi", 89, 90, 86);
	s.calavg(s);
	s.compute_grade();
	s.display();
	getchar();
	return 0;
}