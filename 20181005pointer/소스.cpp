//**********************************************
// 제목: 포인터, 구조체, 동적할당 예제
// 기능: 연결 리스트 사용을 위한 기본 개념
// 파일 이름: 소스.cpp
// 수정날짜 : 2018년 10월 5일
// 작성자 : 김정용
//**********************************************

#include <stdio.h>

typedef struct complex {

	double real;   //member variable
	double imag;   //member variable

} Complex; //구조체 선언은 semicolon으로 끝내야 한다.

int main() {

	int a=10, b=20, c=30;

	//포인터
	int* ptr;  //포인터 변수 선언

	ptr = &a;
	*ptr = b;
//	printf(" a = %d\n", a);

	//구조체
//	struct complex c1 = { 1.0, 1.0 }, c2 = { 2.0, 3.0 }, c3;  //구조체 변수 선언
	Complex c1 = { 1.0, 1.0 }, c2 = { 2.0, 3.0 }, c3;  //구조체 변수 선언

//	불가능! : c3 = c1 + c2;
	c3.real = c1.real + c2.real;  //멤버 변수 접근 -> 구조체변수이름.멤버변수이름
	c3.imag = c1.imag + c2.imag;

	printf("c3 = %.1f + j%.1f", c3.real, c3.imag);

	return 0;
}