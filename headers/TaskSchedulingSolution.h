#pragma once

class TaskDesc 
{
public:
	int tag, declineTime;
	int weight;

	TaskDesc(int tag, int declineTime, int weight) 
	{
		this->tag = tag;
		this->declineTime = declineTime;
		this->weight = weight;
	}

	bool operator < (const TaskDesc& td) const {
		return weight >= td.weight;
	}

	bool operator > (const TaskDesc& td) const {
		return weight >= td.weight;
	}

};

class TaskSchedulingSolution 
{
public:
	/* 1~n个单位时间任务。在单CPU上对他们进行调度，也就是形成一个排列组成。
	d[i]表示其截止时间，w[i]表示未在截止时间完成该任务的惩罚时间。
	排列的结果存放在result中，目标是最小化未在截止时间完成的任务的惩罚之后。
	*/

	// 规范化的调度方法：提前任务都在延迟任务之后。
	// 寻找最优调度方案问题即为寻找提前任务子集A，而且最小化延迟任务的惩罚之后与最大化提前任务的惩罚之和等价
	
	// (S, T)是一个拟阵（证明看不懂），S是一个给定截止时间的单位时间任务集合，T是所有独立任务的集合。
	// 可以使用Greedy算法来求解最大权重的独立任务集合。

	/*
		单位调度问题的独立任务，定义为A中的所有任务都可以在截止时间内完成。
		1、如果A中的任务按截止时间单调递增的顺序调度，那么不会有任务延迟。
	    2、对于 t = 0，1， 2， ..., n， 有Nt（A）<= t， Nt(A)定义为截止时间小于等于t的任务数。
	*/

	int taskSchedule(int *d, int *w, int *scheduling, int n);

	
};