#include <iostream>
using namespace std;

int main(){
int m,n,s=0;
cout<<"enter a number";
cin>>n;
while(n>0)
{
m=n%10;
s+=m;
n=n/10;
}
cout<<s;
system("pause");
}
