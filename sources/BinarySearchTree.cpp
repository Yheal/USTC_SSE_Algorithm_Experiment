#include "BinarySearchTree.h"

#include <iostream>

BinarySearchTree::BinarySearchTree() 
{ 
	root = nullptr;
}

void BinarySearchTree::InorderTreeWalk() {
	InorderTreeWalk(root);
	cout << endl;
}

TreeNode * BinarySearchTree::FindNode(int d)
{
	TreeNode *res = root;
	
	while (res != nullptr) {
		if (res->data == d)
			break;
		else if (res->data < d)
			res = res->right;
		else
			res = res->left;
	}

	return res;
}

void BinarySearchTree::InsertNode(int d)
{
	if (FindNode(d) != nullptr) {
		std::cout << "Warning：结点不存在" << endl;
		return;
	}
	TreeNode *newNode = new TreeNode(d);
	InsertNode(newNode);
}

void BinarySearchTree::DeleteNode(int d)
{
	TreeNode *node = FindNode(d);
	if (node == nullptr) 
	{
		std::cout << "Warning����㲻����" << endl;
		return;
	}
	DeleteNode(node);

}

bool BinarySearchTree::IsBinarySearchTree(TreeNode * tree)
{
	pre = INT_MIN;
	return Check(tree);
}

bool BinarySearchTree::IsNullTree() {
	return root == nullptr;
}

void BinarySearchTree::InsertNode(TreeNode * newNode)
{
	TreeNode *parent = nullptr, *x = root;

	while (x != nullptr) {
		parent = x;
		if (x->data > newNode->data)
			x = x->left;
		else 
			x = x->right;
		
	}

	newNode->parent = parent;
	if (parent == nullptr) 
		root = newNode;
	else if(parent->data > newNode->data)
		parent->left = newNode;
	else
		parent->right = newNode;

}

void BinarySearchTree::DeleteNode(TreeNode * node)
{
	// 对于一个待删结点，如果左孩子为空，那么用右孩子替换即可。如果左孩子不为空，右孩子为空，那么使用左孩子替换
	// 如果两个孩子都不为空。我们用左子树最大的结点来替换被结点。
	if (node == nullptr)
		return;
	
	if (node->left == nullptr)
		Transplant(node, node->right);
	else if (node->right == nullptr)
		Transplant(node, node->left);
	else
	{
		TreeNode *replacementNode = MaxmuimNode(node->left);
		if (replacementNode->parent != node) {
			/* 强制保证node->left的父亲结点是replacementNode */
			Transplant(replacementNode, replacementNode->left);
			node->left->parent = replacementNode;
			replacementNode->left = node->left;
		}
		Transplant(node, replacementNode);
		replacementNode->right = node->right;
		node->right->parent = replacementNode;
	}
	delete node;
}

void BinarySearchTree::InorderTreeWalk(TreeNode *t)
{
	if (t == nullptr)
		return;
	InorderTreeWalk(t->left);
	std::cout << t->data << ' ';  
	InorderTreeWalk(t->right);
}

bool BinarySearchTree::Check(TreeNode * root)
{
	if (root == nullptr)
		return true;

	if(!Check(root->left))
		return false;

	if (root->data < pre)
		return false;

	pre = root->data;

	return Check(root->right);
}

TreeNode * BinarySearchTree::MaxmuimNode(TreeNode * root)
{
	// 最大结点一定没有右子树
	if (root == nullptr)
		return nullptr;

	TreeNode *res = root;
	while (res->right != nullptr)
		res = res->right;
	return res;
}

void BinarySearchTree::Transplant(TreeNode *u, TreeNode * v)
{
	// 把v子树移植到u子树的父亲结点上。
	if (u == nullptr)
	{
		std::cout <<"error u不能为空"<< endl;
		return;
	}

	if (u->parent == nullptr)
		root = v;
	else if (u->parent->left == u)
		u->parent->left = v;
	else
		u->parent->right = v;

	if (v != nullptr)
		v->parent = u->parent;
}

