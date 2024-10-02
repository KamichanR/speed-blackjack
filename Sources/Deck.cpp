#include "Deck.hpp"

Deck::Deck() {
	this->numCards = INITIAL_NUM_CARD;
	for (int i = 0; i < this->numCards; i++) {
		this->cards[i] = nullptr;
	}
	this->Reset();
}

Deck::~Deck() {}

/*
* @brief 山札の枚数を取得する。
* 
* @return int 山札の枚数。
*/
int Deck::GetNumCards() const {
	return this->numCards;
}

/*
* @brief 山札の枚数を設定する。
* 
* @param int numCards_ 山札の枚数。
*/
void Deck::SetNumCards(int numCards_) {
	this->numCards = numCards_;
}

/*
* @brief カードをシャッフルする。
* 
* @details Fisher-Yatesアルゴリズムを使用してシャッフルする。
*/
void Deck::Shuffle() {
	for (int i = this->numCards - 1; i > 0; i--) {
		int j = this->engine() % (this->numCards + 1);

		Card* temporary = this->cards[i];
		this->cards[i] = this->cards[j];
		this->cards[j] = temporary;
	}
}

/*
* @brief 山札を初期化する。
*/
void Deck::Reset() {
	for (int i = 0; i < this->INITIAL_NUM_CARD; i++) {
		this->poolAllocator.Deallocate(this->cards[i]);
		this->cards[i] = nullptr;
	}

	Card::Suit suit;
	Card::Rank rank;
	for (int i = 0; i < NUM_CARD_PER_DECK; i++) {
		for (int j = 0; j < NUM_DECK; j++) {
			int k = i * NUM_DECK + j;
			suit = static_cast<Card::Suit>(i % Card::NUM_SUIT + 1);
			rank = static_cast<Card::Rank>(i % Card::NUM_RANK + 1);
			while (this->cards[k] == nullptr) {
				this->cards[k] = this->poolAllocator.Allocate();
			}
			this->cards[k]->SetSuit(suit);
			this->cards[k]->SetRank(rank);
		}
	}

	this->SetNumCards(INITIAL_NUM_CARD);
	this->Shuffle();
}

/*
* @brief 山札からカードを引く。
* 
* @return Card 引いたカード。
*/
Card Deck::Draw() {
	this->numCards--;
	Card* pointer = this->cards[this->numCards];
	this->poolAllocator.Deallocate(pointer);

	return *pointer;
}
