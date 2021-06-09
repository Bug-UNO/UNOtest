#include "Deck.h"
#include "Card.h"

#define CARD_COUNT 108

using namespace std;

class HandCards {

};

Deck::Deck() {
	ptr_deck = new Card[CARD_COUNT];//����108���ƵĿռ�
	size = 0;//��ʼ���Ƶĳߴ�
}

Deck::Deck(const Deck& other) {
	copy(other);
}

const Deck& Deck::operator=(const Deck& other) {
	if (this != &other) {
		clear();
		copy(other);
	}
	return *this;
}

//�����ƿ�
void Deck::Init() {
	int num = 0;


	// ��0���ƽ��ж���
	for (int col = 0; col < 4; col++)
	{
		ptr_deck[size].number = num;
		ptr_deck[size].color = static_cast<CardColor>(col);
		size++;
	}

	// ��1-9���ƣ�������skip��+2��draw-two����ת��reverseÿ����ɫ���� 
	for (num = 1; num <= 12; num++)
	{
		for (int x = 0; x < 2; x++)
		{
			for (int col = 1; col <= 4; col++)
			{
				ptr_deck[size].number = num;
				ptr_deck[size].color = static_cast<CardColor>(col);
				size++;
			}
		}

	}

	// ���Ʊ�ɫ��wild������wild draw four
	for (num = 13; num <= 14; num++)
	{
		for (int x = 0; x < 4; x++)
		{
			ptr_deck[size].number = num;
			ptr_deck[size].color = black;
			size++;
		}
	}
}

//ϴ��
void Deck::Shuffle() {
	Card* temp_deck = new Card[size];	//����һ��temp_deck���������ƿ���ͬ�Ŀռ�
	for (int i = 0; i < size; i++) {
		temp_deck[i] = ptr_deck[i];		//���Ʒ��뻺����
	}

	int temp_size = size;
	int temp_pos;
	int pos;
	for (int i = 0; i < size; i++) {
		//��temp_deck�����һ��λ��
		srand(time(NULL));			//��ÿ��ʱ�������λ�ö���һ��
		pos = rand() % temp_size;
		ptr_deck[i] = temp_deck[pos];//���������Ʒ����ƿ�

		//�Ƴ�temp_deck�Ķ�ӦԪ��
		temp_size--;
		for (temp_pos = pos; temp_pos < temp_size; temp_pos++) {
			temp_deck[temp_pos] = temp_deck[temp_pos + 1];
		}
	}
	delete[] temp_deck;//ɾ������������
}


//����һ�η��ƣ����ƣ�
Card Deck::GetCard() {
	if (size <= 0) {
		return Card();
	}

	Card temp_card = ptr_deck[size - 1];
	size--;
	return temp_card;
}

//���Ʋ���
int Deck::AddCard(Card temp_card) {
	if (size < CARD_COUNT) {
		ptr_deck[size] = temp_card;
		size++;
		return 0;
	}
	else {
		return 1;
	}
}

//��ӡ�ƿ�
void Deck::PrintDeck() {
	for (int i = 0; i < size; i++) {
		cout << i << ": " << ptr_deck[i] << endl;
	}
}

//�����ƿ�����
void Deck::copy(const Deck& other)
{
	size = other.size;
	ptr_deck = new Card[size];
	for (int i = 0; i < size; i++)
	{
		ptr_deck[i] = other.ptr_deck[i];
	}
}

//���
void Deck::clear()
{
	delete[]ptr_deck;
	ptr_deck = NULL;
	size = 0;
}

//��ȡ�ߴ�
int Deck::GetSize()
{
	return size;
}