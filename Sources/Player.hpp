#pragma once

#include "Person.hpp"

class Player : public Person {
public:
	Player();
	int GetScore() const;			// �v���C���[�̓_�����擾����B
	void AddScore(int score_);		// �v���C���[�̓_�������Z����B
	void Bet(int bet);				// �v���C���[���x�b�g����B
	void Lose();					// �s�k���̏���������B
	void NaturalWin();				// �i�`�������������̏���������B
	void SetScore(int score_);		// �v���C���[�̓_����ݒ肷��B
	void SubtractScore(int score_);	// �v���C���[�̓_�������Z����B
	void Tie();						// �����������̏���������B
	void Reset();					// ����������B
	void Win();						// �������̏���������B

private:
	int score;
};
