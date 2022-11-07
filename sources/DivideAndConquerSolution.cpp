#include "DivideAndConquerSolution.h"

double DivideAndConquerSolution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	/*
		找到中位数，当nums1和nums2的长度之和为偶数，我们需要找到
		第(l1 + l2) / 2 大、第(l1 + l2) / 2 + 1大
		当为奇数时，只有一个
		(l1 + l2 ) / 2 + 1
	*/
	int len1 = nums1.size(), len2 = nums2.size();
	
	int k1 = (len1 + len2) / 2, k2 = (len1 + len2) / 2 + 1;

	if ((len1 + len2) % 2 == 0)
	{
		double res1 = GetKthInTwoSortedArrays(nums1, 0, len1 - 1, nums2, 0, len2 - 1, k1);
		double res2 = GetKthInTwoSortedArrays(nums1, 0, len1 - 1, nums2, 0, len2 - 1, k2);
		return (res1 + res2) * 0.5;
	}

	return GetKthInTwoSortedArrays(nums1, 0, len1 - 1, nums2, 0, len2 - 1, k2); 
}

double DivideAndConquerSolution::GetKthInTwoSortedArrays(vector<int>& nums1, int left1, int right1, vector<int>& nums2, int left2, int right2, int k)
{
	/*
	  每次去除 k/2个元素
	*/
	int len1 = right1 - left1 + 1;
	int len2 = right2 - left2 + 1;

	//让 len1 的长度小于 len2，这样就能保证如果有数组空了，一定是 len1
	if (len1 > len2)
		return GetKthInTwoSortedArrays(nums2, left2, right2, nums1, left1, right1, k);
	if (len1 == 0)
		return nums2[left1 + k - 1];

	if (k == 1)
		return std::min(nums1[left1], nums2[left2]);

	int i = left1 + std::min(len1, k / 2) - 1;
	int j = left2 + std::min(len2, k / 2) - 1;

	if (nums1[i] > nums2[j])
		return GetKthInTwoSortedArrays(nums1, left1, right1, nums2, j + 1, right2, k - (j - left2 + 1));
	else
		return GetKthInTwoSortedArrays(nums1, i + 1, right1, nums2, left2, right2, k - (i - left1 + 1));

}

int DivideAndConquerSolution::MaximumSubarray(vector<int>& nums)
{
	/*
		分支算法
		对于(nums1, start, left) 我们把它分解为三部分，
		左半部分，中间元素，右半部分。
			答案可能在左半边、右半边和中间那一块
				递归的求解左半边和右半边，
				如果是中间的那一块，我们可以从中间元素的前一个元素向前统计最大的连续子数组和，从中间元素的后一个元素向后
						统计最大的连续子数组和，中间的那一块即为两个统计值的和加上中间元素的值
			最后的答案就是三者的最大值
			时间复杂度等式近似为 T(n) = 2 * T(n / 2) + O(n)，时间复杂度为O（nlgn） 
		

	*/
	return MaximumSubarray(nums, 0, nums.size() - 1);
}

int DivideAndConquerSolution::MaximumSubarray(vector<int>& nums, int left, int right)
{
	/*
		当left == right，返回元素值
		当left > right，无效数组返回最小值
		当left < right,
			mid = （left + right） / 2，
	*/
	if (left > right)
		return INT32_MIN;
	
	int mid = (left + right) / 2;
	int subIntervalMaxs = std::max(MaximumSubarray(nums, left, mid - 1), MaximumSubarray(nums, mid + 1, right));
	
	int leftMaximum = 0, rightMaximum = 0;

	int currentSubarrayCount = 0;
	for (int i = mid - 1;i >= left;i--) 
	{
		currentSubarrayCount += nums[i];
		if (currentSubarrayCount > leftMaximum)
			leftMaximum = currentSubarrayCount;
	}
	
	currentSubarrayCount = 0;
	for (int i = mid + 1;i <= right;i++) {
		currentSubarrayCount += nums[i];
		if (currentSubarrayCount > rightMaximum)
			rightMaximum = currentSubarrayCount;
	}

	return std::max(subIntervalMaxs, nums[mid] + leftMaximum + rightMaximum);
}
