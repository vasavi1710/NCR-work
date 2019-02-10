#include<stdio.h>
void main()
{
	int X, P, N, RESULT;
	int invert(int, int, int);

	printf("ENTER ANY INTEGER TO INVERT (X) : \n");
	scanf_s("%d", &X);
	printf("ENTER THE START POSITION TO INVERT (P) :\n");
	scanf_s("%d", &P);
	printf("ENTER THE LENGTH TO INVERT (N) :\n");
	scanf_s("%d", &N);
	printf("CONVERTED BINARY VALUE OF %d IS \t", X);
	RESULT = invert(X, P, N);
	printf("\nINVERTED INTEGER IN DECIMAL FORM IS \t%d", RESULT);
	getch();
}

int invert(int X, int P, int N)
{
	int I, Y, LIMIT, LEN, BIN[15];
	LEN = 0;
	while (X>0)
	{
		BIN[LEN] = X % 2;
		X = X / 2;
		LEN++;
	};

	for (I = LEN - 1; I>-1; I--)
	{
		printf("%d ", BIN[I]);
	}
	printf("\n");
	LIMIT = P + N;
	if (LIMIT < LEN)
	{
		for (I = P - 1; I<P + N - 1; I++)
		{
			if (BIN[I] == 0)
				BIN[I] = 1;
			else
				BIN[I] = 0;
		}
	}
	else
	{
		printf("YOU HAVE ENTERED LARGE VALUE FOR P AND N");
	}

	printf("INVERTED INTEGER IN BINARY FORM IS \t");
	for (I = LEN - 1; I>-1; I--)
	{
		printf("%d ", BIN[I]);
	}
	Y = 0;
	for (I = LEN - 1; I >= 0; I--)
	{
		Y = Y * 2 + BIN[I];
	}
	return Y;
}