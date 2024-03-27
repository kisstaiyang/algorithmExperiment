#include <iostream>
#include "SingleLinkList.h"		// ������

using namespace std;


/*******************************************************************************************************************************
 * @description����ʼ����ͷ���ĵ�����
 * @param��L		ָ��ͷ����ͷָ��
 * @return��״̬��
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
 * @description����յ�����
 * @param��L		ָ��ͷ����ָ��
 * @return��		״̬��
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
	// ͷ���ָ�����ÿ�
	L->next = NULL;
	return OK;
}





/*******************************************************************************************************************************
 * @description���ڵ� i ���ڵ�ǰ����ֵΪ e ���½��
 * @param��L		ͷ���
 * @param��i		Ҫ�����λ��
 * @param��e		Ҫ�����Ԫ��
 * @return��		״̬��
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
	// ѭ��������pָ���i-1����㣬�ٴν����ж�
	if (!p || count > i) {
		return ERROR;
	}
	s = new node;		// �����½��
	if (!s) {
		return ERROR;
	}
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}





/*******************************************************************************************************************************
 * @description��������Ľ���--ͷ�巨
 * @param��L		ͷָ��
 * @param��n		Ҫ��������Ԫ��
 * @return��		״̬��
 */
status createSingleLinkList_Head(singleLinkList& L, int n)
{
	singleLinkList p;
	// ��ʼ������������֮ǰд�ĳ�ʼ������
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
 * @description��������Ľ���--β�巨
 * @param��L		ͷָ��
 * @param��n		Ҫ�����ļ���Ԫ��
 * @return��		״̬��
 */
status createSingleLinkList_Tail(singleLinkList& L, int n)
{
	singleLinkList p, r;
	// ��ʼ������������֮ǰд�ĳ�ʼ������
	if (!initSingleLinkList(L)) {
		return ERROR;
	}
	r = L;	// rʼ��ָ��β��㣬��ʼʱָ��ͷ���
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
 * @description����ӡ�������е�Ԫ��
 * @param��L		ͷ���
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
