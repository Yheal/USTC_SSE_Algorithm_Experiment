#include "KBackpackQuestions.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


int KBackpackQuestions::BackpackQuestion(int c, int* weights, int* values, int* puts, int n, KBackPackMethod method)
{
	if (method == DYNAMIC_PROGRAMMING)
		return dpSolution(c, weights, values, puts, n);
	else if (method == GREED)
		return greedSolution(c, weights, values, puts, n);
	return backtrackSolution(c, weights, values, puts, n);
}

int KBackpackQuestions::dpSolution(int c, int * weights, int * values, int * puts, int n)
{
	/*
		dps[c, j]表示容量为c时，前j个元素可获得的最大
		dps[c, j] = max(dps[c, j-1], dps[c - weights[j], j-1] + values[j]);
		selection[c, j]表示容量为c时，选不选第j个元素
	*/
	vector<vector<int>> dps(c + 1);
	vector<vector<int>> selection(c + 1);

	for (int i = 0;i <= c;i++) {
		dps[i].resize(n + 1, 0);
		selection[i].resize(n + 1, 0);
	}

	for (int ca = 1;ca <= c;ca++)
	{
		for (int i = 1;i <= n;i++) {
			dps[ca][i] = dps[ca][i - 1];   // 默认不选择
			if (ca >= weights[i - 1]) {
				if (dps[ca - weights[i - 1]][i - 1] + values[i - 1] > dps[ca][i]) {
					selection[ca][i] = 1;
					dps[ca][i] = dps[ca - weights[i - 1]][i - 1] + values[i - 1];
				}
			}

		}
	}

	int k = n, ca = c;
	while (k > 0 && ca > 0) {
		if (selection[ca][k] == 1)
		{
			ca -= weights[k - 1];
			puts[k - 1] = 1;
		}
		else
			puts[k - 1] = 0;

		k--;
	}
	
	return dps[c][n];
}

int KBackpackQuestions::greedSolution(int c, int * weights, int * values, int * puts, int n)
{
	/*
		每次取单位质量最高的进入背包中
	*/
	vector<MyPair> wvs;
	int maxValue = 0, capcity = c;

	for (int i = 0;i < n;i++) 
	{
		MyPair pa(i, ((double)values[i]) / ((double)weights[i]));
		wvs.push_back(pa);
	}

	memset(puts, 0, sizeof(int) * n);
	
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n - i - 1;j++) 
		{
			if (wvs[j].wv < wvs[j + 1].wv) {
				int index = wvs[j].index;
				double v = wvs[j].wv;
				
				wvs[j].index = wvs[j + 1].index;
				wvs[j].wv = wvs[j + 1].wv;

				wvs[j + 1].index = index;
				wvs[j + 1].wv = v;
			}
		}
	}

	for (int i = 0;i < wvs.size();i++) 
	{
		if (capcity >= weights[wvs[i].index]) 
		{
			capcity -= weights[wvs[i].index];
			maxValue += values[wvs[i].index];
			puts[wvs[i].index] = 1;
		}
	}

	return maxValue;
}

int KBackpackQuestions::backtrackSolution(int c, int * weights, int * values, int * puts, int n)
{
	cout << "暂时不会实现"  << endl;
	return 0;
}
