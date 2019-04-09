#include <stdio.h>
int lant[100], lact[100];
int prim(int x)
{
	int d,ok;
	ok = 1;
	if (x<2)
	{
		ok=0;
	}	
	for (d=2;d<=x/2;d++)
	{
		if (x %d == 0)
		{
			ok = 0;			
		}
	}
	if (ok == 1)
	{
		return 1;
	}	
	else
	{
		return 0;
	}
}

void cerinta2(int x[100],int n)
{
	int contor, max, st, stbun,i;
	contor = 0;
	max = 0;
	st = 1;
	for (i = 1; i <= n; i++)
	{
		if (prim(x[i])==1)
		{
			contor++;
		}
		else
		{if (contor>max)
			{
			max = contor;
			stbun = st;
			
			}
		contor = 0;
		st = i + 1;
		}
	}
	if (contor>max)
	{
		max = contor;
		stbun = st;
		contor = 1;
		st = i + 1;
	}
	if (max > 0)
	{
		for (i = stbun; i < stbun + max; i++)
		{
			printf("%d ", x[i]);
		}
	}
	else
	{
		printf("There is no sequence!");
	}
}
void pascal(int n)
{
	int i, contor;	
	for (i=0;i<=100;i++)
	{
		lant[i] = 0;
		lact[i] = 0;
	}
	lant[1] = 1;
	printf("1 \n");
	contor = 1;
	while (contor < n)
	{
		contor = contor + 1;
		for (i = 1; i <= contor; i++)
		{
			lact[i] = lant[i - 1] + lant[i];
			//printf("%d %d ", lant[i - 1], lant[i]);
		}		
		for (i = 1; i <= contor; i++)
		{
			printf("%d ", lact[i]);
		}
		for (i = 1; i <= contor; i++)
		{
			lant[i] = lact[i];
		}
		printf("\n");
	}
	printf("\n");
}
int main()
{
	int option, n,i;
	int x[1000];
	while (1)
	{		
		printf("1.Pascal triangle of degree n\n");
		printf("2.Longest subsequence of prime numbers\n");
		printf("0.Exit\n");
		printf("Enter command: ");
		printf("\n");
		scanf_s("%d", &option);
		if (option == 1)
		{
			printf("Give the degree of the triangle: ");
			scanf_s("%d", &n);
			pascal(n);
		}
		if (option == 2)
		{
			printf("Give the numer n: ");
			scanf_s("%d", &n);
			for (i = 1; i <= n; i++)
			{
				scanf_s("%d", &x[i]);
			}
			cerinta2(x, n);
			printf("\n");
		}
		if (option == 0)
		{
			break;
		}
		if (option>2)
		{
			printf("Invalid command!");
		}
	}
	return 0;
}