#include <iostream>
#include<cmath>
using namespace std;
int main( ){
int n,r,m,s=0;
cin>>n;
int i,c=0;
r=n;
int k=n;
while(k>0){
k=k/10;c++;
}

while(n>0)
{

m=n%10;
n=n/10;
s+=pow(m,c);

}
if(s==r)
cout<<"amstrong";
else
cout<<"not an amstrong";
system("pause");
//getch();
return 0;
}