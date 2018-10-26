//********************************************************
// 제목: 포인터와 동적할당을 사용한 링크드리스트 구현
// 기능: 연결 리스트 사용
// 파일 이름: Node.cpp
// 수정날짜 : 2018년 10월 5일
// 작성자 : 김정용
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

//함수 createNode
//입력 데이터
//출력 Heap에서 생성한 노드의 포인터, 노드의 data는 입력값으로, pNext는 NULL로 설정
//부수 없음
Node* createNode(int val) {

	Node* ptr = (Node*)malloc(sizeof(Node));
	ptr->data = val;
	ptr->pNext = NULL;
	return ptr;
}

//함수 createLList
//입력 데이터
//출력 Heap에서 생성한 LList의 포인터
//부수 없음
LList* createLList(Node* pHead) {

	LList* ptr = (LList*)malloc(sizeof(LList));
	ptr->pHead = pHead;
	InitializeCriticalSection(&(ptr->critical_sec));

	return ptr;
}

//함수 printLL
//입력 linked list의 헤드 포인터
//출력 없음
//부수 화면에 각 노드 데이터를 출력
void printLL(LList* pLList) {

	Node* ptr = pLList->pHead;
	printf("\n------ printNode ------\n");
	while (ptr != NULL) {
		printf("%d\n", ptr->data);
		ptr = ptr->pNext;
	}
	printf("-----------------------\n");
}

//함수 numNode
//입력 linked list의 구조체포인터
//출력 linked list의 노드 갯수
//부수 없음
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

//함수 insertHead
//입력 linked list의 헤드 포인터, 새 노드의 포인터
//출력 없음
//부수 연결리스트의 헤드가 새 노드로 변경됨
void insertHead(LList* pLList, Node* pNewHead) {
	EnterCriticalSection(&(pLList->critical_sec));  // "다른" thread 가 flag 유무에 따라 들어올 지 말지를 결정한다. 즉, EnterCriticalSection 이 여러개 선언되어도 같은 thread 내에서는 flag와 상관없이 들어갈 수 있다.
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

	//pHead == NULL; (약속!)  이 연결리스트가 비어있다는 의미이다.
	//pNext == NULL; (약속!) 이 노드가 연결리스트의 마지막 노드라는 의미이다.
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
		insertHead(inputPod->pLList, createNode(inputPod->threadNum));  //이 한줄이 critical section - 임계영역 : 공유하면 안됨
	return 0;
}