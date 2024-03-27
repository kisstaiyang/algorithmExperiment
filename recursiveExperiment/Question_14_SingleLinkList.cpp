#include <iostream>
#include "SingleLinkList.h"		// 单链表

using namespace std;



/*******************************************************************************************************************************
 * @description：对不带头结点的单链表 L，设计一个递归算法返回i第一个值为 x 的节点的地址，若不存在则返回 NULL。
 * @param：L
 * @param：x
 * @return：指针
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
	cout << "单链表中的元素为：";
	printSingleLinkList(L);

	singleLinkList p = findSingleLinkListElement(L, 'c');

	if (p) {
		cout << "找到了值为 c 的结点，地址为：" << p << endl;
	}
	else {
		cout << "未找到值为 c 的结点" << endl;
	}

	if (!findSingleLinkListElement(L, '6')) {
		cout << "未找到值为 6 的结点" << endl;
	}
}
