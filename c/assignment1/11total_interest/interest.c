#include<stdio.h>
int main()
{
	float s, p, t, r, ca, csa, cqa, cm, cd;
	p = 500000;
	t = 10;
	r = 3.5;
	s = (p*t*r) / 100;

	r = r / 100;
	ca = p*(pow((1 + r), t));
	csa = p*(pow((1 + (r / 2)), t * 2));
	cqa = p*(pow((1 + (r / 4)), t * 4));
	cm = p*(pow((1 + (r / 12)), t * 12));
	cd = p*(pow((1 + (r / 365)), t * 365));
	printf("%f %f %f %f %f %f", s, ca, csa, cqa, cm, cd);
	getch();
	return 0;
}