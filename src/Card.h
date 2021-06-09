#pragma once
#include <iostream>
using namespace std;

enum CardColor {red, green, blue, yellow ,black};

class Card
{
public:
	int number; // 0-9 numbers, +2, skip, reverse, all color, +4 (all color) 
	CardColor color; // 五种颜色：红、黄、蓝、绿、黑

	//牌型检查：相同
	bool operator==(Card const& other) const;
	

	//牌型检查：不相同
	bool operator!=(Card const& other) const;

	Card();
	

	Card(int num, CardColor color);

	~Card();
};

ostream& operator<<(ostream& out, Card const& temp_card);