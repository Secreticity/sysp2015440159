//**********************************************
// ����: ������, ����ü, �����Ҵ� ����
// ���: ���� ����Ʈ ����� ���� �⺻ ����
// ���� �̸�: �ҽ�.cpp
// ������¥ : 2018�� 10�� 5��
// �ۼ��� : ������
//**********************************************

#include <stdio.h>

typedef struct complex {

	double real;   //member variable
	double imag;   //member variable

} Complex; //����ü ������ semicolon���� ������ �Ѵ�.

int main() {

	int a=10, b=20, c=30;

	//������
	int* ptr;  //������ ���� ����

	ptr = &a;
	*ptr = b;
//	printf(" a = %d\n", a);

	//����ü
//	struct complex c1 = { 1.0, 1.0 }, c2 = { 2.0, 3.0 }, c3;  //����ü ���� ����
	Complex c1 = { 1.0, 1.0 }, c2 = { 2.0, 3.0 }, c3;  //����ü ���� ����

//	�Ұ���! : c3 = c1 + c2;
	c3.real = c1.real + c2.real;  //��� ���� ���� -> ����ü�����̸�.��������̸�
	c3.imag = c1.imag + c2.imag;

	printf("c3 = %.1f + j%.1f", c3.real, c3.imag);

	return 0;
}