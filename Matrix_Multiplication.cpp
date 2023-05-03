#include <iostream>
#include <vector>

using namespace std;

void	printMatrix(vector<vector<int> > &A)
{
	for(int i = 0; i < A.size(); ++i)
	{
		for(int j = 0; j < A[i].size(); ++j)
		{
			cout << A[i][j] << ' ';
		}
		cout << endl;
	}
}

vector<vector<int> > matrix_mul(vector<vector<int> > &A,vector<vector<int> > &B)
{
	int n = A.size();
	int m = A[0].size();
	int k = B[0].size();

	if (m != B.size())
		exit(1);
	vector<vector<int> > C(n, vector<int>(k));

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < k; ++j)
		{
			for(int k = 0; k < m; ++k)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	return C;
}

int main()
{
	vector<vector<int> > A = {
		{5, 2, 4},
		{6, 7, 3}
	};
	vector<vector<int> > B = {
		{1, 5, 6, 7},
		{2, 2, 1, 3},
		{4, 3, 2, 1}
	};
	vector<vector<int> > C = {
		{25, 41, 40, 45},
		{32, 53, 49, 66}
	};

	cout << (matrix_mul(A,B) == C) << endl;
}
