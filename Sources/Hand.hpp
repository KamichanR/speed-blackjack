#pragma once

#include <string>
#include "PoolAllocator.hpp"

class Hand {
public:
	Hand();
	~Hand();
	int GetBet() const;						// �x�b�g�z���擾����B
	int GetNumCards() const;				// �J�[�h�̖������擾����B
	int GetPoint() const;					// �n���h�̓_�����擾����B
	bool GetIsBust() const;					// �o�[�X�g���Ă��邩�ǂ������擾����B
	bool GetIsNatural() const;				// �i�`���������ǂ������擾����B
	bool GetIsSoft() const;					// �\�t�g�n���h���ǂ������擾����B
	void AddCard(Card card);				// �J�[�h��ǉ�����B
	void FaceUp(int index);					// �S�ẴJ�[�h��\�����ɂ���B
	void FaceDown(int index);				// �J�[�h�𗠌����ɂ���B
	void SetBet(int bet_);					// �x�b�g�z��ݒ肷��B
	void SetIsSoft(bool isSoft_);			// �\�t�g�n���h���ǂ�����ݒ肷��B
	void SetNumCards(int numCards_);		// �J�[�h�̖�����ݒ肷��B
	void SetPoint(int point_);				// �n���h�̓_����ݒ肷��B
	void Reset();							// �n���h�����Z�b�g����B
	std::string ToString() const;			// �n���h�̕�����\�����擾����B
	constexpr static int MAX_NUM_CARD = 22;	// �ő�̃J�[�h�̖���

private:
	int numCards;										// �J�[�h�̖���
	int bet;											// �x�b�g�z
	int point;											// �n���h�̓_��
	bool isSoft;										// �\�t�g�n���h���ǂ���
	Card* cards[MAX_NUM_CARD];							// �J�[�h�̔z��
	PoolAllocator<Card, MAX_NUM_CARD> poolAllocator;	// �J�[�h�̃v�[���A���P�[�^
};
