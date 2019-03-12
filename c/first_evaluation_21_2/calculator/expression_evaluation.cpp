#include<iostream>
#include<stdlib.h>
using namespace std;
class itopos
{
	int top;
	char *s;
	int size;
	char *output;
	//char *o;
public:
	itopos()
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
		char Temporary_Char = ' ';
		int Size = 2;
		int i = 0;
		cout << "enter the expression and the operations can be performed on single digit numbers only";
		s = (char *)malloc(sizeof(char));
		while ((Temporary_Char = getc(stdin)) != '\n')
		{
			realloc(s, sizeof(char)*Size);
			s[i] = Temporary_Char;
			Size++;
			i++;
		}
		s[i] = '\0';
		size = i;
	/*	 s= new char[20];
		
		cin >> s;
		size = strlen(s);
	*/}
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
	void infix_to_postfix()
	{
		int i, j = 0, m;
		output = new char[size+1];
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
				while (!isEmpty() && get_precednce(s[top]) >= get_precednce(k))
				{
					l = pop();
					//_getchar();
					output[j] = l; j++;
				}
				push(k);
				break;
			case '(':
			case '[':
			case '{':push(k); break;
			case '}':
			case ']':
			case ')':int q;
				char p;
				for (q = top; (!isEmpty() && (s[q] != '[' &&s[q] != '('&&s[q] != '{')); q--)
				{
					p = pop();
			//		cout << p;
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
		//cout << "\n" << output;
		return;
		//output;
	}
	void postfix_evaluation()
	{
		long int a, b, temp, result;
		unsigned int i;
		//int flag = 0;
		for (i = 0; i<strlen(output); i++)
		{
			if (output[i] <= '9' && output[i] >= '0')
				push(output[i] - '0');
			else
			{
				a = pop();
				b = pop();
				switch (output[i])
				{
				case '+':
					temp = b + a; break;
				case '-':
					temp = b - a; break;
				case '*':
					temp = b*a; break;
				case '/':
					temp = b / a; break;
				case '%':
					temp = b%a; break;
				case '^':
					temp = pow(b, a);
				}
				push(temp);
			}
		}

		result = pop();
//		printf("the popped element is %d", result);
		printf("%d", result);
		/*return result;*/
	}

	~itopos()
	{
		delete s;
	}
};
int main()
{
	float res = 0;
	itopos  a;
	a.get_data();
	//char *output;
	//output = new char[strlen(a) + 1];
	a.infix_to_postfix();
	a.postfix_evaluation();
	//printf(" \n%s", res);
	system("pause");
	return 0;
}