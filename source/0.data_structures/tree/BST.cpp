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
����������(binary search tree)
*/
class BST
{
public:
	BST();
	~BST();

	/*�������*/
	void preorder_traverse(BSTNode* tree);
	/*�������*/
	void inorder_traverse(BSTNode* tree);
	/*�������*/
	void postorder_traverse(BSTNode* tree);
	/*�ݹ�����*/
	BSTNode* recursive_search(BSTNode* tree, int value);
	/*��������*/
	BSTNode* iterative_search(int value);
	/*��Сֵ*/
	BSTNode* minimum(BSTNode* tree);
	/*���ֵ*/
	BSTNode* maximum(BSTNode* tree);
	/*�Һ��*/
	BSTNode* successor(BSTNode* tree);
	/*��ǰ��*/
	BSTNode* predecessor(BSTNode* tree);
	/*����*/
	void insert(int value);
	/*ɾ��*/
	void remove(int value);
	/*�ݻ�*/
	void destory();
	/*��ӡ*/
	void print();
private:
	/*���ڵ�*/
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
	//1.tree���������ǿ�
	if (tree->right)
	{
		return minimum(tree->right);
	}
	//2.tree��������Ϊ�գ�������tree������parent��ֱ���ҵ���parent�����ӡ�
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
	//1.tree���������ǿ�
	if (tree->left)
	{
		return maximum(tree->left);
	}
	//2.tree��������Ϊ�գ�������tree������parent��ֱ���ҵ���parent���Һ��ӡ�
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
