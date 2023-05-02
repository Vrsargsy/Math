#include <iostream>

using namespace std;

int	gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int	lcd(int a, int b)
{
	return a / gcd(a, b) * b;
}

int main()
{
	cout << gcd(15, 4) << endl;
	cout << lcd(15, 4) << endl;
}
