
#include "Card.h"
#include "Player.h"
#include<iostream>

using namespace std;

Player::Player() {
	head = NULL;
	hand_size = 0;
}

Player::Player(const Player& other) {
	copy(other);
}

//��������
const Player& Player::operator=(const Player& other) {
	if (this != &other) {
		clear();
		copy(other);
	}
	return *this;
}


Player::~Player() {
	clear();
}

//�����Ƶ���ǰ�����
void Player::HandCardAdd(Card temp) {
	card_elem* temp_ptr;		//����һ����������
	temp_ptr = new card_elem;	//
	temp_ptr->data = temp;
	temp_ptr->next = head;
	head = temp_ptr;
	hand_size++;
}

//�����Ƴ�
Card Player::HandCardRemove(int pos) {
	//λ�ó�����
	if (pos<0 || pos >hand_size) {
		return Card();
	}
	//����ɾ������
	card_elem* prev_ptr = head;
	card_elem* target = prev_ptr->next;
	Card temp_card;
	int temp_pos = pos;

	//����λ��Ϊ��һ��
	if (pos == 0) {
		temp_card = head->data; //���淵�ص�����
		head = head->next;		//��ָ��ָ����һ��
		delete prev_ptr;		//ɾ��Ŀ��Ԫ��
		hand_size--;			
		return temp_card;
	}

	//�ҵ�ǰһԪ��
	while (temp_pos > 1) {
		prev_ptr = prev_ptr->next;
		target = prev_ptr->next;
		temp_pos--;
	} 
	prev_ptr->next = target->next; //������������Ԫ��
	temp_card = target->data;		//�����ݱ��浽tem
	delete target;					//ɾ��Ŀ��Ԫ��
	hand_size--;
	return temp_card;				//����Ŀ��Ԫ��
}

//��ӡ���
void Player::PrintPlayer() {
	int temp_size = hand_size;
	int i = 0;
	card_elem* temp_ptr = head;
	while(temp_size > 0) {
		cout << i << ": " << temp_ptr->data << endl;
		temp_ptr = temp_ptr->next;
		i++;
		temp_size--;
	}
}
//��ȡ�����������
int Player::GetHandCardSize() {
	return hand_size;
}

//��ҳ�ʼ��
void Player::InitPlayer(Player& name) {
	for (int i = 0; i < 7; i++) {
		name.HandCardAdd(Card());
	}
}

//���и��Ʋ���
void Player::copy(const Player& other) {
	hand_size = other.hand_size;

	//����Ŀ����ҵĶ���
	if (hand_size > 0) {
		head = new card_elem();
		head->data = other.head->data;
	}
	else {
		head = NULL;
		return;
	}
	//��other_ptr ����������
	card_elem* other_ptr = other.head->next;
	//����һ�������� temp_ptr ������������
	card_elem* temp_ptr;
	//����֮ǰ��ָ��ָ��ǰ
	card_elem* prev_ptr = head;
	for (int i = 1; i < hand_size; i++) {
		
		temp_ptr = new card_elem;			//������Ԫ��
		prev_ptr->next = temp_ptr;			//��һĿ��Ϊ����������
		temp_ptr->data = other_ptr->data;	//��ǰ���ݽ��뻺����
		prev_ptr = temp_ptr;				//��ǰ���ݷ�����һ����
		temp_ptr = NULL;					//��ǰ����Ϊ��
		other_ptr = other_ptr->next;		//ָ����һ����
	}
}
//��ղ���
void Player::clear() {
	card_elem* temp_ptr = head;
	card_elem* next_ptr;
	while (hand_size > 0) {
		next_ptr = temp_ptr->next;
		delete temp_ptr;
		temp_ptr = next_ptr;
		hand_size--;
	}
	head = NULL;
}







