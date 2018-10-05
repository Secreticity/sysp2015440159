//**********************************************
// ����: ������, ����ü, �����Ҵ� ����
// ���: ���� ����Ʈ ����� ���� �⺻ ����
// ���� �̸�: �ҽ�.cpp
// ������¥ : 2018�� 10�� 5��
// �ۼ��� : ������
//**********************************************

#include <stdio.h>
#include <stdlib.h>

typedef struct complex {

	double real;   //member variable
	double imag;   //member variable

} Complex; //����ü ������ semicolon���� ������ �Ѵ�.

//�Լ�: printComplexVar
//�Է�: ���Ҽ�
//���: ����
//�μ�: ȭ�鿡 ���Ҽ��� ����Ѵ�.
void printComplexVar(Complex a) {

	printf("%.1f + j%.1f\n", a.real, a.imag);
}

//�Լ�: printComplex
//�Է�: ���Ҽ��� ������
//���: ����
//�μ�: ȭ�鿡 ���Ҽ��� ����Ѵ�.
void printComplex(Complex *a) {

	printf("%.1f + j%.1f\n", a->real, a->imag);
}

//�Լ�: addComplexVar
//�Է�: �ΰ��� ���Ҽ��� ������
//���: �� ���Ҽ��� ��
//�μ�: ����.
Complex addComplexVar(Complex* ptr1, Complex* ptr2) {

	Complex c;
	c.real = ptr1->real + ptr2->real;
	c.imag = ptr1->imag + ptr2->imag;

	return c;
}

//�Լ�: addComplex
//�Է�: �ΰ��� ���Ҽ��� ������
//���: ����ü ������
//�μ�: ����.
Complex* addComplex(Complex* ptr1, Complex* ptr2) {

//	WRONG !! : Complex c;

	//�����Ҵ� (Dynamic memory allocation)
	//void* malloc {} - Casting�� ����Ͽ� ����ؾ� �Ѵ�.
	Complex* c = (Complex*) malloc(sizeof(Complex));

	c->real = ptr1->real + ptr2->real;
	c->imag = ptr1->imag + ptr2->imag;

	return c;
}

int main() {

	Complex c1 = { 1.0, 1.0 }, c2 = { 2.0, 3.0 }, c3;
	c3.real = c1.real + c2.real;
	c3.imag = c1.imag + c2.imag;

	Complex* ptr1;
	ptr1 = &c3;  //�Ϲ� �����Ϳ� ���������� ����ü ptr1 �����Ϳ� c3�� �ּҸ� �Է��Ͽ� �����Ŵ.

	ptr1->real = 10.0;  //ptr1�� �� �ּ��� ����ü�� real ���� �����ϱ� ���� "->" ���
	ptr1->imag = 20.0;
	printf("c3 = %.1f + j%.1f\n", c3.real, c3.imag);

	//����ü�� �Ű������� �Լ�
	c3 = c1;  //��-��
	printComplexVar(c3);  //��ȿ����
	printComplex(&c3);
	
	//�����Ҵ�
	c3 = addComplexVar(&c1, &c2);

	printComplex(&c1);
	printComplex(&c2);
	printComplex(&c3);

	ptr1 = addComplex(&c1, &c2);
	printf(" --- \n");
	printComplex(ptr1);
	free(ptr1);   //heap ���� �Ҹ�


	return 0;
}