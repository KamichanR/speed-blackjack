#pragma once

#include <random>
#include "Card.hpp"
#include "PoolAllocator.hpp"

class Deck {
public:
	Deck();
	~Deck();
	int GetNumCards() const;												// カードの枚数を取得する。
	void SetNumCards(int numCards_);										// カードの枚数を設定する。
	void Shuffle();															// デックをシャッフルする。
	void Reset();															// デックをリセットする。
	Card Draw();															// カードを引く。
	constexpr static int NUM_DECK = 8;										// デックの数
	constexpr static int NUM_CARD_PER_DECK = 52;							// デック1つあたりのカードの枚数
	constexpr static int INITIAL_NUM_CARD = NUM_DECK * NUM_CARD_PER_DECK;	// デック分の枚数

private:
	int numCards;															// 残りのカードの枚数
	std::random_device engine;												// 乱数生成エンジン
	Card* cards[INITIAL_NUM_CARD];											// カードのポインタの配列
	PoolAllocator<Card, INITIAL_NUM_CARD> poolAllocator;					// カードのプールアロケータ
};
