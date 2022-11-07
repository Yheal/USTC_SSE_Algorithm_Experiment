#include "SortAlgorithmSolution.h"

void SortAlgorithmSolution::quickSort(vector<int>& A) { quickSort(A, 0, A.size() - 1);}

void SortAlgorithmSolution::quickSort(vector<int>& A, int left, int right)
{
	if (left < right)
	{
		int q = partition(A, left, right);
		quickSort(A, left, q - 1);
		quickSort(A, q + 1, right);
	}
}

int SortAlgorithmSolution::partition(vector<int>& A, int left, int right)
{
	int baseElement = A[left];
	int p = left, q = right;
	while (p < q) {
		// 先让右边的
		while (p < q && A[q] >= baseElement)
			q--;
		A[p] = A[q];
		while (p < q &&  A[p] < baseElement)
			p++;
		A[q] = A[p];
	}

	A[p] = baseElement;

	return p;
}

void SortAlgorithmSolution::CountSort(vector<int>& A)
{
	int minValue = *min_element(A.begin(), A.end());
	int maxValue = *max_element(A.begin(), A.end());
	
	vector<int> C(maxValue - minValue + 1);
	vector<int> B(A);

	for (int n : A) 
		C[n - minValue]++;
	
	for (int i = 1;i < C.size();i++)
		C[i] += C[i - 1];

	/*
		这里直接赋值
	*/
	for (int i = B.size() - 1;i >= 0;i--) {
		int offset = B[i] - minValue;
		C[offset]--;
		A[C[offset]] = B[i];
	}

}
