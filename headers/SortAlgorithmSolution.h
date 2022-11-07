#pragma once

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SortAlgorithmSolution 
{
public:
	void quickSort(vector<int>& A);
	void CountSort(vector<int> &A);

private:
	void quickSort(vector<int>& A, int left, int right);
	int partition(vector<int>& A, int left, int right);
};