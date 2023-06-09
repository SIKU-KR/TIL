/*
	제출자 : 202111290 박범식
	수행환경 : Windows
*/

#pragma once
#include "menu.h"

class Report {
protected:
	int soldcount;
	int salestotal;
public:
	void printCurrentDate();
	void setSalestotal(Menu& menu1, Menu& menu2, Menu& menu3);
};

class Dailyreport : public Report {
public:
	Dailyreport();
	~Dailyreport();
	void printDailyReport();
};

class Monthlyreport : public Report {
private:
	int sold29days;
public:
	Monthlyreport();
	~Monthlyreport();
	void setsold29days(); //지난 29일간의 매출액을 랜덤으로 세팅함
	void printMonthlyReport(); //월간매출현황보고서 출력
};
