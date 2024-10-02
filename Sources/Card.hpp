#pragma once

#include <algorithm>
#include <string>

/*
* @brief �g�����v�̃J�[�h��\���N���X
*/
class Card {
public:
	/*
	* @brief �g�����v�̃X�[�g��\���񋓌^
	*/
	enum class Suit : int {
		None	= 0,
		SPADE	= 1,
		HEART	= 2,
		DIAMOND	= 3,
		CLUB	= 4,
	};

	/*
	* @brief �g�����v�̃����N��\���񋓌^
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
	constexpr static int NUM_SUIT = 4;	// �X�[�g�̐�
	constexpr static int NUM_RANK = 13;	// �����N�̐�
	int GetPoint() const;				// �J�[�h�̃|�C���g���擾����B
	void SetIsFaceUp(bool isFaceUp_);	// �J�[�h���\�����ł��邩��ݒ肷��B
	void SetSuit(Suit suit_);			// �J�[�h�̃X�[�g��ݒ肷��B
	void SetRank(Rank rank_);			// �J�[�h�̃����N��ݒ肷��B
	bool GetIsFaceUp() const;			// �J�[�h���\�����ł��邩���擾����B
	Suit GetSuit() const;				// �J�[�h�̃X�[�g���擾����B
	Rank GetRank() const;				// �J�[�h�̃����N���擾����B
	std::string ToString() const;		// �J�[�h�̕�����\�����擾����B

private:
	Suit suit;		// �J�[�h�̃X�[�g
	Rank rank;		// �J�[�h�̃����N
	bool isFaceUp;	// �\�����ł��邩
};
