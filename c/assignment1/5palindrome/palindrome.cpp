#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,m,p=0,r;
	cin>>n;
	r=n;
	int c=log10(n)+1;
	while(n>0)
	{
		m=n%10;
		n=n/10;
		c--;
		p+=m*pow(10,c);
		
	}
	if(r==p)
	cout<<"palindrome";
	else
	cout<<"not a palindrome";
	system("pause");
	return 0;
	}