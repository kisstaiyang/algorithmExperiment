#include <iostream>
#include "SingleLinkList.h"		// ������

using namespace std;



/*******************************************************************************************************************************
 * @description���Բ���ͷ���ĵ����� L�����һ���ݹ��㷨����i��һ��ֵΪ x �Ľڵ�ĵ�ַ�����������򷵻� NULL��
 * @param��L
 * @param��x
 * @return��ָ��
 */
singleLinkList findSingleLinkListElement(singleLinkList L, elementType x)
{
	if (!L) {
		return NULL;
	}

	if (L->data == x) {
		return L;
	}
	else {
		return findSingleLinkListElement(L->next, x);
	}
}




void question_14_main()
{
	singleLinkList L;
	initSingleLinkList(L);
	createSingleLinkList_Tail(L, 5);
	cout << "�������е�Ԫ��Ϊ��";
	printSingleLinkList(L);

	singleLinkList p = findSingleLinkListElement(L, 'c');

	if (p) {
		cout << "�ҵ���ֵΪ c �Ľ�㣬��ַΪ��" << p << endl;
	}
	else {
		cout << "δ�ҵ�ֵΪ c �Ľ��" << endl;
	}

	if (!findSingleLinkListElement(L, '6')) {
		cout << "δ�ҵ�ֵΪ 6 �Ľ��" << endl;
	}
}
