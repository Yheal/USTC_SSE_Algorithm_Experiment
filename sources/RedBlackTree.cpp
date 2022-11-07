#include <iostream>

#include "RedBlackTree.h"



RBNode::RBNode(int value)
{
	this->value = value;
	this->color = RED;
	this->parent = this->left = this->right = nullptr;
}

RBTree::RBTree()
{
	this->nil = new RBNode(-1);
	this->nil->color = BLACK;
	this->root = nil;
	this->root->parent = nil;
}

RBNode * RBTree::insertNode(int value)
{
	RBNode * newNode = findNode(value);
	if (newNode != nil)
	{
		std::cout << "树中已有结点" << std::endl;
		return newNode;
	}
	
	newNode = new RBNode(value);
	insertNode(newNode);
	return newNode;
}

RBNode * RBTree::deleteNode(int value)
{
	RBNode *x = findNode(value);
	if (x == nil)
		std::cout << "树中无结点" << std::endl;
	else
		deleteNode(x);
	return x;
}

RBNode * RBTree::findNode(int value)
{
	RBNode *res = root;

	while (res != nil) {
		if (res->value == value)
			break;
		else if (res->value < value)
			res = res->right;
		else
			res = res->left;
	}

	return res;
}

RBNode * RBTree::MinmuimNode(RBNode * r)
{
	// 最小结点一定没有左子树
	if (r == nil)
		return r;
	RBNode *res = r;
	while (res->left != nil)
		res = res->left;
	return res;
}

bool RBTree::checkRB()
{

	rbTree = true;    // 是不是一个红黑树
	if (root->color == RED)
		rbTree = false;

	if (rbTree) 
		checkFeatures4And5(root);

	if(!rbTree)
		std::cout << "not a red black tree!" << std::endl;
	else
		std::cout << "a red black tree!" << std::endl;

	return rbTree;
}

void RBTree::printRB() { printRB(root);}

void RBTree::leftRotate(RBNode * x)
{
	RBNode *y = (x == nullptr ? nullptr : x->right);

	if (isANullNode(x) || isANullNode(y))
	{
		std::cout << "ERROR 无法进行旋转" << std::endl;
		return;
	}
		
	// 旋转过后：
	// xleft值不变；
	// x.right变为y.left，因此y.left的parent变了
	// 上面完成后，y->left变成x。

	x->right = y->left;
	if (x->right != this->nil && x->right != nullptr)
		x->right->parent = x;
	y->left = x;

		// 再修改x->parent为y，我们得先修改x->parent孩子指向
	y->parent = x->parent;
	
	if (x->parent == this->nil)
		this->root = y;
	else if (x->parent->left == x)
		x->parent->left = y;
	else
		x->parent->right = y;
	x->parent = y;

		// 如果x为root结点，那么把y设置root结点。
	// 如果x不是root，那么x.parent变成了y，同时x.parent指向x的孩子指针变了指向y
	// y的left变为了x，y的父结点变成了x的父结点。 x的父结点为y。

}

void RBTree::rightRotate(RBNode * x)
{
	RBNode *y = (x == nullptr ? nullptr : x->left);

	if (isANullNode(x) || isANullNode(y))
	{
		std::cout << "ERROR 无法进行旋转" << std::endl;
		return;
	}

	x->left = y->right;
	if (x->left != this->nil && x->left != nullptr)
		x->left->parent = x;
	y->right = x;

	// 再修改x->parent为y，我们得先修改x->parent孩子指向
	y->parent = x->parent;

	if (x->parent == this->nil)
		this->root = y;
	else if (x->parent->left == x)
		x->parent->left = y;
	else
		x->parent->right = y;
	x->parent = y;                 // 修改x的指向
}

bool RBTree::isANullNode(RBNode * x)
{
	if (x == nullptr || x == this->nil)
		return true;
	return false;
}

void RBTree::insertNode(RBNode * x)
{
	// 还是先找其父结点
	RBNode* y = nil, *t = root;

	while (t != nil) {
		y = t;
		if (t->value < x->value)
			t = t->right;
		else
			t = t->left;
	}

	x->parent = y;
	if (y == nil)
		root = x;
	else if (y->value > x->value)
		y->left = x;
	else
		y->right = x;

	x->color = RED;
	x->left = x->right = nil;

	/*
		x为红色而不是黑色。理由有几点（可能会有其他的）：
			1、我们希望红黑树的结点有红有黑，不然为啥叫红黑树
			2、修复性质4或者性质2比性质5要简单。插入后，因为新结点x为红色，那么违反的性质只可能是4. 即可能x的父节点和x都是红色的
			...
	 */
	insertNodeFixUp(x);
}

void RBTree::insertNodeFixUp(RBNode * x)
{
	/* 
		下列循环开始时，每次会保证一个不变式：除了性质4和2可能被破坏外，其余性质均没有被破坏
		我们的目标是把红色向上传递，直到根或者x的父节点为黑色, 不去管深度比x还大的子树。

		具体证明: 暂无
	*/

	while (x->parent->color == RED) 
	{
		// 当 x->parent是 x->parent->parent的左子树
		if (x->parent == x->parent->parent->left)
		{
			RBNode *uncle = x->parent->parent->right;
			if (uncle->color == RED) 
			{    
				// case 1 和 case2 
				x->parent->color = BLACK;
				uncle->color = BLACK;
				x->parent->parent->color = RED;
				x = x->parent->parent;
			}else if(x == x->parent->right) 
			{
				// case4
				leftRotate(x->parent);
				x = x->left;
			}
			else 
			{   
				// case 3
				x->parent->color = BLACK;
				x->parent->parent->color = RED;
				rightRotate(x->parent->parent);
			}

		}
		else 
		{
			RBNode *uncle = x->parent->parent->left;
			if (uncle->color == RED)
			{
				// case 1 和 case2 
				x->parent->color = BLACK;
				uncle->color = BLACK;
				x->parent->parent->color = RED;
				x = x->parent->parent;
			}
			else if (x == x->parent->left)
			{
				// case4
				rightRotate(x->parent);
				x = x->right;
			}
			else
			{
				// case 3
				x->parent->color = BLACK;
				x->parent->parent->color = RED;
				leftRotate(x->parent->parent);
			}
		}
	}

	root->color = BLACK;
}

