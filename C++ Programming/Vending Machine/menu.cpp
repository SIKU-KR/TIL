/*
	제출자 : 202111290 박범식
	수행환경 : Windows
*/

#include "menu.h"
#include<iostream>
#include<string>
using namespace std;

//생성자
Menu::Menu() {
	menuname = "Unknown";
	menuprice = 0;
	salesrate = 0;
}

//생성자 : 이름과 가격을 매개변수로 받아서 생성해줌
Menu::Menu(string name, int price) {
	menuname = name;
	menuprice = price;
	salesrate = 0;
}

//소멸자
Menu::~Menu() {

}

//판매할때 판매량 1증가
void Menu::sellmenu() {
	this->salesrate += 1;
}

//금액 return
int Menu::getPrice() {
	return menuprice;
}

//이름 return
string Menu::getName() {
	return menuname;
}