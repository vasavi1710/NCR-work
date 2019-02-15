#include<iostream>
using namespace std;
class arith {
	int a;
	int b;
public:
	arith()
	{
	 a = 10;
	 b =10;
	}
	arith(int c, int d)
	{
		a = c;
		b = d;
	}
	friend inline int add(arith);
	friend inline int sub(arith);
	friend inline int mul(arith);
	friend inline int div(arith);
	friend inline int mod(arith);
};
inline int add(arith A)
{
	int res = A.a + A.b;
	return res;
}
inline int sub(arith A)
{
	int res = A.a - A.b;
	return res;
}
inline int mul(arith A)
{
	int res = A.a * A.b;
	return res;
}
inline int div(arith A)
{
	if (A.b == 0)
	{
		cout << "divide by zero exception";
		return 0;
	}
	else
	{
		int res = A.a / A.b;
		return res;
	}

}
inline int mod(arith A)
{
	int res = A.a % A.b;
	return res;
}
int main()
{
	arith a1,a2(10,20),a3(4,2),a4;
	
	int added_res = add(a1);
	int subtracted_res = sub(a2);
	int multiplied_res=mul(a3);
	int division_res=div(a3);
	int mod_res=mod(a3);
	cout << "addition result is" << added_res << "\n subtracted result is" << subtracted_res << "\n multiplied result is" << multiplied_res << "division result is:" << division_res << "\n mod result " << mod_res;
	getchar();
	return 0;
}