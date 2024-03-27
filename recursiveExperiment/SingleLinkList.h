#pragma once

#ifndef SINGLELINKLIST__H
#define SINGLELINKLIST__H

#include "StatusCode.h"		// 状态码


typedef struct Node {
	char data;				// 结点的数据域
	struct Node* next;		// 结点的指针域

}node, * singleLinkList;	// node: 结点类型, singleLinkList: 结点指针类型



/*************************************函数声明*************************************/

// 初始化单链表
status initSingleLinkList(singleLinkList& L);

// 清空单链表
status clearSingleLinkList(singleLinkList& L);

// 在第 i 个结点前插入值为e的新结点
status insertSingleLinkListElement(singleLinkList& L, int i, elementType e);

// 单链表的建立--头插法
status createSingleLinkList_Head(singleLinkList& L, int n);

// 单链表的建立--尾插法
status createSingleLinkList_Tail(singleLinkList& L, int n);

// 打印单链表中的元素
void printSingleLinkList(singleLinkList L);

#endif // !SINGLELINKLIST__H
