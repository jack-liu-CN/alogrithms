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
二叉搜索树(binary search tree)
*/
class BST
{
public:
	BST();
	~BST();

	///递归-先序遍历
	void preorder_traverse(TreeNode* tree);
	///迭代-先序遍历
	void iterative_preorder_traverse(TreeNode* tree);
	///递归-中序遍历
	void inorder_traverse(TreeNode* tree);
	///迭代-中序遍历
	void iterative_inorder_traverse(TreeNode* tree);
	///递归-后序遍历
	void postorder_traverse(TreeNode* tree);
	///迭代-后序遍历
	void iterative_postorder_traverse(TreeNode* tree);
	///递归搜索
	TreeNode* recursive_search(TreeNode* tree, int value);
	///迭代搜索
	TreeNode* iterative_search(int value);
	///最小值
	TreeNode* minimum(TreeNode* tree);
	///最大值
	TreeNode* maximum(TreeNode* tree);
	///找后继
	TreeNode* successor(TreeNode* tree);
	///找前驱
	TreeNode* predecessor(TreeNode* tree);
	///插入
	void insert(int value);
	///删除
	void remove(int value);
	///摧毁
	void destory();
	///打印
	void print();
private:
	///根节点
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
	//1.tree的右子树非空
	if (tree->right)
	{
		return minimum(tree->right);
	}
	//2.tree的右子树为空，则沿着tree向上找parent，直到找到该parent有左孩子。
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
	//1.tree的左子树非空
	if (tree->left)
	{
		return maximum(tree->left);
	}
	//2.tree的左子树为空，则沿着tree向上找parent，直到找到该parent有右孩子。
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
