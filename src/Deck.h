#pragma once

class Deck {
public:
	Deck();
	Deck(const Deck& other);
	const Deck& operator= (const Deck& other);
	~Deck();
	//对牌库进行初始化
	void Init();

	//洗牌
	void Shuffle();

	//进行一次发牌（摸牌）
	Card GetCard();
	
	//加牌操作
	int AddCard(Card temp_card);

	//打印牌库
	void PrintDeck();

	//获取尺寸
	int GetSize();


private:
	Card* ptr_deck;  //创建牌库
	int size;		//牌的尺寸
	void clear();	//清空
	void copy(const Deck& other);	//复制

};

