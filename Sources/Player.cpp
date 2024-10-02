#include "Player.hpp"

Player::Player() : Person() {
	this->score = 0;
}

/*
* @brief �v���C���[�̓_�����擾����B
* 
* @return int �v���C���[�̓_���B
*/
int Player::GetScore() const {
	return this->score;
}

/*
* @brief �v���C���[�̓_�������Z����B
* 
* @param int score_ ���Z����_���B
*/
void Player::AddScore(int score_) {
	this->score += score_;
}

/*
* @brief �v���C���[���x�b�g����B
* 
* @param int bet �x�b�g�z�B
*/
void Player::Bet(int bet) {
	this->SubtractScore(bet);
	this->GetHand()->SetBet(bet);
}

/*
* @brief �s�k���̏���������B
*/
void Player::Lose() {
	this->GetHand()->SetBet(0);
}

/*
* @brief �i�`�������������̏���������B
*/
void Player::NaturalWin() {
	this->AddScore(int(this->GetHand()->GetBet() * 2.5));
	this->GetHand()->SetBet(0);
}

/*
* @brief �v���C���[�̓_����ݒ肷��B
* 
* @param int score_ �v���C���[�̓_���B
*/
void Player::SetScore(int score_) {
	this->score = score_;
}

/*
* @brief �v���C���[�̓_�������Z����B
* 
* @param int score_ ���Z����_���B
*/
void Player::SubtractScore(int score_) {
	this->score -= score_;
}

/*
* @brief �����������̏���������B
*/
void Player::Tie() {
	this->AddScore(this->GetHand()->GetBet());
	this->GetHand()->SetBet(0);
}

/*
* @brief ����������B
*/
void Player::Reset() {
	this->Person::Reset();
	this->SetScore(0);
}

/*
* @brief �������̏���������B
*/
void Player::Win() {
	this->AddScore(this->GetHand()->GetBet() * 2);
	this->GetHand()->SetBet(0);
}
