#include<iostream>
using namespace std;
int rotate_right(int n, int b);
int main()
{
int n,r;
cout<<"enter the number";
cin>>n;
cout<<"enter the number of bits to be rotated";
cin>>r;
int k=rotate_right(n,r);
cout << k << endl;
system("pause");
}
int rotate_right(int n, int b)
{
int l;
l=n>>b;
return l;
}
