/*
* Numbers.c
*
* Sample code for "Multithreading Applications in Win32"
* This is from Chapter 2, Listing 2-1
*
* Starts five threads and gives visible feedback
* of these threads running by printing a number
* passed in from the primary thread.
*
*/

#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

DWORD WINAPI ThreadFunc(LPVOID);

int main()
{
	HANDLE hThrd[5];
	DWORD threadId;
	int i;

	for (i = 0; i<5; i++)
	{
		hThrd[i] = CreateThread(NULL,0,ThreadFunc,(LPVOID)i,0,&threadId);
		//������ Ŀ�� ������Ʈ�� ����
		//Signaled: �����尡 �����
		//non-signaled: �����尡 ������� ����

		//if (hThrd)
		//{
		//	printf("Thread launched %d\n", i);
		//	CloseHandle(hThrd);
		//}
	}
	// Wait for the threads to complete.
	// We'll see a better way of doing this later.

	//���⼭ �ڵ��� ������ WaitForMultipleObjects()���� �������� �ڵ��� ������ �� ����.
	//���� �����尡 ����� ���� Ȯ���� �� CloseHandle()�� ȣ���ؾ� �Ѵ�.
	if (hThrd)
	{
		printf("Thread launched %d\n", i);
		CloseHandle(hThrd);
	}
	Sleep(2000);
	DWORD result;

	result = WaitForMultipleObjects(5, hThrd, TRUE, INFINITE);
	printf("%d\n", result);
	return EXIT_SUCCESS;
}

DWORD WINAPI ThreadFunc(LPVOID n)
{
	int i;
	for (i = 0; i<10; i++)
		printf("%d%d%d%d%d%d%d%d\n", n, n, n, n, n, n, n, n);
	return 0;
}
