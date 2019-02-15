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
		strcpy_s(sptr, len + 1, s);
	}
	str(const str &temp)
	{
		len = temp.len;
		sptr = (char *)malloc(sizeof(char)*(len + 1));
		strcpy_s(sptr, len + 1, temp.sptr);
	}
	friend ostream& operator<<(ostream &cout, str s);
	~str()
	{
		if (sptr != NULL)
			free(sptr);
	}
};
ostream& operator<<(ostream &cout, str s)
{
	cout << s.sptr << s.len << endl;
	return (cout);
}
int main()
{
	str s1, s2("abc");
	str s4(s2);

	cout << s4;
	system("pause");
}