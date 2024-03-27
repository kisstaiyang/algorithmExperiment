#include <iostream>
#include "SingleLinkList.h"		// 单链表

using namespace std;


/*******************************************************************************************************************************
 * @description：初始化带头结点的单链表
 * @param：L		指向头结点的头指针
 * @return：状态码
 */
status initSingleLinkList(singleLinkList& L)
{
	L = new node;
	if (!L) {
		return OVERFLOW;
	}
	L->next = NULL;
	return OK;
}





/*******************************************************************************************************************************
 * @description：清空单链表
 * @param：L		指向头结点的指针
 * @return：		状态码
 */
status clearSingleLinkList(singleLinkList& L)
{
	singleLinkList p, q;
	p = L->next;
	while (p) {
		q = p->next;
		delete p;
		p = q;
	}
	// 头结点指针域置空
	L->next = NULL;
	return OK;
}





/*******************************************************************************************************************************
 * @description：在第 i 个节点前插入值为 e 的新结点
 * @param：L		头结点
 * @param：i		要插入的位置
 * @param：e		要插入的元素
 * @return：		状态码
 */
status insertSingleLinkListElement(singleLinkList& L, int i, elementType e)
{
	int count = 1;
	singleLinkList p = L;
	singleLinkList s;
	while (p && count < i) {
		p = p->next;
		count++;
	}
	// 循环结束后，p指向第i-1个结点，再次进行判断
	if (!p || count > i) {
		return ERROR;
	}
	s = new node;		// 生成新结点
	if (!s) {
		return ERROR;
	}
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}





/*******************************************************************************************************************************
 * @description：单链表的建立--头插法
 * @param：L		头指针
 * @param：n		要创建几个元素
 * @return：		状态码
 */
status createSingleLinkList_Head(singleLinkList& L, int n)
{
	singleLinkList p;
	// 初始化单链表，调用之前写的初始化函数
	if (!initSingleLinkList(L)) {
		return ERROR;
	}
	for (int i = 0; i < n; i++) {
		p = new node;
		if (!p) {
			return ERROR;
		}
		/*cin >> p->data;*/
		p->data = i + 97;	// e d c b a
		p->next = L->next;
		L->next = p;
	}
	return OK;
}





/*******************************************************************************************************************************
 * @description：单链表的建立--尾插法
 * @param：L		头指针
 * @param：n		要创建的几个元素
 * @return：		状态码
 */
status createSingleLinkList_Tail(singleLinkList& L, int n)
{
	singleLinkList p, r;
	// 初始化单链表，调用之前写的初始化函数
	if (!initSingleLinkList(L)) {
		return ERROR;
	}
	r = L;	// r始终指向尾结点，开始时指向头结点
	for (int i = 0; i < n; i++) {
		p = new node;
		if (!p) {
			return ERROR;
		}
		/*cin >> p->data;*/
		p->data = i + 97;	// a b c d e
		r->next = p;
		r = p;
	}
	r->next = NULL;
	return OK;
}





/*******************************************************************************************************************************
 * @description：打印单链表中的元素
 * @param：L		头结点
 */
void printSingleLinkList(singleLinkList L)
{
	singleLinkList p = L->next;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
