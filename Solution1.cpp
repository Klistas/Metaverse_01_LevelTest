// SolutionCpp.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>
#include <iostream>



//A.	void swap(int* a, int* b);

void swap(int* a, int* b)
{
	// 바꿀 변수 두개를 저장한 뒤 서로 교환.
	
	int swapA = *b;
	int swapB = *a;
	*a = swapA;
	*b = swapB;

}



//B.	void swap(int& a, int& b);

void swap(int& a, int& b)
{
	// 바꿀 변수 두개를 저장한 뒤 서로 교환.
	int swapA = b;
	int swapB = a;
	a = swapA;
	b = swapB;
}




