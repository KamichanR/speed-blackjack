#include "Game.hpp"

Game::Game() {
	this->inputKey = 0;
	this->currentState = State::TITLE;
	this->deck = new Deck();
	this->player = new Player();
	this->dealer = new Person();
	this->startTime = std::chrono::system_clock::now();
	this->endTime = std::chrono::system_clock::now();
	this->resultTime = std::chrono::duration<double>(0.0);
}

Game::~Game() {
	delete this->deck;
	delete this->player;
	delete this->dealer;
}

/*
* @brief �Q�[���̏�Ԃɉ�������ʂ̕`�������B
*/
void Game::Display() const {
	this->DisplayClear();

	switch (this->currentState) {
	case State::TITLE:
		this->DisplayPadding(2);
		this->DisplayLine("*************************************************************************************************************************************");
		this->DisplayPadding(2);
		this->DisplayLine(" ######  ########  ######## ######## ########     ########  ##          ###     ######  ##    ##       ##    ###     ######  ##    ##");
		this->DisplayLine("##    ## ##     ## ##       ##       ##     ##    ##     ## ##         ## ##   ##    ## ##   ##        ##   ## ##   ##    ## ##   ## ");
		this->DisplayLine("##       ##     ## ##       ##       ##     ##    ##     ## ##        ##   ##  ##       ##  ##         ##  ##   ##  ##       ##  ##  ");
		this->DisplayLine(" ######  ########  ######   ######   ##     ##    ########  ##       ##     ## ##       #####          ## ##     ## ##       #####   ");
		this->DisplayLine("      ## ##        ##       ##       ##     ##    ##     ## ##       ######### ##       ##  ##   ##    ## ######### ##       ##  ##  ");
		this->DisplayLine("##    ## ##        ##       ##       ##     ##    ##     ## ##       ##     ## ##    ## ##   ##  ##    ## ##     ## ##    ## ##   ## ");
		this->DisplayLine(" ######  ##        ######## ######## ########     ########  ######## ##     ##  ######  ##    ##  ######  ##     ##  ######  ##    ##");
		this->DisplayPadding(2);
		this->DisplayLine("*************************************************************************************************************************************");
		this->DisplayPadding(2);
		this->DisplayPadding(11);
		this->DisplayLine("                                                       Press [Space] to Start.                                                       ");
		break;
	case State::DESCRIPTION:
		this->DisplayPadding(2);
		this->DisplayLine("*************************************************************************************************************************************");
		this->DisplayPadding(2);
		this->DisplayLine("                    ########  ########  ######   ######  ########  #### ########  ######## ####  #######  ##    ##                   ");
		this->DisplayLine("                    ##     ## ##       ##    ## ##    ## ##     ##  ##  ##     ##    ##     ##  ##     ## ###   ##                   ");
		this->DisplayLine("                    ##     ## ##       ##       ##       ##     ##  ##  ##     ##    ##     ##  ##     ## ####  ##                   ");
		this->DisplayLine("                    ##     ## ######    ######  ##       ########   ##  ########     ##     ##  ##     ## ## ## ##                   ");
		this->DisplayLine("                    ##     ## ##             ## ##       ##   ##    ##  ##           ##     ##  ##     ## ##  ####                   ");
		this->DisplayLine("                    ##     ## ##       ##    ## ##    ## ##    ##   ##  ##           ##     ##  ##     ## ##   ###                   ");
		this->DisplayLine("                    ########  ########  ######   ######  ##     ## #### ##           ##    ####  #######  ##    ##                   ");
		this->DisplayPadding(2);
		this->DisplayLine("*************************************************************************************************************************************");
		this->DisplayPadding(2);
		this->DisplayLine(" * This game is a \"Time Attack\" Blackjack where you aim to reach a target score.");
		this->DisplayLine(" * The time it takes to increase your points to the target score is measured.");
		this->DisplayLine(" * The initial score is 25, and the target score is 50.");
		this->DisplayLine(" * Players can choose to \"Hit\" or \"Stand\".");
		this->DisplayLine(" * The dealer will \"Hit\" until reaching at least 17 points.");
		this->DisplayLine(" * The game is over if the player's points drop to 0 or below, or if the remaining cards in the deck are less than 20.");
		this->DisplayLine(" * The minimum bet is 1 point, and the maximum bet is 10 points.");
		this->DisplayPadding(4);
		this->DisplayLine("                                                        Press [Space] to Next.                                                       ");
		this->DisplayLine("                                                    Press [Q] to Return to Title.                                                    ");
		break;
	case State::READY:
		this->DisplayPadding(2);
		this->DisplayLine("*************************************************************************************************************************************");
		this->DisplayPadding(2);
		this->DisplayLine("        ###    ########  ########    ##    ##  #######  ##     ##    ########  ########    ###    ########  ##    ##     #######     ");
		this->DisplayLine("       ## ##   ##     ## ##           ##  ##  ##     ## ##     ##    ##     ## ##         ## ##   ##     ##  ##  ##     ##     ##    ");
		this->DisplayLine("      ##   ##  ##     ## ##            ####   ##     ## ##     ##    ##     ## ##        ##   ##  ##     ##   ####            ##     ");
		this->DisplayLine("     ##     ## ########  ######         ##    ##     ## ##     ##    ########  ######   ##     ## ##     ##    ##           ###      ");
		this->DisplayLine("     ######### ##   ##   ##             ##    ##     ## ##     ##    ##   ##   ##       ######### ##     ##    ##          ##        ");
		this->DisplayLine("     ##     ## ##    ##  ##             ##    ##     ## ##     ##    ##    ##  ##       ##     ## ##     ##    ##                    ");
		this->DisplayLine("     ##     ## ##     ## ########       ##     #######   #######     ##     ## ######## ##     ## ########     ##          ##        ");
		this->DisplayPadding(2);
		this->DisplayLine("*************************************************************************************************************************************");
		this->DisplayPadding(2);
		this->DisplayPadding(11);
		this->DisplayLine("                                                       Press [Space] to Start.                                                       ");
		this->DisplayLine("                                                 Press [Q] to Return to Description.                                                 ");
		break;
	case State::BETTING:
		this->DisplayPadding(2);
		this->DisplayLine("*************************************************************************************************************************************");
		this->DisplayPadding(2);
		this->DisplayLine("                  ########  ######## ######## ######## #### ##    ##  ######      ######## #### ##     ## ########                   ");
		this->DisplayLine("                  ##     ## ##          ##       ##     ##  ###   ## ##    ##        ##     ##  ###   ### ##                         ");
		this->DisplayLine("                  ##     ## ##          ##       ##     ##  ####  ## ##              ##     ##  #### #### ##                         ");
		this->DisplayLine("                  ########  ######      ##       ##     ##  ## ## ## ##   ####       ##     ##  ## ### ## ######                     ");
		this->DisplayLine("                  ##     ## ##          ##       ##     ##  ##  #### ##    ##        ##     ##  ##     ## ##                         ");
		this->DisplayLine("                  ##     ## ##          ##       ##     ##  ##   ### ##    ##        ##     ##  ##     ## ##                         ");
		this->DisplayLine("                  ########  ########    ##       ##    #### ##    ##  ######         ##    #### ##     ## ########                   ");
		this->DisplayPadding(2);
		this->DisplayLine("*************************************************************************************************************************************");
		this->DisplayPadding(2);
		this->DisplayLine("* [1]:  1 Point ");
		this->DisplayLine("* [2]:  2 Points");
		this->DisplayLine("        :       ");
		this->DisplayLine("* [9]:  9 Points");
		this->DisplayLine("* [0]: 10 Points");
		this->DisplayPadding(6);
		this->DisplayLine("                                              Press the Number Button [0] ~ [9] to Bet.                                              ");
		break;
	case State::PLAYER_TURN:
		this->DisplayPadding(2);
		this->DisplayLine("*************************************************************************************************************************************");
		this->DisplayPadding(2);
		this->DisplayLine("                  ########  ##          ###    ##    ## ######## ########     ######## ##     ## ########  ##    ##                  ");
		this->DisplayLine("                  ##     ## ##         ## ##    ##  ##  ##       ##     ##       ##    ##     ## ##     ## ###   ##                  ");
		this->DisplayLine("                  ##     ## ##        ##   ##    ####   ##       ##     ##       ##    ##     ## ##     ## ####  ##                  ");
		this->DisplayLine("                  ########  ##       ##     ##    ##    ######   ########        ##    ##     ## ########  ## ## ##                  ");
		this->DisplayLine("                  ##        ##       #########    ##    ##       ##   ##         ##    ##     ## ##   ##   ##  ####                  ");
		this->DisplayLine("                  ##        ##       ##     ##    ##    ##       ##    ##        ##    ##     ## ##    ##  ##   ###                  ");
		this->DisplayLine("                  ##        ######## ##     ##    ##    ######## ##     ##       ##     #######  ##     ## ##    ##                  ");
		this->DisplayPadding(2);
		this->DisplayLine("*************************************************************************************************************************************");
		this->DisplayPadding(2);
		this->DisplayLine("Player");
		this->DisplayLine(this->player->GetHand()->ToString());
		this->DisplayPadding(1);
		this->DisplayLine("Dealer");
		this->DisplayLine(this->dealer->GetHand()->ToString());
		this->DisplayPadding(1);
		this->DisplayLine("Card Remaining : " + std::to_string(this->deck->GetNumCards()));
		this->DisplayLine("Score          : " + std::to_string(this->player->GetScore()));
		this->DisplayLine("Bet            : " + std::to_string(this->player->GetHand()->GetBet()));
		this->DisplayPadding(1);
		this->DisplayLine("                                                          Press [H] to Hit.                                                          ");
		this->DisplayLine("                                                         Press [S] to Stand.                                                         ");
		break;
	case State::RESULT:
		this->DisplayPadding(2);
		this->DisplayLine("*************************************************************************************************************************************");
		this->DisplayPadding(2);
		this->DisplayLine("                                       ########  ########  ######  ##     ## ##       ########                                       ");
		this->DisplayLine("                                       ##     ## ##       ##    ## ##     ## ##          ##                                          ");
		this->DisplayLine("                                       ##     ## ##       ##       ##     ## ##          ##                                          ");
		this->DisplayLine("                                       ########  ######    ######  ##     ## ##          ##                                          ");
		this->DisplayLine("                                       ##   ##   ##             ## ##     ## ##          ##                                          ");
		this->DisplayLine("                                       ##    ##  ##       ##    ## ##     ## ##          ##                                          ");
		this->DisplayLine("                                       ##     ## ########  ######   #######  ########    ##                                          ");
		this->DisplayPadding(2);
		this->DisplayLine("*************************************************************************************************************************************");
		this->DisplayPadding(2);
		this->DisplayLine("Player");
		this->DisplayLine(this->player->GetHand()->ToString());
		this->DisplayPadding(1);
		this->DisplayLine("Dealer");
		this->DisplayLine(this->dealer->GetHand()->ToString());
		this->DisplayPadding(1);
		this->DisplayLine("Card Remaining : " + std::to_string(this->deck->GetNumCards()));
		this->DisplayLine("Score : " + std::to_string(this->player->GetScore()));
		this->DisplayPadding(1);
		this->DisplayLine("                                                          Press [Space] to Next.                                                      ");
		break;
	case State::GAMECLEAR:
		this->DisplayPadding(2);
		this->DisplayLine("*************************************************************************************************************************************");
		this->DisplayPadding(2);
		this->DisplayLine("                   ######      ###    ##     ## ########     ######  ##       ########    ###    ########     ####                   ");
		this->DisplayLine("                  ##    ##    ## ##   ###   ### ##          ##    ## ##       ##         ## ##   ##     ##    ####                   ");
		this->DisplayLine("                  ##         ##   ##  #### #### ##          ##       ##       ##        ##   ##  ##     ##    ####                   ");
		this->DisplayLine("                  ##   #### ##     ## ## ### ## ######      ##       ##       ######   ##     ## ########      ##                    ");
		this->DisplayLine("                  ##    ##  ######### ##     ## ##          ##       ##       ##       ######### ##   ##                             ");
		this->DisplayLine("                  ##    ##  ##     ## ##     ## ##          ##    ## ##       ##       ##     ## ##    ##     ####                   ");
		this->DisplayLine("                   ######   ##     ## ##     ## ########     ######  ######## ######## ##     ## ##     ##    ####                   ");
		this->DisplayPadding(2);
		this->DisplayLine("*************************************************************************************************************************************");
		this->DisplayPadding(2);
		this->DisplayLine("Time  : " + std::to_string(this->GetResultTime().count()) + " sec");
		this->DisplayLine("Score : " + std::to_string(this->player->GetScore()));
		this->DisplayPadding(9);
		this->DisplayLine("                                                             Press [Space]                                                           ");
		break;
	case State::GAMEOVER:
		this->DisplayPadding(2);
		this->DisplayLine("*************************************************************************************************************************************");
		this->DisplayPadding(2);
		this->DisplayLine("                    ######      ###    ##     ## ########     #######  ##     ## ######## ########                                   ");
		this->DisplayLine("                   ##    ##    ## ##   ###   ### ##          ##     ## ##     ## ##       ##     ##                                  ");
		this->DisplayLine("                   ##         ##   ##  #### #### ##          ##     ## ##     ## ##       ##     ##                                  ");
		this->DisplayLine("                   ##   #### ##     ## ## ### ## ######      ##     ## ##     ## ######   ########                                   ");
		this->DisplayLine("                   ##    ##  ######### ##     ## ##          ##     ##  ##   ##  ##       ##   ##                                    ");
		this->DisplayLine("                   ##    ##  ##     ## ##     ## ##          ##     ##   ## ##   ##       ##    ##     ### ### ###                   ");
		this->DisplayLine("                    ######   ##     ## ##     ## ########     #######     ###    ######## ##     ##    ### ### ###                   ");
		this->DisplayPadding(2);
		this->DisplayLine("*************************************************************************************************************************************");
		this->DisplayPadding(2);
		this->DisplayLine("Time  : " + std::to_string(this->GetResultTime().count()) + " sec");
		this->DisplayLine("Score : " + std::to_string(this->player->GetScore()));
		this->DisplayPadding(9);
		this->DisplayLine("                                                             Press [Space]                                                           ");
		break;
	}
}

