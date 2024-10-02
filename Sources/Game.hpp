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
		TITLE,			// タイトル
		DESCRIPTION,	// ゲーム説明
		READY,			// ゲーム開始準備
		BETTING,		// ベットの受付
		PLAYER_TURN,	// プレイヤーのターン
		DEALER_TURN,	// ディーラーのターン
		JUDGEMENT,		// 勝敗判定
		RESULT,			// 結果表示
		GAMECLEAR,		// ゲームクリア
		GAMEOVER,		// ゲームオーバー
		TERMINATE,		// ゲーム終了
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
	constexpr static int NULL_KEY = 0x00;				// 無効なキーの値
	constexpr static int ESCAPE_KEY = 0x1b;				// ESCキーの値
	constexpr static int SPACE_KEY = 0x20;				// スペードキーの値
	constexpr static int ZERO_KEY = 0x30;				// 0キーの値
	constexpr static int NINE_KEY = 0x39;				// 9キーの値
	constexpr static int H_KEY = 0x68;					// Hキーの値
	constexpr static int Q_KEY = 0x71;					// Qキーの値
	constexpr static int S_KEY = 0x73;					// Sキーの値
	constexpr static int PLAYER_INITIAL_POINT = 25;		// プレイヤーの初期点数
	constexpr static int PLAYER_TARGET_POINT = 50;		// プレイヤーの目標点数
	int inputKey;										// 入力されたキーを格納する変数
	std::chrono::system_clock::time_point startTime;	// 開始時刻
	std::chrono::system_clock::time_point endTime;		// 終了時刻
	std::chrono::duration<double> resultTime;			// 経過時間
	State currentState;									// ゲームの状態を格納する変数
	Deck* deck;											// 山札
	Player* player;										// プレイヤー
	Person* dealer;										// ディーラー
};
