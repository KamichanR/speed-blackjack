#include "Person.hpp"

Person::Person() {
	this->hand = new Hand();
}

Person::~Person() {
	delete this->hand;
}

/*
* @brief 初期化する。
* 
* @detail ハンドをリセットする。
*/
void Person::Reset() {
	this->GetHand()->Reset();
}

/*
* @brief ハンドのポインタを取得する。
* 
* @return Hand* ハンドのポインタ。
*/
Hand* Person::GetHand() const {
	return this->hand;
}
