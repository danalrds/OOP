#include <stdio.h>
#include <assert.h>
//procedure that generates all the prime numbers until the n^th one 
//input data: n - integer number
//output data: the first n prime numbers
void ciur(int v[10000],int n)
{
	int prim[100000];
	long i, j, contor;
	contor = 0;
	for (i = 2; i<100000; i++)
	{
		prim[i] = 1;
	}
	for (i = 2; i <100000; i++)
	{
		if (prim[i] == 1)
		{
			j = i;
			contor = contor + 1;
			v[contor] = i;
			while (j<100000)
			{
				prim[j] = 0;
				j = j + i;
			}

		}
		if (contor == n)
		{
			break;
		}
	}

}
//test function for requirement 1
void test1()
{
	int n;
	int x[10000];	
	n = 4;
	ciur(x, n);		
	assert(x[1] == 2);
	assert(x[2] == 3);
	assert(x[3] == 5);
	assert(x[4] == 7);
}
//function that decides if 2 given numbers are prime between each other
//input data: a,b both integers
//output data: 1 if they are relatively prime, 0 otherwise
int primeintreele(int a, int b)
{
	int r, aux;
	if (a < b)
	{
		aux = a;
		a = b;
		b = aux;
	}
	r = 1;
	if (a==0)
	{
		return 1;
	}
	if (b==0)
	{
		return 1;
	}
	while (r != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	if (a == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//procedure that solves requirement 2 by finding the longest sequence in which any 2 consecutive numbers are relatively prime
//input data:the vector x and the number of elements n 
//output data:the longest sequence that respects the requirements 
void cerinta2(int x[10000], int n,int *start,int *fin)
{
	int max, contor, st, stbun, i;
	contor = 1;
	max = 0;
	st = 1;
	for (i = 1; i < n; i++)
	{
		if (primeintreele(x[i], x[i + 1]) == 1)
		{
			contor = contor + 1;
		}
		else
		{
			if (contor > max)
			{
				stbun = st;
				max = contor;
			}
			contor = 1;
			st = i + 1;
		}
	}
	if (contor > max)
	{
		stbun = st;
		max = contor;
		contor = 1;
	}
	*start = stbun;
	*fin = stbun + max - 1;
}
//function that solves requirement 3 
//input data: n integer number
//output data: x array with contor elements
int cerinta3(int x[10000], int n)
{
	int i,contor;
	contor = 0;
	for (i = 1; i < n; i++)
	{
		if (primeintreele(i, n) == 1)
		{
			contor++;
			x[contor] = i;
		}
	}
	return contor;
}
//test function for requirement 2
void test2()
{
	int i,start,fin;
	int x[10000];
	for (i = 1; i <= 7; i++)
	{
		x[i] = i;
	}
	int *st = &start;
	int *dr = &fin;
	cerinta2(x, 7, st, dr);
	assert(start == 1);
	assert(fin == 7);
}
//test function for requirement 3
void test3()
{
	int n,contor;
	int x[10000];
	n = 8;
	contor=cerinta3(x,n);
	assert(x[1] == 1);
	assert(x[2] == 3);
	assert(x[3] == 5);
	assert(x[4] == 7);
}
//procedure that finds the first n prime numbers 
//input data: integer number n
//output data: the first n prime numbers
void cerinta1(int v[10000],int n)
{
	int contor, d, i, ok;
	contor = 0;
	i = 2;
	while (contor < n)
	{
		ok = 1;
		for (d = 2; d <= i / 2; d++)
		{
			if (i%d == 0)
			{
				ok = 0;
				break;
			}
		}
		if (ok == 1)
		{			
			contor = contor + 1;
			v[contor] = i;
		}
		i = i + 1;

	}	
}
//reading procedure for a vector, returns the number of elements
int citire(int x[10000])
{
	int n,i;
	printf("Give the number n: ");
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf_s("%d", &x[i]);
	}
	return n;
}
//procedure that prints a vector v with n elements
void afisare(int v[10000], int st, int n)
{
	int i;
	for (i=st;i<=n;i++)
	{
		printf("%d ", v[i]);
	}
	printf("\n");
}
//function that calls the tests
void testall()
{
	test1();
	test2();
	test3();
}
//main function: prints the menu and reads the required data
//calls to cerinta1,cerinta2,ciur
int main()
{
	testall();
	int option, n,start,fin,contor;
	int x[10000];
	int v[10000];
	while (1)
	{
		printf("1.The first n prime numbers\n");
		printf("2.The longest continuous subsequence such that any two consecutive elements are relatively prime\n");
		printf("3.All the numbers relatively prime with n\n");
		printf("Enter option: ");
		scanf_s("%d", &option);
		if (option == 1)
		{
			printf("Give the number n: ");
			scanf_s("%d", &n);
			printf("The first n prime numbers are: ");
			//cerinta1(n);    //or call to ciur
			ciur(v,n);
			afisare(v, 1,n);			
			//scanf_s("%d", &n);
		}
		if (option == 2)
		{
			n=citire(x);
			int *st = &start;
			int *dr = &fin;
			cerinta2(x, n,st,dr);
			printf("The longest continuous subsequence required is: ");
			afisare(x, start, fin);			
			//scanf_s("%d", &n);
		}
		if (option == 3)
		{
			printf("Give the number n: ");
			scanf_s("%d", &n);
			printf("All the numbers smaller than n, which are relatively prime with n: ");
			//cerinta1(n);    //or call to ciur
			contor=cerinta3(x,n);
			afisare(x, 1, contor);
			//scanf_s("%d", &n);	
		}
		if (option>3)
		{
			printf("Invalid command!");
		}
		if (option == 0)
		{
			break;
		}
	}
	return 0;
}
