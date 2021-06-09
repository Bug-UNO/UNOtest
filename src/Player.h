
#include "Card.h"

class Player {
	
public:
	//设置玩家
	Player();
	Player(const Player& other);
	//逻辑等于
	const Player & operator=(const Player& other);
	~Player();

	//玩家手中加牌
	void HandCardAdd(Card temp);
	//玩家手中减牌
	Card HandCardRemove(int pos);
	//打印玩家
	void PrintPlayer();
	//获取玩家手牌数量
	int GetHandCardSize();
	//玩家初始化
	void InitPlayer(Player& name);
	
	

private:
	//设置私有类：卡牌元素
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