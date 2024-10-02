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
* @brief �R�D�̖������擾����B
* 
* @return int �R�D�̖����B
*/
int Deck::GetNumCards() const {
	return this->numCards;
}

/*
* @brief �R�D�̖�����ݒ肷��B
* 
* @param int numCards_ �R�D�̖����B
*/
void Deck::SetNumCards(int numCards_) {
	this->numCards = numCards_;
}

/*
* @brief �J�[�h���V���b�t������B
* 
* @details Fisher-Yates�A���S���Y�����g�p���ăV���b�t������B
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
* @brief �R�D������������B
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
* @brief �R�D����J�[�h�������B
* 
* @return Card �������J�[�h�B
*/
Card Deck::Draw() {
	this->numCards--;
	Card* pointer = this->cards[this->numCards];
	this->poolAllocator.Deallocate(pointer);

	return *pointer;
}
