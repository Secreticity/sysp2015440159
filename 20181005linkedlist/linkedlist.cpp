//********************************************************
// ����: �����Ϳ� �����Ҵ��� ����� ��ũ�帮��Ʈ ����
// ���: ���� ����Ʈ ���
// ���� �̸�: Node.cpp
// ������¥ : 2018�� 10�� 5��
// �ۼ��� : ������
//********************************************************
#include <stdio.h>
#include <stdlib.h>

typedef struct node {

	int data;
	struct node* pNext;
} Node;

//�Լ� createNode
//�Է� ������
//��� Heap���� ������ ����� ������
//�μ� ����
Node* createNode(int val) {

	Node* ptr = (Node*)malloc(sizeof(Node));
	ptr->data = val;
	ptr->pNext = NULL;
	return ptr;
}

void printNode(Node* body) {

	Node* ptr = body;
	printf("\n------ printNode ------\n");
	while (ptr != NULL) {
		printf("%d\n", ptr->data);
		ptr = ptr->pNext;
	}
	printf("-----------------------\n");
}
void addNode(Node* body, int val) {
	Node* next = (Node*)malloc(sizeof(Node));
	Node* ptr = body;

	while (ptr->pNext != NULL) {
		ptr = ptr->pNext;
	}
	ptr->pNext = next;
	next->data = val;
	next->pNext = NULL;
}

void insertHead(Node** ppHead, Node* pNewHead) {

	if (*ppHead == NULL) {
		*ppHead = pNewHead;
		return;
	}
	pNewHead->pNext = *ppHead;
	*ppHead = pNewHead;
}

void deleteHead(Node** pHead) {

	*pHead = (*pHead)->pNext;
}
void deleteTail(Node* body) {
	Node* ptr = body;
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

	Node *head1, *head2, *pHead;
	//pHead == NULL; (���!)  �� ���Ḯ��Ʈ�� ����ִٴ� �ǹ��̴�.
	//pNext == NULL; (���!) �� ��尡 ���Ḯ��Ʈ�� ������ ����� �ǹ��̴�.
	head1 = createNode(10);
	head2 = createNode(20);
	head1->pNext = head2;
	pHead = head1;

	insertHead(&pHead, createNode(50));

	addNode(pHead, 10);
	printNode(pHead);
	
	deleteTail(pHead);
	printNode(pHead);

	deleteHead(&pHead);
	printNode(pHead);

	return 0;
}