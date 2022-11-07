#pragma once

#include <vector>

using namespace std;


struct TreeNode 
{
	TreeNode *left, *right, *parent;
	int data;

	TreeNode(int data):data(data), left(nullptr), right(nullptr), parent(nullptr) {}
};

/*
	二叉查找树
*/
class BinarySearchTree 
{

private:
	TreeNode* root;
	int pre;

public:
	BinarySearchTree();        
	void InorderTreeWalk();
	void InsertNode(int d);
	void DeleteNode(int d);
	TreeNode *FindNode(int d);
	bool IsBinarySearchTree(TreeNode *tree);  
	bool IsNullTree();
	void InsertNode(TreeNode *node);
	void DeleteNode(TreeNode *node);


private:
	void InorderTreeWalk(TreeNode *t);
	bool Check(TreeNode *tree);
	TreeNode *MaxmuimNode(TreeNode *root);
	void Transplant(TreeNode *u, TreeNode *v);
};