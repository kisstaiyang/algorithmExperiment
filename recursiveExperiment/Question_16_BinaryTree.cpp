// 求二叉树所有叶子节点值之和

#include <iostream>
#include "BinaryTree.h"

using namespace std;


void question_16_main()
{
	binaryTree<int> bt;
	bt.preOrderCreate(0); // 以先序序列创建二叉树，0表示空节点
	cout << "二叉树的结构如下：" << endl;
	bt.printTree();
	cout << "二叉树叶子节点值之和为：" << bt.leafSum() << endl;
}
