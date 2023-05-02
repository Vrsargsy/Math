#include <iostream>
#include <vector>

using namespace std;

bool binary_search(const vector<int> &arr, int x)
{
	int l = 0, r = arr.size() - 1;
	while(l <= r)
	{
		int m = (l + r) / 2;
		if (arr[m] == x)
			return true;
		else if (arr[m] < x)
		{
			l = m + 1;
		}
		else if (arr[m] > x)
		{
			r = m - 1;
		}
		cout << "a" << endl;
	}
	
	return false;
}

int main()
{
	vector<int> arr;
	for(int i = 0; i < 100; ++i)
	{
		arr.push_back(i);
	}
	// arr 0 - 99 ;

	cout << binary_search(arr, 76);

}