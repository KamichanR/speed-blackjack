#include "Person.hpp"

Person::Person() {
	this->hand = new Hand();
}

Person::~Person() {
	delete this->hand;
}

/*
* @brief ����������B
* 
* @detail �n���h�����Z�b�g����B
*/
void Person::Reset() {
	this->GetHand()->Reset();
}

/*
* @brief �n���h�̃|�C���^���擾����B
* 
* @return Hand* �n���h�̃|�C���^�B
*/
Hand* Person::GetHand() const {
	return this->hand;
}
