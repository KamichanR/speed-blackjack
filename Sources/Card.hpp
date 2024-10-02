#pragma once

#include <algorithm>
#include <string>

/*
* @brief トランプのカードを表すクラス
*/
class Card {
public:
	/*
	* @brief トランプのスートを表す列挙型
	*/
	enum class Suit : int {
		None	= 0,
		SPADE	= 1,
		HEART	= 2,
		DIAMOND	= 3,
		CLUB	= 4,
	};

	/*
	* @brief トランプのランクを表す列挙型
	*/
	enum class Rank : int {
		None	= 0,
		ACE		= 1,
		TWO		= 2,
		THREE	= 3,
		FOUR	= 4,
		FIVE	= 5,
		SIX		= 6,
		SEVEN	= 7,
		EIGHT	= 8,
		NINE	= 9,
		TEN		= 10,
		JACK	= 11,
		QUEEN	= 12,
		KING	= 13,
	};

	Card();
	~Card();
	constexpr static int NUM_SUIT = 4;	// スートの数
	constexpr static int NUM_RANK = 13;	// ランクの数
	int GetPoint() const;				// カードのポイントを取得する。
	void SetIsFaceUp(bool isFaceUp_);	// カードが表向きであるかを設定する。
	void SetSuit(Suit suit_);			// カードのスートを設定する。
	void SetRank(Rank rank_);			// カードのランクを設定する。
	bool GetIsFaceUp() const;			// カードが表向きであるかを取得する。
	Suit GetSuit() const;				// カードのスートを取得する。
	Rank GetRank() const;				// カードのランクを取得する。
	std::string ToString() const;		// カードの文字列表現を取得する。

private:
	Suit suit;		// カードのスート
	Rank rank;		// カードのランク
	bool isFaceUp;	// 表向きであるか
};
