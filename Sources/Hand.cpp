#include "Hand.hpp"

Hand::Hand() {
	for (int i = 0; i < this->MAX_NUM_CARD; i++) {
		this->cards[i] = nullptr;
	}
	this->Reset();
}

Hand::~Hand() {}

/*
* @brief �x�b�g�z���擾����B
*
* @return int �x�b�g�z�B
*/
int Hand::GetBet() const {
	return this->bet;
}

/*
* @brief �J�[�h�̖������擾����B
* 
* @return int �J�[�h�̖����B
*/
int Hand::GetNumCards() const {
	return this->numCards;
}

/*
* @brief �n���h�̓_�����擾����B
*
* @return int �n���h�̓_���B
*/
int Hand::GetPoint() const {
	return this->point;
}

/*
* @brief �o�[�X�g���Ă��邩�ǂ������擾����B
* 
* @return bool �o�[�X�g���Ă��邩�ǂ����B
*/
bool Hand::GetIsBust() const {
	return this->GetPoint() > 21;
}

/*
* @brief �\�t�g�n���h�ł��邩���擾����B
*
* @return bool �\�t�g�n���h�ł��邩�B
*/
bool Hand::GetIsSoft() const {
	return this->isSoft;
}

/*
* @brief �i�`���������ǂ������擾����B
* 
* @return bool �i�`���������ǂ����B
*/
bool Hand::GetIsNatural() const {
	return this->GetNumCards() == 2 && this->GetPoint() == 21;
}

/*
* @brief �J�[�h��ǉ�����B
* 
* @param Card card �ǉ�����J�[�h�B
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
* @brief �J�[�h�𗠌����ɂ���B
* 
* @param int index �������ɂ���J�[�h�̃C���f�b�N�X�B
*/
void Hand::FaceDown(int index) {
	if (index < 0 || index >= this->GetNumCards()) {
		return;
	}
	this->cards[index]->SetIsFaceUp(false);
}

/*
* @brief �J�[�h��\�����ɂ���B
*
* @param int index �\�����ɂ���J�[�h�̃C���f�b�N�X�B
*/
void Hand::FaceUp(int index) {
	if (index < 0 || index >= this->GetNumCards()) {
		return;
	}
	this->cards[index]->SetIsFaceUp(true);
}

/*
* @brief �x�b�g�z��ݒ肷��B
*
* @param int bet_ �x�b�g�z�B
*/
void Hand::SetBet(int bet_) {
	this->bet = bet_;
}

/*
* @brief �\�t�g�n���h���ǂ�����ݒ肷��B
* 
* @param bool isSoft_ �\�t�g�n���h���ǂ����B
*/
void Hand::SetIsSoft(bool isSoft_) {
	this->isSoft = isSoft_;
}

/*
* @brief �J�[�h�̖�����ݒ肷��B
*
* @param int point_ �J�[�h�̖����B
*/
void Hand::SetNumCards(int numCards_) {
	this->numCards = numCards_;
}

/*
* @brief �n���h�̓_����ݒ肷��B
* 
* @param int point_ �n���h�̓_���B
*/
void Hand::SetPoint(int point_) {
	this->point = point_;
}

/*
* @brief �n���h������������B
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
* @brief �n���h�̕�����\�����擾����B
* 
* @return std::string �n���h�̕�����\���B
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
