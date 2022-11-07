#include "TaskSchedulingSolution.h"

#include <vector>
#include <algorithm>

using namespace std;

int TaskSchedulingSolution::taskSchedule(int * d, int * w, int *scheduling, int n)
{
	/*
		算法流程，
			1、收集d[i],i,w[i]到一个TaskDesc结构中，并放入列表tasks中。
			2、创建一个保存当前独立任务的列表B（B中的元素是A中的元素的索引，且B中的元素安装d[i]降序）
			2、按照w[i]对列表tasks进行排序。
			3、执行greedy算法
				每次从列表取一个项k，检查是否可以扩展成独立任务。
					按照插入排序，把k插入到B中，同时记录确定k在B中的位置索引i。
					按照索引顺序访问B中的每一个元素
						每个元素，需要满足 A[B[i]].d >= i + 1。即截止时间大于完成时间。
					如果都满足，那么接受k项。
					否则，不接受，删除k（用索引i）。
			4、根据B填写调度的结果
			
			!!!!! 上面过程忽略了不少细节，具体请参加代码。
			时间复杂度O（n^2), 空间复杂度 O(n)
	*/

	vector<TaskDesc> tasks;
	vector<int> B;
	vector<bool> mask(n);
	int preTaskTotalWeight = 0, totalWeight = 0, p = 0;

	for (int i = 0;i < n;i++) 
	{
		totalWeight += w[i];
		TaskDesc taskDesc(i, d[i], w[i]);
		tasks.push_back(taskDesc);
	}

	sort(tasks.begin(), tasks.end());

	for (TaskDesc &td : tasks) {
	
		int i = 0;
		bool ok = true;

		for(;i < B.size();i++)
			if (td.declineTime < tasks[B[i]].declineTime)
				break;
		B.insert(i + B.begin(), td.tag);
		
		// 检查是否满足条件
		for (int j = 0; j < B.size(); j++) 
		{
			if (tasks[B[j]].declineTime < (j + 1))
			{
				ok = false;
				break;
			}
		}

		if (!ok)
			B.erase(i + B.begin());
	}

	for (int i : B) {
		preTaskTotalWeight += tasks[i].weight;
		mask[i] = 1;
		scheduling[p++] = i;
	}


	for (int i = 0;i < n;i++) 
		if (mask[i] == 0)
			scheduling[p++] = i;
	
	return totalWeight - preTaskTotalWeight;
}
