#pragma once

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


template <class elementType>
class binaryTree
{
private:
	struct node {
		elementType data;
		node* left;
		node* right;
		node() :left(NULL), right(NULL) {}	// 无参构造函数
		node(elementType value) :data(value), left(NULL), right(NULL) {}	// 有参构造函数
		~node() {}
	};
	node* root;
	void clear(node* t);								// 清空二叉树
	int size(node* t)const;								// 返回二叉树节点总数						
	int height(node* t)const;							// 返回二叉树高度
	int leafNum(node* t)const;							// 返回二叉树叶子节点个数
	int leafSum(node* t)const;							// 返回二叉树叶子节点值之和
	void preOrder(node* t)const;						// 先序遍历
	void inOrder(node* t)const;							// 中序遍历
	void postOrder(node* t)const;						// 后序遍历
	void preOrderCreate(elementType flag, node*& t);	// 先序创建二叉树
	void printTree(const node* t, int space = 0, int width = 5)const;	// 打印二叉树


public:
	binaryTree() :root(NULL) {}									// 无参构造函数
	~binaryTree() { clear(); }									// 析构函数
	bool empty()const { return root == NULL; }					// 公有，判断二叉树是否为空
	void clear() { clear(root); root = NULL; }					// 公有，清空二叉树
	int size()const { return size(root); }						// 公有，返回二叉树节点总数
	int height()const { return height(root); }					// 公有，返回二叉树高度
	int leafNum()const { return leafNum(root); }				// 公有，返回二叉树叶子节点个数
	int leafSum()const { return leafSum(root); }				// 公有，返回二叉树叶子节点值之和
	void preOrderTraverse()const { if (root) preOrder(root); }	// 公有，先序遍历
	void inOrderTraverse()const { if (root) inOrder(root); }	// 公有，中序遍历
	void postOrderTraverse()const { if (root) postOrder(root); }// 公有，后序遍历
	void preOrderCreate(elementType flag) {						// 公有，先序创建二叉树
		preOrderCreate(flag, root);
	}
	void printTree()const { printTree(root); }					// 公有，打印二叉树

};




/*******************************************************************************************************************************
 * @description：私有，清空二叉树
 * @param：t
 */
template <class elementType>
void binaryTree<elementType>::clear(node* t) {
	if (t == NULL) return;
	clear(t->left);
	clear(t->right);
	delete t;
}





/*******************************************************************************************************************************
 * @description：私有，返回二叉树节点总数
 * @param：t
 * @return：节点总数
 */
template <class elementType>
int binaryTree<elementType>::size(node* t)const {
	if (t == NULL) return 0;
	return 1 + size(t->left) + size(t->right);
}




/*******************************************************************************************************************************
 * @description：私有，返回二叉树高度
 * @param：t
 * @return：
 */
template <class elementType>
int binaryTree<elementType>::height(node* t)const {
	if (t == NULL) return 0;
	int lt = height(t->left);
	int rt = height(t->right);
	return 1 + (lt > rt ? lt : rt);
}




/*******************************************************************************************************************************
 * @description：私有，返回二叉树叶子节点个数
 * @param：t
 * @return：
 */
template <class elementType>
int binaryTree<elementType>::leafNum(node* t)const {
	if (t == NULL) return 0;
	if (t->left == NULL && t->right == NULL) return 1;
	return leafNum(t->left) + leafNum(t->right);
}




/*******************************************************************************************************************************
 * @description：私有，返回二叉树叶子节点值之和
 * @param：t
 * @return：
 */
template <class elementType>
int binaryTree<elementType>::leafSum(node* t)const {
	if (t == NULL) return 0;
	if (t->left == NULL && t->right == NULL) return t->data;
	return leafSum(t->left) + leafSum(t->right);
}





/*******************************************************************************************************************************
 * @description：私有，先序遍历
 * @param：t
 */
template <class elementType>
void binaryTree<elementType>::preOrder(node* t)const {
	if (t == NULL) return;
	cout << t->data << " ";
	preOrder(t->left);
	preOrder(t->right);
}




/*******************************************************************************************************************************
 * @description：私有，中序遍历
 * @param：t
 */
template <class elementType>
void binaryTree<elementType>::inOrder(node* t)const {
	if (t == NULL) return;
	inOrder(t->left);
	cout << t->data << " ";
	inOrder(t->right);
}





/*******************************************************************************************************************************
 * @description：私有，后序遍历
 * @param：t
 */
template <class elementType>
void binaryTree<elementType>::postOrder(node* t)const {
	if (t == NULL) return;
	postOrder(t->left);
	postOrder(t->right);
	cout << t->data << " ";
}





/*******************************************************************************************************************************
 * @description：私有，先序创建二叉树
 * @param：flag
 * @param：t
 */
template <class elementType>
void binaryTree<elementType>::preOrderCreate(elementType flag, node*& t) {
	elementType data;
	cin >> data;
	if (data == flag) t = NULL;
	else {
		t = new node(data);
		preOrderCreate(flag, t->left);
		preOrderCreate(flag, t->right);
	}
}




/*******************************************************************************************************************************
 * @description：私有，打印二叉树
 * @param：t
 * @param：space
 * @param：width
 */
template <class elementType>
void binaryTree<elementType>::printTree(const node* t, int space, int width)const {
	if (t == NULL) {
		return;
	}

	space += width;
	printTree(t->right, space);
	cout << setw(space) << t->data << endl;
	for (int i = 0; i < width; i++) {
		cout << " ";
	}
	cout << endl;

	printTree(t->left, space);

}


#endif // !BINARYTREE_H
