#include <iostream>

#include "DivideAndConquerSolution.h"
#include "SortAlgorithmSolution.h"
#include "KBackpackQuestions.h"
#include "TaskSchedulingSolution.h"
#include "BinarySearchTree.h"
#include "RedBlackTree.h"

void divideAndConquerTest()
{
	std::cout<<"------------------------------ Divide And Conquer --------------------------"<<std::endl;
	
	DivideAndConquerSolution solution;
	vector<int> test1;
	test1.push_back(-2);
	test1.push_back(1);
	test1.push_back(-3);
	test1.push_back(4);
	test1.push_back(-1);
	test1.push_back(2);
	test1.push_back(1);
	test1.push_back(-5);
	test1.push_back(4);

	std::cout << "Maximum Subarray: " << solution.MaximumSubarray(test1) << endl;

	vector<int> test2;
	test2.push_back(1);
	test2.push_back(2);
	test2.push_back(3);
	test2.push_back(4);
	test2.push_back(8);

	vector<int> test3;
	test3.push_back(2);
	test3.push_back(4);
	test3.push_back(6);
	test3.push_back(8);
	test3.push_back(10);


	std::cout << "Median Element: " << solution.findMedianSortedArrays(test2, test3) << endl;

	std::cout<<"------------------------------- Divide And Conquer--------------------------"<<std::endl;


} 

void sortAlgoritmsTest()
{
	std::cout<<"------------------------------ Sort Algorithm --------------------------"<<std::endl;
	SortAlgorithmSolution sortAlgorithmSolution;

	vector<int> test;
	test.push_back(-2);
	test.push_back(1);
	test.push_back(-3);
	test.push_back(4);
	test.push_back(-1);
	test.push_back(2);
	test.push_back(1);
	test.push_back(-5);
	test.push_back(4);
	sortAlgorithmSolution.quickSort(test);
	cout<<"Quick Sort: ";
	for (int i : test)
		cout << i << " ";
	cout << endl;

	test.clear();
	test.push_back(95);
	test.push_back(94);
	test.push_back(90);
	test.push_back(98);
	test.push_back(99);
	test.push_back(97);
	test.push_back(96);
	test.push_back(93);
	test.push_back(91);
	test.push_back(92);
	sortAlgorithmSolution.CountSort(test);
	cout<<"Count Sort: ";
	for (int i : test)
		cout << i << " ";
	cout << endl;
	std::cout<<"------------------------------ Sort Algorithm --------------------------"<<std::endl;

}

void binarySearchTreeTest()
{
	std::cout<<"------------------------------ Binary Search Tree --------------------------"<<std::endl;

	BinarySearchTree tree;
	tree.InsertNode(5);
	tree.InsertNode(1);
	tree.InsertNode(4);
	tree.InsertNode(3);
	tree.InsertNode(6);
	 
	cout<<"After inserting 5, 1, 4, 3, 6, the middle order sequence is: "; 
	tree.InorderTreeWalk();

	tree.DeleteNode(1);
	tree.DeleteNode(5);
	tree.DeleteNode(4);
	tree.DeleteNode(3);
	cout<<"After deleteing 1, 5, 4, 3, the middle order sequence is: "; 
	tree.InorderTreeWalk();

	TreeNode *root = new TreeNode(5);
	TreeNode *r_l = new TreeNode(1);
	TreeNode *r_r = new TreeNode(4);
	TreeNode *r_r_l = new TreeNode(3);
	TreeNode *r_r_r = new TreeNode(6);

	root->left = r_l;
	root->right = r_r;
	r_r->left = r_r_l;
	r_r->right = r_r_r;
	if (tree.IsBinarySearchTree(root))
		cout << "\nexample is binary search tree!" << endl;
	else
		cout << "\nexample is not binary search tree!" << endl;
	std::cout<<"------------------------------ Binary Search Tree --------------------------"<<std::endl;
}

void redBlackTreeTest()
{
	std::cout<<"------------------------------Red Black Tree --------------------------"<<std::endl;
	RBTree rbTree;
	
	rbTree.insertNode(1);
	rbTree.insertNode(5);
	rbTree.insertNode(6);
	rbTree.insertNode(7);
	rbTree.insertNode(8);
	rbTree.insertNode(9);
	rbTree.insertNode(10);
	rbTree.insertNode(11);
	rbTree.insertNode(12);
	rbTree.insertNode(13);
	rbTree.insertNode(14);
	rbTree.checkRB();
	rbTree.printRB();

	rbTree.deleteNode(14);
	rbTree.deleteNode(9);
	rbTree.deleteNode(5);
	rbTree.deleteNode(8);
	rbTree.checkRB();
	rbTree.printRB();
	
	std::cout<<"------------------------------Red Black Tree --------------------------"<<std::endl;

}

void taskSchedulingTest()
{
	std::cout<<"------------------------------Task Scheduling --------------------------"<<std::endl;
	TaskSchedulingSolution tss;
	int d[7] = { 4, 2, 4 ,3, 1, 4, 6 };
	int w[7] = { 70, 60, 50, 40, 30, 20, 10 };
	int result[7];
	int k = 7;
	cout << "Question 1:\n    The penalty value is " << tss.taskSchedule(d, w, result, k) << endl;
	cout << "    The scheduling sequence is ";
	for (int i = 0;i < k;i++) 
		cout << " a" << result[i] + 1;
	cout << '\n'<< endl;

	for(int i = 0;i < k;i++)
		w[i] = 80 - w[i];

	cout << "Question 2:\n    The penalty value is " << tss.taskSchedule(d, w, result, k) << endl;
	cout << "    The scheduling sequence is ";
	for (int i = 0;i < k;i++) 
		cout << " a" << result[i] + 1;
	cout << '\n'<< endl;
	std::cout<<"------------------------------Task Scheduling --------------------------"<<std::endl;

}

void knapsackTest()
{
	std::cout<<"------------------------------0-1 Knapsack--------------------------"<<std::endl;

	KBackpackQuestions kback;
	
	int c = 10, n = 5;
	int weights[] = { 2, 2, 6, 5 ,4 };
	int values[] = { 6, 3, 5, 4, 6 };
	int puts[5];

	cout<<"Greedy method:\n    Max Value: "<<kback.BackpackQuestion(c, weights, values, puts, n, GREED)<<endl;
	for (int i = 0;i < n;i++) 
	{
		if(puts[i])
			cout << "    The " << i + 1 << " thing is selected" << endl;
		else
			cout << "    The " << i + 1 << " thing is not selected" << endl;
	}

	cout<<"Dynamic Programming method:\n    Max Value: "<<kback.BackpackQuestion(c, weights, values, puts, n)<<endl;
	for (int i = 0;i < n;i++) 
	{
		if(puts[i])
			cout << "    The " << i + 1 << " thing is selected" << endl;
		else
			cout << "    The " << i + 1 << " thing is not selected" << endl;
	}

	std::cout<<"------------------------------0-1 Knapsack--------------------------"<<std::endl;

}


int main()
{
	
	divideAndConquerTest();
	sortAlgoritmsTest();
	binarySearchTreeTest();
	redBlackTreeTest();
	taskSchedulingTest();
	knapsackTest();
	return 0;
}
