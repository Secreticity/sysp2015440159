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
		//쓰레드 커널 오브젝트의 상태
		//Signaled: 쓰레드가 종료됨
		//non-signaled: 쓰레드가 종료되지 않음

		//if (hThrd)
		//{
		//	printf("Thread launched %d\n", i);
		//	CloseHandle(hThrd);
		//}
	}
	// Wait for the threads to complete.
	// We'll see a better way of doing this later.

	//여기서 핸들을 닫으면 WaitForMultipleObjects()에서 쓰레드의 핸들을 접근할 수 없다.
	//따라서 쓰레드가 종료된 것을 확인한 후 CloseHandle()을 호출해야 한다.
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
