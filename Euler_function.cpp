#include <iostream>
#include <vector>

using namespace std;

int	gcd(int a, int b)
{
	return b ? gcd(b, a % b): a;
}

int Euler_func(int n) // n(log(n))
{
	int count = 1;
	for(int i = 2; i < n; ++i)
	{
		if(gcd(i,n) == 1)
			count++;
	}
	return count;
}

int Euler_func_fast(int n) // O(sqrt(n))
{
	int res = n;
	int prime = 2;
	while(n >= prime * prime)
	{
		if (n % prime == 0)
		{
			res = res / prime * (prime - 1);
			while(n % prime == 0)
			{
				n /= prime;
			}
		}
		++prime;
	}
	if (n != 1)
	{
		res = res / n * (n - 1);
	}
	return res;
}

int main()
{
	cout << (Euler_func(9) == 6) << endl;
	cout << (Euler_func_fast(9) == 6) << endl;
	cout << (Euler_func(36) == 12) << endl;
	cout << (Euler_func_fast(36) == 12) << endl;
	cout << (Euler_func(84) == 24) << endl;
	cout << (Euler_func_fast(84) == 24) << endl;
}