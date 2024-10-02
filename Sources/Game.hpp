#pragma once

#include <chrono>
#include <conio.h>
#include <iostream>
#include <string>
#include "Deck.hpp"
#include "Person.hpp"
#include "Player.hpp"

class Game {
public:
	enum class State {
		TITLE,			// �^�C�g��
		DESCRIPTION,	// �Q�[������
		READY,			// �Q�[���J�n����
		BETTING,		// �x�b�g�̎�t
		PLAYER_TURN,	// �v���C���[�̃^�[��
		DEALER_TURN,	// �f�B�[���[�̃^�[��
		JUDGEMENT,		// ���s����
		RESULT,			// ���ʕ\��
		GAMECLEAR,		// �Q�[���N���A
		GAMEOVER,		// �Q�[���I�[�o�[
		TERMINATE,		// �Q�[���I��
	};

	Game();
	~Game();
	void Display() const;									// 
	void DisplayClear() const;								//
	void DisplayLine(std::string text) const;				//
	void DisplayPadding(int numLine) const;					//
	void KeyInput();										//
	void Process();											//
	void Run();												//
	void SetTime();											//
	std::chrono::duration<double> GetResultTime() const;	//
private:
	constexpr static int NULL_KEY = 0x00;				// �����ȃL�[�̒l
	constexpr static int ESCAPE_KEY = 0x1b;				// ESC�L�[�̒l
	constexpr static int SPACE_KEY = 0x20;				// �X�y�[�h�L�[�̒l
	constexpr static int ZERO_KEY = 0x30;				// 0�L�[�̒l
	constexpr static int NINE_KEY = 0x39;				// 9�L�[�̒l
	constexpr static int H_KEY = 0x68;					// H�L�[�̒l
	constexpr static int Q_KEY = 0x71;					// Q�L�[�̒l
	constexpr static int S_KEY = 0x73;					// S�L�[�̒l
	constexpr static int PLAYER_INITIAL_POINT = 25;		// �v���C���[�̏����_��
	constexpr static int PLAYER_TARGET_POINT = 50;		// �v���C���[�̖ڕW�_��
	int inputKey;										// ���͂��ꂽ�L�[���i�[����ϐ�
	std::chrono::system_clock::time_point startTime;	// �J�n����
	std::chrono::system_clock::time_point endTime;		// �I������
	std::chrono::duration<double> resultTime;			// �o�ߎ���
	State currentState;									// �Q�[���̏�Ԃ��i�[����ϐ�
	Deck* deck;											// �R�D
	Player* player;										// �v���C���[
	Person* dealer;										// �f�B�[���[
};
