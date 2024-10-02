#include "Card.hpp"

Card::Card() {
	this->suit = Suit::None;
	this->rank = Rank::None;
	this->isFaceUp = true;
}

Card::~Card() {}

/*
* @brief カードのポイントを取得する。
*
* @detail Aの場合は1として扱う。
* @detail J, Q, Kの場合は10として扱う。
* 
* @return int カードのポイント。
*/
int Card::GetPoint() const {
	return std::min(static_cast<int>(this->GetRank()), 10);
}

/*
* @brief カードが表向きであるかを設定する。
*
* @param bool isFaceUp_ カードが表向きであるか。
*/
void Card::SetIsFaceUp(bool isFaceUp_) {
	this->isFaceUp = isFaceUp_;
}

/*
* @brief カードのスートを設定する。
*
* @param Rank rank_ カードのスート。
*/
void Card::SetSuit(Suit suit_) {
	this->suit = suit_;
}

/*
* @brief カードのランクを設定する。
* 
* @param Rank rank_ カードのランク。
*/
void Card::SetRank(Rank rank_) {
	this->rank = rank_;
}

/*
* @brief カードが表向きであるかを取得する。
* 
* @return bool カードが表向きであるか。
*/
bool Card::GetIsFaceUp() const {
	return this->isFaceUp;
}

/*
* @brief カードのスートを取得する。
*
* @return Card::Suit カードのスート。
*/
Card::Suit Card::GetSuit() const {
	return this->suit;
}

/*
* @brief カードのランクを取得する。
* 
* @return Card::Rank カードのポイント。
*/
Card::Rank Card::GetRank() const {
	return this->rank;
}

/*
* @brief カードの文字列表現を取得する。
* 
* @return std::string カードの文字列表現。
*/
std::string Card::ToString() const {
	if (!this->isFaceUp) {
		return "X";
	}

	switch (this->Card::GetRank()) {
	case Rank::ACE:
		return "A";
	case Rank::TEN:
		return "T";
	case Rank::JACK:
		return "J";
	case Rank::QUEEN:
		return "Q";
	case Rank::KING:
		return "K";
	}
	
	return std::to_string(static_cast<int>(this->Card::GetRank()));
}
