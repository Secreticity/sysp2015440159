#include <stdio.h>

int sum(int, int);
int (*fff)(int, int);  //fff �� �������̴�.


int main() {

	/*

		1. �Լ��� �̸� (sum) �� �� �Լ��� ���� �ּ��̴�.
		2. �Լ� �����͸� �����Ϸ��� �� �Լ��� Ÿ��(��ȯ��,
		�Ű������� �ڷ��� �� ����)�� �����ؾ��Ѵ�.

	*/

	fff = sum; 

	printf("value = %d\n", sum(10, 20));
	printf("value = %d\n", fff(100, 200));

	return 0;
}

int sum(int a, int b) {
	return a + b;
}