#include<iostream>
#include<stdlib.h>
using namespace std;
class itopre
{
	int top;
	char *s;
	int size;
	//char *o;
public:
	itopre()
	{
		top = -1;
		s = NULL;
		size = 0;
		//o = NULL;
	}
	bool isFull()
	{
		return(top == size - 1);
	}
	void push(char n)
	{
		if (!isFull())
			(s[++top] = n);
		else
			cout << "stack overflow";
	}
	bool isEmpty()
	{
		return(top == -1);
	}
	char pop()
	{
		char x = ' ';
		if (!isEmpty())
			(x = s[top--]);
		else
			cout << "stack underflow";
		return x;
	}
	char peek()
	{
		char x = ' ';
		if (!isEmpty())
			(x = s[top]);
		else
			cout << "stack underflow";
		return x;
	}
	void get_data()
	{
		s = new char[20];
		cout << "enter the expression";
		cin >> s;
		size = strlen(s);
	}
	int get_precednce(char ch)
	{
		int prec = -999;
		switch (ch)
		{
		case '+':prec = 1; break;
		case '-':prec = 1; break;
		case '*':prec = 2; break;
		case '/':prec = 2; break;
		case '{':prec = 0; break;
		case '(':prec = 0; break;
		case '[':prec = 0; break;
		default:;
		}
		return prec;
	}
	void infix_to_prefix()
	{
		_strrev(s);
		
		int i, j = 0, m;
		char *output;
		output = new char[20];
		for (i = 0; i < size; i++)
		{
			char k;
			k = s[i];
			switch (k)
			{
			case '+':
			case '-':
			case '*':
			case'/':char l;
				while (!isEmpty() && get_precednce(s[top]) > get_precednce(k))
				{
					l = pop();
					//_getchar();
					output[j] = l; j++;
				}
				push(k);
				break;
			case ')':
			case ']':
			case '}':push(k); break;
			case '{':
			case '[':
			case '(':int q;
				char p;
				for (q = top; (!isEmpty() && (s[q] != ']' &&s[q] != ')'&&s[q] != '}')); q--) 
				{
					p = pop();
					output[j] = p;
					j++;
				}
				p = pop();
				break;
			default:output[j] = k;
				j++;
				break;
			}
		}

		if (!isEmpty()) {
			for (i = top; i >= 0; i--)
			{
				char l;
				l = pop();
				output[j] = l;
				j++;
			}
		}
		output[j] = '\0';

		_strrev(output);
		cout << "\n" << output;
	}


	~itopre()
	{
		delete s;
	}
};
int main()
{
	itopre  a;
	a.get_data();
	a.infix_to_prefix();
	system("pause");
	return 0;
}