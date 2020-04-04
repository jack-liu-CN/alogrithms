#include<iostream>
#include<vector>
#include<stack>
using namespace std;

constexpr auto SPACE = ' ';

struct TreeNode
{
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;

	TreeNode(int d, TreeNode* l, TreeNode* r, TreeNode* p) :
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

	///�ݹ�-�������
	void preorder_traverse(TreeNode* tree);
	///����-�������
	void iterative_preorder_traverse(TreeNode* tree);
	///�ݹ�-�������
	void inorder_traverse(TreeNode* tree);
	///����-�������
	void iterative_inorder_traverse(TreeNode* tree);
	///�ݹ�-�������
	void postorder_traverse(TreeNode* tree);
	///����-�������
	void iterative_postorder_traverse(TreeNode* tree);
	///�ݹ�����
	TreeNode* recursive_search(TreeNode* tree, int value);
	///��������
	TreeNode* iterative_search(int value);
	///��Сֵ
	TreeNode* minimum(TreeNode* tree);
	///���ֵ
	TreeNode* maximum(TreeNode* tree);
	///�Һ��
	TreeNode* successor(TreeNode* tree);
	///��ǰ��
	TreeNode* predecessor(TreeNode* tree);
	///����
	void insert(int value);
	///ɾ��
	void remove(int value);
	///�ݻ�
	void destory();
	///��ӡ
	void print();
private:
	///���ڵ�
	TreeNode* root;
};

BST::BST(): root(nullptr){}

BST::~BST()
{
	destory();
}

void BST::preorder_traverse(TreeNode* tree)
{
	if (tree)
	{
		std::cout << tree->data << SPACE;
		preorder_traverse(tree->left);
		preorder_traverse(tree->right);
	}
}

void BST::iterative_preorder_traverse(TreeNode * tree)
{
	stack<TreeNode*>s;
	while (!s.empty() || tree != nullptr)
	{
		if (tree != nullptr)
		{
			s.push(tree);

		}
	}
}

void BST::inorder_traverse(TreeNode* tree)
{
	if (tree)
	{
		inorder_traverse(tree->left);
		std::cout << tree->data << SPACE;
		inorder_traverse(tree->right);
	}
}

void BST::iterative_inorder_traverse(TreeNode * tree)
{
	stack<TreeNode*> s;
	while (!s.empty() || tree != nullptr)
	{
		if (tree != nullptr)
		{
			s.push(tree);
			tree = tree->left;
		}
		else
		{
			cout << s.top()->data << SPACE;
			s.pop();
			tree = tree->right;
		}
	}
}

void BST::postorder_traverse(TreeNode* tree)
{
	if (tree)
	{
		postorder_traverse(tree->left);
		postorder_traverse(tree->right);
		std::cout << tree->data << SPACE;
	}
}

void BST::iterative_postorder_traverse(TreeNode * tree)
{
}

TreeNode* BST::recursive_search(TreeNode* tree, int value)
{
	if (!tree || tree->data == value)
		return tree;
	return tree->data < value
		? recursive_search(tree->left, value)
		: recursive_search(tree->right, value);
}

TreeNode* BST::iterative_search(int value)
{
	TreeNode *cur = root;

}

TreeNode* BST::minimum(TreeNode* tree)
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

TreeNode* BST::maximum(TreeNode* tree)
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

TreeNode* BST::successor(TreeNode* tree)
{
	if (!tree)
		return nullptr;
	//1.tree���������ǿ�
	if (tree->right)
	{
		return minimum(tree->right);
	}
	//2.tree��������Ϊ�գ�������tree������parent��ֱ���ҵ���parent�����ӡ�
	TreeNode* p = tree->parent;
	while (p && (tree == p->right))
	{
		tree = p;
		p = p->parent;
	}
	return p;
}

TreeNode* BST::predecessor(TreeNode* tree)
{
	if (!tree)
		return nullptr;
	//1.tree���������ǿ�
	if (tree->left)
	{
		return maximum(tree->left);
	}
	//2.tree��������Ϊ�գ�������tree������parent��ֱ���ҵ���parent���Һ��ӡ�
	TreeNode* p = tree->parent;
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
