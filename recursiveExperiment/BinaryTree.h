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
		node() :left(NULL), right(NULL) {}	// �޲ι��캯��
		node(elementType value) :data(value), left(NULL), right(NULL) {}	// �вι��캯��
		~node() {}
	};
	node* root;
	void clear(node* t);								// ��ն�����
	int size(node* t)const;								// ���ض������ڵ�����						
	int height(node* t)const;							// ���ض������߶�
	int leafNum(node* t)const;							// ���ض�����Ҷ�ӽڵ����
	int leafSum(node* t)const;							// ���ض�����Ҷ�ӽڵ�ֵ֮��
	void preOrder(node* t)const;						// �������
	void inOrder(node* t)const;							// �������
	void postOrder(node* t)const;						// �������
	void preOrderCreate(elementType flag, node*& t);	// ���򴴽�������
	void printTree(const node* t, int space = 0, int width = 5)const;	// ��ӡ������


public:
	binaryTree() :root(NULL) {}									// �޲ι��캯��
	~binaryTree() { clear(); }									// ��������
	bool empty()const { return root == NULL; }					// ���У��ж϶������Ƿ�Ϊ��
	void clear() { clear(root); root = NULL; }					// ���У���ն�����
	int size()const { return size(root); }						// ���У����ض������ڵ�����
	int height()const { return height(root); }					// ���У����ض������߶�
	int leafNum()const { return leafNum(root); }				// ���У����ض�����Ҷ�ӽڵ����
	int leafSum()const { return leafSum(root); }				// ���У����ض�����Ҷ�ӽڵ�ֵ֮��
	void preOrderTraverse()const { if (root) preOrder(root); }	// ���У��������
	void inOrderTraverse()const { if (root) inOrder(root); }	// ���У��������
	void postOrderTraverse()const { if (root) postOrder(root); }// ���У��������
	void preOrderCreate(elementType flag) {						// ���У����򴴽�������
		preOrderCreate(flag, root);
	}
	void printTree()const { printTree(root); }					// ���У���ӡ������

};




/*******************************************************************************************************************************
 * @description��˽�У���ն�����
 * @param��t
 */
template <class elementType>
void binaryTree<elementType>::clear(node* t) {
	if (t == NULL) return;
	clear(t->left);
	clear(t->right);
	delete t;
}





/*******************************************************************************************************************************
 * @description��˽�У����ض������ڵ�����
 * @param��t
 * @return���ڵ�����
 */
template <class elementType>
int binaryTree<elementType>::size(node* t)const {
	if (t == NULL) return 0;
	return 1 + size(t->left) + size(t->right);
}




/*******************************************************************************************************************************
 * @description��˽�У����ض������߶�
 * @param��t
 * @return��
 */
template <class elementType>
int binaryTree<elementType>::height(node* t)const {
	if (t == NULL) return 0;
	int lt = height(t->left);
	int rt = height(t->right);
	return 1 + (lt > rt ? lt : rt);
}




/*******************************************************************************************************************************
 * @description��˽�У����ض�����Ҷ�ӽڵ����
 * @param��t
 * @return��
 */
template <class elementType>
int binaryTree<elementType>::leafNum(node* t)const {
	if (t == NULL) return 0;
	if (t->left == NULL && t->right == NULL) return 1;
	return leafNum(t->left) + leafNum(t->right);
}




/*******************************************************************************************************************************
 * @description��˽�У����ض�����Ҷ�ӽڵ�ֵ֮��
 * @param��t
 * @return��
 */
template <class elementType>
int binaryTree<elementType>::leafSum(node* t)const {
	if (t == NULL) return 0;
	if (t->left == NULL && t->right == NULL) return t->data;
	return leafSum(t->left) + leafSum(t->right);
}





/*******************************************************************************************************************************
 * @description��˽�У��������
 * @param��t
 */
template <class elementType>
void binaryTree<elementType>::preOrder(node* t)const {
	if (t == NULL) return;
	cout << t->data << " ";
	preOrder(t->left);
	preOrder(t->right);
}




/*******************************************************************************************************************************
 * @description��˽�У��������
 * @param��t
 */
template <class elementType>
void binaryTree<elementType>::inOrder(node* t)const {
	if (t == NULL) return;
	inOrder(t->left);
	cout << t->data << " ";
	inOrder(t->right);
}





/*******************************************************************************************************************************
 * @description��˽�У��������
 * @param��t
 */
template <class elementType>
void binaryTree<elementType>::postOrder(node* t)const {
	if (t == NULL) return;
	postOrder(t->left);
	postOrder(t->right);
	cout << t->data << " ";
}





/*******************************************************************************************************************************
 * @description��˽�У����򴴽�������
 * @param��flag
 * @param��t
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
 * @description��˽�У���ӡ������
 * @param��t
 * @param��space
 * @param��width
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
