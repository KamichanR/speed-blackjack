#include "Player.hpp"

Player::Player() : Person() {
	this->score = 0;
}

/*
* @brief プレイヤーの点数を取得する。
* 
* @return int プレイヤーの点数。
*/
int Player::GetScore() const {
	return this->score;
}

/*
* @brief プレイヤーの点数を加算する。
* 
* @param int score_ 加算する点数。
*/
void Player::AddScore(int score_) {
	this->score += score_;
}

/*
* @brief プレイヤーがベットする。
* 
* @param int bet ベット額。
*/
void Player::Bet(int bet) {
	this->SubtractScore(bet);
	this->GetHand()->SetBet(bet);
}

/*
* @brief 敗北時の処理をする。
*/
void Player::Lose() {
	this->GetHand()->SetBet(0);
}

/*
* @brief ナチュラル勝利時の処理をする。
*/
void Player::NaturalWin() {
	this->AddScore(int(this->GetHand()->GetBet() * 2.5));
	this->GetHand()->SetBet(0);
}

/*
* @brief プレイヤーの点数を設定する。
* 
* @param int score_ プレイヤーの点数。
*/
void Player::SetScore(int score_) {
	this->score = score_;
}

/*
* @brief プレイヤーの点数を減算する。
* 
* @param int score_ 減算する点数。
*/
void Player::SubtractScore(int score_) {
	this->score -= score_;
}

/*
* @brief 引き分け時の処理をする。
*/
void Player::Tie() {
	this->AddScore(this->GetHand()->GetBet());
	this->GetHand()->SetBet(0);
}

/*
* @brief 初期化する。
*/
void Player::Reset() {
	this->Person::Reset();
	this->SetScore(0);
}

/*
* @brief 勝利時の処理をする。
*/
void Player::Win() {
	this->AddScore(this->GetHand()->GetBet() * 2);
	this->GetHand()->SetBet(0);
}
