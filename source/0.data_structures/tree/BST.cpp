#include<iostream>

using namespace std;

constexpr auto SPACE = ' ';

struct BSTNode
{
	int data;
	BSTNode* left;
	BSTNode* right;
	BSTNode* parent;

	BSTNode(int d, BSTNode* l, BSTNode* r, BSTNode* p) :
		data(d), left(l), right(r), parent(p) {}
};

/*
二叉搜索树(binary search tree)
*/
class BST
{
public:
	BST();
	~BST();

	/*先序遍历*/
	void preorder_traverse(BSTNode* tree);
	/*中序遍历*/
	void inorder_traverse(BSTNode* tree);
	/*后序遍历*/
	void postorder_traverse(BSTNode* tree);
	/*递归搜索*/
	BSTNode* recursive_search(BSTNode* tree, int value);
	/*迭代搜索*/
	BSTNode* iterative_search(int value);
	/*最小值*/
	BSTNode* minimum(BSTNode* tree);
	/*最大值*/
	BSTNode* maximum(BSTNode* tree);
	/*找后继*/
	BSTNode* successor(BSTNode* tree);
	/*找前驱*/
	BSTNode* predecessor(BSTNode* tree);
	/*插入*/
	void insert(int value);
	/*删除*/
	void remove(int value);
	/*摧毁*/
	void destory();
	/*打印*/
	void print();
private:
	/*根节点*/
	BSTNode* root;
};

BST::BST(): root(nullptr){}

BST::~BST()
{
	destory();
}

void BST::preorder_traverse(BSTNode* tree)
{
	if (tree)
	{
		cout << tree->data << SPACE;
		preorder_traverse(tree->left);
		preorder_traverse(tree->right);
	}
}

void BST::inorder_traverse(BSTNode* tree)
{
	if (tree)
	{
		inorder_traverse(tree->left);
		cout << tree->data << SPACE;
		inorder_traverse(tree->right);
	}
}

void BST::postorder_traverse(BSTNode* tree)
{
	if (tree)
	{
		postorder_traverse(tree->left);
		postorder_traverse(tree->right);
		cout << tree->data << SPACE;
	}
}

BSTNode* BST::recursive_search(BSTNode* tree, int value)
{
	if (!tree || tree->data == value)
		return tree;
	return tree->data < value
		? recursive_search(tree->left, value)
		: recursive_search(tree->right, value);
}

//TO-DO
BSTNode* BST::iterative_search(int value)
{
	return nullptr;
}

BSTNode* BST::minimum(BSTNode* tree)
{
	if (!tree)
	{
		return tree;
	}
	while (tree->left)
	{
		tree = tree->left;
	}
	return tree;
}

BSTNode* BST::maximum(BSTNode* tree)
{
	if (!tree)
	{
		return tree;
	}
	while (tree->right)
	{
		tree = tree->right;
	}
	return tree;
}

BSTNode* BST::successor(BSTNode* tree)
{
	if (!tree)
		return nullptr;
	//1.tree的右子树非空
	if (tree->right)
	{
		return minimum(tree->right);
	}
	//2.tree的右子树为空，则沿着tree向上找parent，直到找到该parent有左孩子。
	BSTNode* p = tree->parent;
	while (p && (tree == p->right))
	{
		tree = p;
		p = p->parent;
	}
	return p;
}

BSTNode* BST::predecessor(BSTNode* tree)
{
	if (!tree)
		return nullptr;
	//1.tree的左子树非空
	if (tree->left)
	{
		return maximum(tree->left);
	}
	//2.tree的左子树为空，则沿着tree向上找parent，直到找到该parent有右孩子。
	BSTNode* p = tree->parent;
	while (p && (tree == p->left))
	{
		tree = p;
		p = p->parent;
	}
	return p;
}

void BST::insert(int value)
{
}

void BST::remove(int value)
{
}

void BST::destory()
{
}

void BST::print()
{
}
