/*
	제출자 : 202111290 박범식
	수행환경 : Windows
*/

#pragma once
class Coin {
private:
	int num500;
	int num100;
	int num50;
	int num10;
public:
	Coin(); //디폴트생성자
	~Coin(); //소멸자
	void addCoins(); //잔액충전
	int calculateChange(); //거스름돈 잔액계산
	int moneyInput(int price); //살때 입금
	void giveChange(int amount); //거스름돈 계산 알고리즘
	int isTooMuchCash(int price, int n1000); //지폐를 너무 많이넣었는지
	bool canGiveChange(int amount); //거스름돈 줄수있는지
};
