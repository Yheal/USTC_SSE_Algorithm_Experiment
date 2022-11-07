#pragma once

enum RBColor
{
	RED,
	BLACK
};

struct RBNode
{
public:
	
	RBColor color;
	int value;
	RBNode *parent, *left, *right;
	RBNode(int value);

};


class RBTree {

private:
	RBNode *root, *nil;
	bool rbTree;

public:
	RBTree();
	RBNode *insertNode(int value);
	RBNode *deleteNode(int value);
	RBNode *findNode(int value);
	RBNode *MinmuimNode(RBNode * r);
	bool checkRB();
	void printRB();
	void clearAll();

private:
	void leftRotate(RBNode *x);
	void rightRotate(RBNode *x);
	bool isANullNode(RBNode *x);
	void insertNode(RBNode *x);
	void insertNodeFixUp(RBNode *x);
	void printRB(RBNode *x);
	void RBTransplant(RBNode *u, RBNode *v);
	void deleteNode(RBNode *x);
	void deleteFixUp(RBNode *x);
	void clearNode(RBNode *x); 
	int checkFeatures4And5(RBNode *x);

};