
#include "Card.h"

class Player {
	
public:
	//�������
	Player();
	Player(const Player& other);
	//�߼�����
	const Player & operator=(const Player& other);
	~Player();

	//������м���
	void HandCardAdd(Card temp);
	//������м���
	Card HandCardRemove(int pos);
	//��ӡ���
	void PrintPlayer();
	//��ȡ�����������
	int GetHandCardSize();
	//��ҳ�ʼ��
	void InitPlayer(Player& name);
	
	

private:
	//����˽���ࣺ����Ԫ��
	class card_elem {
	public:
		card_elem() {
			next = NULL;
		}
		card_elem* next;
		Card data;
	};
	int hand_size;
	card_elem* head;
	void copy(const Player& other);
	void clear();
};