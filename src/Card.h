#pragma once
#include <iostream>
using namespace std;

enum CardColor {red, green, blue, yellow ,black};

class Card
{
public:
	int number; // 0-9 numbers, +2, skip, reverse, all color, +4 (all color) 
	CardColor color; // ������ɫ���졢�ơ������̡���

	//���ͼ�飺��ͬ
	bool operator==(Card const& other) const;
	

	//���ͼ�飺����ͬ
	bool operator!=(Card const& other) const;

	Card();
	

	Card(int num, CardColor color);

	~Card();
};

ostream& operator<<(ostream& out, Card const& temp_card);