void RBTree::printRB(RBNode * x)
{
	if (x == nil)
		return;
	printRB(x->left);
	if (x->color == RED)
		std::cout << "Red     ";
	else
		std::cout << "black   ";
	std::cout << x->value <<"Left child is "<<x->left->value<< 
		" ,Right child is "<<x->right->value<<" ,Parent is "<<x->parent->value<<std::endl;

	printRB(x->right);
}

void RBTree::RBTransplant(RBNode * u, RBNode * v)
{
	// 移植v到u
	if (u == root)
		root = v;
	else if (u->parent->left == u)
		u->parent->left = v;
	else
		u->parent->right = v;
	v->parent = u->parent;
}

void RBTree::deleteNode(RBNode * z)
{
	RBNode *colordeletedNode = z, *colorMixedNode = nullptr;
	RBColor deleted_color = z->color;

	if (z->left == nil) 
	{
		colorMixedNode = z->right;
		RBTransplant(z, z->right);
	}
	else if (z->right == nil) {
		colorMixedNode = z->left;
		RBTransplant(z, z->left);
	}
	else 
	{
		colordeletedNode = MinmuimNode(z->right);   // 一定没有左子树
		deleted_color = colordeletedNode->color;
		colorMixedNode = colordeletedNode->right;

		if (colordeletedNode->parent == z)
			colorMixedNode->parent = colordeletedNode;
		else {
			RBTransplant(colordeletedNode, colordeletedNode->right);
			colordeletedNode->right = z->right;
			z->right->parent = colordeletedNode;
		}

		RBTransplant(z, colordeletedNode);
		colordeletedNode->left = z->left;
		z->left->parent = colordeletedNode;
		colordeletedNode->color = z->color;

	}

	if (deleted_color == BLACK) {
		deleteFixUp(colorMixedNode);
	}
}


void RBTree::deleteFixUp(RBNode * blackMixedNode)
{
	// 混合一道黑色的结点
	while (blackMixedNode != root && blackMixedNode->color == BLACK) 
	{
		RBNode *parent = blackMixedNode->parent;

		if (parent->left == blackMixedNode) 
		{
			RBNode *brother = parent->right;

			if (brother->color == RED) 
			{
				parent->color = RED;
				brother->color = BLACK;
				leftRotate(parent);
				continue;
			}

			RBNode *leftNephew = brother->left;
			RBNode *rightNephew = brother->right;

			if (leftNephew->color == BLACK && rightNephew->color == BLACK)   // case 2
			{
				brother->color = RED;
				blackMixedNode = parent;
			}
			else if (rightNephew->color == BLACK)                           // case 3
			{
					leftNephew->color = BLACK;
					brother->color = RED;
					rightRotate(brother);
			}
			else                                                            // case 4
			{
				brother->color = parent->color;
				rightNephew->color = BLACK;
				parent->color = BLACK;
				leftRotate(parent);
				blackMixedNode = root;
			}
		}
		else
		{
			RBNode *brother = parent->left;
			if (brother->color == RED)
			{
				parent->color = RED;
				brother->color = BLACK;
				rightRotate(parent);
				continue;
			}

			RBNode *leftNephew = brother->left;
			RBNode *rightNephew = brother->right;
			
			if (leftNephew->color == BLACK && rightNephew->color == BLACK)   // case 2
			{
				brother->color = RED;
				blackMixedNode = parent;
			}
			else if (leftNephew->color == BLACK)                            // case 3
			{
				rightNephew->color = BLACK;
				brother->color = RED;
				leftRotate(brother);
			}
			else                                                           // case 4
			{
				brother->color = parent->color;
				leftNephew->color = BLACK;
				parent->color = BLACK;
				rightRotate(parent);
				blackMixedNode = root;
			}
		}
	}

	blackMixedNode->color = BLACK;
}


// 返回x为结点的黑高（包括x）
int RBTree::checkFeatures4And5(RBNode * x)
{
	// 按照递归的方式检查性质4和性质5有没有被违反，性质2和性质3不需要检查
	// 如果是叶子结点，那么返回1
	// 如果是红色结点，那么检查两个子树
	// 在左孩子和右孩子上递归调用checkFeatures（），对比黑高是否相等
	
	if(x == nil)
		return 1;
	
	if (x->color == RED && rbTree) 
	{
		if(x->left->color != BLACK || x->right->color != BLACK)
			rbTree = false;
	}

	if (!rbTree)
		return -1;
	
	int leftBH = checkFeatures4And5(x->left);
	int rightBH = checkFeatures4And5(x->right);
	
	if (leftBH != rightBH)
	{
		rbTree = false;
		return -1;
	}
	
	return leftBH + (x->color == BLACK ?1 : 0);
}