/*
* @brief ��ʂ��N���A����B
*/
void Game::DisplayClear() const {
	std::system("cls");
}

/*
* @brief ��ʂɕ������1�s�\������B
* @param std::string text �\�����镶����B
*/
void Game::DisplayLine(std::string text) const {
	std::cout << text << std::endl;
}

/*
* @brief ��ʂɋ󔒍s��\������B
* @param int numLine �\������󔒍s�̐��B

*/
void Game::DisplayPadding(int numLine = 1) const {
	for (int i = 0; i < numLine; i++) {
		std::cout << std::endl;
	}
}

/*
* @brief �L�[���͂��󂯕t����B
* 
* @details ���݂̏�Ԃɉ����ėL���ȃL�[���͂ł��邩�𔻒肷��B
* @details �L���ȃL�[���͂ł���΂��̃L�[��Ԃ��B
*/
void Game::KeyInput() {
	int key = this->NULL_KEY;
	bool isValidKey = false;

	// �L���ȃL�[�܂���ESC�L�[���������܂Ń��[�v����B
	while (!isValidKey) {
		key = _getch();	// �L�[���͂��󂯕t����B

		// ESC�L�[�͏�ɗL���ł���B
		if (key == this->ESCAPE_KEY) {
			isValidKey = true;
			continue;
		}

		switch (currentState) {
		case State::TITLE:
		case State::RESULT:
		case State::GAMECLEAR:
		case State::GAMEOVER:
			if (key == this->SPACE_KEY) {
				isValidKey = true;
			}
			break;
		case State::DESCRIPTION:
		case State::READY:
			if (key == this->SPACE_KEY || key == this->Q_KEY) {
				isValidKey = true;
			}
			break;
		case State::BETTING:
			if (key >= this->ZERO_KEY && key <= this->NINE_KEY) {
				isValidKey = true;
			}
			break;
		case State::PLAYER_TURN:
			if (key == this->H_KEY || key == this->S_KEY) {
				isValidKey = true;
			}
			break;
		}
	}

	this->inputKey = key;
}

