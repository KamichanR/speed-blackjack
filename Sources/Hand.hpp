#pragma once

#include <string>
#include "PoolAllocator.hpp"

class Hand {
public:
	Hand();
	~Hand();
	int GetBet() const;						// ベット額を取得する。
	int GetNumCards() const;				// カードの枚数を取得する。
	int GetPoint() const;					// ハンドの点数を取得する。
	bool GetIsBust() const;					// バーストしているかどうかを取得する。
	bool GetIsNatural() const;				// ナチュラルかどうかを取得する。
	bool GetIsSoft() const;					// ソフトハンドかどうかを取得する。
	void AddCard(Card card);				// カードを追加する。
	void FaceUp(int index);					// 全てのカードを表向きにする。
	void FaceDown(int index);				// カードを裏向きにする。
	void SetBet(int bet_);					// ベット額を設定する。
	void SetIsSoft(bool isSoft_);			// ソフトハンドかどうかを設定する。
	void SetNumCards(int numCards_);		// カードの枚数を設定する。
	void SetPoint(int point_);				// ハンドの点数を設定する。
	void Reset();							// ハンドをリセットする。
	std::string ToString() const;			// ハンドの文字列表現を取得する。
	constexpr static int MAX_NUM_CARD = 22;	// 最大のカードの枚数

private:
	int numCards;										// カードの枚数
	int bet;											// ベット額
	int point;											// ハンドの点数
	bool isSoft;										// ソフトハンドかどうか
	Card* cards[MAX_NUM_CARD];							// カードの配列
	PoolAllocator<Card, MAX_NUM_CARD> poolAllocator;	// カードのプールアロケータ
};
