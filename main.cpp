#include <iostream>

#include "DivideAndConquerSolution.h"
#include "SortAlgorithmSolution.h"
#include "KBackpackQuestions.h"
#include "TaskSchedulingSolution.h"
#include "BinarySearchTree.h"
#include "RedBlackTree.h"

int main()
{
	/*
	DivideAndConquerSolution solution;
	vector<int> test;
	test.push_back(-2);
	test.push_back(-2);
	test.push_back(-2);
	test.push_back(-2);
	test.push_back(-2);
	test.push_back(-2);
	std::cout << "result: " << solution.MaximumSubarray(test) << endl;
	*/
	
	/*
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
	*/

	/*
	vector<int> test;
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
	SortAlgorithmSolution sortAlgorithmSolution;
	sortAlgorithmSolution.CountSort(test);
	for (int i : test)
		cout << i << " ";
	cout << endl;
	*/

	KBackpackQuestions kback;
	
	int c = 10, n = 5;
	int weights[] = { 2, 2, 6, 5 ,4 };
	int values[] = { 6, 3, 5, 4, 6 };
	int puts[5];

	cout<<"Max Value: "<<kback.BackpackQuestion(c, weights, values, puts, n, GREED)<<endl;
	for (int i = 0;i < n;i++) 
	{
		if(puts[i])
			cout << "The " << i + 1 << " thing is selected" << endl;
		else
			cout << "The " << i + 1 << " thing is not selected" << endl;
	}

	TaskSchedulingSolution tss;
	int d[7] = { 4, 2, 4 ,3, 1, 4, 6 };
	int w[7] = { 70, 60, 50, 40, 30, 20, 10 };
	int result[7];
	int k = 7;
	cout << "\nThe penalty value is " << tss.taskSchedule(d, w, result, k) << endl;
	cout << "The scheduling sequence is ";
	for (int i = 0;i < k;i++) 
		cout << " a" << result[i] + 1;
	cout << '\n'<< endl;

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
		cout << "\nbinary search tree!" << endl;
	else
		cout << "\nnot binary search tree!" << endl;


	cout<<"\nRed Black Test:"<<endl;
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
	
	rbTree.deleteNode(14);
	rbTree.deleteNode(9);
	rbTree.deleteNode(5);
	rbTree.deleteNode(8);

	
	/*
	rbTree.insertNode(41);
	rbTree.insertNode(38);
	rbTree.insertNode(31);
	rbTree.insertNode(12);
	rbTree.insertNode(19);
	rbTree.insertNode(8);

	rbTree.deleteNode(41);
	rbTree.deleteNode(19);
	*/
	rbTree.checkRB();
	rbTree.printRB();
	return 0;
}
