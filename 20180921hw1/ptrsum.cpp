#include <windows.h>

void WINAPI ptrsum(int *p1, int *p2, int *p3);

int main(void) {

	int a, b, c;
	a = 10;
	b = 20;
	ptrsum(&a, &b, &c);

	return 0;
}

void WINAPI ptrsum(int *p1, int *p2, int *p3) {

	*p3 = *p1 + *p2;
}