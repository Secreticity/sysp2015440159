//********************************************************
// ����: �����Ϳ� �����Ҵ��� ����� ��ũ�帮��Ʈ ����
// ���: ���� ����Ʈ ���
// ���� �̸�: Node.cpp
// ������¥ : 2018�� 10�� 5��
// �ۼ��� : ������
//********************************************************

#define WIN32_LEAN_AND_MEAN				//from thread.cpp
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

DWORD WINAPI ThreadFunc(LPVOID);		//from thread.cpp

typedef struct node {

	int data;
	struct node* pNext;
} Node;

typedef struct llist {

	Node* pHead;
	CRITICAL_SECTION critical_sec;
} LList;

typedef struct input {

	LList* pLList;
	int threadNum;
} Input;

//�Լ� createNode
//�Է� ������
//��� Heap���� ������ ����� ������, ����� data�� �Է°�����, pNext�� NULL�� ����
//�μ� ����
Node* createNode(int val) {

	Node* ptr = (Node*)malloc(sizeof(Node));
	ptr->data = val;
	ptr->pNext = NULL;
	return ptr;
}

//�Լ� createLList
//�Է� ������
//��� Heap���� ������ LList�� ������
//�μ� ����
LList* createLList(Node* pHead) {

	LList* ptr = (LList*)malloc(sizeof(LList));
	ptr->pHead = pHead;
	InitializeCriticalSection(&(ptr->critical_sec));

	return ptr;
}

//�Լ� printLL
//�Է� linked list�� ��� ������
//��� ����
//�μ� ȭ�鿡 �� ��� �����͸� ���
void printLL(LList* pLList) {

	Node* ptr = pLList->pHead;
	printf("\n------ printNode ------\n");
	while (ptr != NULL) {
		printf("%d\n", ptr->data);
		ptr = ptr->pNext;
	}
	printf("-----------------------\n");
}

//�Լ� numNode
//�Է� linked list�� ����ü������
//��� linked list�� ��� ����
//�μ� ����
int numNode(LList* pLList) {

	Node* ptr = pLList->pHead;
	int num = 0;

	while (ptr != NULL) {
		
		num++;
		ptr = ptr->pNext;
	}
	return num;
}

void addNode(LList* pLList, int val) {
	Node* next = (Node*)malloc(sizeof(Node));
	Node* ptr = pLList->pHead;

	while (ptr->pNext != NULL) {
		ptr = ptr->pNext;
	}
	ptr->pNext = next;
	next->data = val;
	next->pNext = NULL;
}

//�Լ� insertHead
//�Է� linked list�� ��� ������, �� ����� ������
//��� ����
//�μ� ���Ḯ��Ʈ�� ��尡 �� ���� �����
void insertHead(LList* pLList, Node* pNewHead) {
	EnterCriticalSection(&(pLList->critical_sec));  // "�ٸ�" thread �� flag ������ ���� ���� �� ������ �����Ѵ�. ��, EnterCriticalSection �� ������ ����Ǿ ���� thread �������� flag�� ������� �� �� �ִ�.
	if (pLList->pHead == NULL) {
		pLList->pHead = pNewHead;
		return;
	}
	pNewHead->pNext = pLList->pHead;
	pLList->pHead = pNewHead;
	LeaveCriticalSection(&(pLList->critical_sec));
}

void deleteHead(LList* pLList) {

	pLList->pHead = (pLList->pHead)->pNext;
}
void deleteTail(LList* pLList) {
	Node* ptr = pLList->pHead;
	if (ptr->pNext == NULL) {
		ptr = NULL;
	}
	while (ptr->pNext->pNext != NULL) {
		ptr = ptr->pNext;
	}
	free(ptr->pNext);
	ptr->pNext = NULL;
}
int main() {

	//LList myLList;
	LList* pLList = createLList(createNode(1));
	//Node *head1, *head2, *pHead;
	HANDLE hThrd[5];
	DWORD threadId;
	Input inputPod;
	input* pInput = &inputPod;
	CRITICAL_SECTION criticalSection;
	int i;

	//pHead == NULL; (���!)  �� ���Ḯ��Ʈ�� ����ִٴ� �ǹ��̴�.
	//pNext == NULL; (���!) �� ��尡 ���Ḯ��Ʈ�� ������ ����� �ǹ��̴�.
	//head1 = createNode(10);
	//head2 = createNode(20);
	//head1->pNext = head2;
	//myLList.pHead = createNode(100);

	//insertHead(pLList, createNode(30));

	//addNode(pLList, 40);
	//printLL(pLList);
	//printf("Number of nodes = s%d\n", numNode(pLList));

	//deleteTail(pLList);
	//printLL(pLList);

	//deleteHead(pLList);
	//printLL(pLList);

	//return 0;


	for (i = 0; i<5; i++)
	{
		pInput->pLList = pLList;
		pInput->threadNum = i;
		hThrd[i] = CreateThread(NULL, 0, ThreadFunc, (LPVOID) pInput, 0, &threadId);
	}

	if (hThrd)
	{
		printf("Thread launched %d\n", i);
		CloseHandle(hThrd);
	}
	Sleep(2000);
	DWORD result;

	result = WaitForMultipleObjects(5, hThrd, TRUE, INFINITE);
	printf("Total Created Node Number = %d\n", numNode(pInput->pLList));

	return EXIT_SUCCESS;
}

DWORD WINAPI ThreadFunc(LPVOID pInput)
{
	input* inputPod = (input*)pInput;
	int i;

	for (i = 0; i < 10000; i++)
		insertHead(inputPod->pLList, createNode(inputPod->threadNum));  //�� ������ critical section - �Ӱ迵�� : �����ϸ� �ȵ�
	return 0;
}