#pragma once

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DivideAndConquerSolution 
{

public :
	/*
		两个有序数组中找到中位数
	*/
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

	/*
		找到连续子数组的最大和
	*/
	int MaximumSubarray(vector<int>& nums);

private:
	double GetKthInTwoSortedArrays(vector<int> & nums1, int left1, int right1, vector<int>& nums, int left2, int right2, int k);
	
	int MaximumSubarray(vector<int> & nums, int left, int right);

};
