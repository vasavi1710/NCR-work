#include<iostream>
using namespace std;
class matrix
{
	
	int arr[3][3];
	int sum = 0;
public:
	matrix()
	{
		int i,j;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				cin >> arr[i][j];
			}
		}
		sum = 0;
	}
	matrix(int x)
	{
		int i, j;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				 arr[i][j]=0;
			}
		}
		sum = 0;
	}
	void display()
	{
		int i, j;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				cout << arr[i][j]<<" ";
				
			}
			cout <<"\n";
		}
	}
	friend matrix multiplication(matrix b,matrix c);
};
	
matrix multiplication(matrix b,matrix c)
{
	
	matrix a(1);
	int i = 0, j = 0, k = 0;
	a.sum = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 3; k++)
			{
				a.sum = a.sum + b.arr[i][k] * c.arr[k][j];
			}
			a.arr[i][j] = a.sum;
//			cout << a.arr[i][j];
			a.sum = 0;
		}
	}
	//cout << a.arr[0][0];
	return a;

}
int main()
{
	cout << "enter the elements of the matrix";
	matrix m1;
	cout << "m1 reading done";
	matrix m2;
	//m2.display();
	cout << "m2 reading done";
	matrix m3(1);
	//m3.display();
	m3=multiplication(m1, m2);
	m3.display();
	system("pause");
	return 0;
}