/*
* @brief �Q�[���̏�Ԃɉ��������������s����B
* 
* @details ��ɁA�L�[���͂ɉ����ăQ�[���̏�Ԃ�J�ڂ���B
* @details ���̑��A��ԑJ�ڑO�ɂ��ׂ����������s����B
*/
void Game::Process() {
	if (this->inputKey == this->ESCAPE_KEY) {
		this->currentState = State::TERMINATE;
		return;
	}

	switch (this->currentState) {
	case State::TITLE:
		if (this->inputKey == this->SPACE_KEY) {
			this->currentState = State::DESCRIPTION;
		}
		break;
	case State::DESCRIPTION:
		if (this->inputKey == this->SPACE_KEY) {
			this->currentState = State::READY;
		}
		else if (this->inputKey == this->Q_KEY) {
			this->currentState = State::TITLE;
		}
		break;
	case State::READY:
		if (this->inputKey == this->SPACE_KEY) {
			this->deck->Reset();
			this->player->Reset();
			this->player->SetScore(this->PLAYER_INITIAL_POINT);
			this->dealer->Reset();
			this->SetTime();

			this->currentState = State::BETTING;
		}
		else if (this->inputKey == this->Q_KEY) {
			this->currentState = State::DESCRIPTION;
		}
		break;
	case State::BETTING:
		// �x�b�g�z��ݒ肷��B
		if (this->inputKey == this->ZERO_KEY) {
			this->player->Bet(10);
		}
		else {
			this->player->Bet(this->inputKey - this->ZERO_KEY);
		}

		// �v���C���[�ƃf�B�[���[�ɃJ�[�h��2�����z��B
		this->player->GetHand()->AddCard(this->deck->Draw());
		this->dealer->GetHand()->AddCard(this->deck->Draw());
		this->player->GetHand()->AddCard(this->deck->Draw());
		this->dealer->GetHand()->AddCard(this->deck->Draw());

		// �f�B�[���[��2���ڂ̃J�[�h�𗠌����ɂ���B
		this->dealer->GetHand()->FaceDown(1);

		this->currentState = State::PLAYER_TURN;

		break;
	case State::PLAYER_TURN:
		if (this->inputKey == this->H_KEY) {
			this->player->GetHand()->AddCard(this->deck->Draw());
		}

		if (this->inputKey == this->H_KEY && this->player->GetHand()->GetPoint() < 21) {
			break;
		}
		
		// �v���C���[���X�^���h�܂��̓o�[�X�g�����ꍇ�A�f�B�[���[�̃^�[���Ɉڍs����B
		this->currentState = State::DEALER_TURN;
	case State::DEALER_TURN:
		// �f�B�[���[��2���ڂ̃J�[�h��\�����ɂ���B
		this->dealer->GetHand()->FaceUp(1);

		// �f�B�[���[��17�_�ȏ�ɂȂ�܂ŃJ�[�h�������B
		while (this->dealer->GetHand()->GetPoint() < 17) {
			this->dealer->GetHand()->AddCard(this->deck->Draw());
		}

		// ���̂܂܏��s����Ɉڍs����B
		this->currentState = State::JUDGEMENT;
	case State::JUDGEMENT:
		// �v���C���[���o�[�X�g���Ă���ꍇ�A�f�B�[���[�̏����B
		if (this->player->GetHand()->GetIsBust()) {
			this->player->Lose();
		}
		// �v���C���[���i�`�������̏ꍇ
		else if (this->player->GetHand()->GetIsNatural()) {
			if (this->dealer->GetHand()->GetIsNatural()) {
				this->player->Tie();
			}
			else {
				this->player->NaturalWin();
			}
		}
		// �f�B�[���[���o�[�X�g���Ă���ꍇ�A�v���C���[�̏����B
		else if (this->dealer->GetHand()->GetIsBust()) {
			this->player->Win();
		}
		// �v���C���[�̓_�����e�B�[���[�̓_�����傫���ꍇ�A�v���C���[�̏����B
		else if (this->player->GetHand()->GetPoint() > this->dealer->GetHand()->GetPoint()) {
			this->player->Win();
		}
		// �v���C���[�̓_�����f�B�[���[�̓_���Ɠ����ꍇ�A���������B
		else if (this->player->GetHand()->GetPoint() == this->dealer->GetHand()->GetPoint()) {
			this->player->Tie();
		}
		// �v���C���[�̓_�����f�B�[���[�̓_����菬�����ꍇ�A�v���C���[�̕����B
		else if (this->player->GetHand()->GetPoint() < this->dealer->GetHand()->GetPoint()) {
			this->player->Lose();
		}

		// ���̂܂܌��ʕ\���Ɉڍs����B
		this->currentState = State::RESULT;
	case State::RESULT:
		if (this->inputKey != this->SPACE_KEY) {
			break;
		}

		this->player->GetHand()->Reset();
		this->dealer->GetHand()->Reset();

		if (this->player->GetScore() >= this->PLAYER_TARGET_POINT) {
			this->SetTime();
			this->currentState = State::GAMECLEAR;
		}
		else if (this->player->GetScore() <= 0 || this->deck->GetNumCards() < 20) {
			this->SetTime();
			this->currentState = State::GAMEOVER;
		}
		else {
			this->currentState = State::BETTING;
		}
		
		break;
	case State::GAMECLEAR:
	case State::GAMEOVER:
		if (this->inputKey == this->SPACE_KEY) {
			this->currentState = State::READY;
		}
		break;
	}

	this->inputKey = this->NULL_KEY;
}

/*
* @brief �Q�[�������s���邽�߂̃T�u���[�`���B
*/
void Game::Run() {
	// ESC�L�[���������܂Ń��[�v
	while (this->inputKey != this->ESCAPE_KEY) {
		this->Display();	// ��ʂ̕`��
		this->KeyInput();	// �L�[���͂̎�t
		this->Process();	// �����̎��s
	}
}

/*
* @brief �o�ߎ��Ԃ�ݒ肷��B
* 
* @details �o�ߎ��Ԃ��v�����邽�߂̊J�n�����ƏI��������ݒ肷��B
* @details �O��̏I���������J�n�����ɐݒ肵�A���݂̎������I�������ɐݒ肷��B
*/
void Game::SetTime() {
	this->startTime = this->endTime;
	this->endTime = std::chrono::system_clock::now();
	this->resultTime = this->endTime - this->startTime;
}

/*
* @brief �o�ߎ��Ԃ��擾����B
* 
* @return std::chrono::duration<double> �o�ߎ��ԁB
*/
std::chrono::duration<double> Game::GetResultTime() const {
	return this->resultTime;
}
