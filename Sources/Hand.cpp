#include "Hand.hpp"

Hand::Hand() {
	for (int i = 0; i < this->MAX_NUM_CARD; i++) {
		this->cards[i] = nullptr;
	}
	this->Reset();
}

Hand::~Hand() {}

/*
* @brief ベット額を取得する。
*
* @return int ベット額。
*/
int Hand::GetBet() const {
	return this->bet;
}

/*
* @brief カードの枚数を取得する。
* 
* @return int カードの枚数。
*/
int Hand::GetNumCards() const {
	return this->numCards;
}

/*
* @brief ハンドの点数を取得する。
*
* @return int ハンドの点数。
*/
int Hand::GetPoint() const {
	return this->point;
}

/*
* @brief バーストしているかどうかを取得する。
* 
* @return bool バーストしているかどうか。
*/
bool Hand::GetIsBust() const {
	return this->GetPoint() > 21;
}

/*
* @brief ソフトハンドであるかを取得する。
*
* @return bool ソフトハンドであるか。
*/
bool Hand::GetIsSoft() const {
	return this->isSoft;
}

/*
* @brief ナチュラルかどうかを取得する。
* 
* @return bool ナチュラルかどうか。
*/
bool Hand::GetIsNatural() const {
	return this->GetNumCards() == 2 && this->GetPoint() == 21;
}

/*
* @brief カードを追加する。
* 
* @param Card card 追加するカード。
*/
void Hand::AddCard(Card card) {
	int i = this->GetNumCards();

	this->cards[i] = this->poolAllocator.Allocate();
	if (this->cards[i] == nullptr) {
		return;
	}
	this->cards[i]->SetSuit(card.GetSuit());
	this->cards[i]->SetRank(card.GetRank());
	this->SetNumCards(i + 1);

	int point_ = this->GetPoint() + card.GetPoint();
	bool isAce = card.GetRank() == Card::Rank::ACE;
	if (isAce && point_ <= 11) {
		point_ += 10;
		this->SetIsSoft(true);
	}
	else if (this->GetIsSoft() && point_ > 21) {
		point_ -= 10;
		this->SetIsSoft(false);
	}
	this->SetPoint(point_);
}

/*
* @brief カードを裏向きにする。
* 
* @param int index 裏向きにするカードのインデックス。
*/
void Hand::FaceDown(int index) {
	if (index < 0 || index >= this->GetNumCards()) {
		return;
	}
	this->cards[index]->SetIsFaceUp(false);
}

/*
* @brief カードを表向きにする。
*
* @param int index 表向きにするカードのインデックス。
*/
void Hand::FaceUp(int index) {
	if (index < 0 || index >= this->GetNumCards()) {
		return;
	}
	this->cards[index]->SetIsFaceUp(true);
}

/*
* @brief ベット額を設定する。
*
* @param int bet_ ベット額。
*/
void Hand::SetBet(int bet_) {
	this->bet = bet_;
}

/*
* @brief ソフトハンドかどうかを設定する。
* 
* @param bool isSoft_ ソフトハンドかどうか。
*/
void Hand::SetIsSoft(bool isSoft_) {
	this->isSoft = isSoft_;
}

/*
* @brief カードの枚数を設定する。
*
* @param int point_ カードの枚数。
*/
void Hand::SetNumCards(int numCards_) {
	this->numCards = numCards_;
}

/*
* @brief ハンドの点数を設定する。
* 
* @param int point_ ハンドの点数。
*/
void Hand::SetPoint(int point_) {
	this->point = point_;
}

/*
* @brief ハンドを初期化する。
*/
void Hand::Reset() {
	this->SetBet(0);
	this->SetIsSoft(false);
	this->SetNumCards(0);
	this->SetPoint(0);
	for (int i = 0; i < this->MAX_NUM_CARD; i++) {
		this->poolAllocator.Deallocate(this->cards[i]);
		this->cards[i] = nullptr;
	}
}

/*
* @brief ハンドの文字列表現を取得する。
* 
* @return std::string ハンドの文字列表現。
*/
std::string Hand::ToString() const {
	std::string str = "Cards:";
	for (int i = 0; i < this->GetNumCards(); i++) {
		str += " ";
		str += this->cards[i]->ToString();
	}

	for (int i = 0; i < this->GetNumCards(); i++) {
		if (!this->cards[i]->GetIsFaceUp()) {
			return str;
		}
	}

	str += "\n";
	str += "Point: " + std::to_string(this->GetPoint());
	return str;
}
