//**********************************************
// 제목: 포인터, 구조체, 동적할당 예제
// 기능: 연결 리스트 사용을 위한 기본 개념
// 파일 이름: 소스.cpp
// 수정날짜 : 2018년 10월 5일
// 작성자 : 김정용
//**********************************************

#include <stdio.h>
#include <stdlib.h>

typedef struct complex {

	double real;   //member variable
	double imag;   //member variable

} Complex; //구조체 선언은 semicolon으로 끝내야 한다.

//함수: printComplexVar
//입력: 복소수
//출력: 없음
//부수: 화면에 복소수를 출력한다.
void printComplexVar(Complex a) {

	printf("%.1f + j%.1f\n", a.real, a.imag);
}

//함수: printComplex
//입력: 복소수의 포인터
//출력: 없음
//부수: 화면에 복소수를 출력한다.
void printComplex(Complex *a) {

	printf("%.1f + j%.1f\n", a->real, a->imag);
}

//함수: addComplexVar
//입력: 두개의 복소수의 포인터
//출력: 두 복소수의 합
//부수: 없음.
Complex addComplexVar(Complex* ptr1, Complex* ptr2) {

	Complex c;
	c.real = ptr1->real + ptr2->real;
	c.imag = ptr1->imag + ptr2->imag;

	return c;
}

//함수: addComplex
//입력: 두개의 복소수의 포인터
//출력: 구조체 포인터
//부수: 없음.
Complex* addComplex(Complex* ptr1, Complex* ptr2) {

//	WRONG !! : Complex c;

	//동적할당 (Dynamic memory allocation)
	//void* malloc {} - Casting을 사용하여 사용해야 한다.
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
	ptr1 = &c3;  //일반 포인터와 마찬가지로 구조체 ptr1 포인터에 c3의 주소를 입력하여 연결시킴.

	ptr1->real = 10.0;  //ptr1에 들어간 주소의 구조체의 real 값을 접근하기 위해 "->" 사용
	ptr1->imag = 20.0;
	printf("c3 = %.1f + j%.1f\n", c3.real, c3.imag);

	//구조체가 매개변수인 함수
	c3 = c1;  //가-능
	printComplexVar(c3);  //비효율적
	printComplex(&c3);
	
	//동적할당
	c3 = addComplexVar(&c1, &c2);

	printComplex(&c1);
	printComplex(&c2);
	printComplex(&c3);

	ptr1 = addComplex(&c1, &c2);
	printf(" --- \n");
	printComplex(ptr1);
	free(ptr1);   //heap 공간 소멸


	return 0;
}