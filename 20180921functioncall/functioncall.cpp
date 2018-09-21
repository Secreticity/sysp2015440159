#include <windows.h>

int sum(int a, int b);
int WINAPI wsum(int a, int b);

int main(void) {

	int a, b, c;
	a = 10;
	b = 20;
	c = a + b;
	c = sum(a, b);
	c = wsum(a, b);

	return 0;
}

int sum(int x, int y) {
	int z;
	z = x + y;
	return z;
}

int WINAPI wsum(int x, int y) {
	int z;
	z = x + y;
	return z;
}