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

	while (ptr != NULL) {
		printf("%d\n", ptr->data);
		ptr = ptr->pNext;
	}
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

void deleteTail(Node* body) {
	Node* ptr = body;
	while (ptr->pNext != NULL) {
		ptr = ptr->pNext;
	}

}
int main() {

	Node *head1, *head2, *pHead;
	head1 = createNode(10);
	head2 = createNode(20);
	head1->pNext = head2;
	pHead = head1;

	addNode(pHead, 10);
	printNode(pHead);

	return 0;
}