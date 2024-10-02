#pragma once

#include <random>
#include "Card.hpp"
#include "PoolAllocator.hpp"

class Deck {
public:
	Deck();
	~Deck();
	int GetNumCards() const;												// �J�[�h�̖������擾����B
	void SetNumCards(int numCards_);										// �J�[�h�̖�����ݒ肷��B
	void Shuffle();															// �f�b�N���V���b�t������B
	void Reset();															// �f�b�N�����Z�b�g����B
	Card Draw();															// �J�[�h�������B
	constexpr static int NUM_DECK = 8;										// �f�b�N�̐�
	constexpr static int NUM_CARD_PER_DECK = 52;							// �f�b�N1������̃J�[�h�̖���
	constexpr static int INITIAL_NUM_CARD = NUM_DECK * NUM_CARD_PER_DECK;	// �f�b�N���̖���

private:
	int numCards;															// �c��̃J�[�h�̖���
	std::random_device engine;												// ���������G���W��
	Card* cards[INITIAL_NUM_CARD];											// �J�[�h�̃|�C���^�̔z��
	PoolAllocator<Card, INITIAL_NUM_CARD> poolAllocator;					// �J�[�h�̃v�[���A���P�[�^
};
