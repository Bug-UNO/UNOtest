#pragma once

class Deck {
public:
	Deck();
	Deck(const Deck& other);
	const Deck& operator= (const Deck& other);
	~Deck();
	//���ƿ���г�ʼ��
	void Init();

	//ϴ��
	void Shuffle();

	//����һ�η��ƣ����ƣ�
	Card GetCard();
	
	//���Ʋ���
	int AddCard(Card temp_card);

	//��ӡ�ƿ�
	void PrintDeck();

	//��ȡ�ߴ�
	int GetSize();


private:
	Card* ptr_deck;  //�����ƿ�
	int size;		//�Ƶĳߴ�
	void clear();	//���
	void copy(const Deck& other);	//����

};

