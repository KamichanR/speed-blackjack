#pragma once

#include "Person.hpp"

class Player : public Person {
public:
	Player();
	int GetScore() const;			// プレイヤーの点数を取得する。
	void AddScore(int score_);		// プレイヤーの点数を加算する。
	void Bet(int bet);				// プレイヤーがベットする。
	void Lose();					// 敗北時の処理をする。
	void NaturalWin();				// ナチュラル勝利時の処理をする。
	void SetScore(int score_);		// プレイヤーの点数を設定する。
	void SubtractScore(int score_);	// プレイヤーの点数を減算する。
	void Tie();						// 引き分け時の処理をする。
	void Reset();					// 初期化する。
	void Win();						// 勝利時の処理をする。

private:
	int score;
};
