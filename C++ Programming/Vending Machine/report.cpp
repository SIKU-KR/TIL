/*
	제출자 : 202111290 박범식
	수행환경 : Windows
*/

#define _CRT_SECURE_NO_WARNINGS
#include "report.h"
#include "menu.h"
#include<iostream>
#include<Windows.h>
#include<ctime>
#include<cstdlib>
using namespace std;

// 오늘 날짜 출력
void Report::printCurrentDate() {
	time_t currentTime = time(nullptr);
	tm* localTime = localtime(&currentTime);

	int year = localTime->tm_year + 1900; // 
	int month = localTime->tm_mon + 1;
	int day = localTime->tm_mday;

	cout << year << "/" << month << "/" << day << endl;
}

// 음료별 판매량 가져오기
void Report::setSalestotal(Menu& menu1, Menu& menu2, Menu& menu3) {
	int tmp1 = 0, tmp2 = 0;
	tmp1 = (menu1.salesrate * menu1.menuprice) + (menu2.salesrate * menu2.menuprice) + (menu3.salesrate * menu3.menuprice);
	tmp2 = menu1.salesrate + menu2.salesrate + menu3.salesrate;
	this->salestotal = tmp1;
	this->soldcount = tmp2;
	return;
}

// 디폴트 생성자
Dailyreport::Dailyreport() {

}

// 디폴트 소멸자
Dailyreport::~Dailyreport() {

}

// 일일 보고서 출력 함수
void Dailyreport::printDailyReport() {
	cout << endl;
	cout << "==========일일매출현황==========" << endl
		<< "오늘 날짜 : ";
	printCurrentDate();
	cout << "오늘의 매출액 : " << this->salestotal << endl
		<< "오늘의 판매수량 : " << this->soldcount << endl;
}

// 디폴트 생성자
Monthlyreport::Monthlyreport() {

}

// 디폴트 소멸자
Monthlyreport::~Monthlyreport() {

}

// 29일간 판매한 금액을 랜덤으로 생성한다 
void Monthlyreport::setsold29days() {
	int tmp = 0, randomvalue;
	srand(time(nullptr));
	//일일매출액 10,000원~100,000원 사이 랜덤 발생
	for (int i = 0; i < 29; i++) {
		tmp += ((rand() % 9001 + 1000) * 10); 
	}
	this->sold29days = tmp;
	return;
}

// 월간(지난 30일) 매출 보고서 출력
void Monthlyreport::printMonthlyReport() {
	cout << endl;
	cout << "==========월매출현황==========" << endl
		<< "오늘 날짜 : ";
	printCurrentDate();
	cout << "지난 30일 매출액 : " << this->salestotal + this->sold29days << endl
		<< "일간 평균 판매수익 : " << (this->salestotal + this->sold29days) / 30 << endl;
}
