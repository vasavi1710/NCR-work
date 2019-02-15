#include<iostream>
#include<stdlib.h>
#include<cstring>

using namespace std;
class str
{
	char *sptr;
	int len;
public:
	str()
	{
		sptr = NULL;
		len = 0;
	}
	str(char *s)
	{
		len = strlen(s);
		sptr = (char *)malloc(sizeof(char)*(len + 1));
		strcpy_s(sptr, len+1, s);
	}
	str(const str &temp)
	{
		len = temp.len;
		sptr = (char *)malloc(sizeof(char)*(len + 1));
		strcpy_s(sptr, len+1,temp.sptr);
	}
	~str()
	{
		if (sptr!= NULL)
			free(sptr);
	}
	str operator+(str s)
	{
		str t;
		t.len = len + s.len;
		 t.sptr=(char *)calloc((t.len + 1),sizeof(char));
		 strcpy_s(t.sptr, len + 1, sptr);
		strcat_s(t.sptr,t.len+1, s.sptr);
		return t;
	}
	str operator=(str s)
	{
		len = s.len;
	sptr=(char *)calloc(len+1,sizeof(char));
		strcpy_s(sptr,len+1,s.sptr);
		return (*this);
	}
	char& operator[](int x)
	{
		return sptr[x];
	}
	friend ostream& operator<<(ostream &cout, str s);
	friend  istream& operator>> (istream &cin, str &s);
};
ostream& operator<<(ostream &cout,str s)
{
	cout << s.sptr << s.len << endl;
	return (cout);
}
istream& operator>> (istream &cin,str &s)
{
	cout<< "enter the length of the string";
	cin >> s.len;
	cout << "enter the string";
	s.sptr = (char*)malloc(sizeof(char)*(s.len + 1));
	cin >> s.sptr;
	return (cin);
}
int main()
{
	str s1, s2("apple");
		str s3(s2);
		cout << s2;
		str s4;
		cin >> s4;
		str s5;
		s5=(s2 + s4);
		cout << s5;
		s2[2] = 'x';
		cout << s2;
		cout << s2[3];
		cout << s2;
		system("pause");
		return 0;
}
