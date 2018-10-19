//********************************************************
// 제목: 포인터와 동적할당을 사용한 링크드리스트 구현
// 기능: 연결 리스트 사용
// 파일 이름: Node.cpp
// 수정날짜 : 2018년 10월 5일
// 작성자 : 김정용
//********************************************************
#include <stdio.h>
#include <stdlib.h>

typedef struct node {

	int data;
	struct node* pNext;
} Node;

//함수 createNode
//입력 데이터
//출력 Heap에서 생성한 노드의 포인터
//부수 없음
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
	//pHead == NULL; (약속!)  이 연결리스트가 비어있다는 의미이다.
	//pNext == NULL; (약속!) 이 노드가 연결리스트의 마지막 노드라는 의미이다.
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