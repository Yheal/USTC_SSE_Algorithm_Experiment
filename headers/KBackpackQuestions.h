#pragma once

enum KBackPackMethod {
	DYNAMIC_PROGRAMMING,
	GREED,
	BACKTRACK,
};

class MyPair
{
public:
	int index;
	double wv;
	MyPair(int index, double wv) {
		this->index = index;
		this->wv = wv;
	}

};

class KBackpackQuestions 
{
public:
	/*  c为背包容量，n为物品个数，weights为重量、valus为价值、puts记录物品是否放入背包，method为算法方法 */
	int BackpackQuestion(int c, int* weights, int* values, int* puts, int n, KBackPackMethod method = DYNAMIC_PROGRAMMING);

private:

	int dpSolution(int c, int* weights, int* values, int* puts, int n);
	int greedSolution(int c, int* weights, int* values, int* puts, int n);
	int backtrackSolution(int c, int* weights, int* values, int* puts, int n);
};