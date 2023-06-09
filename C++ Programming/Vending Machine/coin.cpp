/*
	제출자 : 202111290 박범식
	수행환경 : Windows
*/

#include"coin.h"
#include<iostream>
#include<Windows.h>
using namespace std;

//생성자 : 동전 개수 전부 0으로 생성
Coin::Coin() {
	num500 = 0;
	num100 = 0;
	num50 = 0;
	num10 = 0;
}

//소멸자
Coin::~Coin() {

}

//동전 보급하기 : 최초 1회 보급한 후 메뉴 선택시 가능
void Coin::addCoins() {
	int n500, n100, n50, n10;

	cout << "동전보급 : 현재 동전 개수는 500원 " << this->num500 << "개, 100원 " << this->num100 << "개, 50원 " << this->num50 << "개, 10원 " << this->num10 << "개입니다." << endl;
	cout << "500원 몇개 추가하시겠습니까?(5~10) : ";
	cin >> n500;
	cout << "100원 몇개 추가하시겠습니까?(5~10) : ";
	cin >> n100;
	cout << "50원 몇개 추가하시겠습니까?(5~10) : ";
	cin >> n50;
	cout << "10원 몇개 추가하시겠습니까?(5~10) : ";
	cin >> n10;

	//예외처리 : 의도하지 않은 값이 입력되었을때
	try {
		if (n500 < 5 || n500 > 10) {
			throw n500;
		}
		if (n100 < 5 || n100 > 10) {
			throw n100;
		}
		if (n50 < 5 || n50 > 10) {
			throw n50;
		}
		if (n10 < 5 || n10 > 10) {
			throw n10;
		}
		this->num500 += n500;
		this->num100 += n100;
		this->num50 += n50;
		this->num10 += n10;
	}
	//잘못입력 시 변수값 조정 없이 반환
	catch (int e) {
		cout << "예외발생 : 동전은 5~10개 범위 내에서 보급할 수 있습니다." << endl;
		system("pause");
		return;
	}
	//정상 입력 시
	cout << "보급 후 동전 개수는 500원 " << this->num500 << "개, 100원 " << this->num100 << "개, 50원 " << this->num50 << "개, 10원 " << this->num10 << "개입니다." << endl;
	system("pause");
	return;

}

//(동전개수 * 가격) 으로 남은 거스름돈을 계산해준다
int Coin::calculateChange() {
	int change = 0;
	change = (this->num500 * 500) + (this->num100 * 100) + (this->num50 * 50) + (this->num10 * 10);
	return change;
}

//판매단계에서 입금단계 
int Coin::moneyInput(int price) {
	int n1000, n500, n100, n50, n10;
	int total = 0;
	int cashleft;
	cout << "1000원 몇개 투입하시겠습니까? : ";
	cin >> n1000;
	cashleft = isTooMuchCash(price, n1000);
	if (n1000 < 0) {
		cout << "제대로 입력하시오" << endl;
	}
	else {
		if (cashleft) {
			cout << "지폐 반환. 1000원:" << cashleft << "장" << endl;
			total += (n1000 - cashleft) * 1000;
		}
		else {
			total += n1000 * 1000;
		}
	}

	//음료수가격 이상을 지폐투입 했으면, 동전 투입 없음
	//투입된 동전 개수만큼 총 동전개수에 더해줌
	if (total < price) {
		cout << "500원 몇개 투입하시겠습니까? : ";
		cin >> n500;
		if (n500 < 0) {
			cout << "제대로 입력하시오" << endl;
		}
		else {
			total += n500 * 500;
			this->num500 += n500;
		}

		if (total < price) {
			cout << "100원 몇개 투입하시겠습니까? : ";
			cin >> n100;
			if (n100 < 0) {
				cout << "제대로 입력하시오" << endl;
			}
			else {
				total += n100 * 100;
				this->num100 += n100;
			}
		}
	}
	if (total < price) { // 전체 금액보다 적게 넣었을때
		this->num500 -= n500;
		this->num100 -= n100;
		cout << "음료수 가격보다 적은 금액을 투입헀습니다" << endl << endl;
		cout << "반환. 1000원 :" << n1000 << ", 500원 :" << n500 << ", 100원 : " << n100 << endl;
		return -1;
	}
	else if (canGiveChange(total - price) == false) {
		cout << "거스름돈을 지급하기 위한 동전이 부족합니다." << endl;
		return -1;
	}
	//거스름돈 값 반환
	else {
		return total - price;
	}
}

//거스름돈 반환
void Coin::giveChange(int amount) {
	int coins[4] = { 500, 100, 50, 10 };
	int coinCounts[4] = { this->num500, this->num100 , this->num50 , this->num10 };
	int coinReturned[4] = { 0 };

	cout << "---------거스름돈---------" << endl;
	//최적의 동전 지급방법 계산 : 그리디 알고리즘 사용
	for (int i = 0; i < 4; i++) {
		if (amount >= coins[i]) {
			int count = min(amount / coins[i], coinCounts[i]);
			amount -= count * coins[i];
			coinCounts[i] -= count;
			coinReturned[i] = count;
		}
	}
	
	//거스름돈 지급에 사용된 동전 개수 빼기
	this->num500 -= coinReturned[0];
	this->num100 -= coinReturned[1];
	this->num50 -= coinReturned[2];
	this->num10 -= coinReturned[3];
	//거스름돈 출력
	for (int i = 0; i < 4; i++) {
		cout << coins[i] << "원 동전: " << coinReturned[i] << "개" << endl;
	}
	return;
}

// 1000원짜리를 너무 많이넣으면 동전 부족우려있음
int Coin::isTooMuchCash(int price, int n1000) {
	int tmp = (n1000 * 1000 - price) / 1000;
	if (tmp > 0) {
		return tmp;
	}
	else {
		return 0;
	}		
}

bool Coin::canGiveChange(int amount) {
	int coins[] = { 500, 100, 50, 10 };
	int coinCounts[4] = { this->num500, this->num100 , this->num50 , this->num10 };
	bool canGiveChange = true;

	for (int i = 0; i < 4; i++) {
		if (amount >= coins[i]) {
			int count = min(amount / coins[i], coinCounts[i]);
			amount -= count * coins[i];
			coinCounts[i] -= count;
		}
	}

	if (amount > 0) {
		return false;
	}
	else {
		return true;
	}
}