#include <iostream>

using namespace std;

int bin_pow(int a, int n)
{
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return bin_pow(a, n - 1) * a;
	int bpow = bin_pow(a, n / 2);
	return bpow * bpow;
}

int main(void)
{
	cout << bin_pow(2,31) - 1 << endl;
}