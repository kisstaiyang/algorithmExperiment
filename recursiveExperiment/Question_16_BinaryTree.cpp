// �����������Ҷ�ӽڵ�ֵ֮��

#include <iostream>
#include "BinaryTree.h"

using namespace std;


void question_16_main()
{
	binaryTree<int> bt;
	bt.preOrderCreate(0); // ���������д�����������0��ʾ�սڵ�
	cout << "�������Ľṹ���£�" << endl;
	bt.printTree();
	cout << "������Ҷ�ӽڵ�ֵ֮��Ϊ��" << bt.leafSum() << endl;
}
