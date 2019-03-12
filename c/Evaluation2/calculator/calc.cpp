/*CALCULATOR*/
#include<iostream>
#include<stdlib.h>
int add();
int sub();
int mul();
int div();
int mod();
int operand1, operand2;
//int a, b;
using namespace std;
class itopos//INFIX TO POSTFIX CLASS
{
	int top;//TOP ELEMENT IN THE STACK
	char *s;//STACK
	int size;//SIZE OF THE STACK
	char *output;//OUTPUT
	//char *o;
public:
	itopos()//DEFAULT CONSTRUCTOR
{
		top = -1;//SETTING TOP TO -1
		s = NULL;//STACK IS POINTING TO NULL
		size = 0;//SETTING SIZE OF THE STACK TO 0
		//o = NULL;
	}
//void balance()//BALANCE FUNCTION
//	{
//		top = -1;
//		s = NULL;
//		size = 0;
//	}
int bal_fun()//BALANCED PARANTHESIS CHECK FUNCTION
{
	int i;
	int flag = 0;//FLAG TO KNOW WHETHER EXPRESSION IS BALANCED OR NOT
	char ch;//TEMPORARY CHARACTER

	for (i = 0; i<size; i++)//TRAVERSING THE ENTIRE EXPRESSION
	{
		ch = s[i];//GETTING EACH CHAR FROM THE EXPRESSION
		switch (ch)
		{
		case '(':
		case '[':

		case '{':push(ch);//CASES WHEN ENCOUNTER THE OPEN BRACKETS
			break;
		case ')':

		case ']':

		case '}':
			if (!isEmpty())
			{
				char t;
				t = peek();
				if ((t == '(' && ch == ')') || (t == '[' && ch == ']') || (t == '{' && ch == '}'))
				{
					t = pop();
				}
			}
			else
				flag = 1;
			break;
		default:break;
		}

		if (flag == 1)
			break;
	}
	if (top == -1 && flag == 0)
		flag = 0;
	else
		flag = 1;

	return flag;
}


	bool isFull()//WHETHER STACK IS FULL
	{
		return(top == size - 1);
	}
	void push(char n)//PUSHING THE ELEMENT TO THE STACK
	{
		if (!isFull())//IF STACK IS NOT FULL
			(s[++top] = n);
		else
			cout << "stack overflow";//STACK IS FULL
	}
	bool isEmpty()//UNDERFLOW
	{
		return(top == -1);
	}
	char pop()//DELETING ELEMENT FROM THE STACK
	{
		char x = ' ';
		if (!isEmpty())
			(x = s[top--]);
		else
			cout << "stack underflow";
		return x;
	}
	char peek()//FETCHING TOP ELEMENT FROM THE STACK
	{
		char x = ' ';
		if (!isEmpty())
			(x = s[top]);
		else
			cout << "stack underflow";
		return x;
	}
	void get_data()//GETTING THE EXPRESSION FROM USER
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
			*/
		for (i = 0; i < size; i++)
		{
			if (('a' <= s[i] && s[i] <= 'z')|| ('A' <= s[i] && s[i] <= 'Z'))
			{
				printf("you have entered characters operations cannot be performed");
				getchar();
				exit(1);
			}
			if (s[i] == '.')
			{
				printf("float value not allowed");
				getchar();
				exit(1);
			}
			if (isdigit(s[i]))
			{
				if (isdigit(s[i + 1]))
				{
					printf("multiple digits not allowed");
					getchar();
					exit(1);
				}
			}
			if (s[i] == '+' || s[i] == '*' || s[i] == '/' || s[i] == '-')

			{
				if (s[i + 1] == '+' || s[i + 1] == '*' || s[i + 1] == '/' || s[i + 1] == '-')
				{
					printf("operator should be preceded by an operand");
					getchar();
					exit(1);
				}
			}
		}
	}
	int get_precednce(char ch)//GETTING THE PRECEDENCE OF A SYMBOL ENCOUNTERED
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
	void infix_to_postfix()//CONVERTING THE INFIX EXPRESSION TO POSTFIX 
	{
		int i, j = 0, m;
		output = new char[size + 1];
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
		cout << "\n" << output;
		return;
		//output;
	}
	void postfix_evaluation()//POSTFIX EVALUATION
	{
		long int  temp=0, result;
		unsigned int i;
		//int flag = 0;
		for (i = 0; i<strlen(output); i++)
		{
			if (output[i] <= '9' && output[i] >= '0')
				push(output[i] - '0');
			else
			{
				operand1 = pop();
				operand2 = pop();
				switch (output[i])
				{
				case '+':
					temp = add(); break;
				case '-':
					temp = sub(); break;
				case '*':
					temp = mul(); break;
				case '/':
					temp = div(); break;
				case '%':
					temp = mod(); break;
				case '^':
					temp = pow(operand2, operand1);
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
	a.get_data();//GETTING THE EXPRESSION FROM USER
	//char *output;
	//output = new char[strlen(a) + 1];
	int f = a.bal_fun();//SENDING TO BALANCE FUNCTION TO CHECK THE PARANTHESIS
	if (f == 1)//NOT BALANCED
	{
		cout << "paranthesis are not balanced in the given expression\n invalid data";
		getchar();
		exit(1);
	}
	else//BALANCED
		cout << "given expession has paranthesis balanced";


	a.infix_to_postfix();//CONVERSION FROM INFIX TO POSTFIX
	a.postfix_evaluation();//POSTFIX EVALUATION
	//printf(" \n%s", res);
	system("pause");
	return 0;
}