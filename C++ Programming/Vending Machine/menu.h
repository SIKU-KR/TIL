/*
	제출자 : 202111290 박범식
	수행환경 : Windows
*/

#pragma once
#include<string>
using std::string;

class Menu {
private:
	string menuname; //음료수이름
	int menuprice; //음료수가격
	int salesrate; //음료수판매량
	friend class Report; //report는 menu의 프렌드클래스
public:
	Menu(); //디폴트생성자
	Menu(string name, int price); //생성자
	~Menu(); //소멸자
	void sellmenu(); //메뉴판매
	int getPrice(); //금액가져오기
	string getName();
};
