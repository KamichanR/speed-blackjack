#include "Card.hpp"

Card::Card() {
	this->suit = Suit::None;
	this->rank = Rank::None;
	this->isFaceUp = true;
}

Card::~Card() {}

/*
* @brief �J�[�h�̃|�C���g���擾����B
*
* @detail A�̏ꍇ��1�Ƃ��Ĉ����B
* @detail J, Q, K�̏ꍇ��10�Ƃ��Ĉ����B
* 
* @return int �J�[�h�̃|�C���g�B
*/
int Card::GetPoint() const {
	return std::min(static_cast<int>(this->GetRank()), 10);
}

/*
* @brief �J�[�h���\�����ł��邩��ݒ肷��B
*
* @param bool isFaceUp_ �J�[�h���\�����ł��邩�B
*/
void Card::SetIsFaceUp(bool isFaceUp_) {
	this->isFaceUp = isFaceUp_;
}

/*
* @brief �J�[�h�̃X�[�g��ݒ肷��B
*
* @param Rank rank_ �J�[�h�̃X�[�g�B
*/
void Card::SetSuit(Suit suit_) {
	this->suit = suit_;
}

/*
* @brief �J�[�h�̃����N��ݒ肷��B
* 
* @param Rank rank_ �J�[�h�̃����N�B
*/
void Card::SetRank(Rank rank_) {
	this->rank = rank_;
}

/*
* @brief �J�[�h���\�����ł��邩���擾����B
* 
* @return bool �J�[�h���\�����ł��邩�B
*/
bool Card::GetIsFaceUp() const {
	return this->isFaceUp;
}

/*
* @brief �J�[�h�̃X�[�g���擾����B
*
* @return Card::Suit �J�[�h�̃X�[�g�B
*/
Card::Suit Card::GetSuit() const {
	return this->suit;
}

/*
* @brief �J�[�h�̃����N���擾����B
* 
* @return Card::Rank �J�[�h�̃|�C���g�B
*/
Card::Rank Card::GetRank() const {
	return this->rank;
}

/*
* @brief �J�[�h�̕�����\�����擾����B
* 
* @return std::string �J�[�h�̕�����\���B
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
