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