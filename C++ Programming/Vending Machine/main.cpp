/*
	제출자 : 202111290 박범식
	수행환경 : Windows
*/

#include"coin.h"
#include"menu.h"
#include"report.h"
#include<iostream>
using namespace std;

// main page 구성하기
int mainPage() {
	int number;
	cout << "==========메뉴를 선택하세요==========" << endl
		<< "1. 동전 보급하기" << endl
		<< "2. 일일 매출현황 보고서 출력" << endl
		<< "3. 월 매출현황 보고서 출력" << endl
		<< "4. 음료수 구입" << endl
		<< "5. 종료하기" << endl
		<< "숫자를 입력하세요 : ";
	try {
		cin >> number;
		// 입력 숫자 검사
		if (number < 1 || number >5) {
			throw number;
		}
	}
	// 예외처리, 처음부터 시작하도록
	catch (int e) {
		cout << "숫자를 정확히 입력하세요." << endl;
		mainPage();
	}
	// 선택한 번호 반환
	return number;
}

// 음료수 선택 창
int selectmenu(Menu& menu1, Menu& menu2, Menu& menu3) {
	int number;
	cout << endl
		<< "==========메뉴를 선택하세요==========" << endl
		<< "1. " << menu1.getName() << " " << menu1.getPrice() << "원" << endl
		<< "2. " << menu2.getName() << " " << menu2.getPrice() << "원" << endl
		<< "3. " << menu3.getName() << " " << menu3.getPrice() << "원" << endl
		<< "숫자를 입력하세요 : ";
	try {
		cin >> number;
		// 입력 숫자 검사
		if (number < 1 || number >3) {
			throw number;
		}
	}
	// 예외처리, 처음부터 시작하도록
	catch (int e) {
		cout << "숫자를 정확히 입력하세요." << endl;
		selectmenu(menu1, menu2, menu3);
	}
	cout << endl;
	return number;
}

// main 함수
int main() {
	//변수선언
	bool loopKey = true;
	int select, crtMoney = 0;

	//음료수 3종류 선언
	Menu cola("콜라", 2550);
	Menu cider("사이다", 1470);
	Menu water("물", 900);

	//거스름돈 선언
	Coin coinset;
	coinset.addCoins();

	// 리포트 작성 class들
	Dailyreport daily;
	Monthlyreport monthly;
	monthly.setsold29days();

	// 반복시작, 5번메뉴 입력시 종료
	while (loopKey) {
		system("cls");
		select = mainPage();

		switch (select) {

		case 1: //동전보급하기
			coinset.addCoins();
			break;

		case 2: //일일보고서인쇄
			daily.setSalestotal(cola, cider, water);
			daily.printDailyReport();
			system("pause");
			break;

		case 3: //월간보고서인쇄
			monthly.setSalestotal(cola, cider, water);
			monthly.printMonthlyReport();
			system("pause");
			break;

		case 4: //음료판매
			if (coinset.calculateChange() < 1000) { //거스름돈 부족
				cout << "판매 정지상태입니다. 사유 : 거스름돈 잔액 부족" << endl;
			}
			else { //판매 가능
				switch (selectmenu(cola, cider, water)) {
				case 1:
					cout << cola.getPrice() <<"원 입니다." << endl;
					crtMoney = coinset.moneyInput(cola.getPrice());
					if (crtMoney == -1) { // 에러코드 -1
						break;
					}
					else {
						cola.sellmenu();
						cout << endl << "콜라 나왔습니다" << endl;
						break;
					}
				case 2:
					cout << cider.getPrice() << "원 입니다." << endl;
					crtMoney = coinset.moneyInput(cider.getPrice());
					if (crtMoney == -1) { // 에러코드 -1
						break;
					}
					else {
						cider.sellmenu();
						cout << endl << "사이다 나왔습니다" << endl;
						break;
					}
				case 3:
					cout << water.getPrice() << "원 입니다." << endl;
					crtMoney = coinset.moneyInput(water.getPrice());
					if (crtMoney == -1) { // 에러코드 -1
						break;
					}
					else {
						water.sellmenu();
						cout << endl << "물 나왔습니다" << endl;
						break;
					}
				}
				// 거스름돈 지급
				if (crtMoney > 0) {
					coinset.giveChange(crtMoney);
				}
			}
			system("pause");
			break;

		case 5: //끝, 반복정지
			loopKey = false;
			break;
		}
	}
	return 0;
}